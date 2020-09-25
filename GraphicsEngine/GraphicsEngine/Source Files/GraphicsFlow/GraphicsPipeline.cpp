#include "GraphicsPipeline.h"
#include "../Geometry/Mesh.h"
#include "../Geometry/Transforms.h"
#include <filesystem>
#include <cmath>
#include <algorithm>

Mesh mesh;
bool loaded;

void InitPipelining()
{
	const std::string absPath = R"(C:\Users\Dmitry\Documents\GitHub\KartonGameEngine\GraphicsEngine\GraphicsEngine\Resource Files\)";
	loaded = mesh.LoadFromObjectFile(absPath + "teapot.obj3d");
}

void FramePipelineFlow()
{
	if(loaded)
	{
		std::sort(mesh.tris.begin(), mesh.tris.end(), [](Triangle& t1, Triangle& t2)
		{
			float z1 = (t1.points[0].z + t1.points[1].z + t1.points[2].z) / 3.0f;
			float z2 = (t2.points[0].z + t2.points[1].z + t2.points[2].z) / 3.0f;
			return z1 > z2;
		});



		for (Triangle element : mesh.tris)
		{
			auto elementNew = Ortho2DTris(element, 1, 1000, 3.1415 / 2);

			elementNew.points[0].MultiplyByScalar(30);
			elementNew.points[1].MultiplyByScalar(30);
			elementNew.points[2].MultiplyByScalar(30);

			Vector3d v{ 100, 100, 100, 1 };

			elementNew.points[0].AddScalar(v);
			elementNew.points[1].AddScalar(v);
			elementNew.points[2].AddScalar(v);

			DrawTriangle(elementNew);
			printf("new renderer\n");
		}
	}
}

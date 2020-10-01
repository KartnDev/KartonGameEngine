#include "GraphicsPipeline.h"
#include "../Geometry/Mesh.h"
#include "../Geometry/Transforms.h"
#include <filesystem>
#include <cmath>
#include <algorithm>

Mesh mesh;
bool loaded = true;

void InitPipelining()
{
	//const std::string absPath = R"(C:\Users\Dmitry\Documents\GitHub\KartonGameEngine\GraphicsEngine\GraphicsEngine\Resource Files\)";
	//loaded = mesh.LoadFromObjectFile(absPath + "teapot.obj3d");
	Triangle triSouth1;
	triSouth1.points[0] = Vector3d(0.0f, 0.0f, 0.0f, 1.0f);
	triSouth1.points[1] = Vector3d(0.0f, 1.0f, 0.0f, 1.0f);
	triSouth1.points[2] = Vector3d(1.0f, 1.0f, 0.0f, 1.0f);

	Triangle triSouth2;
	triSouth1.points[0] = Vector3d(0.0f, 0.0f, 0.0f, 1.0f);
	triSouth1.points[1] = Vector3d(1.0f, 1.0f, 0.0f, 1.0f);
	triSouth1.points[2] = Vector3d(1.0f, 0.0f, 0.0f, 1.0f);

	Triangle triEast1;
	triSouth1.points[0] = Vector3d(1.0f, 0.0f, 0.0f, 1.0f);
	triSouth1.points[1] = Vector3d(1.0f, 1.0f, 0.0f, 1.0f);
	triSouth1.points[2] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);

	Triangle triEast2;
	triSouth1.points[0] = Vector3d(1.0f, 0.0f, 0.0f, 1.0f);
	triSouth1.points[1] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);
	triSouth1.points[2] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);

	Triangle triNorth1;
	triSouth1.points[0] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);
	triSouth1.points[1] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);
	triSouth1.points[2] = Vector3d(0.0f, 1.0f, 1.0f, 1.0f);

	Triangle triNorth2;
	triSouth1.points[0] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);
	triSouth1.points[1] = Vector3d(0.0f, 1.0f, 1.0f, 1.0f);
	triSouth1.points[2] = Vector3d(0.0f, 0.0f, 1.0f, 1.0f);

	Triangle triWest1;
	triSouth1.points[0] = Vector3d(0.0f, 0.0f, 1.0f, 1.0f);
	triSouth1.points[1] = Vector3d(0.0f, 1.0f, 1.0f, 1.0f);
	triSouth1.points[2] = Vector3d(0.0f, 1.0f, 0.0f, 1.0f);

	Triangle triWest2;
	triSouth1.points[0] = Vector3d(0.0f, 0.0f, 1.0f, 1.0f);
	triSouth1.points[1] = Vector3d(0.0f, 1.0f, 0.0f, 1.0f);
	triSouth1.points[2] = Vector3d(0.0f, 0.0f, 0.0f, 1.0f);

	Triangle triTop1;
	triSouth1.points[0] = Vector3d(0.0f, 1.0f, 0.0f, 1.0f);
	triSouth1.points[1] = Vector3d(0.0f, 1.0f, 1.0f, 1.0f);
	triSouth1.points[2] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);

	Triangle triTop2;
	triSouth1.points[0] = Vector3d(0.0f, 1.0f, 0.0f, 1.0f);
	triSouth1.points[1] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);
	triSouth1.points[2] = Vector3d(1.0f, 1.0f, 0.0f, 1.0f);

	Triangle triBottom1;
	triSouth1.points[0] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);
	triSouth1.points[1] = Vector3d(0.0f, 0.0f, 1.0f, 1.0f);
	triSouth1.points[2] = Vector3d(0.0f, 0.0f, 0.0f, 1.0f);

	Triangle triBottom2;
	triSouth1.points[0] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);
	triSouth1.points[1] = Vector3d(0.0f, 0.0f, 0.0f, 1.0f);
	triSouth1.points[2] = Vector3d(1.0f, 0.0f, 0.0f, 1.0f);

	mesh.tris.push_back(triSouth1);
	mesh.tris.push_back(triSouth2);
	mesh.tris.push_back(triEast1);
	mesh.tris.push_back(triEast2);
	mesh.tris.push_back(triNorth1);
	mesh.tris.push_back(triNorth2);
	mesh.tris.push_back(triWest1);
	mesh.tris.push_back(triWest2);
	mesh.tris.push_back(triTop1);
	mesh.tris.push_back(triTop2);
	mesh.tris.push_back(triBottom1);
	mesh.tris.push_back(triBottom2);

}

void FramePipelineFlow()
{
	if (loaded)
	{
		for (auto element : mesh.tris)
		{
			Vector3d v{ 3.0f, 3.0f, 3.0f, 1.0f };
			element.points[0] += v;
			element.points[1] += v;
			element.points[2] += v;

			auto elementNew = Ortho2DTris(element, 0.1f, 1000, 90);

			// Scale into view
			elementNew.points[0].x += 1.0f; elementNew.points[0].y += 1.0f;
			elementNew.points[1].x += 1.0f; elementNew.points[1].y += 1.0f;
			elementNew.points[2].x += 1.0f; elementNew.points[2].y += 1.0f;
			elementNew.points[0].x *= 0.5f * WIDTH;
			elementNew.points[0].y *= 0.5f * HEIGHT;
			elementNew.points[1].x *= 0.5f * WIDTH;
			elementNew.points[1].y *= 0.5f * HEIGHT;
			elementNew.points[2].x *= 0.5f * WIDTH;
			elementNew.points[2].y *= 0.5f * HEIGHT;

			


			

			DrawTriangle(elementNew);
			printf("new renderer\n");
		}
	}


	



}

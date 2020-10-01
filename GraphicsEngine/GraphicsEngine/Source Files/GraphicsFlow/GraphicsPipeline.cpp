#include "GraphicsPipeline.h"
#include <filesystem>
#include <cmath>
#include <algorithm>
#include "Graphics3D.h"


namespace KtStd::Graphics
{
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
		triSouth2.points[0] = Vector3d(0.0f, 0.0f, 0.0f, 1.0f);
		triSouth2.points[1] = Vector3d(1.0f, 1.0f, 0.0f, 1.0f);
		triSouth2.points[2] = Vector3d(1.0f, 0.0f, 0.0f, 1.0f);

		Triangle triEast1;
		triEast1.points[0] = Vector3d(1.0f, 0.0f, 0.0f, 1.0f);
		triEast1.points[1] = Vector3d(1.0f, 1.0f, 0.0f, 1.0f);
		triEast1.points[2] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);

		Triangle triEast2;
		triEast2.points[0] = Vector3d(1.0f, 0.0f, 0.0f, 1.0f);
		triEast2.points[1] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);
		triEast2.points[2] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);

		Triangle triNorth1;
		triNorth1.points[0] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);
		triNorth1.points[1] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);
		triNorth1.points[2] = Vector3d(0.0f, 1.0f, 1.0f, 1.0f);

		Triangle triNorth2;
		triNorth2.points[0] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);
		triNorth2.points[1] = Vector3d(0.0f, 1.0f, 1.0f, 1.0f);
		triNorth2.points[2] = Vector3d(0.0f, 0.0f, 1.0f, 1.0f);

		Triangle triWest1;
		triWest1.points[0] = Vector3d(0.0f, 0.0f, 1.0f, 1.0f);
		triWest1.points[1] = Vector3d(0.0f, 1.0f, 1.0f, 1.0f);
		triWest1.points[2] = Vector3d(0.0f, 1.0f, 0.0f, 1.0f);

		Triangle triWest2;
		triWest2.points[0] = Vector3d(0.0f, 0.0f, 1.0f, 1.0f);
		triWest2.points[1] = Vector3d(0.0f, 1.0f, 0.0f, 1.0f);
		triWest2.points[2] = Vector3d(0.0f, 0.0f, 0.0f, 1.0f);

		Triangle triTop1;
		triTop1.points[0] = Vector3d(0.0f, 1.0f, 0.0f, 1.0f);
		triTop1.points[1] = Vector3d(0.0f, 1.0f, 1.0f, 1.0f);
		triTop1.points[2] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);

		Triangle triTop2;
		triTop2.points[0] = Vector3d(0.0f, 1.0f, 0.0f, 1.0f);
		triTop2.points[1] = Vector3d(1.0f, 1.0f, 1.0f, 1.0f);
		triTop2.points[2] = Vector3d(1.0f, 1.0f, 0.0f, 1.0f);

		Triangle triBottom1;
		triBottom1.points[0] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);
		triBottom1.points[1] = Vector3d(0.0f, 0.0f, 1.0f, 1.0f);
		triBottom1.points[2] = Vector3d(0.0f, 0.0f, 0.0f, 1.0f);

		Triangle triBottom2;
		triBottom2.points[0] = Vector3d(1.0f, 0.0f, 1.0f, 1.0f);
		triBottom2.points[1] = Vector3d(0.0f, 0.0f, 0.0f, 1.0f);
		triBottom2.points[2] = Vector3d(1.0f, 0.0f, 0.0f, 1.0f);

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
				Vector3d v{ 50.0f, 50.0f, 50.0f, 1.0f };
				auto elementNew = Ortho2DTris(element, 0.1f, 1000, 90);

				elementNew.points[0] *= 100;
				elementNew.points[1] *= 100;
				elementNew.points[2] *= 100;

				elementNew.points[0] += v;
				elementNew.points[1] += v;
				elementNew.points[2] += v;

				for (size_t i = 0; i < 3; i++)
				{
					std::cout << "X" << i << ": " << elementNew.points[i].x << " " << i << "Y: " << elementNew.points[i].y << std::endl;
				}
				std::cout << std::endl;
				DrawTriangle(elementNew);
				
			}
		}
	}
}

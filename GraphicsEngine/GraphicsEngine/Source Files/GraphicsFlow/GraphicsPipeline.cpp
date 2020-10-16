#include "GraphicsPipeline.h"
#include <filesystem>
#include <windows.h>
#include <cmath>
#include <algorithm>
#include "Graphics3D.h"
#include "Camera.h"

namespace KtStd::Graphics
{
	Mesh mesh;
	bool loaded = true;

	Camera cam;

	void InitPipelining()
	{
		// Set All Start Pos
		cam.camVec.Normailize();

		// Load Textures/Objects Region
		const std::string absPath = R"(C:\Users\Dmitry\Documents\GitHub\KartonGameEngine\GraphicsEngine\GraphicsEngine\Resource Files\)";
		loaded = mesh.LoadFromObjectFile(absPath + "teapot.obj3d");
	}

	void FramePipelineFlow(float theta)
	{
		if (loaded)
		{

			for (auto element : mesh.tris)
			{
				Vector3d v{ 300.0f, 200.0f, 200.0f, 1.0f };

				auto rotated = RotateByY(element, theta);


				auto normalOfTri = rotated.GetNormal();

				auto tt = normalOfTri.x * (rotated.points[0].x - cam.camVec.x) +
					normalOfTri.y * (rotated.points[0].y - cam.camVec.y) +
					normalOfTri.z * (rotated.points[0].z - cam.camVec.z);

				if (tt < 0.0f)
				{
					auto elementNew = Ortho2DTris(rotated, 0.1f, 1000, 90);


					elementNew.points[0] *= 40;
					elementNew.points[1] *= 40;
					elementNew.points[2] *= 40;

					elementNew.points[0] += v;
					elementNew.points[1] += v;
					elementNew.points[2] += v;

					DrawTriangle(elementNew);
				}
			}

		}
	}
}

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
		cam.camVec = { 1.0f, 1.0f, 1.0f, 1.0f };

		// Load Textures/Objects Region
		const std::string absPath = R"(C:\Users\Dmitry\Documents\GitHub\KartonGameEngine\GraphicsEngine\GraphicsEngine\Resource Files\)";
		loaded = mesh.LoadFromObjectFile(absPath + "teapot.obj3d");
	}

	void FramePipelineFlow(float theta)
	{
		std::vector<Triangle> vecTrianglesToRaster;
		if (loaded)
		{
			
			for (auto element : mesh.tris)
			{
				Vector3d v{ 300.0f, 200.0f, 200.0f, 1.0f };

				auto rotated = RotateByY(element, theta);
				rotated = RotateByX(rotated, theta);
				rotated = RotateByZ(rotated, theta);

				auto normalOfTri = rotated.GetNormal();

				auto vCameraRay = rotated.points[0] + cam.camVec;

				if (normalOfTri.Dot(vCameraRay) < 0.0f)
				{
					auto elementNew = Ortho2DTris(rotated, 0.1f, 1000, 90);


					elementNew.points[0] *= 70;
					elementNew.points[1] *= 70;
					elementNew.points[2] *= 70;

					elementNew.points[0] += v;
					elementNew.points[1] += v;
					elementNew.points[2] += v;

					vecTrianglesToRaster.push_back(elementNew);
				}

			}


			for (auto& triProjected : vecTrianglesToRaster)
			{
				DrawTriangle(triProjected);
			}
		}

		
	}
}

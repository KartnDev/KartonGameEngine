#include "GraphicsPipeline.h"
#include "../Geometry/Mesh.h"
#include <filesystem>

Mesh mesh;
bool loaded;

void InitPipelining()
{
	const std::string absPath = R"(C:\Users\Dmitry\Documents\GitHub\KartonGameEngine\GraphicsEngine\GraphicsEngine\Resource Files\)";
	loaded = mesh.LoadFromObjectFile(absPath + "Teapot.obj");
}

void FramePipelineFlow()
{
	if(loaded)
	{
		for (Triangle element : mesh.tris)
		{
			//element.points->MultiplyByScalar(10);


			DrawTriangle(element);
			printf("new renderer\n");
		}
	}
}

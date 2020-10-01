#pragma once
#include <GL/glut.h>

#include "Graphing2D.h"
#include "../Math Utilities/vector3d.h"
#include "../Geometry/Mesh.h"
#include "../Geometry/Transforms.h"

using namespace KtStd::Geometry;
using namespace KtStd::Math;


namespace KtStd::Graphics
{
	void InitPipelining();

	void FramePipelineFlow(float theta);
}
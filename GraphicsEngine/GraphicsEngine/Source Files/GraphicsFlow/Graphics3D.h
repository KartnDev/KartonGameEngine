#pragma once

#include "Graphing2D.h"
#include "../Math Utilities/vector3d.h"

using namespace KtStd::Geometry;
using namespace KtStd::Math;

namespace KtStd::Graphics
{
#ifdef USING_FAST_FLOAT
#define GlVector3D glVertex3f
#endif

#ifndef USING_FAST_FLOAT
#define GlVector3D glVertex3d
#endif


	void DrawTriangle3D(const Triangle& triangle);
}

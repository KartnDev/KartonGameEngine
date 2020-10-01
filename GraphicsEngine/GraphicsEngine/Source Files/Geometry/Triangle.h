#pragma once

#include "../Math Utilities/Vector3d.h"

using namespace KtStd;

struct Triangle
{
	Vector3d points[3];
	unsigned char red = 255;
	unsigned char green = 255;
	unsigned char blue = 255;
};


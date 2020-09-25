#pragma once
#include "../Math Utilities/vector3d.h"
#include "../Math Utilities/vector2d.h"
#include "Triangle.h"

Vector2d Ortho2D(Vector3d vec, int zFar, int zNear, float thetaFoV);

Triangle Ortho2DTris(Triangle triangle, int zFar, int zNear, float thetaFoV);



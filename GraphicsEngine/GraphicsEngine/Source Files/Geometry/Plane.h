#pragma once
#include "Triangle.h"
#include "../Math Utilities/vector3d.h"
#include "../Math Utilities/vector2d.h"
#include "Point3D.h"

using namespace KtStd::Math;
using namespace KtStd::Geometry;

struct PlaneVectorized
{
	Vector3d normalPlane;
	Vector3d directVector;
};

struct Plane3Points
{
	Point3D point1;
	Point3D point2;
	Point3D point3;
};


struct PlaneTriangle
{
	Triangle planeTri;
};
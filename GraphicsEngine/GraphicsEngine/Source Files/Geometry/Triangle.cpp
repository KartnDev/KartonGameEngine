#include "Triangle.h"
namespace KtStd::Geometry
{
	Vector3d & Triangle::GetNormal()
	{
		Vector3d res;

		res.x = this->points[0].y * this->points[1].z - this->points[0].z * this->points[1].y;
		res.y = this->points[0].z * this->points[1].x - this->points[0].x * this->points[1].z;
		res.z = this->points[0].x * this->points[1].y - this->points[0].y * this->points[1].x;

		res.Normailize();

		return res;
	}
}
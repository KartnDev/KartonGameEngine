#include "Triangle.h"
namespace KtStd::Geometry
{
	Vector3d & Triangle::GetNormal()
	{
		Vector3d normal, line1, line2;
		line1.x = this->points[1].x - this->points[0].x;
		line1.y = this->points[1].y - this->points[0].y;
		line1.z = this->points[1].z - this->points[0].z;

		line2.x = this->points[2].x - this->points[0].x;
		line2.y = this->points[2].y - this->points[0].y;
		line2.z = this->points[2].z - this->points[0].z;

		normal.x = line1.y * line2.z - line1.z * line2.y;
		normal.y = line1.z * line2.x - line1.x * line2.z;
		normal.z = line1.x * line2.y - line1.y * line2.x;

		normal.Normailize();

		return normal;
	}
}
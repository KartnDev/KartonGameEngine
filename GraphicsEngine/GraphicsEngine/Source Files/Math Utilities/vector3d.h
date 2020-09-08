#include "../Common/pchdr.h"

struct vector3d
{
	FloatFX x, y, z, w;

	vector3d();
	vector3d(FloatFX x, FloatFX y, FloatFX z, FloatFX w);

	inline FloatFX Length() const;
	void Normailize();

	inline bool Equals(const vector3d& rhs) const;
	inline bool operator==(const vector3d& rhs) const;

	inline FloatFX Dot(const vector3d& rhs);
	vector3d Cross(const vector3d& rhs);

	void MultiplyByScalar(FloatFX scalar);
	void operator/= (FloatFX scalar);

	void DivideByScalar(FloatFX scalar);
	void operator*= (FloatFX scalar);

	void AddScalar(const vector3d& rhs);
	void operator+= (const vector3d& rhs);

	void SubScalar(const vector3d& rhs);
	void operator-= (const vector3d& rhs);

	vector3d operator+(const vector3d& rhs);
	vector3d operator-(const vector3d& rhs);
	vector3d operator*(const FloatFX scalar);
	vector3d operator/(const FloatFX scalar);
	
};
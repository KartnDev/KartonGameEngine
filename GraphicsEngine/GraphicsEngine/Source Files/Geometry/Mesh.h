#include "Triangle.h"
#include <vector>
#include <filesystem>
#include <strstream>
#include <fstream>
#include "../Math Utilities/vector3d.h"

struct Mesh
{
	std::vector<Triangle> tris;

	bool LoadFromObjectFile(std::string sFileName);
};


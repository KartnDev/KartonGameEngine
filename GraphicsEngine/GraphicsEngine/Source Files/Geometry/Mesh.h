#include "Triangle.h"
#include <vector>
#include <filesystem>


struct Mesh
{
	std::vector<Triangle> tris;

	bool LoadFromObjectFile(const std::string& sFileName);
};


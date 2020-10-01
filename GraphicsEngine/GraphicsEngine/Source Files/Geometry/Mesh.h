#pragma once
#include <vector>
#include <filesystem>
#include "Triangle.h"
#include "../Math Utilities/vector3d.h"

using namespace KtStd::Math;

namespace KtStd::Geometry
{
	struct Mesh
	{
		std::vector<Triangle> tris;

		bool LoadFromObjectFile(const std::string& sFileName);
	};
}

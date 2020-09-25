#define _SILENCE_CXX17_STRSTREAM_DEPRECATION_WARNING

#include "Mesh.h"
#include <fstream>
#include "../Math Utilities/vector3d.h"
#include <strstream>


bool Mesh::LoadFromObjectFile(const std::string& sFileName)
{
	std::ifstream fileStream(sFileName);
	if (!fileStream.is_open())
	{
		return false;
	}
	//Local cache of vertexes
	std::vector<Vector3d> vertexes;

	while (!fileStream.eof())
	{
		const int buffSize = 128;
		char line[buffSize];
		fileStream.getline(line, buffSize);

		std::strstream stringStream;
		stringStream << line;

		char junk;

		if (line[0] == 'v')
		{
			Vector3d v;
			stringStream >> junk >> v.x >> v.y >> v.z;
			vertexes.push_back(v);
		}
		if (line[0] == 'f')
		{
			int triangleStr[3];
			stringStream >> junk >> triangleStr[0] >> triangleStr[1] >> triangleStr[2];

			tris.push_back({ vertexes[triangleStr[0] - 1],
							 vertexes[triangleStr[1] - 1],
							 vertexes[triangleStr[2] - 1] });
		}
	}
	return true;
}

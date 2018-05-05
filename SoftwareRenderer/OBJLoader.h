#pragma once
#include "Mesh.h"
#include <string>

struct OBJIndex {
	int vertIndex;
	int texIndex;
	int normIndex;
};

class OBJMesh {
public:
	OBJMesh(std::string path);
	Mesh toIndexedMesh();
private:
	void parseVertex(std::vector<std::string> tokens, int lineNr);
	void parseTexCoord(std::vector<std::string> tokens, int lineNr);
	void parseNormal(std::vector<std::string> tokens, int lineNr);
	void parseFace(std::vector<std::string> tokens, int lineNr);
	std::vector<std::string> split(std::string s, char delim);
	std::vector<Vec3> m_vertices;
	std::vector<Vec2> m_texCoords;
	std::vector<Vec3> m_normals;
	std::vector<OBJIndex> m_indices;
}
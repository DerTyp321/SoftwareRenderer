#include "OBJLoader.h"
#include <fstream>
#include <iostream>

OBJMesh::OBJMesh(std::string path) {
	std::cout << "loading OBJ Model " << path << std::endl;
	std::ifstream in(path);
	if (in.is_open()) {
		std::cerr << "Error loading OBJ: cant open file";
	}
	std::string line;
	int lineNr = 0;
	while (std::getline(in, line)) {
		lineNr++;
		std::vector<std::string> tokens = split(line, ' ');
		if (tokens[0] == "v") {
			parseVertex(tokens, lineNr);
		}
		else if (tokens[0] == "vt") {
			parseTexCoord(tokens, lineNr);
		}
		else if (tokens[0] == "vn") {
			parseNormal(tokens, lineNr);
		}
		else if (tokens[0] == "f") {
			parseFace(tokens, lineNr);
		}
	}
	in.close();
}

Mesh OBJMesh::toIndexedMesh() {
	Mesh result;
	int currentVertexIndex = 0;
	for (OBJIndex current : m_indices) {
		Vertex vert(m_vertices[current.vertIndex], m_texCoords[current.texIndex], m_normals[current.normIndex]);
		int existingIndex = result.hasVertex(vert);
		if (existingIndex == -1) {
			result.addVertex(vert);
			result.addIndex(currentVertexIndex);
			currentVertexIndex++;
		}
		else {
			result.addIndex(existingIndex);
		}
	}
	return result;
}

void OBJMesh::parseVertex(std::vector<std::string> tokens, int lineNr) {
	if (tokens.size() < 4) {
		std::cerr << "Error loading OBJ: invalid vertex syntax" << std::endl;
		return;
	}
	m_vertices.push_back(Vec3{ std::stof(tokens[1]), std::stof(tokens[2]), std::stof(tokens[3]) });
}

void OBJMesh::parseTexCoord(std::vector<std::string> tokens, int lineNr) {
	if (tokens.size() < 3) {
		std::cerr << "Error loading OBJ: invalid texture coordinate syntax" << std::endl;
		return;
	}
	m_texCoords.push_back(Vec2{ std::stof(tokens[1]), std::stof(tokens[2])});
}

void OBJMesh::parseNormal(std::vector<std::string> tokens, int lineNr) {
	if (tokens.size() < 4) {
		std::cerr << "Error loading OBJ: invalid vertex syntax" << std::endl;
		return;
	}
	m_normals.push_back(Vec3{ std::stof(tokens[1]), std::stof(tokens[2]), std::stof(tokens[3]) });
}

void OBJMesh::parseFace(std::vector<std::string> tokens, int lineNr) {
	if (tokens.size() < 4) {
		std::cerr << "Error loading OBJ: invalid face syntax" << std::endl;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		std::vector<std::string> vertIndices = split(tokens[i], '/');
		m_indices.push_back(OBJIndex{std::stoi(vertIndices[0]) - 1, std::stoi(vertIndices[1]) - 1 , std::stoi(vertIndices[2]) - 1 });
	}
}

std::vector<std::string> OBJMesh::split(std::string s, char delim) {
	std::vector<std::string> result;
	size_t start = 0;
	for (size_t current = 0; current < s.length(); current++) {
		if (s[current] == delim) {
			result.push_back(s.substr(start, current - start));
			start = current + 1;
		}
	}
	result.push_back(s.substr(start, s.length() - start));
	return result;
}

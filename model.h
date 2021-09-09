#pragma once

#ifndef __MODEL_H__
#define __MODEL_H__

#include "vector3.h"
#include <vector>

using namespace std;

class Model{
public:
	Vector3 center;
	vector<Triangle> triangles;
	vector<Vector3> vertices;
	vector<Vector3> faces;
	
	Model(const char *filename);
	void mesh();
};

#endif
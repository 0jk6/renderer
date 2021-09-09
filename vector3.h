#pragma once

#ifndef __VECTOR_3__
#define __VECTOR_3__

#include <math.h>

class Vector3{
public:
	float x, y, z;

	Vector3();
	Vector3(float mX, float mY, float mZ);

	void scale(float amount);
	void add(float amount);
	void add(Vector3 v);
	void divide(float amount);
	void subtract(Vector3 v);
	void multiply(Vector3 v);
	float distance(Vector3 v1, Vector3 v2);
};


typedef struct{
	Vector3 a, b, c;
} Triangle;

typedef struct{
	int x, y;
} Point;


#endif
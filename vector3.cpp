#include "vector3.h"

Vector3::Vector3(){
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float mX, float mY, float mZ){
	x = mX;
	y = mY;
	z = mZ;
}

void Vector3::scale(float amount){
	x *= amount;
	y *= amount;
	z *= amount;
}

void Vector3::add(float amount){
	x += amount;
	y += amount;
	z += amount;
}

void Vector3::add(Vector3 v){
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector3::divide(float amount){
	x /= amount;
	y /= amount;
	z /= amount;
}

void Vector3::subtract(Vector3 v){
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vector3::multiply(Vector3 v){
	x *= v.x;
	y *= v.y;
	z *= v.z;
}

float Vector3::distance(Vector3 v1, Vector3 v2){
	return (float)sqrt((v2.x-v1.x)*(v2.x-v1.x) + (v2.y-v1.y)*(v2.y-v1.y) + (v2.z-v1.z)*(v2.z-v1.z));
}
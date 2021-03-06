#pragma once
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <cmath>

struct Vector3 {
	float x, y, z;

	Vector3() {
		x = y = z = 0.0f;
	}

	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void set(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3 operator * (const float multiplier) {
		Vector3 newVector(x, y, z);
		newVector.x *= multiplier;
		newVector.y *= multiplier;
		newVector.z *= multiplier;
		return newVector;
	}
	Vector3 operator / (const float multiplier) {
		Vector3 newVector(x, y, z);
		newVector.x /= multiplier;
		newVector.y /= multiplier;
		newVector.z /= multiplier;
		return newVector;
	}
	Vector3 operator + (const Vector3 &vectorb) {
		Vector3 result;
		result.x = x + vectorb.x;
		result.y = y + vectorb.y;
		result.z = z + vectorb.z;
		return result;
	}
	Vector3 operator - (const Vector3 &vectorb) {
		Vector3 result;
		result.x = x - vectorb.x;
		result.y = y - vectorb.y;
		result.z = z - vectorb.z;
		return result;
	}
	Vector3 getAbsolute() {
		Vector3 result;
		result.x = abs(x);
		result.y = abs(y);
		result.z = abs(z);
		return result;
	}
	float getNorm() {
		return sqrt(x*x + y*y + z*z);
	}
	Vector3 getNormalized() {
		return Vector3(*this / getNorm());
	}
};

class Collision {
public:
	Collision() {}
	Collision(Vector3 midPoint, Vector3 collidedPosition, float distance)	{
		this->midPoint = midPoint;
		this->collidedPosition = collidedPosition;
		this->distance = distance;
	}
	~Collision() {

	}

	Vector3 midPoint;
	Vector3 collidedPosition;
	float distance;
};

class GameObject {
protected:
	int glListID;
	float material[4];

public:
	GameObject();
	~GameObject();

	Vector3 *position;
	Vector3 *rotation;
	Vector3 *scale;

	virtual void init();
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void input(SDL_Event &evnt);
	virtual void onCollision(Collision &collision);

	void translate(const Vector3 &translation);
};
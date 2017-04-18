#pragma once
#include <GL/glew.h>

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
};

class GameObject {
public:
	GameObject();
	~GameObject();

	Vector3 *position;
	Vector3 *rotation;
	Vector3 *scale;

	virtual void update(float deltaTime);
	virtual void draw();
};

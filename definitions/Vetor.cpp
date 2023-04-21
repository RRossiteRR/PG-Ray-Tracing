#ifndef _VETOR_
#define _VETOR_

#include <iostream>
#include <stdio.h>

#include "Vetor.hpp"
#include <cmath>

using namespace std;

Vec3::Vec3() : x(0), y(0), z(0){};

Vec3::Vec3(float x) : x(x), y(x), z(x) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z)
{
}

Vec3::Vec3(Vec3 const &v) : x(v.x), y(v.y), z(v.z)
{
}

Vec3::~Vec3() {}

inline float Vec3::comp2() const
{
	return qdd(x) + qdd(y) + qdd(z);
}

inline float Vec3::comp() const
{
	return sqrt(comp2());
}

Vec3 Vec3::normalizar() const
{
	float mag = comp();
	return Vec3(x / mag, y / mag, z / mag);
}

Vec3 Vec3::refletir(const Vec3 &normal) const
{
	// retorna uma vetor com a direção do raio refletida sobre a normal fornecida
	Vec3 v = *this;
	return v - (normal * pr_esc(v, normal)) * 2;
}

bool Vec3::refratar(Vec3 &v, const Vec3 &normal, float refInd)
{
	v = this->normalizar();
	float r = 1 / refInd;
	float cos_theta = pr_esc(-v, normal);
	float sin2_theta = qdd(r) * (1 - qdd(cos_theta));
	if (sin2_theta > 1)
		return false;

	v = r * v + (r * cos_theta - sqrt(1 - sin2_theta)) * normal;
	return true;
};

Vec3 Vec3::neg() const
{
	return Vec3(-x, -y, -z);
}
// produto escalar
float pr_esc(Vec3 v1, Vec3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
// produto vetorial
Vec3 pr_vet(Vec3 v1, Vec3 v2)
{
	return Vec3(v1.y * v2.z - v1.z * v2.y,
				v1.z * v2.x - v1.x * v2.z,
				v1.x * v2.y - v1.y * v2.x);
}

Vec3 &Vec3::operator+=(const Vec3 &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vec3 &Vec3::operator-=(const Vec3 &v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vec3 &Vec3::operator*=(float f)
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

Vec3 &Vec3::operator/=(float f)
{
	x /= f;
	y /= f;
	z /= f;
	return *this;
}

Vec3 Vec3::operator-() const
{
	return Vec3(-x, -y, -z);
}

#endif
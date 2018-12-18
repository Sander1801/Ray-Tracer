#include "Math/Vector.h"

#include <assert.h>
#include <stdexcept>
#include <math.h>     

///////////////////
// Vector 2      //
///////////////////

vec2::vec2() : m_X(0.f), m_Y(0.f)
{
}

vec2::vec2(float a_X, float a_Y) : m_X(a_X), m_Y(a_Y)
{
}

vec2 & vec2::operator=(const vec2 & rhs)
{
	m_X = rhs.m_X;
	m_Y = rhs.m_Y;
	return *this;
}

vec2 & vec2::operator+=(const vec2 & a_Rhs)
{
	m_X += a_Rhs.m_X;
	m_Y += a_Rhs.m_Y;
	return *this;
}

vec2 & vec2::operator-=(const vec2 & a_Rhs)
{
	m_X -= a_Rhs.m_X;
	m_Y -= a_Rhs.m_Y;
	return *this;
}

vec2 & vec2::operator*=(float a_Rhs)
{
	m_X *= a_Rhs;
	m_Y *= a_Rhs;
	return *this;
}

vec2 & vec2::operator/=(float a_Rhs)
{
	m_X /= a_Rhs;
	m_Y /= a_Rhs;
	return *this;
}

float vec2::operator[](int a_Index) const
{
	assert(a_Index == 0 || a_Index == 1);
	return v[a_Index];
}

float & vec2::operator[](int a_Index)
{
	assert(a_Index == 0 || a_Index == 1);
	return v[a_Index];
}

vec2 & vec2::normalize()
{
	float fLength = length();

	if (fLength != 0) {
		m_X = m_X / fLength;
		m_Y = m_Y / fLength;
	}

	return *this;
}

inline float vec2::length() const
{
	return static_cast<float>(sqrt((m_X * m_X) + (m_Y * m_Y)));
}

vec2 operator+(const vec2 & a_Lhs, const vec2 & a_Rhs)
{
	return vec2(a_Lhs.m_X + a_Rhs.m_X, a_Lhs.m_Y + a_Rhs.m_Y);
}

vec2 operator-(const vec2 & a_Lhs, const vec2 & a_Rhs)
{
	return vec2(a_Lhs.m_X - a_Rhs.m_X, a_Lhs.m_Y - a_Rhs.m_Y);
}

vec2 operator*(const vec2 & a_Lhs, float a_Rhs)
{
	return vec2(a_Lhs.m_X * a_Rhs, a_Lhs.m_Y * a_Rhs);
}

vec2 operator/(const vec2 & a_Lhs, float a_Rhs)
{
	return vec2(a_Lhs.m_X / a_Rhs, a_Lhs.m_Y / a_Rhs);
}

bool operator==(const vec2 & a_Lhs, const vec2 & a_Rhs)
{
	return (a_Lhs.m_X == a_Rhs.m_X && a_Lhs.m_Y == a_Rhs.m_Y);
}

bool operator!=(const vec2 & a_Lhs, const vec2 & a_Rhs)
{
	return !(a_Lhs.m_X == a_Rhs.m_X && a_Lhs.m_Y == a_Rhs.m_Y);
}

///////////////////
// Vector 3      //
///////////////////

vec3::vec3() : m_X(0.f), m_Y(0.f), m_Z(0.f)
{
}

vec3::vec3(float a_X, float a_Y, float a_Z) : m_X(a_X), m_Y(a_Y), m_Z(a_Z)
{
}

vec3 & vec3::operator-()
{
	this->m_X = -m_X;
	this->m_Y = -m_Y;
	this->m_Z = -m_Z;
	return *this;
}

vec3 & vec3::operator=(const vec3 & rhs)
{
	m_X = rhs.m_X;
	m_Y = rhs.m_Y;
	m_Z = rhs.m_Z;
	return *this;
}

vec3 & vec3::operator+=(const vec3 & a_Rhs)
{
	m_X += a_Rhs.m_X;
	m_Y += a_Rhs.m_Y;
	m_Z += a_Rhs.m_Z;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & a_Rhs)
{
	m_X -= a_Rhs.m_X;
	m_Y -= a_Rhs.m_Y;
	m_Z -= a_Rhs.m_Z;
	return *this;
}

vec3 & vec3::operator*=(float a_Rhs)
{
	m_X *= a_Rhs;
	m_Y *= a_Rhs;
	m_Z *= a_Rhs;
	return *this;
}

vec3 & vec3::operator/=(float a_Rhs)
{
	m_X /= a_Rhs;
	m_Y /= a_Rhs;
	m_Z /= a_Rhs;
	return *this;
}

float vec3::operator[](int a_Index) const
{
	assert(a_Index == 0 || a_Index == 1 || a_Index == 2);
	return v[a_Index];
}

float & vec3::operator[](int a_Index)
{
	assert(a_Index == 0 || a_Index == 1 || a_Index == 2);
	return v[a_Index];
}

vec3 & vec3::normalize()
{
	float fLength = length();

	if (fLength != 0) {
		m_X = m_X / fLength;
		m_Y = m_Y / fLength;
		m_Z = m_Z / fLength;
	}

	return *this;
}

inline float vec3::length() const
{
	return static_cast<float>(sqrt((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z)));
}

vec3 operator+(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return vec3(a_Lhs.m_X + a_Rhs.m_X, a_Lhs.m_Y + a_Rhs.m_Y, a_Lhs.m_Z + a_Rhs.m_Z);
}

vec3 operator-(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return vec3(a_Lhs.m_X - a_Rhs.m_X, a_Lhs.m_Y - a_Rhs.m_Y, a_Lhs.m_Z - a_Rhs.m_Z);
}

vec3 operator*(const vec3 & a_Lhs, float a_Rhs)
{
	return vec3(a_Lhs.m_X * a_Rhs, a_Lhs.m_Y * a_Rhs, a_Lhs.m_Z * a_Rhs);
}

vec3 operator*(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return vec3(a_Lhs.m_X * a_Rhs.m_X, a_Lhs.m_Y * a_Rhs.m_Y, a_Lhs.m_Z * a_Rhs.m_Z);
}

vec3 operator/(const vec3 & a_Lhs, float a_Rhs)
{
	return vec3(a_Lhs.m_X / a_Rhs, a_Lhs.m_Y / a_Rhs, a_Lhs.m_Z / a_Rhs);
}

vec3 operator/(float a_Lhs, const vec3 & a_Rhs)
{
	return vec3(a_Lhs / a_Rhs.m_X, a_Lhs / a_Rhs.m_Y, a_Lhs / a_Rhs.m_Z);
}

vec3 operator/(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return vec3(a_Lhs.m_X / a_Rhs.m_X, a_Lhs.m_Y / a_Rhs.m_Y, a_Lhs.m_Z / a_Rhs.m_Z);
}

bool operator==(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return (a_Lhs.m_X == a_Rhs.m_X && a_Lhs.m_Y == a_Rhs.m_Y && a_Lhs.m_Z == a_Rhs.m_Z);
}

bool operator!=(const vec3 & a_Lhs, const vec3 & a_Rhs)
{
	return !(a_Lhs.m_X == a_Rhs.m_X && a_Lhs.m_Y == a_Rhs.m_Y && a_Lhs.m_Z == a_Rhs.m_Z);
}

///////////////////
// Vector 4      //
///////////////////

vec4::vec4() : m_X(0.f), m_Y(0.f), m_Z(0.f), m_W(0.f)
{
}

vec4::vec4(vec3 a_v3XYZ, float a_W)
{
	m_X = a_v3XYZ.m_X;
	m_Y = a_v3XYZ.m_Y;
	m_Z = a_v3XYZ.m_Z;
	m_W = a_W;
}

vec4::vec4(float a_X, float a_Y, float a_Z, float a_W) : m_X(a_X), m_Y(a_Y), m_Z(a_Z), m_W(a_W)
{
}

vec4 & vec4::operator-()
{
	this->m_X = -m_X;
	this->m_Y = -m_Y;
	this->m_Z = -m_Z;
	this->m_W = -m_W;
	return *this;
}

vec4 & vec4::operator+()
{
	this->m_X = +m_X;
	this->m_Y = +m_Y;
	this->m_Z = +m_Z;
	this->m_W = +m_W;
	return *this;
}

vec4 & vec4::operator=(const vec4 & rhs)
{
	m_X = rhs.m_X;
	m_Y = rhs.m_Y;
	m_Z = rhs.m_Z;
	m_W = rhs.m_W;
	return *this;
}

vec4 & vec4::operator+=(const vec4 & a_Rhs)
{
	m_X += a_Rhs.m_X;
	m_Y += a_Rhs.m_Y;
	m_Z += a_Rhs.m_Z;
	m_W += a_Rhs.m_W;
	return *this;
}

vec4 & vec4::operator-=(const vec4 & a_Rhs)
{
	m_X -= a_Rhs.m_X;
	m_Y -= a_Rhs.m_Y;
	m_Z -= a_Rhs.m_Z;
	m_W -= a_Rhs.m_W;
	return *this;
}

vec4 & vec4::operator*=(float a_Rhs)
{
	m_X *= a_Rhs;
	m_Y *= a_Rhs;
	m_Z *= a_Rhs;
	m_W *= a_Rhs;
	return *this;
}

vec4 & vec4::operator/=(float a_Rhs)
{
	m_X /= a_Rhs;
	m_Y /= a_Rhs;
	m_Z /= a_Rhs;
	m_W /= a_Rhs;
	return *this;
}

float vec4::operator[](int a_Index) const
{
	assert(a_Index == 0 || a_Index == 1 || a_Index == 2 || a_Index == 3);
	return v[a_Index];
}

float & vec4::operator[](int a_Index)
{
	assert(a_Index == 0 || a_Index == 1 || a_Index == 2 || a_Index == 3);
	return v[a_Index];
}
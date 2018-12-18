#pragma once
#pragma warning(push)
#pragma warning(disable : 4201) // Disable warning message 4201 (nameless union/struct)

///////////////////
// Vector 2      //
///////////////////

class vec2
{
public:
	union {
		struct
		{
			float m_X;
			float m_Y;
		};
		float v[2];
	};

public:
	vec2();
	vec2(float a_X, float a_Y);

	vec2& operator=(const vec2& rhs);

	vec2& operator+=(const vec2 &a_Rhs);
	vec2& operator-=(const vec2 &a_Rhs);
	vec2& operator*=(float a_Rhs);
	vec2& operator/=(float a_Rhs);

	float operator[](int a_Index) const;
	float& operator[](int a_Index);

	inline float dot(vec2 const& a_Rhs) const { return m_X * a_Rhs.m_X + m_Y * a_Rhs.m_Y; };
	vec2& normalize();
	inline float length() const;
};

vec2 operator+(const vec2 &a_Lhs, const vec2 &a_Rhs);
vec2 operator-(const vec2 &a_Lhs, const vec2 &a_Rhs);
vec2 operator*(const vec2 &a_Lhs, float a_Rhs);
vec2 operator/(const vec2 &a_Lhs, float a_Rhs);
bool operator==(const vec2 &a_Lhs, const vec2 &a_Rhs);
bool operator!=(const vec2 &a_Lhs, const vec2 &a_Rhs);

///////////////////
// Vector 3      //
///////////////////

class vec3 {
public:
	union {
		struct
		{
			float m_X;
			float m_Y;
			float m_Z;
		};
		float v[3];
	};
	
public:
	vec3();
	vec3(float a_X, float a_Y, float a_Z);

	vec3& operator-();
	vec3& operator=(const vec3& rhs);

	vec3& operator+=(const vec3 &a_Rhs);
	vec3& operator-=(const vec3 &a_Rhs);
	vec3& operator*=(float a_Rhs);
	vec3& operator/=(float a_Rhs);

	float operator[](int a_Index) const;
	float& operator[](int a_Index);

	inline float dot(vec3 const& a_Rhs) const { return m_X * a_Rhs.m_X + m_Y * a_Rhs.m_Y + m_Z * a_Rhs.m_Z; };
	inline vec3 cross(vec3 const& a_Rhs) const {
		return vec3((m_Y * a_Rhs.m_Z) - (m_Z * a_Rhs.m_Y),
					(m_Z * a_Rhs.m_X) - (m_X * a_Rhs.m_Z),
					(m_X * a_Rhs.m_Y) - (m_Y * a_Rhs.m_X));
	};
	vec3& normalize();
	inline float length() const;
};

vec3 operator+(const vec3 &a_Lhs, const vec3 &a_Rhs);
vec3 operator-(const vec3 &a_Lhs, const vec3 &a_Rhs);
vec3 operator*(const vec3 &a_Lhs, float a_Rhs);
vec3 operator*(const vec3 &a_Lhs, const vec3 &a_Rhs);
vec3 operator/(const vec3 &a_Lhs, float a_Rhs);
vec3 operator/(float a_Lhs, const vec3 &a_Rhs);
vec3 operator/(const vec3 &a_Lhs, const vec3 &a_Rhs);
bool operator==(const vec3 &a_Lhs, const vec3 &a_Rhs);
bool operator!=(const vec3 &a_Lhs, const vec3 &a_Rhs); 

///////////////////
// Vector 4      //
///////////////////

class vec4 {
public:
	union {
		struct
		{
			float m_X;
			float m_Y;
			float m_Z;
			float m_W;
		};
		float v[4];
	};

public:
	vec4();
	vec4(vec3 a_v3XYZ, float a_W);
	vec4(float a_X, float a_Y, float a_Z, float a_W);

	vec4& operator-();
	vec4& operator+();
	vec4& operator=(const vec4& rhs);

	vec4& operator+=(const vec4 &a_Rhs);
	vec4& operator-=(const vec4 &a_Rhs);
	vec4& operator*=(float a_Rhs);
	vec4& operator/=(float a_Rhs);

	float operator[](int a_Index) const;
	float& operator[](int a_Index);
};

#pragma warning(pop) 
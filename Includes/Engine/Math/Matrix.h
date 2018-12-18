/*
 *
 * 4x4 matrix.
 * Note: I am using the float array instead of m_00, et cetera. The reason: in the beginning I had 
 * a warning about nameless struct/union, so I removed m_00, et cetera. 
 * So a lot of functions were done, and after that I added the #pragma warning. I did not want to rewrite everything, so 
 * I decided to finish the class with the float array.
 *
*/


#pragma once
#pragma warning(push)
#pragma warning(disable : 4201) // Disable warning message 4201 (nameless union/struct)

// Preprocessor define
#define USE_INVERSE_ALGORITHM true  

#include "Vector.h"

#include <iostream>

class mat4
{
public:
	union {
		struct
		{
			float m_00; float m_01; float m_02; float m_03;
			float m_10; float m_11; float m_12; float m_13;
			float m_20; float m_21; float m_22; float m_23;
			float m_30; float m_31; float m_32; float m_33;
		};
		float m[16];
	};

public:
	// Matrix is an identity matrix as default.
	mat4();
	mat4(vec3 a_Row0, float a_03,
		vec3 a_Row1, float a_13,
		vec3 a_Row2, float a_23,
		vec3 a_Row3, float a_33);
	mat4(float a_00, float a_01, float a_02, float a_03,
		float a_10, float a_11, float a_12, float a_13,
		float a_20, float a_21, float a_22, float a_23,
		float a_30, float a_31, float a_32, float a_33);

	mat4& operator=(const mat4& rhs);

	mat4& operator+=(const mat4 &a_Rhs);
	mat4& operator-=(const mat4 &a_Rhs);
	mat4& operator*=(const mat4 &a_Rhs);

	float determinant() const;
	float determinant(int iN) const;
	inline mat4& inverse() {
		float fDeterminant = determinant();

		if (fDeterminant == 0.f) {
			std::cout << "Cannot find the inverse" << std::endl;
			return *this;
		}

		#if USE_INVERSE_ALGORITHM  
			mat4 m4Temp;
			adjoint(m4Temp, 4); // This class is a 4x4 matrix.

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					m[(i * 4) + j] = m4Temp.m[(i * 4) + j] / fDeterminant;
				}
			}
		#else  
			// New matrix
			mat4 m4;
			m4 += *this;

			// Row one
			m4.m[0] =  m[5] * m[10] * m[15] + m[6] * m[11] * m[13] + m[7] * m[9] * m[14] -
					m[7] * m[10] * m[13] - m[6] * m[9] * m[15] - m[5] * m[11] * m[14];
			m4.m[1] =  -(m[1] * m[10] * m[15] + m[2] * m[11] * m[13] + m[3] * m[9] * m[14] -
					m[3] * m[10] * m[13] - m[2] * m[9] * m[15] - m[1] * m[11] * m[14]);
			m4.m[2] =  m[1] * m[6] * m[15] + m[2] * m[7] * m[13] + m[3] * m[5] * m[14] -
					m[3] * m[6] * m[13] - m[2] * m[5] * m[15] - m[1] * m[7] * m[14];
			m4.m[3] =  -(m[1] * m[6] * m[11] + m[2] * m[7] * m[9] + m[3] * m[5] * m[10] -
					m[3] * m[6] * m[9] - m[2] * m[5] * m[11] - m[1] * m[7] * m[10]);
			// Row two
			m4.m[4] =  -(m[4] * m[10] * m[15] + m[6] * m[11] * m[12] + m[7] * m[8] * m[14] -
					m[7] * m[10] * m[12] - m[6] * m[8] * m[15] - m[4] * m[11] * m[14]);
			m4.m[5] =  m[0] * m[10] * m[15] + m[2] * m[11] * m[12] + m[3] * m[8] * m[14] -
					m[3] * m[10] * m[12] - m[2] * m[8] * m[15] - m[0] * m[11] * m[14];
			m4.m[6] =  -(m[0] * m[6] * m[15] + m[2] * m[7] * m[12] + m[3] * m[4] * m[14] -
					m[3] * m[6] * m[12] - m[2] * m[4] * m[15] - m[0] * m[7] * m[14]);
			m4.m[7] =  m[0] * m[6] * m[11] + m[2] * m[7] * m[8] + m[3] * m[4] * m[10] -
					m[3] * m[6] * m[8] - m[2] * m[4] * m[11] - m[0] * m[7] * m[10];
			// Row three
			m4.m[8] =  m[4] * m[9] * m[15] + m[5] * m[11] * m[12] + m[7] * m[8] * m[13] -
					m[7] * m[9] * m[12] - m[5] * m[8] * m[15] - m[4] * m[11] * m[13];
			m4.m[9] =  -(m[0] * m[9] * m[15] + m[1] * m[11] * m[12] + m[3] * m[8] * m[13] -
					m[3] * m[9] * m[12] - m[1] * m[8] * m[15] - m[0] * m[11] * m[13]);
			m4.m[10] = m[0] * m[5] * m[15] + m[1] * m[7] * m[12] + m[3] * m[4] * m[13] -
					m[3] * m[5] * m[12] - m[1] * m[4] * m[15] - m[0] * m[7] * m[13];
			m4.m[11] = -(m[0] * m[5] * m[11] + m[1] * m[7] * m[8] + m[3] * m[4] * m[9] -
					m[3] * m[5] * m[8] - m[1] * m[4] * m[11] - m[0] * m[7] * m[9]);
			// Row three
			m4.m[12] = -(m[4] * m[9] * m[14] + m[5] * m[10] * m[12] + m[6] * m[8] * m[13] -
					m[6] * m[9] * m[12] - m[5] * m[8] * m[14] - m[4] * m[10] * m[13]);
			m4.m[13] = m[0] * m[9] * m[14] + m[1] * m[10] * m[12] + m[2] * m[8] * m[13] -
					m[2] * m[9] * m[12] - m[1] * m[8] * m[14] - m[0] * m[10] * m[13];
			m4.m[14] = -(m[0] * m[5] * m[14] + m[1] * m[6] * m[12] + m[2] * m[4] * m[13] -
					m[2] * m[5] * m[12] - m[1] * m[4] * m[14] - m[0] * m[6] * m[13]);
			m4.m[15] = m[0] * m[5] * m[10] + m[1] * m[6] * m[8] + m[2] * m[4] * m[9] -
					m[2] * m[5] * m[8] - m[1] * m[4] * m[10] - m[0] * m[6] * m[9];

			for (int i = 0; i < 16; i++) {
				m[i] = 1 / fDeterminant * m4.m[i];
			}
		#endif

		return *this;
	};
	void adjoint(mat4& a_m4, int iN) const; // NxN matrix. This class is a 4x4 matrix, so iN should be 4.
	void getCofactor(mat4& a_m4, int a_iRow, int a_iCell, int iN) const;

	static mat4 identity();
	static mat4 rotateX(float a_Radians);
	static mat4 rotateY(float a_Radians);
	static mat4 rotateZ(float a_Radians);
	static mat4 translate(const vec3 &a_Translation);

	static mat4 lookat(const vec3 &a_Eye, const vec3 &a_Center, const vec3 &a_Up = vec3(0, 1, 0));
	static mat4 projection(float a_FovY, float a_AspectRatio, float a_Near, float a_Far);

	/**
	 * Receive a specific cell of the 4x4 matrix with the parentheses.
	 * It is not allowed to pass a number lower than zero or higher than three, because it is a 4x4 matrix.
	 *
	 * @param a_iRow: number between zero and three.
	 * @param a_iCell: number between zero and three.
	 * @example matrix(2, 3); . This will return the value of the third row and fourth cell. 
	 * @return This function returns a float value.
	*/
	float operator()(int a_iRow, int a_iCell) const;
	float& operator()(int a_iRow, int a_iCell);

	/**
	 * Receive a specific cell of the 4x4 matrix with the square brackets.
	 * It is not allowed to pass a number lower than zero or higher than three, because it is a 4x4 matrix.
	 *
	 * @param a_iRow: number between zero and three.
	 * @param a_iCell: number between zero and three. 
	 * @example matrix[2, 3]; . This will return the value of the third row and fourth cell. 
	 * @return This function returns a float value.
	*/
	struct SquareBracketProxy {
		int m_iRow;
		mat4& m_m4Owner;

		SquareBracketProxy(mat4& a_m4Owner, int a_iRow);
		float operator[](int a_iCell) const;
		float& operator[](int a_iCell);
	};
	SquareBracketProxy operator[] (int a_iRow);
};

mat4 operator+(const mat4 &a_Lhs, const mat4 &a_Rhs);
mat4 operator-(const mat4 &a_Lhs, const mat4 &a_Rhs);
mat4 operator*(const mat4 &a_Lhs, const mat4 &a_Rhs);
vec3 operator*(const mat4 &a_Lhs, const vec3 &a_Rhs);
vec4 operator*(const mat4 &a_Lhs, const vec4 &a_Rhs);

#pragma warning(pop) 
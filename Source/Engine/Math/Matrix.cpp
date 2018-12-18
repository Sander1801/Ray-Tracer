#include "Math/Matrix.h"

#include <assert.h>
#include <math.h>

mat4::mat4()
{
	// Set identity matrix
	m[0] = m[1] = m[2] = m[3] = m[4] = m[5] = m[6] =
		m[7] = m[8] = m[9] = m[10] = m[11] = m[12] = m[13] = m[14] = m[15] = 0;
}

mat4::mat4(vec3 a_Row0, float a_03, vec3 a_Row1, float a_13, vec3 a_Row2, float a_23, vec3 a_Row3, float a_33)
{
	m[0] = a_Row0.m_X;
	m[1] = a_Row0.m_Y;
	m[2] = a_Row0.m_Z;
	m[3] = a_03;

	m[4] = a_Row1.m_X;
	m[5] = a_Row1.m_Y;
	m[6] = a_Row1.m_Z;
	m[7] = a_13;

	m[8] = a_Row2.m_X;
	m[9] = a_Row2.m_Y;
	m[10] = a_Row2.m_Z;
	m[11] = a_23;
	
	m[12] = a_Row3.m_X;
	m[13] = a_Row3.m_Y;
	m[14] = a_Row3.m_Z;
	m[15] = a_33;
}

mat4::mat4(float a_00, float a_01, float a_02, float a_03, float a_10, float a_11, float a_12, float a_13, float a_20, float a_21, float a_22, float a_23, float a_30, float a_31, float a_32, float a_33)
{
	m[0] = a_00;
	m[1] = a_01;
	m[2] = a_02;
	m[3] = a_03;

	m[4] = a_10;
	m[5] = a_11;
	m[6] = a_12;
	m[7] = a_13;

	m[8] = a_20;
	m[9] = a_21;
	m[10] = a_22;
	m[11] = a_23;

	m[12] = a_30;
	m[13] = a_31;
	m[14] = a_32;
	m[15] = a_33;
}

mat4 & mat4::operator=(const mat4 & rhs)
{
	m[0] = rhs.m[0];
	m[1] = rhs.m[1];
	m[2] = rhs.m[2];
	m[3] = rhs.m[3];

	m[4] = rhs.m[4];
	m[5] = rhs.m[5];
	m[6] = rhs.m[6];
	m[7] = rhs.m[7];

	m[8] = rhs.m[8];
	m[9] = rhs.m[9];
	m[10] = rhs.m[10];
	m[11] = rhs.m[11];

	m[12] = rhs.m[12];
	m[13] = rhs.m[13];
	m[14] = rhs.m[14];
	m[15] = rhs.m[15];

	return *this;
}

mat4 & mat4::operator+=(const mat4 & a_Rhs)
{
	m[0] += a_Rhs.m[0];
	m[1] += a_Rhs.m[1];
	m[2] += a_Rhs.m[2];
	m[3] += a_Rhs.m[3];

	m[4] += a_Rhs.m[4];
	m[5] += a_Rhs.m[5];
	m[6] += a_Rhs.m[6];
	m[7] += a_Rhs.m[7];

	m[8] += a_Rhs.m[8];
	m[9] += a_Rhs.m[9];
	m[10] += a_Rhs.m[10];
	m[11] += a_Rhs.m[11];

	m[12] += a_Rhs.m[12];
	m[13] += a_Rhs.m[13];
	m[14] += a_Rhs.m[14];
	m[15] += a_Rhs.m[15];

	return *this;
}

mat4 & mat4::operator-=(const mat4 & a_Rhs)
{
	m[0] -= a_Rhs.m[0];
	m[1] -= a_Rhs.m[1];
	m[2] -= a_Rhs.m[2];
	m[3] -= a_Rhs.m[3];

	m[4] -= a_Rhs.m[4];
	m[5] -= a_Rhs.m[5];
	m[6] -= a_Rhs.m[6];
	m[7] -= a_Rhs.m[7];

	m[8] -= a_Rhs.m[8];
	m[9] -= a_Rhs.m[9];
	m[10] -= a_Rhs.m[10];
	m[11] -= a_Rhs.m[11];

	m[12] -= a_Rhs.m[12];
	m[13] -= a_Rhs.m[13];
	m[14] -= a_Rhs.m[14];
	m[15] -= a_Rhs.m[15];

	return *this;
}

mat4 & mat4::operator*=(const mat4 & a_Rhs)
{
	float temp[16];

	temp[0] = m[0] * a_Rhs.m[0] + m[1] * a_Rhs.m[4] + m[2] * a_Rhs.m[8] + m[3] * a_Rhs.m[12];
	temp[1] = m[0] * a_Rhs.m[1] + m[1] * a_Rhs.m[5] + m[2] * a_Rhs.m[9] + m[3] * a_Rhs.m[13];
	temp[2] = m[0] * a_Rhs.m[2] + m[1] * a_Rhs.m[6] + m[2] * a_Rhs.m[10] + m[3] * a_Rhs.m[14];
	temp[3] = m[0] * a_Rhs.m[3] + m[1] * a_Rhs.m[7] + m[2] * a_Rhs.m[11] + m[3] * a_Rhs.m[15];
	// Row two
	temp[4] = m[4] * a_Rhs.m[0] + m[5] * a_Rhs.m[4] + m[6] * a_Rhs.m[8] + m[7] * a_Rhs.m[12];
	temp[5] = m[4] * a_Rhs.m[1] + m[5] * a_Rhs.m[5] + m[6] * a_Rhs.m[9] + m[7] * a_Rhs.m[13];
	temp[6] = m[4] * a_Rhs.m[2] + m[5] * a_Rhs.m[6] + m[6] * a_Rhs.m[10] + m[7] * a_Rhs.m[14];
	temp[7] = m[4] * a_Rhs.m[3] + m[5] * a_Rhs.m[7] + m[6] * a_Rhs.m[11] + m[7] * a_Rhs.m[15];
	// Row three
	temp[8] = m[8] * a_Rhs.m[0] + m[9] * a_Rhs.m[4] + m[10] * a_Rhs.m[8] + m[11] * a_Rhs.m[12];
	temp[9] = m[8] * a_Rhs.m[1] + m[9] * a_Rhs.m[5] + m[10] * a_Rhs.m[9] + m[11] * a_Rhs.m[13];
	temp[10] = m[8] * a_Rhs.m[2] + m[9] * a_Rhs.m[6] + m[10] * a_Rhs.m[10] + m[11] * a_Rhs.m[14];
	temp[11] = m[8] * a_Rhs.m[3] + m[9] * a_Rhs.m[7] + m[10] * a_Rhs.m[11] + m[11] * a_Rhs.m[15];
	// Row four
	temp[12] = m[12] * a_Rhs.m[0] + m[13] * a_Rhs.m[4] + m[14] * a_Rhs.m[8] + m[15] * a_Rhs.m[12];
	temp[13] = m[12] * a_Rhs.m[1] + m[13] * a_Rhs.m[5] + m[14] * a_Rhs.m[9] + m[15] * a_Rhs.m[13];
	temp[14] = m[12] * a_Rhs.m[2] + m[13] * a_Rhs.m[6] + m[14] * a_Rhs.m[10] + m[15] * a_Rhs.m[14];
	temp[15] = m[12] * a_Rhs.m[3] + m[13] * a_Rhs.m[7] + m[14] * a_Rhs.m[11] + m[15] * a_Rhs.m[15];

	for (int a = 0; a < 16; a++) {
		m[a] = temp[a];
	}

	return *this;
}

// Return hard code determinant
float mat4::determinant() const
{
	return  m[0] * (m[5] * (m[10] * m[15] - m[11] * m[14]) - m[6] * (m[9] * m[15] - m[11] * m[13]) + m[7] * (m[9] * m[14] - m[10] * m[13])) -
		m[1] * (m[4] * (m[10] * m[15] - m[11] * m[14]) - m[6] * (m[8] * m[15] - m[11] * m[12]) + m[7] * (m[8] * m[14] - m[10] * m[12])) +
		m[2] * (m[4] * (m[9] * m[15] - m[11] * m[13]) - m[5] * (m[8] * m[15] - m[11] * m[12]) + m[7] * (m[8] * m[13] - m[9] * m[12])) -
		m[3] * (m[4] * (m[9] * m[14] - m[10] * m[13]) - m[5] * (m[8] * m[14] - m[10] * m[12]) + m[6] * (m[8] * m[13] - m[9] * m[12]));
}

void mat4::adjoint(mat4& a_m4, int iN) const
{
	int iSign = 1; // + - + - + - + - ....... Use + when the sum of row and column indexes is even.
	mat4 m4Temp; // Temporary mat4

	// This is an 4x4 matrix, so it loops 4 times 4.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// Get the cofactor
			getCofactor(m4Temp, i, j, iN);

			// Use + when the sum of row and column indexes is even.
			iSign = (i + j) % 2 == 0 ? 1 : -1;

			// Add the adjoint of the column. The matrix is a transpose.
			a_m4.m[(j * 4) + i] = iSign * m4Temp.determinant(iN - 1);
		}
	}
}

void mat4::getCofactor(mat4 & a_m4, int a_iRow, int a_iCell, int iN) const
{
	int i = 0;
	int j = 0;

	// This is an 4x4 matrix, so it loops 4 times 4.
	for (int iRow = 0; iRow < iN; iRow++) {
		for (int iCell = 0; iCell < iN; iCell++) {
			if (iRow != a_iRow && iCell != a_iCell) {
				a_m4.m[(i * 4) + j++] = m[(iRow * 4) + iCell]; // Transpose. 

				// The row is filled, so go to the next one if there is a row left
				if (j == iN - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

// Return determinant with an algorithm
float mat4::determinant(int iN) const
{
	float fDeterminant = 0.f;

	// 1x1 matrix
	if (iN == 1) return m[0];

	int iSign = 1; // + - + - + - + - .......
	mat4 m4Temp; // Temporary mat4

	// Iterate through the first row
	for (int j = 0; j < iN; j++) {
		getCofactor(m4Temp, 0, j, iN);

		fDeterminant += iSign * m[j] * m4Temp.determinant(iN - 1);

		// This value goes from + to - and from - to +.
		iSign = -iSign;
	}

	return fDeterminant;
}

mat4 mat4::identity()
{
	// Set identity matrix
	mat4 m4;
	m4.m[0] = m4.m[5] = m4.m[10] = m4.m[15] = 1;

	return m4;
}

mat4 mat4::rotateX(float a_Radians)
{
	mat4 m4 = identity();

	float fCos = cos(a_Radians);
	float fSin = sin(a_Radians);

	m4.m[5] = fCos;
	m4.m[6] = -fSin;
	m4.m[9] = fSin;
	m4.m[10] = fCos;

	return m4;
}

mat4 mat4::rotateY(float a_Radians)
{
	mat4 m4 = identity();

	float fCos = cos(a_Radians);
	float fSin = sin(a_Radians);

	m4.m[0] = fCos;
	m4.m[2] = fSin;
	m4.m[8] = -fSin;
	m4.m[10] = fCos;

	return m4;
}

mat4 mat4::rotateZ(float a_Radians)
{
	mat4 m4 = identity();

	float fCos = cos(a_Radians);
	float fSin = sin(a_Radians);

	m4.m[0] = fCos;
	m4.m[1] = -fSin;
	m4.m[4] = fSin;
	m4.m[5] = fCos;

	return m4;
}

mat4 mat4::translate(const vec3 & a_Translation)
{
	mat4 m4 = identity();

	m4.m[3] = a_Translation.m_X;
	m4.m[7] = a_Translation.m_Y;
	m4.m[11] = a_Translation.m_Z;

	return m4;
}

mat4 mat4::lookat(const vec3 & a_Eye, const vec3 & a_Center, const vec3 & a_Up)
{
	// Z axis
	vec3 v3AxisZ = a_Center - a_Eye;
	v3AxisZ = v3AxisZ.normalize();
	// X axis
	vec3 v3AxisX = v3AxisZ;
	v3AxisX = v3AxisX.cross(a_Up);
	v3AxisX = v3AxisX.normalize();
	// Y axis
	vec3 v3AxisY = v3AxisX;
	v3AxisY = v3AxisY.cross(v3AxisZ);

	mat4 m4 = identity();
	m4.m[0] = v3AxisX.m_X;
	m4.m[1] = v3AxisX.m_Y;
	m4.m[2] = v3AxisX.m_Z;

	m4.m[4] = v3AxisY.m_X;
	m4.m[5] = v3AxisY.m_Y;
	m4.m[6] = v3AxisY.m_Z;

	m4.m[8] = -v3AxisZ.m_X;
	m4.m[9] = -v3AxisZ.m_Y;
	m4.m[10] = -v3AxisZ.m_Z;

	m4.m[3] = -v3AxisX.dot(a_Eye);
	m4.m[7] = -v3AxisY.dot(a_Eye);
	m4.m[11] = v3AxisZ.dot(a_Eye);


	return m4;
}

mat4 mat4::projection(float a_FovY, float a_AspectRatio, float a_Near, float a_Far)
{
	// Calculate the scale
	float fWidth = (1 / a_AspectRatio) / tanf(a_FovY / 2.0f);
	float fHeight = 1 / tanf(a_FovY / 2.0f);

	mat4 m4;

	m4.m[0] = fWidth;
	m4.m[5] = fHeight;
	m4.m[10] = -a_Far / (a_Far - a_Near);
	m4.m[14] = (-a_Far * a_Near / (a_Far - a_Near) * 2);
	m4.m[11] = -1;

	return m4;
}

mat4 operator+(const mat4 & a_Lhs, const mat4 & a_Rhs)
{
	// Row one
	return mat4(a_Lhs.m[0] + a_Rhs.m[0],
		a_Lhs.m[1] + a_Rhs.m[1],
		a_Lhs.m[2] + a_Rhs.m[2],
		a_Lhs.m[3] + a_Rhs.m[3],
		// Row two
		a_Lhs.m[4] + a_Rhs.m[4],
		a_Lhs.m[5] + a_Rhs.m[5],
		a_Lhs.m[6] + a_Rhs.m[6],
		a_Lhs.m[7] + a_Rhs.m[7],
		// Row three
		a_Lhs.m[8] + a_Rhs.m[8],
		a_Lhs.m[9] + a_Rhs.m[9],
		a_Lhs.m[10] + a_Rhs.m[10],
		a_Lhs.m[11] + a_Rhs.m[11],
		// Row four
		a_Lhs.m[12] + a_Rhs.m[12],
		a_Lhs.m[13] + a_Rhs.m[13],
		a_Lhs.m[14] + a_Rhs.m[14],
		a_Lhs.m[15] + a_Rhs.m[15]);
}

mat4 operator-(const mat4 & a_Lhs, const mat4 & a_Rhs)
{
	// Row one
	return mat4(a_Lhs.m[0] - a_Rhs.m[0],
		a_Lhs.m[1] - a_Rhs.m[1],
		a_Lhs.m[2] - a_Rhs.m[2],
		a_Lhs.m[3] - a_Rhs.m[3],
		// Row two
		a_Lhs.m[4] - a_Rhs.m[4],
		a_Lhs.m[5] - a_Rhs.m[5],
		a_Lhs.m[6] - a_Rhs.m[6],
		a_Lhs.m[7] - a_Rhs.m[7],
		// Row three
		a_Lhs.m[8] - a_Rhs.m[8],
		a_Lhs.m[9] - a_Rhs.m[9],
		a_Lhs.m[10] - a_Rhs.m[10],
		a_Lhs.m[11] - a_Rhs.m[11],
		// Row four
		a_Lhs.m[12] - a_Rhs.m[12],
		a_Lhs.m[13] - a_Rhs.m[13],
		a_Lhs.m[14] - a_Rhs.m[14],
		a_Lhs.m[15] - a_Rhs.m[15]);
}

mat4 operator*(const mat4 & a_Lhs, const mat4 & a_Rhs)
{
	// Row one
	return mat4(a_Lhs.m[0] * a_Rhs.m[0] + a_Lhs.m[1] * a_Rhs.m[4] + a_Lhs.m[2] * a_Rhs.m[8] + a_Lhs.m[3] * a_Rhs.m[12],
				a_Lhs.m[0] * a_Rhs.m[1] + a_Lhs.m[1] * a_Rhs.m[5] + a_Lhs.m[2] * a_Rhs.m[9] + a_Lhs.m[3] * a_Rhs.m[13],
				a_Lhs.m[0] * a_Rhs.m[2] + a_Lhs.m[1] * a_Rhs.m[6] + a_Lhs.m[2] * a_Rhs.m[10] + a_Lhs.m[3] * a_Rhs.m[14],
				a_Lhs.m[0] * a_Rhs.m[3] + a_Lhs.m[1] * a_Rhs.m[7] + a_Lhs.m[2] * a_Rhs.m[11] + a_Lhs.m[3] * a_Rhs.m[15],
				// Row two
				a_Lhs.m[4] * a_Rhs.m[0] + a_Lhs.m[5] * a_Rhs.m[4] + a_Lhs.m[6] * a_Rhs.m[8] + a_Lhs.m[7] * a_Rhs.m[12],
				a_Lhs.m[4] * a_Rhs.m[1] + a_Lhs.m[5] * a_Rhs.m[5] + a_Lhs.m[6] * a_Rhs.m[9] + a_Lhs.m[7] * a_Rhs.m[13],
				a_Lhs.m[4] * a_Rhs.m[2] + a_Lhs.m[5] * a_Rhs.m[6] + a_Lhs.m[6] * a_Rhs.m[10] + a_Lhs.m[7] * a_Rhs.m[14],
				a_Lhs.m[4] * a_Rhs.m[3] + a_Lhs.m[5] * a_Rhs.m[7] + a_Lhs.m[6] * a_Rhs.m[11] + a_Lhs.m[7] * a_Rhs.m[15],
				// Row three
				a_Lhs.m[8] * a_Rhs.m[0] + a_Lhs.m[9] * a_Rhs.m[4] + a_Lhs.m[10] * a_Rhs.m[8] + a_Lhs.m[11] * a_Rhs.m[12],
				a_Lhs.m[8] * a_Rhs.m[1] + a_Lhs.m[9] * a_Rhs.m[5] + a_Lhs.m[10] * a_Rhs.m[9] + a_Lhs.m[11] * a_Rhs.m[13],
				a_Lhs.m[8] * a_Rhs.m[2] + a_Lhs.m[9] * a_Rhs.m[6] + a_Lhs.m[10] * a_Rhs.m[10] + a_Lhs.m[11] * a_Rhs.m[14],
				a_Lhs.m[8] * a_Rhs.m[3] + a_Lhs.m[9] * a_Rhs.m[7] + a_Lhs.m[10] * a_Rhs.m[11] + a_Lhs.m[11] * a_Rhs.m[15],
				// Row four
				a_Lhs.m[12] * a_Rhs.m[0] + a_Lhs.m[13] * a_Rhs.m[4] + a_Lhs.m[14] * a_Rhs.m[8] + a_Lhs.m[15] * a_Rhs.m[12],
				a_Lhs.m[12] * a_Rhs.m[1] + a_Lhs.m[13] * a_Rhs.m[5] + a_Lhs.m[14] * a_Rhs.m[9] + a_Lhs.m[15] * a_Rhs.m[13],
				a_Lhs.m[12] * a_Rhs.m[2] + a_Lhs.m[13] * a_Rhs.m[6] + a_Lhs.m[14] * a_Rhs.m[10] + a_Lhs.m[15] * a_Rhs.m[14],
				a_Lhs.m[12] * a_Rhs.m[3] + a_Lhs.m[13] * a_Rhs.m[7] + a_Lhs.m[14] * a_Rhs.m[11] + a_Lhs.m[15] * a_Rhs.m[15]);
}

vec3 operator*(const mat4 & a_Lhs, const vec3 & a_Rhs)
{
	return vec3(a_Lhs.m_00 * a_Rhs.m_X + a_Lhs.m_01 * a_Rhs.m_Y + a_Lhs.m_02 * a_Rhs.m_Z + a_Lhs.m_03,
				a_Lhs.m_10 * a_Rhs.m_X + a_Lhs.m_11 * a_Rhs.m_Y + a_Lhs.m_12 * a_Rhs.m_Z + a_Lhs.m_13,
				a_Lhs.m_20 * a_Rhs.m_X + a_Lhs.m_21 * a_Rhs.m_Y + a_Lhs.m_22 * a_Rhs.m_Z + a_Lhs.m_23);
}

vec4 operator*(const mat4 & a_Lhs, const vec4 & a_Rhs)
{
	return vec4(a_Lhs.m_00 * a_Rhs.m_X + a_Lhs.m_01 * a_Rhs.m_Y + a_Lhs.m_02 * a_Rhs.m_Z + a_Lhs.m_03 * a_Rhs.m_W,
				a_Lhs.m_10 * a_Rhs.m_X + a_Lhs.m_11 * a_Rhs.m_Y + a_Lhs.m_12 * a_Rhs.m_Z + a_Lhs.m_13 * a_Rhs.m_W,
				a_Lhs.m_20 * a_Rhs.m_X + a_Lhs.m_21 * a_Rhs.m_Y + a_Lhs.m_22 * a_Rhs.m_Z + a_Lhs.m_23 * a_Rhs.m_W,
				a_Lhs.m_30 * a_Rhs.m_X + a_Lhs.m_31 * a_Rhs.m_Y + a_Lhs.m_32 * a_Rhs.m_Z + a_Lhs.m_33 * a_Rhs.m_W);
}

float mat4::operator()(int a_iRow, int a_iCell) const
{
	assert(a_iRow >= 0 && a_iRow <= 3);
	assert(a_iCell >= 0 && a_iCell <= 3);
	return m[(a_iRow * 4) + a_iCell];
}

float & mat4::operator()(int a_iRow, int a_iCell)
{
	assert(a_iRow >= 0 && a_iRow <= 3);
	assert(a_iCell >= 0 && a_iCell <= 3);
	return m[(a_iRow * 4) + a_iCell];
}

mat4::SquareBracketProxy::SquareBracketProxy(mat4& a_m4Owner, int a_iRow) : m_m4Owner(a_m4Owner), m_iRow(a_iRow)
{
}

float mat4::SquareBracketProxy::operator[](int a_iCell) const
{
	assert(a_iCell >= 0 && a_iCell <= 3);
	return m_m4Owner.m[(m_iRow * 4) + a_iCell];
}

float & mat4::SquareBracketProxy::operator[](int a_iCell)
{
	assert(a_iCell >= 0 && a_iCell <= 3);
	return m_m4Owner.m[(m_iRow * 4) + a_iCell];
}

mat4::SquareBracketProxy mat4::operator[](int a_iRow)
{
	assert(a_iRow >= 0 && a_iRow <= 3);
	return SquareBracketProxy(*this, a_iRow);
}
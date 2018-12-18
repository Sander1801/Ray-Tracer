#include "Utilities/Color.h"

#include <iostream>
#include <assert.h>

Color::Color()
{
	R = 0.f;
	G = 0.f;
	B = 0.f;
}

Color::Color(float a_fR, float a_fG, float a_fB)
{
	R = a_fR;
	G = a_fG;
	B = a_fB;
}

Color::Color(vec3 a_v3Color)
{
	R = a_v3Color.m_X;
	G = a_v3Color.m_Y;
	B = a_v3Color.m_Z;
}

Color & Color::ConvertToRGB()
{
	R *= 255;
	G *= 255;
	B *= 255;
	return *this;
}

Color & Color::MaxToOne()
{
	float fMaxValue = std::fmax(R, std::fmax(G, B));

	if (fMaxValue > 1.f) {
		R /= fMaxValue;
		G /= fMaxValue;
		B /= fMaxValue;
	}

	return *this;
}

sf::Color Color::GetSFMLColor() const
{
	return sf::Color(
		static_cast<sf::Uint8>(R),
		static_cast<sf::Uint8>(G),
		static_cast<sf::Uint8>(B)
	);
}

Color & Color::operator-()
{
	R = -R;
	G = -G;
	B = -B;
	return *this;
}

Color & Color::operator+()
{
	R = std::fabs(R);
	G = std::fabs(G);
	B = std::fabs(B);
	return *this;
}

Color & Color::operator=(const Color & a_Rhs)
{
	R = a_Rhs.R;
	G = a_Rhs.G;
	B = a_Rhs.B;
	return *this;
}

Color & Color::operator+=(const Color & a_Rhs)
{
	R += a_Rhs.R;
	G += a_Rhs.G;
	B += a_Rhs.B;
	return *this;
}

Color & Color::operator-=(const Color & a_Rhs)
{
	R -= a_Rhs.R;
	G -= a_Rhs.G;
	B -= a_Rhs.B;
	return *this;
}

Color & Color::operator+=(const vec3 & a_Rhs)
{
	R += a_Rhs.m_X;
	G += a_Rhs.m_Y;
	B += a_Rhs.m_Z;
	return *this;
}

Color & Color::operator-=(const vec3 & a_Rhs)
{
	R -= a_Rhs.m_X;
	G -= a_Rhs.m_Y;
	B -= a_Rhs.m_Z;
	return *this;
}

Color & Color::operator*=(float a_Rhs)
{
	R *= a_Rhs;
	G *= a_Rhs;
	B *= a_Rhs;
	return *this;
}

Color & Color::operator*=(const Color & a_Rhs)
{
	R *= a_Rhs.R;
	G *= a_Rhs.G;
	B *= a_Rhs.B;
	return *this;
}

Color & Color::operator*=(const vec3 & a_Rhs)
{
	R *= a_Rhs.m_X;
	G *= a_Rhs.m_Y;
	B *= a_Rhs.m_Z;
	return *this;
}

Color & Color::operator/=(float a_Rhs)
{
	R /= a_Rhs;
	G /= a_Rhs;
	B /= a_Rhs;
	return *this;
}

Color & Color::operator/=(const Color & a_Rhs)
{
	R /= a_Rhs.R;
	G /= a_Rhs.G;
	B /= a_Rhs.B;
	return *this;
}

Color & Color::operator/=(const vec3 & a_Rhs)
{
	R /= a_Rhs.m_X;
	G /= a_Rhs.m_Y;
	B /= a_Rhs.m_Z;
	return *this;
}

Color operator*(const Color & a_Lhs, float a_Rhs)
{
	return Color(a_Lhs.R * a_Rhs, a_Lhs.G * a_Rhs, a_Lhs.B * a_Rhs);
}

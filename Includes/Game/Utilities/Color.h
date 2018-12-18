#ifndef __Color_H_
#define __Color_H_

#include "Engine/Math/Vector.h"

// SFML 
#include <SFML/Graphics.hpp>

class Color
{
public:
	// Variables
	float R;
	float G;
	float B;

	// Constructors
	Color();
	Color(float a_fR, float a_fG, float a_fB);
	Color(vec3 a_v3Color);

	/*
	 * Converts a number between 0 and 1 to a value between 0 and 255
	*/
	Color& ConvertToRGB();

	/*
	 * Color higher than one is outside the range, so this function changes it into one.
	*/
	Color& MaxToOne();

	/*
	 * Returns a SFML Color
	*/
	sf::Color GetSFMLColor() const;

	// Operators
	Color& operator-();
	Color& operator+();
	Color& operator=(const Color& a_Rhs);

	Color& operator+=(const Color &a_Rhs);
	Color& operator-=(const Color &a_Rhs);
	Color& operator+=(const vec3 &a_Rhs);
	Color& operator-=(const vec3 &a_Rhs);
	Color& operator*=(float a_Rhs);
	Color& operator*=(const Color &a_Rhs);
	Color& operator*=(const vec3 &a_Rhs);
	Color& operator/=(float a_Rhs);
	Color& operator/=(const Color &a_Rhs);
	Color& operator/=(const vec3 &a_Rhs);
};

Color operator*(const Color &a_Lhs, float a_Rhs);

#endif // __Color_H_
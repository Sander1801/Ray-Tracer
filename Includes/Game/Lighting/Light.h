#ifndef __Light_H_
#define __Light_H_

#include "Engine/Math/Vector.h"
#include "Utilities/Color.h"

class Light
{
public:
	Light(const float& a_fIntensity, const Color& a_Color);
	~Light();

	/*
	 * This function calculates the ambient light
	 *
	 * @params	a_v3LightColor: It returns the color, which we need to multiply with the material color.
	*/
	virtual void CalcAmbientLight(Color& a_lightColor) const = 0;

	/*
	 * This function calculates the diffuse light
	 *
	 * @params	a_v3Hitpoint: This is the point of intersection between the ray and the shape.
	 * @params	a_v3Normal: The normal is calculated on intersection.
	 * @params	a_v3Direction: Direction of the light. The direction has to be a zero vector. It will be returned to the caller and we need to use it to create shadow.
	 * @params	a_v3LightColor: It returns the color, which we need to multiply with the material color.
	*/
	virtual void CalcDiffuseLight(const vec3& a_v3Hitpoint, const vec3& a_v3Normal, const float& a_fKd,
									vec3& a_v3Direction, Color& a_lightColor) const = 0;

	/*
	 * This function calculates the specular light
	 *
	 * @params	a_v3Hitpoint: This is the point of intersection between the ray and the shape.
	 * @params	a_v3Normal: The normal is calculated on intersection.
	 * @params	a_v3Direction: Direction of the light. The direction has to be a zero vector. It will be returned to the caller and we need to use it to create shadow.
	 * @params	a_v3ViewDirection: View direction is the direction of the ray before the intersection.
	 * @params	a_v3LightColor: It returns the color, which we need to multiply with the material color.
	*/
	virtual void CalcSpecularLight(const vec3& a_v3Hitpoint, const vec3 & a_v3Normal, const vec3& a_v3ViewDirection, 
									const float& a_fKr, vec3& a_v3Direction, Color& a_lightColor) const = 0;

protected:
	// Get functions
	const float& GetIntensity() const;
	const Color& GetColor() const;

private:
	float m_fIntensity;
	Color m_Color;
};

#endif // __Light_H_
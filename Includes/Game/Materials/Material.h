#ifndef __Material_H_
#define __Material_H_

#include "Lighting/Light.h"
#include "RayTracer.h"
#include "Collision/Contact.h"
#include "Engine/Math/Vector.h"
// Standard C++ 
#include <vector>

class Shape;

class Material
{
public:
	~Material();

	/*
	 * This function creates shadow and calculates the result color for the material. 
	 *
	 * @params	a_v3Hitpoint: This is the point of intersection between the ray and the shape.
	 * @params	a_v3Normal: The normal is calculated on intersection.
	 * @params	a_Lights: All the lights in the scene.
	 * @params	a_ResultColor: It returns the result color of the material to the caller.
	*/
	virtual void Shade(const Ray& a_Ray, const RayTracer& a_RayTracer, const Contact& a_Contact, const std::vector<Light*>& a_Lights,
							const std::vector<Shape*>& a_Shapes, const float& a_fBias, Color& a_ResultColor) const = 0;

	/*
	 * Set the color of the material
	 *
	 * @params	a_Color: The color of the material.
	*/
	virtual void SetColor(const Color a_Color) = 0;

	/*
	 * Set an extra color for the material.
	 *
	 * @params	a_Color: The color of the material.
	*/
	virtual void SetSecondColor(const Color a_Color) = 0;

	/*
	 * Get the color of the material
	 *
	 * @return	Color
	*/
	virtual Color& GetColor(bool a_bGetFirstColor = true) = 0;
};

#endif // __Material_H_
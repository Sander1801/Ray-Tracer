#include "Materials/Matte.h"
#include "Lighting/Light.h"
#include "Collision/Ray.h"
#include "Utilities/Math.h"
#include <iostream>

Matte::Matte() 
{
}

Matte::~Matte()
{
}

void Matte::Shade(const Ray& a_Ray, const RayTracer& a_RayTracer, const Contact& a_Contact, const std::vector<Light*>& a_Lights,
						const std::vector<Shape*>& a_Shapes, const float& a_fBias, Color& a_ResultColor) const
{
	vec3 v3LightDirection(0.f, 0.f, 0.f);
	Color lightColor;

	for (const Light* light : a_Lights) {
		light->CalcDiffuseLight(a_Contact.m_v3Point, a_Contact.m_v3Normal, m_fKd, v3LightDirection, lightColor);
	
		a_Ray;
		//a_fBias;

		Ray lightRay(a_Contact.m_v3Point + a_Contact.m_v3Normal * a_fBias, v3LightDirection);
	
		bool test = !a_RayTracer.ShadowTrace(lightRay, a_Shapes);
	
		vec3 normTest = a_Contact.m_v3Normal;
		float test2 = normTest.dot(v3LightDirection);
		
		// No shadow
		if (test) {
			a_ResultColor += lightColor * test * test2;
		}
		else {
			a_ResultColor = Color(); // Test code - change color to black.
		}
	}
}

void Matte::SetColor(const Color a_Color)
{
	m_Color = a_Color;
}

void Matte::SetSecondColor(const Color a_Color)
{
	m_SecondColor = a_Color;
}

Color & Matte::GetColor(bool a_bGetFirstColor)
{
	if (!a_bGetFirstColor) return m_SecondColor;

	return m_Color;
}

void Matte::SetKd(const float a_fKd)
{
	m_fKd = a_fKd;
}

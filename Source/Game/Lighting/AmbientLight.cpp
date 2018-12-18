#include "Lighting/AmbientLight.h"

AmbientLight::AmbientLight(const float & a_fIntensity, const Color & a_Color) : 
	Light(a_fIntensity, a_Color)
{
}

AmbientLight::~AmbientLight()
{
}

void AmbientLight::CalcAmbientLight(Color & a_lightColor) const
{
	const float& fIntensity = GetIntensity();
	const Color& lightColor = GetColor();

	a_lightColor.R += lightColor.R * fIntensity;
	a_lightColor.G += lightColor.G * fIntensity;
	a_lightColor.B += lightColor.B * fIntensity;
}

void AmbientLight::CalcDiffuseLight(const vec3 &, const vec3 &, const float&, vec3 &, Color &) const
{
}

void AmbientLight::CalcSpecularLight(const vec3 &, const vec3 &, const vec3 &, const float&, vec3 &, Color &) const
{
}

#include "Lighting/PointLight.h"

#include <algorithm>
#include <iostream>

PointLight::PointLight(const float & a_fIntensity, const Color & a_Color, const vec3 & a_v3Position,
						const float& a_fConstant, const float& a_fLinear, const float& a_fQuadratic) :
	Light(a_fIntensity, a_Color),
	m_v3Position(a_v3Position)
{
	m_Attenuation.m_fConstant = a_fConstant;
	m_Attenuation.m_fLinear = a_fLinear;
	m_Attenuation.m_fQuadratic = a_fQuadratic;
}

PointLight::~PointLight()
{
}

void PointLight::CalcAmbientLight(Color &) const
{
}

void PointLight::CalcDiffuseLight(const vec3 & a_v3Hitpoint, const vec3 & a_v3Normal, const float& a_fKd,
									vec3 & a_v3Direction, Color & a_lightColor) const
{
	a_v3Direction = m_v3Position - a_v3Hitpoint;

	vec3 v3Direction = a_v3Direction;
	float fLightPower = std::max(v3Direction.dot(a_v3Normal), 0.f) * GetIntensity();
	const Color& lightColor = GetColor();
	
	a_lightColor = lightColor * fLightPower * a_fKd;

	// Reduce the intensity of light based on the distance.
	float fDistance = 1 / (m_v3Position - a_v3Hitpoint).length();
	float fAttenuation = 1.f / (m_Attenuation.m_fConstant + m_Attenuation.m_fLinear * fDistance +
											m_Attenuation.m_fQuadratic * (fDistance * fDistance));

	a_lightColor *= fAttenuation;
}

void PointLight::CalcSpecularLight(const vec3 &, const vec3 &, const vec3 &, const float&, vec3 &, Color &) const
{
}

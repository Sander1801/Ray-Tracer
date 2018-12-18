#include "Lighting/Light.h"

Light::Light(const float & a_fIntensity, const Color & a_Color) :
	m_fIntensity(a_fIntensity),
	m_Color(a_Color)
{
}

Light::~Light()
{
}

const float & Light::GetIntensity() const
{
	return m_fIntensity;
}

const Color & Light::GetColor() const
{
	return m_Color;
}

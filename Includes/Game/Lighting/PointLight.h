#ifndef __PointLight_H_
#define __PointLight_H_

#include "Light.h"

class PointLight : public Light
{
public:
	PointLight(const float& a_fIntensity, const Color& a_Color, const vec3& a_v3Position, 
				const float& a_fConstant, const float& a_fLinear, const float& a_fQuadratic);
	~PointLight();

	virtual void CalcAmbientLight(Color& a_lightColor) const;
	virtual void CalcDiffuseLight(const vec3& a_v3Hitpoint, const vec3 & a_v3Normal, const float& a_fKd,
									vec3& a_v3Direction, Color& a_lightColor) const;
	virtual void CalcSpecularLight(const vec3& a_v3Hitpoint, const vec3 & a_v3Normal, const vec3& a_v3ViewDirection,
									const float& a_fKr, vec3& a_v3Direction, Color& a_lightColor) const;

private:
	vec3 m_v3Position;

	// Make it global. Spot light needs these values too.
	struct
	{
		float m_fConstant;
		float m_fLinear;
		float m_fQuadratic;
	} m_Attenuation;
};

#endif // __PointLight_H_
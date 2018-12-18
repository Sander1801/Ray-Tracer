#ifndef __AmbientLight_H_
#define __AmbientLight_H_

#include "Light.h"

class AmbientLight : public Light
{
public:
	AmbientLight(const float& a_fIntensity, const Color& a_Color);
	~AmbientLight();

	virtual void CalcAmbientLight(Color& a_lightColor) const;
	virtual void CalcDiffuseLight(const vec3& a_v3Hitpoint, const vec3 & a_v3Normal, const float& a_fKd,
									vec3& a_v3Direction, Color& a_lightColor) const;
	virtual void CalcSpecularLight(const vec3& a_v3Hitpoint, const vec3 & a_v3Normal, const vec3& a_v3ViewDirection, 
									const float& a_fKr, vec3& a_v3Direction, Color& a_lightColor) const;
};

#endif // __AmbientLight_H_
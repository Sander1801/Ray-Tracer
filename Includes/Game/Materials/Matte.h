#ifndef __Matte_H_
#define __Matte_H_

#include "Material.h"

class Matte : public Material
{
public:
	Matte();
	~Matte();

	virtual void Shade(const Ray& a_Ray, const RayTracer& a_RayTracer, const Contact& a_Contact, const std::vector<Light*>& a_Lights,
							const std::vector<Shape*>& a_Shapes, const float& a_fBias, Color& a_ResultColor) const;

	virtual void SetColor(const Color a_Color);
	virtual void SetSecondColor(const Color a_Color);

	virtual Color& GetColor(bool a_bGetFirstColor = true);

	/*
	 * Set the diffuse value
	 *
	 * @params	a_fKd: Diffuse value between zero and one.
	*/
	void SetKd(const float a_fKd);

private:
	float m_fKd;
	Color m_Color;
	Color m_SecondColor;
};

#endif // __Matte_H_
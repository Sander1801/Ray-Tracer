#ifndef __Sphere_H_
#define __Sphere_H_

#include "Collision/Shape.h"

class Sphere : public Shape
{
public:
	Sphere(bool a_bIsCheckerboard = false);
	~Sphere();

	/*
	 * This intersection test is an analytic solution. It checks for intersection between a ray and sphere.
	*/
	virtual bool Collides(Ray const& a_Ray, Contact& a_Contact) const;

	void SetMaterial(Material* a_Material);
	virtual Material* GetMaterial() const;

	void SetRadius(const float a_fRadius);
	void SetCenter(const vec3 &a_v3Center);

private:
	float m_fRadius;
	vec3 m_v3Center;

	Material* m_Material;
};

#endif // __Sphere_H_
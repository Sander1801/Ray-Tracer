#ifndef __Plane_H_
#define __Plane_H_

#include "Collision/Shape.h"

class Plane : public Shape
{
public:
	Plane(bool a_bIsCheckerboard = false);
	~Plane();

	virtual bool Collides(Ray const& a_Ray, Contact& a_Contact) const;

	void SetMaterial(Material* a_Material);
	virtual Material* GetMaterial() const;

	void SetPoint(const vec3 &a_v3Point);
	void SetNormal(const vec3 &a_v3Normal);

private:
	vec3 m_v3Point;
	vec3 m_v3Normal;

	Material* m_Material;
};

#endif // __Plane_H_
#include "Collision/Geometric Objects/Plane.h"

Plane::Plane(bool a_bIsCheckerboard) : Shape(a_bIsCheckerboard)
{
}

Plane::~Plane()
{
}

bool Plane::Collides(Ray const & a_Ray, Contact & a_Contact) const
{
	float denom = m_v3Normal.dot(a_Ray.GetDirection());

	if (denom > 1e-6) {
		vec3 p0l0 = m_v3Point - a_Ray.GetOrigin();
		float t = p0l0.dot(m_v3Normal) / denom;
		
		if (t >= 0.f) {
			a_Contact.m_fCollisionTime = t;
			a_Contact.m_v3Point = a_Ray.GetOrigin() + a_Ray.GetDirection() * t;
			a_Contact.m_v3Normal = m_v3Normal;

			return true;
		}
	} 

	return false;
}

void Plane::SetMaterial(Material * a_Material)
{
	m_Material = a_Material;
}

Material * Plane::GetMaterial() const
{
	return m_Material;
}

void Plane::SetPoint(const vec3 & a_v3Point)
{
	m_v3Point = a_v3Point;
}

void Plane::SetNormal(const vec3 & a_v3Normal)
{
	m_v3Normal = a_v3Normal;
}

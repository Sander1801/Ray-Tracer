#include "Collision/Geometric Objects/Sphere.h"

#include <iostream>

Sphere::Sphere(bool a_bIsCheckerboard) : Shape(a_bIsCheckerboard)
{
}

Sphere::~Sphere()
{
}

bool Sphere::Collides(Ray const & a_Ray, Contact & a_Contact) const
{
	// Maximum of two intersection points
	float t1; float t2;

	vec3 v3Temp = a_Ray.GetOrigin() - m_v3Center;

	// Set the a, b and c value for the quadratic equation
	float a = a_Ray.GetDirection().dot(a_Ray.GetDirection());
	float b = a_Ray.GetDirection().dot(v3Temp) * 2.f;
	float c = v3Temp.dot(v3Temp) - m_fRadius * m_fRadius;

	// The discriminant is an important value. It tells us if there is intersection with zero, one or two points.
	// Lower than zero means no intersection, zero means one intersection point and higher than zero means two intersection points.
	float fDiscriminant = b * b - 4.f * a * c;

	// No intersection.
	if (fDiscriminant < 0.f) return false;

	// One intersection point is found
	if (fDiscriminant == 0) {
		a_Contact.m_fCollisionTime = -0.5f * b / a;
	}
	// There are two intersection points.
	else {
		// Get the first and second intersection point
		float q = (b > 0.f) ?
			-0.5f * (b + sqrtf(fDiscriminant)) :
			-0.5f * (b - sqrtf(fDiscriminant));
		t1 = q / a;
		t2 = c / q;

		// Point one is higher and that means it is further away, so we need to use the second point.
		if (t1 > t2) {
			a_Contact.m_fCollisionTime = t2;
		}
	}

	// Set the intersection point and normal.
	a_Contact.m_v3Point = a_Ray.GetOrigin() + a_Ray.GetDirection() * a_Contact.m_fCollisionTime;
	a_Contact.m_v3Normal = (a_Contact.m_v3Point - m_v3Center).normalize();

	return true;
}

void Sphere::SetMaterial(Material * a_Material)
{
	m_Material = a_Material;
}

Material * Sphere::GetMaterial() const
{
	return m_Material;
}

void Sphere::SetRadius(const float a_fRadius)
{
	m_fRadius = a_fRadius;
}

void Sphere::SetCenter(const vec3 & a_v3Center)
{
	m_v3Center = a_v3Center;
}
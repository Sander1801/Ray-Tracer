#include "Collision/Ray.h"

Ray::Ray(vec3 a_v3Origin, vec3 a_v3Direction) :
	m_v3Origin(a_v3Origin),
	m_v3Direction(a_v3Direction)
{
}

Ray::~Ray()
{
}

void Ray::SetOrigin(const vec3 & a_v3Origin)
{
	m_v3Origin = a_v3Origin;
}

void Ray::SetDirection(const vec3 & a_v3Direction)
{
	m_v3Direction = a_v3Direction;
}

const vec3 & Ray::GetOrigin() const
{
	return m_v3Origin;
}

const vec3 & Ray::GetDirection() const
{
	return m_v3Direction;
}

#include "Collision/Geometric Objects/Box.h"
#include "Utilities/Math.h"

Box::Box(bool a_bIsCheckerboard) : Shape(a_bIsCheckerboard)
{

	// Set the rotate and translate matrices to an identity matrix
	m_m4Rotate = m_m4Rotate.identity();
	m_m4Translate = m_m4Translate.identity();
}

Box::~Box()
{
}

bool Box::Collides(Ray const & a_Ray, Contact & a_Contact) const
{
	// Convert the ray to box space
	vec4 v4RD = m_m4Transform * vec4(a_Ray.GetDirection(), 0.f);
	vec4 v4RO = m_m4Transform * vec4(a_Ray.GetOrigin(), 1.f);

	// Convert vec4 to vec3
	vec3 v3RayDirection = vec3(v4RD.m_X, v4RD.m_Y, v4RD.m_Z);
	vec3 v3RayOrigin = vec3(v4RO.m_X, v4RO.m_Y, v4RO.m_Z).normalize();

	// Calculate how many steps it takes to get from the ray origin to the box origin.
	vec3 m = 1.f / v3RayDirection;
	vec3 n = m * v3RayOrigin; 
	// Calculate how many steps from the box center to the box edge.
	vec3 k = MathLib::ConvertToPositive(m) * (m_v3Scale / 2);

	n = -n;
	// Total steps to the negative and positive part of the surface.
	vec3 t1 = n - k;
	vec3 t2 = n + k;

	float tNear = std::fmax(std::fmax(t1.m_X, t1.m_Y), t1.m_Z);
	float tFar = std::fmin(std::fmin(t2.m_X, t2.m_Y), t2.m_Z);
	
	// No intersection.
	if (tNear > tFar || tFar < 0.f) return false;

	if (tNear < 0.f) tNear = tFar;

	// Set collision time and hit point.
	a_Contact.m_fCollisionTime = tNear;
	a_Contact.m_v3Point = v3RayOrigin + v3RayDirection * tNear;

	// Calculate the normal.
	vec3 v3Sign = -MathLib::Sign(v3RayDirection);
	vec3 v3Normal = v3Sign * MathLib::Step(vec3(t1.m_Y, t1.m_Z, t1.m_X), t1) *
							 MathLib::Step(vec3(t1.m_Z, t1.m_X, t1.m_Y), t1);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
	// Convert the normal to ray space.
	vec4 v4Normal = (m_m4InverseTransform * vec4(v3Normal, 0.0));
	// Set the normal.
	a_Contact.m_v3Normal = vec3(v4Normal.m_X, v4Normal.m_Y, v4Normal.m_Z);

	if (IsCheckerboard()) {
		// Set UV for checkerboard
		vec3 v3AbsPoint = MathLib::ConvertToPositive(a_Contact.m_v3Point) / (m_v3Scale / 2);

		SetUV(v3AbsPoint, a_Contact.m_v3Point, a_Contact.m_v2UV);
	}

	return true;
}

void Box::SetUV(const vec3 & a_v3AbsHitpoint, const vec3& a_v3Hitpoint, vec2 & a_UV) const
{
	vec3 v3U; vec3 v3V;

	// X is the highest value
	if (a_v3AbsHitpoint.m_X >= a_v3AbsHitpoint.m_Y && a_v3AbsHitpoint.m_X >= a_v3AbsHitpoint.m_Z) {
		v3U = vec3(0.f, 1.f, 0.f);
	}
	else {
		v3U = vec3(1.f, 0.f, 0.f);
	}

	// X or Y is the highest value
	if ((a_v3AbsHitpoint.m_X >= a_v3AbsHitpoint.m_Y && a_v3AbsHitpoint.m_X >= a_v3AbsHitpoint.m_Z) ||
		(a_v3AbsHitpoint.m_X < a_v3AbsHitpoint.m_Y && a_v3AbsHitpoint.m_Y >= a_v3AbsHitpoint.m_Z)) {
		v3V = vec3(0.f, 0.f, 1.f);
	}
	else {
		v3V = vec3(0.f, 1.f, 0.f);
	}

	// Calculate the dot product
	float dotX = v3U.dot(a_v3Hitpoint);
	float dotY = v3V.dot(a_v3Hitpoint);

	a_UV.m_X = dotX;
	a_UV.m_Y = dotY;
}

void Box::SetMaterial(Material * a_Material)
{
	m_Material = a_Material;
}

Material * Box::GetMaterial() const
{
	return m_Material;
}

void Box::Translate(const vec3 & a_v3Translation)
{
	m_m4Translate = m_m4Translate.translate(a_v3Translation);
}

void Box::Rotate(const vec3 & a_v3Rotation)
{
	m_m4Rotate += m_m4Rotate.rotateX(a_v3Rotation.m_X);
	m_m4Rotate += m_m4Rotate.rotateY(a_v3Rotation.m_Y);
	m_m4Rotate += m_m4Rotate.rotateZ(a_v3Rotation.m_Z);
}

void Box::SetScale(const vec3 & a_v3Scale)
{
	m_v3Scale = a_v3Scale;
}

void Box::UpdateTransform()
{
	m_m4Transform = m_m4Translate * m_m4Rotate;
	m_m4InverseTransform = m_m4Transform.inverse();
}

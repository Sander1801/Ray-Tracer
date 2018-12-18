#ifndef __Box_H_
#define __Box_H_

#include "Collision/Shape.h"

class Box : public Shape
{
public:
	Box(bool a_bIsCheckerboard = false);
	~Box();

	virtual bool Collides(Ray const& a_Ray, Contact& a_Contact) const;

	/*
	 * This function sets the UV vector for the checkerboard.
	 *
	 * @params	a_v3AbsHitpoint: The positive hitpoint.
	 * @params	a_v3Hitpoint: The hitpoint.
	 * @params	a_UV: This vector is for creating a checkerboard.
	*/
	void SetUV(const vec3& a_v3AbsHitpoint, const vec3& a_v3Hitpoint, vec2& a_UV) const;

	void SetMaterial(Material* a_Material);
	virtual Material* GetMaterial() const;

	// Change transformation
	void Translate(const vec3 &a_v3Translation);
	void Rotate(const vec3 &a_v3Rotation);
	void SetScale(const vec3 &a_v3Scale);

	void UpdateTransform();

private:
	vec3 m_v3Scale;
	mat4 m_m4Rotate;
	mat4 m_m4Translate;

	mat4 m_m4Transform;
	mat4 m_m4InverseTransform;

	Material* m_Material;
};

#endif // __Box_H_
#ifndef __Ray_H_
#define __Ray_H_

#include "Engine/Math/Vector.h"
#include "Engine/Math/Matrix.h"

class Ray
{
public:
	Ray(vec3 a_v3Origin, vec3 a_v3Direction);
	~Ray();

	// Set functions
	void SetOrigin(const vec3 &a_v3Origin);
	void SetDirection(const vec3 &a_v3Direction);

	// Get functions
	const vec3& GetOrigin() const;
	const vec3& GetDirection() const;

private:
	vec3 m_v3Origin;
	vec3 m_v3Direction;
};

#endif // __Ray_H_
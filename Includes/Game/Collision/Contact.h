#ifndef __Contact_H_
#define __Contact_H_

#include "Engine/Math/Vector.h"

struct Contact
{
	/**
	* Holds the time of when two objects intersect with each other. 
	*/
	float m_fCollisionTime;

	/**
	* Holds the direction of the contact.
	*/
	vec3 m_v3Normal;

	/**
	* Holds the position of the contact between two objects.
	*/
	vec3 m_v3Point;

	/**
	* Holds the UV for a checkerboard
	*/
	vec2 m_v2UV;
};

#endif // __Contact_H_
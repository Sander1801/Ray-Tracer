#ifndef __Shape_H_
#define __Shape_H_

#include "Contact.h"
#include "Ray.h"
#include "Materials/Material.h"
#include "Engine/Math/Vector.h"
#include "Engine/Math/Matrix.h"

// Standard C++
#include <math.h>

class Shape
{
public:
	Shape(bool a_bIsCheckerboard);
	~Shape();

	/*
	 * It is a pure virtual function that check whether two objects intersect with each other.
	 *	
	 * @params	Ray: to check if there is intersection between the ray and the shape.
	 * @params	Contact: this is also an output. It returns the point of intersection, the normal and 
	 * the time of collision.
	 * @return	The return value is a boolean. There is intersection if the return value is true.
	*/
	virtual bool Collides(Ray const& a_Ray, Contact& a_Contact) const = 0;

	/*
	 * Returns the material of the shape. Not every shape has a material.
	 */
	// Change into unique pointer, because the pointer can be a null pointer.
	virtual Material* GetMaterial() const = 0;

	/*
	 * Returns true when the material is a checkboard
	 */
	const bool& IsCheckerboard() const;

private:
	bool m_bIsCheckerboard;
};

#endif // __Shape_H_
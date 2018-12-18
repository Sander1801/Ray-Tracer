#include "Collision/Shape.h"
#include "Collision/Ray.h"
#include "Collision/Contact.h"

Shape::Shape(bool a_bIsCheckerboard) : m_bIsCheckerboard(a_bIsCheckerboard)
{
}

Shape::~Shape()
{
}

const bool & Shape::IsCheckerboard() const
{
	return m_bIsCheckerboard;
}

#include "World.h"
#include "Utilities/Dimension.h"
#include "Engine/Math/Matrix.h"
#include "Engine/Math/Vector.h"
// Standard C++
#include <iostream>

World::World(const Dimension& a_RWDimension, sf::RenderWindow & a_RenderWindow) :
	m_RenderWindow(a_RenderWindow),
	m_Scene(a_RWDimension) // Setup scene
{
	// Trace the screen
	m_RayTracer.Trace(m_Scene, a_RWDimension, m_RenderWindow);
}

World::~World()
{
}
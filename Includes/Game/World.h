#ifndef __World_H_
#define __World_H_

#include "Scenes/Scene.h"
#include "RayTracer.h"
// SFML 
#include <SFML/Graphics.hpp>

struct Dimension;

class World
{
public:
	World(const Dimension& a_RWDimension, sf::RenderWindow& a_RenderWindow);
	~World();

private:
	sf::RenderWindow& m_RenderWindow;
	Scene m_Scene;
	RayTracer m_RayTracer;
};

#endif // __World_H_
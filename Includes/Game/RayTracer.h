#ifndef __RayTracer_H_
#define __RayTracer_H_

// SFML 
#include <SFML/Graphics.hpp>

struct Dimension;
struct Contact;

class Scene;
class Ray;
class Shape;

class RayTracer
{
public:
	void Trace(const Scene& a_Scene, const Dimension& a_Dimension, sf::RenderWindow& a_RenderWindow);

	bool ShadowTrace(Ray const& a_Ray, const std::vector<Shape*>& a_Shapes) const;

private:
	// We use this to create an image on the screen
	sf::Texture m_sfTexture;
	sf::Image m_sfImage;
	sf::Sprite m_sfSprite;
};

#endif // __RayTracer_H_
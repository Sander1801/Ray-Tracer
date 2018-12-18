#include "RayTracer.h"
#include "Scenes/Scene.h"
#include "Utilities/Dimension.h"
#include "Lighting/AmbientLight.h"
#include "Lighting/PointLight.h"
#include "Collision/Contact.h"
#include "Collision/Ray.h"
#include "Collision/Geometric Objects/Sphere.h"

#include <iostream>

void RayTracer::Trace(const Scene& a_Scene, const Dimension& a_Dimension, sf::RenderWindow& a_RenderWindow)
{
	// Setup SFML image
	m_sfImage.create(a_Dimension.m_iWidth, a_Dimension.m_iHeight, sf::Color(60, 100, 200)); // Green background

	// Get all shapes and lightning
	const std::vector<Shape*>& shapes = a_Scene.GetShapes();
	const std::vector<Light*>& lights = a_Scene.GetLights();

	// Intersection information. The values are overwritten after every next pixel, if there is intersection.
	Contact contact;

	// Loop through every pixel 
	for (unsigned int r = 0; r < a_Dimension.m_iHeight; r++) {
		for (unsigned int c = 0; c < a_Dimension.m_iWidth; c++) {
			// Get the ray for this pixel
			const Ray ray = a_Scene.GetCamera().GetCameraRay(c - 0.5f * (a_Dimension.m_iWidth - 1.f), r - 0.5f * (a_Dimension.m_iHeight - 1.f));

			// Loop through the shapes
			for (const Shape* shape : shapes) {
				if (shape->Collides(ray, contact)) {
					// Get the material color
					Color materialColor = shape->GetMaterial()->GetColor();
					
					/*
					* Put this inside the material class or create a checkerboard material.
					*/
					if (shape->IsCheckerboard()) {
					//	std::cout << contact.m_fCollisionTime << " - " << contact.m_v3Point.m_X << " - " << contact.m_v3Point.m_Y << " - " << contact.m_v3Point.m_Z << std::endl;
						// More tiles vertical than horizontal.
						float a = std::floor(contact.m_v2UV.m_X * 6.f) + std::floor(contact.m_v2UV.m_Y * 12.f); 
						bool b = (std::fabs(std::fmod(a, 2.f))) < 1.f ? true : false;

						if (b) {
							materialColor = shape->GetMaterial()->GetColor(false);
						}
					}
			
					// Add ambient if there is an ambient light.
					const AmbientLight* ambientLight = a_Scene.GetAmbientLight();

					if (ambientLight != nullptr) {
						ambientLight->CalcAmbientLight(materialColor);
					}

					// Shade function adds the other lightning and shadow
					shape->GetMaterial()->Shade(ray, *this, contact, lights, shapes, a_Scene.GetBias(), materialColor);

					materialColor = materialColor.MaxToOne();

					// Convert the color to a SFML Color.
					sf::Color sfColor(materialColor.ConvertToRGB().GetSFMLColor());
					
					// Set image pixel
					m_sfImage.setPixel(c, r, sfColor);
				}
			}
		}
	}

	// Render the ray tracer image
	m_sfTexture.loadFromImage(m_sfImage);
	m_sfSprite.setTexture(m_sfTexture);
	a_RenderWindow.draw(m_sfSprite);
	a_RenderWindow.display();
}


/*
* Create one trace function....
*/
bool RayTracer::ShadowTrace(Ray const & a_Ray, const std::vector<Shape*>& a_Shapes) const
{
	Contact contact;
	bool bIntersection = false;
//	std::cout << a_Ray.GetOrigin().m_X << " - " << a_Ray.GetOrigin().m_Y << " - " << a_Ray.GetOrigin().m_Z << std::endl;
//	std::cout << "---- " << a_Ray.GetDirection().m_X << " - " << a_Ray.GetDirection().m_Y << " - " << a_Ray.GetDirection().m_Z << std::endl;
	
	for (const Shape* shape : a_Shapes) {
		if (shape->Collides(a_Ray, contact)) {
			bIntersection = true;
		}
	}
	
	if (bIntersection) return true;

	return false;
}

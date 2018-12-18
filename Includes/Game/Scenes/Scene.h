#ifndef __Scene_H_
#define __Scene_H_

#include "Lighting/AmbientLight.h"
#include "Cameras/Camera.h"
#include "Collision/Shape.h"
// Standard C++ 
#include <vector>

struct Dimension;

class Scene
{
public:
	Scene(const Dimension& a_Dimension);
	~Scene();

	void CreateShapes();
	void CreateLights();

	// Get functions
	const float& GetBias() const;
	const AmbientLight* GetAmbientLight() const;
	const Camera& GetCamera() const;
	const std::vector<Shape*> GetShapes() const;
	const std::vector<Light*> GetLights() const;

private:
	float m_fBias;
	AmbientLight* m_AmbientLight; // Ambient light can be a null pointer. 
	Camera m_Camera;
	std::vector<Shape*> m_Shapes;
	std::vector<Light*> m_Lights;
};

#endif // __Scene_H_
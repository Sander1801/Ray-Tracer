#include "Scene.h"
#include "Utilities/Dimension.h"
#include "Collision/Shape.h"
#include "Collision/Geometric Objects/Sphere.h"
#include "Collision/Geometric Objects/Plane.h"
#include "Collision/Geometric Objects/Box.h"
#include "Lighting/PointLight.h"
#include "Materials/Matte.h"

Scene::Scene(const Dimension& a_Dimension) :
	m_Camera(1.22173f, a_Dimension, vec3(0.f, -10.f, -500.f), vec3(0.f, 0.f, 0.f), vec3(0.f, 1.f, 0.f))
{
	// Setup sky light
	Color ambientLightColor(0.2f, 0.1f, 0.1f);
	m_AmbientLight = new AmbientLight(0.1f, ambientLightColor);

	// Setup shapes
	CreateShapes();

	// Setup lights
	CreateLights();

	// Setup bias
	m_fBias = 1.f;
}

Scene::~Scene()
{
}

void Scene::CreateShapes()
{
	Color color1(0.3f, 0.6f, 0.1f); 
	Color color2(0.8f, 0.8f, 0.f);
	Color color3(0.8f, 0.f, 0.f);
	Color color4(0.1f, 0.5f, 0.4f);

	Matte* matte1 = new Matte();
	matte1->SetColor(color1);
	matte1->SetSecondColor(color2);
	matte1->SetKd(1.f);

	Matte* matte2 = new Matte();
	matte2->SetColor(color2);
	matte2->SetSecondColor(color3);
	matte2->SetKd(0.1f);

	Matte* matte3 = new Matte();
	matte3->SetColor(color4);
	matte3->SetKd(1.f);

	/*Sphere* sphere1 = new Sphere();
	sphere1->SetRadius(100.f);
	sphere1->SetCenter(vec3(-180.f, 0.f, -100.f));
	sphere1->SetMaterial(matte1); */


	/*	Box* box1 = new Box(true);
		box1->SetScale(vec3(2.f, 0.1f, 2.f));
		box1->Translate(vec3(0.f, 30.f, 0.f));
		box1->UpdateTransform();
		box1->SetMaterial(matte2);  */

	Sphere* sphere2 = new Sphere();
	sphere2->SetRadius(40.f);
	sphere2->SetCenter(vec3(0.f, 0.f, 0.f));
	sphere2->SetMaterial(matte3);

	Plane* plane = new Plane(true);
	plane->SetNormal(vec3(0.f, 1.f, 0.f));
	plane->SetPoint(vec3(0.f, 0.f, 0.f));
	plane->SetMaterial(matte1);
	 
	m_Shapes.push_back(plane);
	//m_Shapes.push_back(box1);
	m_Shapes.push_back(sphere2);
}

void Scene::CreateLights()
{
	PointLight* pointLight1 = new PointLight(1.f, Color(0.1f, 0.5f, 0.7f), vec3(0.f, -200.f, 0.f), 1.f, 0.09f, 0.032f);
	//PointLight* pointLight2 = new PointLight(1.f, Color(0.1f, 0.5f, 0.7f), vec3(-500.f, 0.f, -200.f), 1.f, 0.09f, 0.032f);
	
	m_Lights.push_back(pointLight1);
	//m_Lights.push_back(pointLight2);
}

const float & Scene::GetBias() const
{
	return m_fBias;
}

const AmbientLight * Scene::GetAmbientLight() const
{
	return m_AmbientLight;
}

const Camera & Scene::GetCamera() const
{
	return m_Camera;
}

const std::vector<Shape*> Scene::GetShapes() const
{
	return m_Shapes;
}

const std::vector<Light*> Scene::GetLights() const
{
	return m_Lights;
}

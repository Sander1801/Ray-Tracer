#ifndef __Camera_H_
#define __Camera_H_

#include "Engine/Math/Vector.h"
#include "Engine/Math/Matrix.h"

struct Dimension;

class Ray;
class World;

class Camera
{
public:
	Camera(float a_fFov, const Dimension& a_viewDimension, vec3 a_v3Eye, vec3 a_v3Center, vec3 a_v3Up);
	~Camera();

	/**
	 * It returns a ray based on the camera and screen. The origin of the ray is the eye position. The direction
	 * is towards the pixel on the screen.
	 *
	 * @params	iPixelX: The horizontal pixel on the screen. 
	 * @params	iPixelY: The vertical pixel on the screen. 
	 * These parameters are used to determine the direction of the ray.
	 * @return	The return value is a boolean. There is intersection if the return value is true.
	*/
	const Ray GetCameraRay(float iPixelX, float iPixelY) const;

private:
	// Camera size
	const Dimension& m_viewDimension;

	// Field of view, position of the camera, position the camera has to look at and the up value.
	float m_fFov;
	vec3 m_v3Eye;
	vec3 m_v3Center;
	vec3 m_v3Up;

	// Bottom left of the plane and the amount we need to increment to determine the direction in screen space.
	vec3 m_v3ViewPlaneBottomLeft;
	vec3 m_v3IncrementX;
	vec3 m_v3IncrementY;
};

#endif // __Camera_H_
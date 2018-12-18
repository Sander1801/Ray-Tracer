#include "Cameras/Camera.h"
#include "Collision/Ray.h"
#include "Utilities/Dimension.h"

Camera::Camera(float a_fFov, const Dimension& a_viewDimension, vec3 a_v3Eye, vec3 a_v3Center, vec3 a_v3Up) :
	m_fFov(a_fFov),
	m_viewDimension(a_viewDimension),
	m_v3Eye(a_v3Eye),
	m_v3Center(a_v3Center),
	m_v3Up(a_v3Up)
{
	// Calculate the x, y and z axis
	vec3 v3ViewDirection = (m_v3Eye - m_v3Center).normalize();
	vec3 v3U = m_v3Up.cross(v3ViewDirection).normalize();
	vec3 v3V = v3ViewDirection.cross(v3U);

	// Calculate the aspect ratio of the screen
	float fAspectRatio = static_cast<float>(m_viewDimension.m_iHeight) / static_cast<float>(m_viewDimension.m_iWidth);
	float fViewPlaneHalfWidth = tanf(m_fFov / 2.f);
	float fViewPlaneHalfHeight = fAspectRatio * fViewPlaneHalfWidth;
	
	// The bottom left of the plane
	m_v3ViewPlaneBottomLeft = m_v3Center - v3V * fViewPlaneHalfHeight - v3U * fViewPlaneHalfWidth;
	
	// The amount we need to increment to get the direction. The width and height are based on the field of view.
	m_v3IncrementX = (v3U * 2.f * fViewPlaneHalfWidth);
	m_v3IncrementY = (v3V * 2.f * fViewPlaneHalfHeight);
}

Camera::~Camera()
{
}

const Ray Camera::GetCameraRay(float iPixelX, float iPixelY) const
{
	vec3 v3Target = m_v3ViewPlaneBottomLeft + m_v3IncrementX * iPixelX + m_v3IncrementY * iPixelY;
	vec3 v3Direction = (v3Target - m_v3Eye).normalize();

	return Ray(m_v3Eye, v3Direction);
}

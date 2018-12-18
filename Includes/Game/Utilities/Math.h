#include "Engine/Math/Vector.h"

namespace MathLib
{
	inline vec3 Sign(vec3 const& a_v3)  
	{ 
		vec3 v3Result;

		// X 
		if (a_v3.m_X < 0.f) v3Result.m_X = -1.f;
		else if (a_v3.m_X > 0.f) v3Result.m_X = 1.f;
		// Y 
		if (a_v3.m_Y < 0.f) v3Result.m_Y = -1.f;
		else if (a_v3.m_Y > 0.f) v3Result.m_Y = 1.f;
		// Z
		if (a_v3.m_Z < 0.f) v3Result.m_Z = -1.f;
		else if (a_v3.m_Z > 0.f) v3Result.m_Z = 1.f;

		return v3Result;
	};

	inline vec3 Step(vec3 const& a_Lhs, vec3 const& a_Rhs)
	{
		vec3 v3Result;

		// X 
		if (a_Lhs.m_X < a_Rhs.m_X) v3Result.m_X = 1.f;
		// Y
		if (a_Lhs.m_Y < a_Rhs.m_Y) v3Result.m_Y = 1.f;
		// Z
		if (a_Lhs.m_Z < a_Rhs.m_Z) v3Result.m_Z = 1.f;

		return v3Result;
	};

	inline vec3 ConvertToPositive(vec3 const& a_v3)
	{
		return vec3(
			std::fabs(a_v3.m_X),
			std::fabs(a_v3.m_Y),
			std::fabs(a_v3.m_Z)
		);
	}
}
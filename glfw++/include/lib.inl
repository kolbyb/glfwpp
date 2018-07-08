#pragma once

namespace glfw
{
	//========================================
	//	...
	//========================================
	template<class HintType>
	void InitHint( InitializationHint hint, const HintType& value )
	{
		::glfwInitHint( static_cast<std::underlying_type<InitializationHint>::type>( hint ), static_cast<int>( value ) );
	}
}
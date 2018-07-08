#pragma once

namespace glfw
{
	inline Window::native_type Window::native( void ) const
	{
		return ::glfwGetCocoaWindow( *this );
	}
}
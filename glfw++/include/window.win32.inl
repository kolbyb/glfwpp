#pragma once

namespace glfw
{
	inline Window::native_type Window::native( void ) const
	{
		return ::glfwGetWin32Window( *this );
	}
}
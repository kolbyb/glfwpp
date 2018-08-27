#pragma once

namespace glfw
{
	inline VideoMode::operator Point2i( void ) noexcept
	{
		return Point2i( width, height );
	}

	template<class UserPointerType>
	void Monitor::userPointer( UserPointerType* pointer )
	{
		::glfwSetMonitorUserPointer( *this, static_cast<void*>( pointer ) );
	}

	template<class UserPointerType>
	UserPointerType* Monitor::userPointer( void ) const
	{
		return static_cast<UserPointerType*>( ::glfwGetMonitorUserPointer( *this ) );
	}
}
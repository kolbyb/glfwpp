#pragma once

namespace glfw
{
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
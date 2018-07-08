#pragma once

namespace glfw
{
	template<class ...Args>
	void Event<Args...>::operator()( const Args&... args )
	{
		for ( auto& callback : callbacks_ )
		{
			callback( args... );
		}
	}

	template<class ...Args>
	Event<Args...>& Event<Args...>::operator+=( const callback_type& callback )
	{
		callbacks_.push_back( callback );
		return *this;
	}
}
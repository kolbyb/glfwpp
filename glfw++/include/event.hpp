#pragma once
#include <functional>

namespace glfw
{
	template<class ...Args>
	class Event
	{
	public:

		using callback_type = std::function<void( const Args&... )>;
		using callback_list = std::vector<callback_type>;

		Event( void ) = default;

		void operator()( const Args&... args );
		Event<Args...>& operator+=( const callback_type& callback );

	protected:

		callback_list		callbacks_ = callback_list();
	};
}
#include "event.inl"
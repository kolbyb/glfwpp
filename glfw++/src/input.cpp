#include "pch.hpp"
#include "input.hpp"

#include "event.hpp"

namespace glfw::input
{
	//========================================
	//	GamepadState
	//========================================
	GamepadState::GamepadState( void ) :
		GLFWgamepadstate( GamepadState::Invalid )
	{
	}
	GamepadState::GamepadState( const GLFWgamepadstate& rhs ) :
		GLFWgamepadstate( rhs )
	{
	}


	//========================================
	//	JoystickHolder
	//========================================
	struct JoystickHolder
	{
		static JoystickHolder& instance( void ) noexcept
		{
			static JoystickHolder holder_ = JoystickHolder();
			return holder_;
		}

		Joystick::ConnectionEvent	connectionEvent_ = Joystick::ConnectionEvent();

	protected:

		JoystickHolder( void )
		{
			::glfwSetJoystickCallback( JoystickCallback_ );
		}

		//========================================
		//	Events
		//========================================
		static void JoystickCallback_( int jid, int event )		{ instance().connectionEvent_( static_cast<JoystickId>( jid ), static_cast<ConnectionStatus>( event ) ); }
	};
	static JoystickHolder s_joystickHolder = JoystickHolder::instance();


	//========================================
	//	Joystick
	//========================================
	Joystick::Joystick( const JoystickId& id ) :
		id_( id )
	{
	}

	bool Joystick::GamepadMappings( std::string_view mappings )
	{
		return ::glfwUpdateGamepadMappings( mappings.data() ) == GLFW_TRUE;
	}

	Joystick::ConnectionEvent& Joystick::ConnectedEvent( void )
	{
		return JoystickHolder::instance().connectionEvent_;
	}

	bool Joystick::present( void ) const
	{
		return ::glfwJoystickPresent( static_cast<std::underlying_type_t<JoystickId>>( id_ ) ) == GLFW_TRUE;
	}

	std::vector<float> Joystick::axes( void ) const
	{
		int		count = 0;
		auto*	axes = ::glfwGetJoystickAxes( static_cast<std::underlying_type_t<JoystickId>>( id_ ), &count );

		return axes == nullptr ? std::vector<float>() : std::vector<float>( axes, axes + count );
	}

	ActionList Joystick::buttons( void ) const
	{
		int		count = 0;
		auto*	buttons = ::glfwGetJoystickButtons( static_cast<std::underlying_type_t<JoystickId>>( id_ ), &count );
		auto	actionList = ActionList();

		if ( buttons != nullptr )
		{
			std::transform( buttons, buttons + count, std::back_inserter( actionList ), []( auto& action ) -> Action { return static_cast<Action>( action ); } );
		}
		return actionList;
	}

	HatStateList Joystick::hats( void ) const
	{
		int		count = 0;
		auto*	hats = ::glfwGetJoystickHats( static_cast<std::underlying_type_t<JoystickId>>( id_ ), &count );
		auto	hatList = HatStateList();

		if ( hats != nullptr )
		{
			std::transform( hats, hats + count, std::back_inserter( hatList ), []( auto& hat ) -> HatState { return static_cast<HatState>( hat ); } );
		}
		return hatList;
	}

	std::string_view Joystick::name( void ) const
	{
		return ::glfwGetJoystickName( static_cast<std::underlying_type_t<JoystickId>>( id_ ) );
	}

	std::string_view Joystick::guid( void ) const
	{
		return ::glfwGetJoystickGUID( static_cast<std::underlying_type_t<JoystickId>>( id_ ) );
	}

	bool Joystick::gamepad( void ) const
	{
		return ::glfwJoystickIsGamepad( static_cast<std::underlying_type_t<JoystickId>>( id_ ) );
	}

	GamepadState Joystick::gamepadState( void ) const
	{
		GamepadState	state = GamepadState::Invalid;

		return ::glfwGetGamepadState( static_cast<std::underlying_type_t<JoystickId>>( id_ ), &state ) == GLFW_TRUE ? state : GamepadState::Invalid;
	}

	std::string_view Joystick::gamepadName( void ) const
	{
		return ::glfwGetGamepadName( static_cast<std::underlying_type_t<JoystickId>>( id_ ) );
	}
}
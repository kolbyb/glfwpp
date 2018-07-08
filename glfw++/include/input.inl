#pragma once

namespace glfw
{
	namespace input
	{
		//========================================
		//	Modifiers
		//========================================
		constexpr Modifiers operator~( const Modifiers& lhs )
		{
			return static_cast<Modifiers>( ~static_cast<std::underlying_type_t<Modifiers>>( lhs ) );
		}

		constexpr Modifiers operator|( const Modifiers& lhs, const Modifiers& rhs )
		{
			return static_cast<Modifiers>( static_cast<std::underlying_type_t<Modifiers>>( lhs ) | static_cast<std::underlying_type_t<Modifiers>>( rhs ) );
		}

		constexpr Modifiers operator^( const Modifiers& lhs, const Modifiers& rhs )
		{
			return static_cast<Modifiers>( static_cast<std::underlying_type_t<Modifiers>>( lhs ) ^ static_cast<std::underlying_type_t<Modifiers>>( rhs ) );
		}

		constexpr Modifiers operator&( const Modifiers& lhs, const Modifiers& rhs )
		{
			return static_cast<Modifiers>( static_cast<std::underlying_type_t<Modifiers>>( lhs ) & static_cast<std::underlying_type_t<Modifiers>>( rhs ) );
		}


		//========================================
		//	GamepadState
		//========================================
		constexpr GamepadAxesList GamepadState::axesStates( void ) const
		{
			auto	axesList = GamepadAxesList();
			auto	begin = axesList.begin();

			for ( auto& value : axes )
			{
				*begin++ = value;
			}
			return axesList;
		}

		constexpr GamepadActionList GamepadState::buttonStates( void ) const
		{
			auto	actionList = GamepadActionList();
			auto	begin = actionList.begin();

			for ( auto& action : buttons )
			{
				*begin++ = static_cast<Action>( action );
			}
			return actionList;
		}


		//========================================
		//	Joystick
		//========================================
		template<class UserPointerType>
		void Joystick::userPointer( UserPointerType* pointer )
		{
			::glfwSetJoystickUserPointer( static_cast<std::underlying_type_t<JoystickId>>( id_ ), static_cast<void*>( pointer ) );
		}

		template<class UserPointerType>
		UserPointerType* Joystick::userPointer( void ) const
		{
			return static_cast<UserPointerType*>( ::glfwGetJoystickUserPointer( static_cast<std::underlying_type_t<JoystickId>>( id_ ) ) );
		}


		//========================================
		//	...
		//========================================
		inline std::string_view KeyName( const Key& key, int scanCode )
		{
			return ::glfwGetKeyName( static_cast<std::underlying_type_t<Key>>( key ), scanCode );
		}

		inline std::string_view KeyName( const Key& key )
		{
			return ::glfwGetKeyName( static_cast<std::underlying_type_t<Key>>( key ), KeyScanCode( key ) );
		}

		inline int KeyScanCode( const Key& key )
		{
			return ::glfwGetKeyScancode( static_cast<std::underlying_type_t<Key>>( key ) );
		}
	}
}
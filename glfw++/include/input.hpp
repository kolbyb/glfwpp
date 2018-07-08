#pragma once

namespace glfw
{
	namespace input
	{
		enum class Mode : int
		{
			// CursorMode
			Cursor = GLFW_CURSOR,
			// Must be either [true] to enable sticky keys, or [false] to disable it.
			// If sticky keys are enabled, a key press will ensure that glfwGetKey returns [Action::Press]
			// the next time it is called even if the key had been released before the call.
			// This is useful when you are only interested in whether keys have been pressed but not when or in which order.
			StickyKeys = GLFW_STICKY_KEYS,
			// Must be either [true] to enable sticky mouse buttons, or [false] to disable it.
			// If sticky mouse buttons are enabled, a mouse button press will ensure that "glfwGetMouseButton" returns
			// [Action::Press] the next time it is called even if the mouse button had been released before the call.
			// This is useful when you are only interested in whether mouse buttons have been pressed but not when or in which order.
			StickyMouseButtons = GLFW_STICKY_MOUSE_BUTTONS,
			// Must be either [true] to enable lock key modifier bits, or [false] to disable them.
			// If enabled, callbacks that receive modifier bits will also have the [Modifiers::CapsLock] bit set
			// when the event was generated with Caps Lock on, and the [Modifiers::NumLock] bit when Num Lock was on.
			LockKeyMods = GLFW_LOCK_KEY_MODS,
		};

		enum class CursorMode : int
		{
			// Makes the cursor visible and behaving normally.
			Normal = GLFW_CURSOR_NORMAL,
			// Makes the cursor invisible when it is over the client area of the window but does not restrict the cursor from leaving.
			Hidden = GLFW_CURSOR_HIDDEN,
			// Hides and grabs the cursor, providing virtual and unlimited cursor movement. This is useful for implementing for example 3D camera controls.
			Disabled = GLFW_CURSOR_DISABLED,
		};

		enum class Key : int
		{
			Unknown = GLFW_KEY_UNKNOWN,
			Space = GLFW_KEY_SPACE,
			Apostrophe = GLFW_KEY_APOSTROPHE,
			Comma = GLFW_KEY_COMMA,
			Minus = GLFW_KEY_MINUS,
			Period = GLFW_KEY_PERIOD,
			Slash = GLFW_KEY_SLASH,
			D0 = GLFW_KEY_0,
			D1 = GLFW_KEY_1,
			D2 = GLFW_KEY_2,
			D3 = GLFW_KEY_3,
			D4 = GLFW_KEY_4,
			D5 = GLFW_KEY_5,
			D6 = GLFW_KEY_6,
			D7 = GLFW_KEY_7,
			D8 = GLFW_KEY_8,
			D9 = GLFW_KEY_9,
			Semicolon = GLFW_KEY_SEMICOLON,
			Equal = GLFW_KEY_EQUAL,
			A = GLFW_KEY_A,
			B = GLFW_KEY_B,
			C = GLFW_KEY_C,
			D = GLFW_KEY_D,
			E = GLFW_KEY_E,
			F = GLFW_KEY_F,
			G = GLFW_KEY_G,
			H = GLFW_KEY_H,
			I = GLFW_KEY_I,
			J = GLFW_KEY_J,
			K = GLFW_KEY_K,
			L = GLFW_KEY_L,
			M = GLFW_KEY_M,
			N = GLFW_KEY_N,
			O = GLFW_KEY_O,
			P = GLFW_KEY_P,
			Q = GLFW_KEY_Q,
			R = GLFW_KEY_R,
			S = GLFW_KEY_S,
			T = GLFW_KEY_T,
			U = GLFW_KEY_U,
			V = GLFW_KEY_V,
			W = GLFW_KEY_W,
			X = GLFW_KEY_X,
			Y = GLFW_KEY_Y,
			Z = GLFW_KEY_Z,
			LeftBracket = GLFW_KEY_LEFT_BRACKET,
			Backslash = GLFW_KEY_BACKSLASH,
			RightBracket = GLFW_KEY_RIGHT_BRACKET,
			GraveAccent = GLFW_KEY_GRAVE_ACCENT,
			World1 = GLFW_KEY_WORLD_1,
			World2 = GLFW_KEY_WORLD_2,
			Escape = GLFW_KEY_ESCAPE,
			Enter = GLFW_KEY_ENTER,
			Tab = GLFW_KEY_TAB,
			Backspace = GLFW_KEY_BACKSPACE,
			Insert = GLFW_KEY_INSERT,
			Delete = GLFW_KEY_DELETE,
			Right = GLFW_KEY_RIGHT,
			Left = GLFW_KEY_LEFT,
			Down = GLFW_KEY_DOWN,
			Up = GLFW_KEY_UP,
			PageUp = GLFW_KEY_PAGE_UP,
			PageDown = GLFW_KEY_PAGE_DOWN,
			Home = GLFW_KEY_HOME,
			End = GLFW_KEY_END,
			CapsLock = GLFW_KEY_CAPS_LOCK,
			ScrollLock = GLFW_KEY_SCROLL_LOCK,
			NumLock = GLFW_KEY_NUM_LOCK,
			PrintScreen = GLFW_KEY_PRINT_SCREEN,
			Pause = GLFW_KEY_PAUSE,
			F1 = GLFW_KEY_F1,
			F2 = GLFW_KEY_F2,
			F3 = GLFW_KEY_F3,
			F4 = GLFW_KEY_F4,
			F5 = GLFW_KEY_F5,
			F6 = GLFW_KEY_F6,
			F7 = GLFW_KEY_F7,
			F8 = GLFW_KEY_F8,
			F9 = GLFW_KEY_F9,
			F10 = GLFW_KEY_F10,
			F11 = GLFW_KEY_F11,
			F12 = GLFW_KEY_F12,
			F13 = GLFW_KEY_F13,
			F14 = GLFW_KEY_F14,
			F15 = GLFW_KEY_F15,
			F16 = GLFW_KEY_F16,
			F17 = GLFW_KEY_F17,
			F18 = GLFW_KEY_F18,
			F19 = GLFW_KEY_F19,
			F20 = GLFW_KEY_F20,
			F21 = GLFW_KEY_F21,
			F22 = GLFW_KEY_F22,
			F23 = GLFW_KEY_F23,
			F24 = GLFW_KEY_F24,
			F25 = GLFW_KEY_F25,
			Kp_0 = GLFW_KEY_KP_0,
			Kp_1 = GLFW_KEY_KP_1,
			Kp_2 = GLFW_KEY_KP_2,
			Kp_3 = GLFW_KEY_KP_3,
			Kp_4 = GLFW_KEY_KP_4,
			Kp_5 = GLFW_KEY_KP_5,
			Kp_6 = GLFW_KEY_KP_6,
			Kp_7 = GLFW_KEY_KP_7,
			Kp_8 = GLFW_KEY_KP_8,
			Kp_9 = GLFW_KEY_KP_9,
			Kp_Decimal = GLFW_KEY_KP_DECIMAL,
			Kp_Divide = GLFW_KEY_KP_DIVIDE,
			Kp_Multiply = GLFW_KEY_KP_MULTIPLY,
			Kp_Subtract = GLFW_KEY_KP_SUBTRACT,
			Kp_Add = GLFW_KEY_KP_ADD,
			Kp_Enter = GLFW_KEY_KP_ENTER,
			Kp_Equal = GLFW_KEY_KP_EQUAL,
			LeftShift = GLFW_KEY_LEFT_SHIFT,
			LeftControl = GLFW_KEY_LEFT_CONTROL,
			LeftAlt = GLFW_KEY_LEFT_ALT,
			LeftSuper = GLFW_KEY_LEFT_SUPER,
			RightShift = GLFW_KEY_RIGHT_SHIFT,
			RightControl = GLFW_KEY_RIGHT_CONTROL,
			RightAlt = GLFW_KEY_RIGHT_ALT,
			RightSuper = GLFW_KEY_RIGHT_SUPER,
			Menu = GLFW_KEY_MENU,
			Last = GLFW_KEY_LAST,
		};

		enum class MouseButton : int
		{
			M1 = GLFW_MOUSE_BUTTON_1,
			M2 = GLFW_MOUSE_BUTTON_2,
			M3 = GLFW_MOUSE_BUTTON_3,
			M4 = GLFW_MOUSE_BUTTON_4,
			M5 = GLFW_MOUSE_BUTTON_5,
			M6 = GLFW_MOUSE_BUTTON_6,
			M7 = GLFW_MOUSE_BUTTON_7,
			M8 = GLFW_MOUSE_BUTTON_8,
			Last = GLFW_MOUSE_BUTTON_LAST,
			Left = GLFW_MOUSE_BUTTON_LEFT,
			Right = GLFW_MOUSE_BUTTON_RIGHT,
			Middle = GLFW_MOUSE_BUTTON_MIDDLE,
		};

		enum class JoystickId : int
		{
			J1 = GLFW_JOYSTICK_1,
			J2 = GLFW_JOYSTICK_2,
			J3 = GLFW_JOYSTICK_3,
			J4 = GLFW_JOYSTICK_4,
			J5 = GLFW_JOYSTICK_5,
			J6 = GLFW_JOYSTICK_6,
			J7 = GLFW_JOYSTICK_7,
			J8 = GLFW_JOYSTICK_8,
			J9 = GLFW_JOYSTICK_9,
			J10 = GLFW_JOYSTICK_10,
			J11 = GLFW_JOYSTICK_11,
			J12 = GLFW_JOYSTICK_12,
			J13 = GLFW_JOYSTICK_13,
			J14 = GLFW_JOYSTICK_14,
			J15 = GLFW_JOYSTICK_15,
			J16 = GLFW_JOYSTICK_16,
			Last = GLFW_JOYSTICK_LAST,
		};

		enum class HatState : unsigned char
		{
			Centered = GLFW_HAT_CENTERED,
			Up = GLFW_HAT_UP,
			Right = GLFW_HAT_RIGHT,
			Down = GLFW_HAT_DOWN,
			Left = GLFW_HAT_LEFT,
			RightUp = GLFW_HAT_RIGHT_UP,
			RightDown = GLFW_HAT_RIGHT_DOWN,
			LeftUp = GLFW_HAT_LEFT_UP,
			LeftDown = GLFW_HAT_LEFT_DOWN,
		};

		enum class GamepadButton : int
		{
			A = GLFW_GAMEPAD_BUTTON_A,
			B = GLFW_GAMEPAD_BUTTON_B,
			X = GLFW_GAMEPAD_BUTTON_X,
			Y = GLFW_GAMEPAD_BUTTON_Y,
			LeftBumper = GLFW_GAMEPAD_BUTTON_LEFT_BUMPER,
			RightBumper = GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER,
			Back = GLFW_GAMEPAD_BUTTON_BACK,
			Start = GLFW_GAMEPAD_BUTTON_START,
			Guide = GLFW_GAMEPAD_BUTTON_GUIDE,
			LeftThumb = GLFW_GAMEPAD_BUTTON_LEFT_THUMB,
			RightThumb = GLFW_GAMEPAD_BUTTON_RIGHT_THUMB,
			DPad_Up = GLFW_GAMEPAD_BUTTON_DPAD_UP,
			DPad_Right = GLFW_GAMEPAD_BUTTON_DPAD_RIGHT,
			DPad_Down = GLFW_GAMEPAD_BUTTON_DPAD_DOWN,
			DPad_Left = GLFW_GAMEPAD_BUTTON_DPAD_LEFT,
			Last = GLFW_GAMEPAD_BUTTON_LAST,
			Cross = GLFW_GAMEPAD_BUTTON_CROSS,
			Circle = GLFW_GAMEPAD_BUTTON_CIRCLE,
			Square = GLFW_GAMEPAD_BUTTON_SQUARE,
			Triangle = GLFW_GAMEPAD_BUTTON_TRIANGLE,
		};

		enum class GamepadAxis : int
		{
			LeftX = GLFW_GAMEPAD_AXIS_LEFT_X,
			LeftY = GLFW_GAMEPAD_AXIS_LEFT_Y,
			RightX = GLFW_GAMEPAD_AXIS_RIGHT_X,
			RightY = GLFW_GAMEPAD_AXIS_RIGHT_Y,
			LeftTrigger = GLFW_GAMEPAD_AXIS_LEFT_TRIGGER,
			RightTrigger = GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER,
			Last = GLFW_GAMEPAD_AXIS_LAST,
		};

		enum class Cursor : int
		{
			// The regular arrow cursor shape.
			Arrow = GLFW_ARROW_CURSOR,
			// The text input I-beam cursor shape.
			IBeam = GLFW_IBEAM_CURSOR,
			// The crosshair shape.
			Crosshair = GLFW_CROSSHAIR_CURSOR,
			// The hand shape.
			Hand = GLFW_HAND_CURSOR,
			// The horizontal resize arrow shape.
			HResize = GLFW_HRESIZE_CURSOR,
			// The vertical resize arrow shape.
			VResize = GLFW_VRESIZE_CURSOR,
		};

		enum class Action : unsigned char
		{
			Release = GLFW_RELEASE,
			Press = GLFW_PRESS,
			Repeat = GLFW_REPEAT,
		};

		enum class Modifiers : int
		{
			// If this bit is set one or more Shift keys were held down.
			Shift = GLFW_MOD_SHIFT,
			// If this bit is set one or more Control keys were held down.
			Control = GLFW_MOD_CONTROL,
			// If this bit is set one or more Alt keys were held down.
			Alt = GLFW_MOD_ALT,
			// If this bit is set one or more Super keys were held down.
			Super = GLFW_MOD_SUPER,
			// If this bit is set the Caps Lock key is enabled.
			CapsLock = GLFW_MOD_CAPS_LOCK,
			// If this bit is set the Num Lock key is enabled.
			NumLock = GLFW_MOD_NUM_LOCK,
		};
		constexpr Modifiers operator~( const Modifiers& lhs );
		constexpr Modifiers operator|( const Modifiers& lhs, const Modifiers& rhs );
		constexpr Modifiers operator^( const Modifiers& lhs, const Modifiers& rhs );
		constexpr Modifiers operator&( const Modifiers& lhs, const Modifiers& rhs );


		//========================================
		//	GamepadState
		//========================================
		struct GamepadState : public GLFWgamepadstate
		{
		public:

			GamepadState( void );
			GamepadState( const GLFWgamepadstate& rhs );

			// Returns the current state of all axes.
			constexpr GamepadAxesList axesStates( void ) const;
			// Returns the current state of button actions.
			constexpr GamepadActionList buttonStates( void ) const;

			inline static const GLFWgamepadstate	Invalid = GLFWgamepadstate{0};
		};


		//========================================
		//	Joystick
		//========================================
		class Joystick
		{
		public:

			//========================================
			//	Events
			//========================================

			// ConnectionEvent( JoystickId id, ConnectionStatus status )
			using ConnectionEvent = Event<JoystickId, ConnectionStatus>;


			Joystick( const JoystickId& id );


			// Updates the global gamepad mappings with the provided mapping.
			bool GamepadMappings( std::string_view mappings );
			// Event when a joystick is connected or disconnected.
			ConnectionEvent& ConnectedEvent( void );

			// Returns if this joystick is present.
			bool present( void ) const;
			// Returns the state of all axes.
			std::vector<float> axes( void ) const;
			// Returns the state of all buttons.
			ActionList buttons( void ) const;
			// Returns the state of all hat buttons.
			HatStateList hats( void ) const;
			// Returns the name of this joystick.
			std::string_view name( void ) const;
			// Returns the GUID of this joystick.
			std::string_view guid( void ) const;
			// Sets the user pointer ( user data ) of this joystick.
			template<class UserPointerType>
			void userPointer( UserPointerType* pointer );
			// Returns the user pointer ( user data ) of this joystick.
			template<class UserPointerType>
			UserPointerType* userPointer( void ) const;
			// Returns if this joystick is a gamepad.
			bool gamepad( void ) const;
			// Returns the gamepad state of this joystick, if this is a gamepad.
			GamepadState gamepadState( void ) const;
			// Returns the gamepad name of this joystick, if this is a gamepad.
			std::string_view gamepadName( void ) const;

		protected:

			JoystickId		id_;
		};

		inline std::string_view KeyName( const Key& key, int scanCode );
		inline std::string_view KeyName( const Key& key );
		inline int KeyScanCode( const Key& key );
	}
}
#include "input.inl"
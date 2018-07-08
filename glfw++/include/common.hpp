#pragma once

#if defined( GLFW_EXPOSE_NATIVE_WIN32 )
	#define GLFWPP_NATIVE win32
	#ifndef NOMINMAX
	#define NOMINMAX
	#endif

	#ifndef VC_EXTRALEAN
	#define VC_EXTRALEAN
	#endif

	#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
	#endif
	#include <windef.h>
	// Win32
#elif defined( GLFW_EXPOSE_NATIVE_COCOA )
	#define GLFWPP_NATIVE cocoa
	// Cocoa
#elif defined( GLFW_EXPOSE_NATIVE_X11 )
	#define GLFWPP_NATIVE x11
	// X11
#else
	#define GLFWPP_NATIVE none
	// Default
#endif

namespace glfw
{
	//========================================
	//	Version
	//========================================
	struct Version
	{
		int		major = 1;
		int		minor = 0;
		int		revision = 0;
	};


	//========================================
	//	Common types
	//========================================
	using unicode_t = unsigned int;


	//========================================
	//	Constants
	//========================================
	enum class ConnectionStatus : int
	{
		Connected = GLFW_CONNECTED,
		Disconnected = GLFW_DISCONNECTED,
	};


	//========================================
	//	Forward Declarations
	//========================================

	// event.hpp
	template<class ...Args>
	class Event;

	// image.hpp
	struct Pixel;
	class Image;
	using PixelList = std::vector<Pixel>;
	using ImageList = std::vector<Image>;

	// input.hpp
	namespace input
	{
		enum class Mode : int;
		enum class CursorMode : int;
		enum class Key : int;
		enum class MouseButton : int;
		enum class JoystickId : int;
		enum class HatState : unsigned char;
		enum class GamepadButton : int;
		enum class GamepadAxis : int;
		enum class Cursor : int;
		enum class Action : unsigned char;
		enum class Modifiers : int;
		struct GamepadState;
		class Joystick;
		using ActionList = std::vector<Action>;
		using GamepadAxesList = std::array<float, sizeof( GLFWgamepadstate::axes ) / sizeof( *GLFWgamepadstate::axes )>;
		using GamepadActionList = std::array<Action, sizeof( GLFWgamepadstate::buttons ) / sizeof( *GLFWgamepadstate::buttons )>;
		using HatStateList = std::vector<HatState>;
	}

	// lib.hpp
	enum class Error : int;
	using ErrorEvent = Event<Error, std::string_view>;

	// monitor.hpp
	struct VideoMode;
	class Monitor;
	using MonitorList = std::vector<Monitor>;
	using VideoModeList = std::vector<VideoMode>;

	// point.hpp
	template<class T>
	struct Point2;
	template<class T>
	struct Point3;
	using Point2i = Point2<int>;
	using Point3i = Point3<int>;
	using Point2f = Point2<float>;
	using Point3f = Point3<float>;
	using Point2d = Point2<double>;
	using Point3d = Point3<double>;

	// rectangle.hpp
	struct Rectangle;

	// window.hpp
	struct AspectRatio;
	class Image;
	class Window;
	struct WindowHolder;
	using WindowPtr = std::shared_ptr<Window>;
	using WindowWeakPtr = std::weak_ptr<Window>;
	using WindowList = std::vector<WindowPtr>;
	using WindowWeakList = std::vector<WindowWeakPtr>;
}

#define GLFWPP_EXPAND( arg ) arg
#define GLFWPP_STRINGIFYX( ... ) #__VA_ARGS__
#define GLFWPP_STRINGIFY( arg ) GLFWPP_STRINGIFYX( arg )
#define GLFWPP_NATIVE_HEADER( header, extension ) GLFWPP_STRINGIFY( header.GLFWPP_EXPAND( GLFWPP_NATIVE ).extension )
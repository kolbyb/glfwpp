#pragma once

namespace glfw
{
	enum class Error : int
	{
		NotInitialized = GLFW_NOT_INITIALIZED,
		NoCurrentContext = GLFW_NO_CURRENT_CONTEXT,
		InvalidEnum = GLFW_INVALID_ENUM,
		InvalidValue = GLFW_INVALID_VALUE,
		OutOfMemory = GLFW_OUT_OF_MEMORY,
		APIUnavailable = GLFW_API_UNAVAILABLE,
		VersionUnavailable = GLFW_VERSION_UNAVAILABLE,
		PlatformError = GLFW_PLATFORM_ERROR,
		FormatUnavailable = GLFW_FORMAT_UNAVAILABLE,
		NoWindowContext = GLFW_NO_WINDOW_CONTEXT,
	};

	struct ErrorDescription
	{
		Error				error;
		std::string_view	description;
	};

	enum class InitializationHint : int
	{
		JoystickHatButtons = GLFW_JOYSTICK_HAT_BUTTONS,
		CocoaChDirResources = GLFW_COCOA_CHDIR_RESOURCES,
		CocoaMenuBar = GLFW_COCOA_MENUBAR,
	};

	bool Initialize( void );
	void Terminate( void );
	template<class HintType>
	void InitHint( InitializationHint hint, const HintType& value );
	Version GetVersion( void );
	std::string GetVersionString( void );
	ErrorDescription GetError( void );
	ErrorEvent& GetErrorEvent( void );
}

std::ostream& operator<<( std::ostream& out, const glfw::Error& error ) noexcept;

#include "lib.inl"
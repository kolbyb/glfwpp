#include "pch.hpp"
#include "lib.hpp"
#include "event.hpp"
#include "window.hpp"

namespace glfw
{
	//========================================
	//	LibHolder
	//========================================
	struct LibHolder
	{
		static LibHolder& instance( void ) noexcept
		{
			static LibHolder holder_ = LibHolder();
			return holder_;
		}

	protected:

		LibHolder( void )
		{
			::glfwSetErrorCallback( []( int error, const char* description ) {
				GetErrorEvent()( static_cast<Error>( error ), description );
			} );
		}
	};
	LibHolder s_libHolder = LibHolder::instance();


	//========================================
	//	...
	//========================================
	bool Initialize( void )
	{
		return ::glfwInit() == GLFW_TRUE;
	}

	void Terminate( void )
	{
		assert( Window::Count() == 0 );
		::glfwTerminate();
	}

	Version GetVersion( void )
	{
		Version version = Version();
		::glfwGetVersion( &version.major, &version.minor, &version.revision );
		return version;
	}

	std::string GetVersionString( void )
	{
		return ::glfwGetVersionString();
	}

	ErrorDescription GetError( void )
	{
		const char*		description = nullptr;
		Error			error = static_cast<Error>( ::glfwGetError( &description ) );
		return ErrorDescription{ error, description };
	}

	ErrorEvent& GetErrorEvent( void )
	{
		static ErrorEvent errorEvent_ = ErrorEvent();
		return errorEvent_;
	}
}

std::ostream& operator<<( std::ostream& out, const glfw::Error& error ) noexcept
{
	switch ( error )
	{
	case glfw::Error::NotInitialized:		return out << "Not Initialized";
	case glfw::Error::NoCurrentContext:		return out << "No Current Context";
	case glfw::Error::InvalidEnum:			return out << "Invalid Enum";
	case glfw::Error::InvalidValue:			return out << "Invalid Value";
	case glfw::Error::OutOfMemory:			return out << "Out Of Memory";
	case glfw::Error::APIUnavailable:		return out << "API Unavailable";
	case glfw::Error::VersionUnavailable:	return out << "Version Unavailable";
	case glfw::Error::PlatformError:		return out << "Platform Error";
	case glfw::Error::FormatUnavailable:	return out << "Format Unavailable";
	case glfw::Error::NoWindowContext:		return out << "No Window Context";
	default:								return out << static_cast<std::underlying_type<glfw::Error>::type>( error );
	}
}
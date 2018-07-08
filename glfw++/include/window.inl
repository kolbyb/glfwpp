#pragma once
#include "aspectratio.hpp"
#include "image.hpp"
#include "input.hpp"
#include "rectangle.hpp"

namespace glfw
{
	//========================================
	// Window
	//========================================
	inline void Window::PollEvents( void )
	{
		::glfwPollEvents();
	}

	inline void Window::WaitEvents( void )
	{
		::glfwWaitEvents();
	}

	inline void Window::WaitEventsTimeout( double timeout )
	{
		::glfwWaitEventsTimeout( timeout );
	}

	inline void Window::PostEmptyEvent( void )
	{
		::glfwPostEmptyEvent();
	}

	inline void Window::DefaultHints( void )
	{
		::glfwDefaultWindowHints();
	}

	inline void Window::SetContextVersion( const Version& version )
	{
		Hint( WindowHint::ContextVersionMajor, version.major );
		Hint( WindowHint::ContextVersionMinor, version.minor );
	}

	inline void Window::shouldClose( bool close )
	{
		::glfwSetWindowShouldClose( *this, close );
	}

	inline bool Window::shouldClose( void ) const
	{
		return ::glfwWindowShouldClose( *this ) != GLFW_FALSE;
	}

	inline void Window::icon( const ImageList& images )
	{
		using image_list = std::vector<GLFWimage>;
		const image_list glfwImageList( images.begin(), images.end() );
		::glfwSetWindowIcon( *this, static_cast<int>( glfwImageList.size() ), &glfwImageList[0] );
	}


	inline void Window::title( std::string_view title )
	{
		::glfwSetWindowTitle( *this, title.data() );
	}

	inline void Window::position( const Point2i& position )
	{
		::glfwSetWindowPos( *this, position.x, position.y );
	}

	inline Point2i Window::position( void ) const
	{
		Point2i		position = Point2i();

		::glfwGetWindowPos( *this, &position.x, &position.y );
		return position;
	}

	inline void Window::aspectRatio( const AspectRatio& ratio )
	{
		::glfwSetWindowAspectRatio( *this, ratio.numerator, ratio.denominator );
	}

	inline void Window::size( const Point2i& size )
	{
		::glfwSetWindowPos( *this, size.x, size.y );
	}

	inline Point2i Window::size( void ) const
	{
		Point2i		size = Point2i();

		::glfwGetWindowSize( *this, &size.x, &size.y );
		return size;
	}

	inline void Window::sizeLimits( int minWidth, int minHeight, int maxWidth, int maxHeight )
	{
		::glfwSetWindowSizeLimits( *this, minWidth, minHeight, maxWidth, maxHeight );
	}

	inline Rectangle Window::frameSize( void ) const
	{
		Rectangle		frameSize = Rectangle();

		::glfwGetWindowFrameSize( *this, &frameSize.left, &frameSize.top, &frameSize.right, &frameSize.bottom );
		return frameSize;
	}

	inline Point2i Window::framebufferSize( void ) const
	{
		Point2i		framebufferSize = Point2i();

		::glfwGetFramebufferSize( *this, &framebufferSize.x, &framebufferSize.y );
		return framebufferSize;
	}

	inline Point2f Window::contentScale( void ) const
	{
		Point2f		contentScale = Point2f();

		::glfwGetWindowContentScale( *this, &contentScale.x, &contentScale.y );
		return contentScale;
	}

	inline void Window::opacity( const float& opacity )
	{
		::glfwSetWindowOpacity( *this, opacity );
	}

	inline float Window::opacity( void ) const
	{
		return ::glfwGetWindowOpacity( *this );
	}

	inline void Window::iconify( void )
	{
		::glfwIconifyWindow( *this );
	}

	inline void Window::restore( void )
	{
		::glfwRestoreWindow( *this );
	}

	inline void Window::maximize( void )
	{
		::glfwMaximizeWindow( *this );
	}

	inline void Window::show( void )
	{
		::glfwShowWindow( *this );
	}

	inline void Window::hide( void )
	{
		::glfwHideWindow( *this );
	}

	inline void Window::focus( void )
	{
		::glfwFocusWindow( *this );
	}

	inline void Window::makeContextCurrent( void )
	{
		::glfwMakeContextCurrent( *this );
	}

	inline void Window::requestAttention( void )
	{
		::glfwRequestWindowAttention( *this );
	}

	inline void Window::monitor( Monitor monitor, const Point2i& position, const Point2i& size, int refreshRate )
	{
		::glfwSetWindowMonitor( *this, monitor, position.x, position.y, size.x, size.y, refreshRate );
	}

	inline Monitor Window::monitor( void ) const
	{
		return ::glfwGetWindowMonitor( *this );
	}

	inline void Window::swapBuffers( void )
	{
		::glfwSwapBuffers( *this );
	}

	template<class UserPointerType>
	void Window::userPointer( UserPointerType* pointer )
	{
		::glfwSetWindowUserPointer( *this, static_cast<void*>( pointer ) );
	}

	template<class UserPointerType>
	UserPointerType* Window::userPointer( void ) const
	{
		return static_cast<UserPointerType*>( ::glfwGetWindowUserPointer( *this ) );
	}

	template<class HintType>
	inline void Window::attribute( WindowHint hint, const HintType& value )
	{
		::glfwSetWindowAttrib( *this, static_cast<std::underlying_type_t<WindowHint>>( hint ), static_cast<int>( value ) );
	}

	template<class AttributeType>
	inline AttributeType Window::attribute( WindowHint hint ) const
	{
		return static_cast<AttributeType>( ::glfwGetWindowAttrib( *this, static_cast<std::underlying_type_t<WindowHint>>( hint ) ) );
	}

	inline input::Action Window::mouseButton( input::MouseButton button ) const
	{
		return static_cast<input::Action>( ::glfwGetMouseButton( *this, static_cast<std::underlying_type_t<input::MouseButton>>( button ) ) );
	}

	inline void Window::cursorPosition( const Point2d& position )
	{
		::glfwSetCursorPos( *this, position.x, position.y );
	}

	inline Point2d Window::cursorPosition( void ) const
	{
		Point2d		cursorPos = Point2d();

		::glfwGetCursorPos( *this, &cursorPos.x, &cursorPos.y );
		return cursorPos;
	}

	template<class ModeType>
	inline void Window::inputMode( input::Mode mode, const ModeType& value )
	{
		::glfwSetInputMode( *this, static_cast<std::underlying_type_t<input::Mode>>( mode ), static_cast<int>( value ) );
	}

	template<class ModeType>
	inline ModeType Window::inputMode( input::Mode mode ) const
	{
		return static_cast<ModeType>( ::glfwGetInputMode( *this, static_cast<std::underlying_type_t<input::Mode>>( mode ) ) );
	}

	//========================================
	// Window::Attributes
	//========================================
	inline bool Window::focused( void ) const
	{
		return attribute<bool>( WindowHint::Focused );
	}

	inline bool Window::iconified( void ) const
	{
		return attribute<bool>( WindowHint::Iconified );
	}

	inline bool Window::maximized( void ) const
	{
		return attribute<bool>( WindowHint::Maximized );
	}

	inline bool Window::visible( void ) const
	{
		return attribute<bool>( WindowHint::Visible );
	}

	inline bool Window::resizable( void ) const
	{
		return attribute<bool>( WindowHint::Resizable );
	}

	inline bool Window::decorated( void ) const
	{
		return attribute<bool>( WindowHint::Decorated );
	}

	inline bool Window::floating( void ) const
	{
		return attribute<bool>( WindowHint::Floating );
	}

	inline ClientAPI Window::clientAPI( void ) const
	{
		return attribute<ClientAPI>( WindowHint::ClientAPI );
	}

	inline ContextCreationAPI Window::contextCreationAPI( void ) const
	{
		return attribute<ContextCreationAPI>( WindowHint::ContextCreationAPI );
	}

	inline ContextRobustness Window::contextRobustness( void ) const
	{
		return attribute<ContextRobustness>( WindowHint::ContextRobustness );
	}

	inline Version Window::contextVersion( void ) const
	{
		return Version{
			attribute( WindowHint::ContextVersionMajor ),
			attribute( WindowHint::ContextVersionMinor ),
			attribute( WindowHint::ContextRevision ),
		};
	}

	inline bool Window::openGLForwardCompat( void ) const
	{
		return attribute<bool>( WindowHint::OpenGLForwardCompat );
	}

	inline bool Window::openGLDebugContext( void ) const
	{
		return attribute<bool>( WindowHint::OpenGLDebugContext );
	}

	inline OpenGLProfile Window::openGLProfile( void ) const
	{
		return attribute<OpenGLProfile>( WindowHint::OpenGLProfile );
	}

	//========================================
	// Window operators
	//========================================
	inline Window::operator GLFWwindow*( void ) const noexcept
	{
		return window_.get();
	}
}
#include GLFWPP_NATIVE_HEADER( window, inl )
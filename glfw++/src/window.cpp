#include "pch.hpp"
#include "window.hpp"

#include "input.hpp"

namespace glfw
{
	//========================================
	//	WindowHolder
	//========================================
	struct WindowHolder
	{
		using List = std::unordered_map<GLFWwindow*, Window*>;

		static WindowHolder& instance( void ) noexcept
		{
			static WindowHolder holder_ = WindowHolder();
			return holder_;
		}


		void registerWindow( Window* window ) noexcept
		{
			GLFWwindow*		glfwWindow = *window;
			auto&			listWindow = windowList_[glfwWindow];

			// Ensure we haven't previously inserted this window
			assert( listWindow == nullptr );
			listWindow = window;

			// Generic Events
			::glfwSetWindowPosCallback( glfwWindow, PosCallback_ );
			::glfwSetWindowSizeCallback( glfwWindow, SizeCallback_ );
			::glfwSetWindowCloseCallback( glfwWindow, CloseCallback_ );
			::glfwSetWindowRefreshCallback( glfwWindow, RefreshCallback_ );
			::glfwSetWindowFocusCallback( glfwWindow, FocusCallback_ );
			::glfwSetWindowIconifyCallback( glfwWindow, IconifyCallback_ );
			::glfwSetWindowMaximizeCallback( glfwWindow, WindowMaximizeCallback_ );
			::glfwSetFramebufferSizeCallback( glfwWindow, FramebufferSizeCallback_ );
			// Input Events
			::glfwSetMouseButtonCallback( glfwWindow, MouseButtonCallback_ );
			::glfwSetCursorPosCallback( glfwWindow, CursorPositionCallback_ );
			::glfwSetCursorEnterCallback( glfwWindow, CursorEnterCallback_ );
			::glfwSetScrollCallback( glfwWindow, CursorScrollCallback_ );
			::glfwSetKeyCallback( glfwWindow, KeyCallback_ );
			::glfwSetCharCallback( glfwWindow, CharacterCallback_ );
			::glfwSetCharModsCallback( glfwWindow, CharacterModifierCallback_ );
			::glfwSetDropCallback( glfwWindow, FileDropCallback_ );
		}

		void unregisterWindow( Window* window ) noexcept
		{
			GLFWwindow*		glfwWindow = *window;

			// Erase this window from the list
			windowList_.erase( glfwWindow );

			// Generic Events
			::glfwSetWindowPosCallback( glfwWindow, nullptr );
			::glfwSetWindowSizeCallback( glfwWindow, nullptr );
			::glfwSetWindowCloseCallback( glfwWindow, nullptr );
			::glfwSetWindowRefreshCallback( glfwWindow, nullptr );
			::glfwSetWindowFocusCallback( glfwWindow, nullptr );
			::glfwSetWindowIconifyCallback( glfwWindow, nullptr );
			::glfwSetFramebufferSizeCallback( glfwWindow, nullptr );
			// Input Events
			::glfwSetMouseButtonCallback( glfwWindow, nullptr );
			::glfwSetCursorPosCallback( glfwWindow, nullptr );
			::glfwSetCursorEnterCallback( glfwWindow, nullptr );
			::glfwSetScrollCallback( glfwWindow, nullptr );
			::glfwSetKeyCallback( glfwWindow, nullptr );
			::glfwSetCharCallback( glfwWindow, nullptr );
			::glfwSetCharModsCallback( glfwWindow, nullptr );
			::glfwSetDropCallback( glfwWindow, nullptr );
		}

		List		windowList_ = List();

	protected:

		WindowHolder( void ) = default;

		//========================================
		//	Events
		//========================================
		using MouseButtonEvent = Event<input::MouseButton, input::Action, input::Modifiers>;
		using CursorPositionEvent = Event<Point2d>;
		using CursorEnterEvent = Event<bool>;
		using CursorScrollEvent = Event<Point2d>;
		using KeyEvent = Event<input::Key, int, input::Action, input::Modifiers>;
		using CharacterEvent = Event<unicode_t>;
		using CharacterModifierEvent = Event<unicode_t, input::Modifiers>;
		using FileDropEvent = Event<int, std::vector<std::string_view>>;
		// Generic Events
		static void PosCallback_( GLFWwindow* window, int xpos, int ypos )							{ instance().windowList_[window]->positionEvent_( Point2i( xpos, ypos ) ); }
		static void SizeCallback_( GLFWwindow* window, int width, int height )						{ instance().windowList_[window]->sizeEvent_( Point2i( width, height ) ); }
		static void CloseCallback_( GLFWwindow* window )											{ instance().windowList_[window]->closeEvent_(); }
		static void RefreshCallback_( GLFWwindow* window )											{ instance().windowList_[window]->refreshEvent_(); }
		static void FocusCallback_( GLFWwindow* window, int focused )								{ instance().windowList_[window]->focusEvent_( static_cast<bool>( focused ) ); }
		static void IconifyCallback_( GLFWwindow* window, int iconified )							{ instance().windowList_[window]->iconifyEvent_( static_cast<bool>( iconified ) ); }
		static void WindowMaximizeCallback_( GLFWwindow* window, int maximized )					{ instance().windowList_[window]->maximizeEvent_( maximized == GLFW_TRUE ); }
		static void FramebufferSizeCallback_( GLFWwindow* window, int width, int height )			{ instance().windowList_[window]->frameBufferSizeEvent_( Point2i( width, height ) ); }
		// Input Events
		static void CursorPositionCallback_( GLFWwindow* window, double xpos, double ypos )			{ instance().windowList_[window]->cursorPositionEvent_( Point2d{xpos, ypos} ); }
		static void CursorEnterCallback_( GLFWwindow* window, int entered )							{ instance().windowList_[window]->cursorEnterEvent_( static_cast<bool>( entered ) ); }
		static void CursorScrollCallback_( GLFWwindow* window, double xoffset, double yoffset )		{ instance().windowList_[window]->cursorScrollEvent_( Point2d{xoffset, yoffset} ); }
		static void CharacterCallback_( GLFWwindow* window, unsigned int codepoint )				{ instance().windowList_[window]->characterEvent_( static_cast<unicode_t>( codepoint ) ); }
		static void MouseButtonCallback_( GLFWwindow* window, int button, int action, int mods )
		{
			using namespace glfw::input;
			instance().windowList_[window]->mouseButtonEvent_( static_cast<MouseButton>( button ), static_cast<Action>( action ), static_cast<Modifiers>( mods ) );
		}
		static void KeyCallback_( GLFWwindow* window, int key, int scancode, int action, int mods )
		{
			using namespace glfw::input;
			instance().windowList_[window]->keyEvent_( static_cast<Key>( key ), scancode, static_cast<Action>( action ), static_cast<Modifiers>( mods ) );
		}
		static void CharacterModifierCallback_( GLFWwindow* window, unsigned int codepoint, int mods )
		{
			using namespace glfw::input;
			instance().windowList_[window]->characterModifierEvent_( static_cast<unicode_t>( codepoint ), static_cast<Modifiers>( mods ) );
		}
		static void FileDropCallback_( GLFWwindow* window, int count, const char** paths )
		{
			auto pathList = std::vector<std::string_view>( &paths[0], &paths[count] );
			instance().windowList_[window]->fileDropEvent_( pathList );
		}
	};
	static WindowHolder s_windowHolder = WindowHolder::instance();


	//========================================
	//	Window
	//========================================
	Window::Window( int width, int height, std::string_view title, Monitor monitor, glfw::WindowPtr share ) :
		window_( ::glfwCreateWindow( width, height, title.data(), monitor, ( share ? share->window_.get() : nullptr ) ) )
	{
		assert( window_ );
		if ( valid() )
		{
			WindowHolder::instance().registerWindow( this );
		}
	}

	Window::~Window( void )
	{
		if ( valid() )
		{
			WindowHolder::instance().unregisterWindow( this );
		}
	}

	std::size_t Window::Count( void ) noexcept
	{
		return WindowHolder::instance().windowList_.size();
	}

	WindowWeakList Window::AllWindows( void ) noexcept
	{
		auto&				originalList = WindowHolder::instance().windowList_;
		WindowWeakList		list = WindowWeakList();

		list.reserve( originalList.size() );
		for ( auto& window : originalList )
		{
			list.push_back( window.second->weak_from_this() );
		}
		return list;
	}

	Window::PositionEvent& Window::positionEvent( void )
	{
		return positionEvent_;
	}

	Window::SizeEvent& Window::sizeEvent( void )
	{
		return sizeEvent_;
	}

	Window::CloseEvent& Window::closeEvent( void )
	{
		return closeEvent_;
	}

	Window::RefreshEvent& Window::refreshEvent( void )
	{
		return refreshEvent_;
	}

	Window::FocusEvent& Window::focusEvent( void )
	{
		return focusEvent_;
	}

	Window::IconifyEvent& Window::iconifyEvent( void )
	{
		return iconifyEvent_;
	}

	Window::MaximizeEvent& Window::maximizeEvent( void )
	{
		return maximizeEvent_;
	}

	Window::FrameBufferSizeEvent& Window::frameBufferSizeEvent( void )
	{
		return frameBufferSizeEvent_;
	}

	Window::WindowContentScaleEvent& Window::windowContentScaleEvent( void )
	{
		return windowContentScaleEvent_;
	}

	Window::MouseButtonEvent& Window::mouseButtonEvent( void )
	{
		return mouseButtonEvent_;
	}

	Window::CursorPositionEvent& Window::cursorPositionEvent( void )
	{
		return cursorPositionEvent_;
	}

	Window::CursorEnterEvent& Window::cursorEnterEvent( void )
	{
		return cursorEnterEvent_;
	}

	Window::CursorScrollEvent& Window::cursorScrollEvent( void )
	{
		return cursorScrollEvent_;
	}

	Window::KeyEvent& Window::keyEvent( void )
	{
		return keyEvent_;
	}

	Window::CharacterEvent& Window::characterEvent( void )
	{
		return characterEvent_;
	}

	Window::CharacterModifierEvent& Window::characterModifierEvent( void )
	{
		return characterModifierEvent_;
	}

	Window::FileDropEvent& Window::fileDropEvent( void )
	{
		return fileDropEvent_;
	}

	bool Window::valid( void ) const noexcept
	{
		return window_ != nullptr;
	}
}
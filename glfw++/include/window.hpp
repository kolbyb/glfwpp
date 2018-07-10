#pragma once
#include "monitor.hpp"
#include "event.hpp"

namespace glfw
{
	//========================================
	//	Constants
	//========================================
	enum class WindowHint : int
	{
		// Framebuffer Hints
		RedBits = GLFW_RED_BITS,
		GreenBits = GLFW_GREEN_BITS,
		BlueBits = GLFW_BLUE_BITS,
		AlphaBits = GLFW_ALPHA_BITS,
		DepthBits = GLFW_DEPTH_BITS,
		StencilBits = GLFW_STENCIL_BITS,
		AccumRedBits = GLFW_ACCUM_RED_BITS,
		AccumGreenBits = GLFW_ACCUM_GREEN_BITS,
		AccumBlueBits = GLFW_ACCUM_BLUE_BITS,
		AccumAlphaBits = GLFW_ACCUM_ALPHA_BITS,
		AuxBuffers = GLFW_AUX_BUFFERS,
		Stereo = GLFW_STEREO,
		Samples = GLFW_SAMPLES,
		SRGBCapable = GLFW_SRGB_CAPABLE,
		RefreshRate = GLFW_REFRESH_RATE,
		DoubleBuffer = GLFW_DOUBLEBUFFER,
		// Window Hints
		Focused = GLFW_FOCUSED,
		Iconified = GLFW_ICONIFIED,
		Resizable = GLFW_RESIZABLE,
		Visible = GLFW_VISIBLE,
		Decorated = GLFW_DECORATED,
		AutoIconify = GLFW_AUTO_ICONIFY,
		Floating = GLFW_FLOATING,
		Maximized = GLFW_MAXIMIZED,
		CenterCursor = GLFW_CENTER_CURSOR,
		TransparentFramebuffer = GLFW_TRANSPARENT_FRAMEBUFFER,
		Hovered = GLFW_HOVERED,
		// Context Hints
		ClientAPI = GLFW_CLIENT_API,
		ContextVersionMajor = GLFW_CONTEXT_VERSION_MAJOR,
		ContextVersionMinor = GLFW_CONTEXT_VERSION_MINOR,
		ContextRevision = GLFW_CONTEXT_REVISION,
		ContextRobustness = GLFW_CONTEXT_ROBUSTNESS,
		OpenGLForwardCompat = GLFW_OPENGL_FORWARD_COMPAT,
		OpenGLDebugContext = GLFW_OPENGL_DEBUG_CONTEXT,
		OpenGLProfile = GLFW_OPENGL_PROFILE,
		ContextReleaseBehavior = GLFW_CONTEXT_RELEASE_BEHAVIOR,
		ContextNoError = GLFW_CONTEXT_NO_ERROR,
		ContextCreationAPI = GLFW_CONTEXT_CREATION_API,
		RetinaFrameBuffer = GLFW_COCOA_RETINA_FRAMEBUFFER,
		FrameName = GLFW_COCOA_FRAME_NAME,
		GraphicsSwitching = GLFW_COCOA_GRAPHICS_SWITCHING,
		ClassName = GLFW_X11_CLASS_NAME,
		InstanceName = GLFW_X11_INSTANCE_NAME,
	};

	enum class ClientAPI : int
	{
		None = GLFW_NO_API,
		OpenGL = GLFW_OPENGL_API,
		OpenGLES = GLFW_OPENGL_ES_API,
	};

	enum class ContextCreationAPI : int
	{
		Native = GLFW_NATIVE_CONTEXT_API,
		EGL = GLFW_EGL_CONTEXT_API,
	};

	enum class ContextRobustness : int
	{
		None = GLFW_NO_ROBUSTNESS,
		NoResetNotification = GLFW_NO_RESET_NOTIFICATION,
		LoseContextOnReset = GLFW_LOSE_CONTEXT_ON_RESET,
	};

	enum class ContextReleaseBehavior : int
	{
		Any = GLFW_ANY_RELEASE_BEHAVIOR,
		Flush = GLFW_RELEASE_BEHAVIOR_FLUSH,
		None = GLFW_RELEASE_BEHAVIOR_NONE,
	};

	enum class OpenGLProfile : int
	{
		Any = GLFW_OPENGL_ANY_PROFILE,
		Compatible = GLFW_OPENGL_COMPAT_PROFILE,
		Core = GLFW_OPENGL_CORE_PROFILE,
	};

	//========================================
	//	Window
	//========================================
	class Window : public std::enable_shared_from_this<Window>
	{
	public:

		friend struct WindowHolder;

	#if defined( GLFW_EXPOSE_NATIVE_WIN32 )
		using native_type = ::HWND;
	#elif defined( GLFW_EXPOSE_NATIVE_COCOA )
		using native_type = ::id;
	#elif defined( GLFW_EXPOSE_NATIVE_X11 )
		using native_type = ::Window;
	#else
		using native_type = int;
	#endif

		//========================================
		//	Generic Events
		//========================================

		// PositionEvent( glfw::Point2i position )
		using PositionEvent = Event<Point2i>;
		// SizeEvent( glfw::Point2i size
		using SizeEvent = Event<Point2i>;
		// CloseEvent( void )
		using CloseEvent = Event<>;
		// RefreshEvent( void )
		using RefreshEvent = Event<>;
		// FocusEvent( bool focused )
		using FocusEvent = Event<bool>;
		// IconifyEvent( bool iconified )
		using IconifyEvent = Event<bool>;
		// MaximizeEvent( bool maximized )
		using MaximizeEvent = Event<bool>;
		// FrameBufferSizeEvent( glfw::Point2i size )
		using FrameBufferSizeEvent = Event<Point2i>;
		// WindowContentScaleEvent( glfw::Point2f scale )
		using WindowContentScaleEvent = Event<Point2f>;

		//========================================
		//	Input Events
		//========================================

		// MouseButtonEvent( glfw::input::MouseButton button, glfw::input::Action action, glfw::input::Modifiers modifiers )
		using MouseButtonEvent = Event<input::MouseButton, input::Action, input::Modifiers>;
		// CursorPositionEvent( glfw::Point2d position )
		using CursorPositionEvent = Event<Point2d>;
		// CursorEnterEvent( bool entered )
		using CursorEnterEvent = Event<bool>;
		// CursorScrollEvent( glfw::Point2d offset )
		using CursorScrollEvent = Event<Point2d>;
		// CharacterEvent( glfw::input::Key key, int scancode, glfw::input::Action action, glfw::input::Modifiers modifiers )
		using KeyEvent = Event<input::Key, int, input::Action, input::Modifiers>;
		// CharacterEvent( unicode_t codepoint )
		using CharacterEvent = Event<unicode_t>;
		// CharacterModifierEvent( glfw::unicode_t codepoint, glfw::input::Modifiers modifiers )
		using CharacterModifierEvent = Event<unicode_t, input::Modifiers>;
		// FileDropEvent( std::vector<std::string_view> pathList )
		using FileDropEvent = Event<std::vector<std::string_view>>;


		Window( void ) = delete;
		// Creates a window and its associated context.
		Window( int width, int height, std::string_view title, Monitor monitor=nullptr, WindowPtr share=nullptr );
		~Window( void );


		//========================================
		//	Global
		//========================================

		// Processes all pending events.
		static inline void PollEvents( void );
		// Waits until events are queued and processes them.
		static inline void WaitEvents( void );
		// Waits with timeout until events are queued and processes them.
		static inline void WaitEventsTimeout( double timeout );
		// Posts an empty event to the event queue.
		static inline void PostEmptyEvent( void );
		// Resets all window hints to their default values.
		static inline void DefaultHints( void );
		// Sets this window hint to the desired value. Type must be convertible to int, or an enum.
		template<class HintType, typename = std::enable_if_t<std::is_convertible_v<HintType, int> || std::is_enum_v<HintType>>>
		static inline void Hint( WindowHint hint, const HintType& value )
		{
			::glfwWindowHint( static_cast<std::underlying_type_t<WindowHint>>( hint ), static_cast<int>( value ) );
		}
		// Sets this window hint to the desired value. Type must be a string, or convertible to a string_view.
		template<class HintType, typename = void, typename = std::enable_if_t<std::is_convertible_v<HintType, std::string_view>>>
		static inline void Hint( WindowHint hint, const HintType& value )
		{
			std::string_view	sv( value );
			::glfwWindowHintString( static_cast<std::underlying_type_t<WindowHint>>( hint ), sv.data() );
		}
		// Sets the desired context api version.
		static inline void SetContextVersion( const Version& version );
		// Returns the number of glfw windows.
		static std::size_t Count( void ) noexcept;
		// Returns all glfw windows.
		static WindowWeakList AllWindows( void ) noexcept;


		//========================================
		//	Generic
		//========================================

		// Sets the close flag of this window.
		inline void shouldClose( bool close );
		// Checks the close flag of this window.
		inline bool shouldClose( void ) const;
		// Sets the icon for this window.
		inline void icon( const ImageList& images );
		// Sets the title of this window.
		inline void title( std::string_view title );
		// Sets the position of the client area of this window.
		inline void position( const Point2i& position );
		// Retrieves the position of the client area of this window.
		inline Point2i position( void ) const;
		// Sets the aspect ratio of this window.
		inline void aspectRatio( const AspectRatio& ratio );
		// Sets the size of the client area of this window.
		inline void size( const Point2i& size );
		// Retrieves the size of the client area of this window.
		inline Point2i size( void ) const;
		// Sets the size limits of this window.
		inline void sizeLimits( int minWidth, int minHeight, int maxWidth, int maxHeight );
		// Retrieves the size of the frame of this window.
		inline Rectangle frameSize( void ) const;
		// Retrieves the size of the framebuffer of this window.
		inline Point2i framebufferSize( void ) const;
		// Retrieves the content scale of this window.
		inline Point2f contentScale( void ) const;
		// Sets the opacity of this window.
		inline void opacity( const float& opacity );
		// Gets the opacity of this window.
		inline float opacity( void ) const;
		// Iconifies this window.
		inline void iconify( void );
		// Restores this window.
		inline void restore( void );
		// Maximizes this window.
		inline void maximize( void );
		// Makes this window visible.
		inline void show( void );
		// Hides this window.
		inline void hide( void );
		// Brings this window to front and sets input focus.
		inline void focus( void );
		// Makes the context of this window current for the calling thread.
		inline void makeContextCurrent( void );
		// Requests attention to this window.
		inline void requestAttention( void );
		// Sets the mode, monitor, video mode and placement of a window.
		inline void monitor( Monitor monitor, const Point2i& position, const Point2i& size, int refreshRate );
		// Returns the monitor that the window uses for full screen mode.
		inline Monitor monitor( void ) const;
		// Swaps the front and back buffers of this window.
		inline void swapBuffers( void );
		// Returns the native window handle.
		inline native_type native( void ) const;
		// Sets the user pointer ( user data ) of this window.
		template<class UserPointerType>
		void userPointer( UserPointerType* pointer );
		// Returns the user pointer ( user data ) of this window.
		template<class UserPointerType>
		UserPointerType* userPointer( void ) const;
		// Sets an attribute of this window.
		template<class HintType>
		inline void attribute( WindowHint hint, const HintType& value );
		// Returns an attribute of this window.
		template<class AttributeType=int>
		inline AttributeType attribute( WindowHint hint ) const;

		//========================================
		//	Input
		//========================================

		// Returns the current state of the provided mouse button.
		inline input::Action mouseButton( input::MouseButton button ) const;
		// Sets the current cursor position of this window.
		inline void cursorPosition( const Point2d& position );
		// Returns the current cursor position of this window.
		inline Point2d cursorPosition( void ) const;
		// Sets an input mode of this window.
		template<class ModeType>
		inline void inputMode( input::Mode mode, const ModeType& value );
		// Returns the value of an input mode of this window.
		template<class ModeType=int>
		inline ModeType inputMode( input::Mode mode ) const;

		//========================================
		//	Attributes
		//========================================

		// WindowHint::Focused
		inline bool focused( void ) const;
		// WindowHint::Iconified
		inline bool iconified( void ) const;
		// WindowHint::Maximized
		inline bool maximized( void ) const;
		// WindowHint::Visible
		inline bool visible( void ) const;
		// WindowHint::Resizable
		inline bool resizable( void ) const;
		// WindowHint::Decorated
		inline bool decorated( void ) const;
		// WindowHint::Floating
		inline bool floating( void ) const;
		// WindowHint::ClientAPI
		inline ClientAPI clientAPI( void ) const;
		// WindowHint::ContextCreationAPI
		inline ContextCreationAPI contextCreationAPI( void ) const;
		// WindowHint::ContextRobustness
		inline ContextRobustness contextRobustness( void ) const;
		// WindowHint::ContextVersionMajor, WindowHint::ContextVersionMinor, WindowHint::ContextRevision
		inline Version contextVersion( void ) const;
		// WindowHint::OpenGLForwardCompat
		inline bool openGLForwardCompat( void ) const;
		// WindowHint::OpenGLDebugContext
		inline bool openGLDebugContext( void ) const;
		// WindowHint::OpenGLProfile
		inline OpenGLProfile openGLProfile( void ) const;

		//========================================
		//	Generic Events
		//========================================
		PositionEvent& positionEvent( void );
		SizeEvent& sizeEvent( void );
		CloseEvent& closeEvent( void );
		RefreshEvent& refreshEvent( void );
		FocusEvent& focusEvent( void );
		IconifyEvent& iconifyEvent( void );
		MaximizeEvent& maximizeEvent( void );
		FrameBufferSizeEvent& frameBufferSizeEvent( void );
		WindowContentScaleEvent& windowContentScaleEvent( void );

		//========================================
		//	Input Events
		//========================================
		MouseButtonEvent& mouseButtonEvent( void );
		CursorPositionEvent& cursorPositionEvent( void );
		CursorEnterEvent& cursorEnterEvent( void );
		CursorScrollEvent& cursorScrollEvent( void );
		KeyEvent& keyEvent( void );
		CharacterEvent& characterEvent( void );
		CharacterModifierEvent& characterModifierEvent( void );
		FileDropEvent& fileDropEvent( void );

		//========================================
		//	Utilities
		//========================================
		bool valid( void ) const noexcept;

	protected:

		// Destroys this window and its context.
		struct InternalDeleter
		{
			void operator()( GLFWwindow* window ) const noexcept
			{
				::glfwDestroyWindow( window );
			}
		};
		using InternalPtr = std::unique_ptr<GLFWwindow, InternalDeleter>;

		inline operator GLFWwindow*( void ) const noexcept;
		
		
		InternalPtr				window_ = nullptr;
		// Generic Events
		PositionEvent			positionEvent_ = PositionEvent();
		SizeEvent				sizeEvent_ = SizeEvent();
		CloseEvent				closeEvent_ = CloseEvent();
		RefreshEvent			refreshEvent_ = RefreshEvent();
		FocusEvent				focusEvent_ = FocusEvent();
		IconifyEvent			iconifyEvent_ = IconifyEvent();
		MaximizeEvent			maximizeEvent_ = MaximizeEvent();
		FrameBufferSizeEvent	frameBufferSizeEvent_ = FrameBufferSizeEvent();
		WindowContentScaleEvent	windowContentScaleEvent_ = WindowContentScaleEvent();
		// Input Events
		MouseButtonEvent		mouseButtonEvent_ = MouseButtonEvent();
		CursorPositionEvent		cursorPositionEvent_ = CursorPositionEvent();
		CursorEnterEvent		cursorEnterEvent_ = CursorEnterEvent();
		CursorScrollEvent		cursorScrollEvent_ = CursorScrollEvent();
		KeyEvent				keyEvent_ = KeyEvent();
		CharacterEvent			characterEvent_ = CharacterEvent();
		CharacterModifierEvent	characterModifierEvent_ = CharacterModifierEvent();
		FileDropEvent			fileDropEvent_ = FileDropEvent();
	};
}
#include "window.inl"
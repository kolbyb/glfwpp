#pragma once

namespace glfw
{
	//========================================
	//	VideoMode
	//========================================
	struct VideoMode : public GLFWvidmode
	{
	public:

		VideoMode( int width, int height, int redBits, int greenBits, int blueBits, int refreshRate );
		VideoMode( const GLFWvidmode& rhs );

		AspectRatio aspectRatio( void ) const;

		inline operator Point2i( void ) noexcept;

		inline static const GLFWvidmode	Invalid = GLFWvidmode{0};
	};
	bool operator==( const AspectRatio& lhs, const VideoMode& rhs ) noexcept;
	bool operator==( const VideoMode& lhs, const AspectRatio& rhs ) noexcept;

	//========================================
	//	GammaRamp
	//========================================
	struct GammaRamp
	{
		friend class Monitor;

		using gamma_t = unsigned short;
		using entry_list = std::vector<gamma_t>;

		GammaRamp( void ) = default;
		GammaRamp( const entry_list& red, const entry_list& green, const entry_list& blue );


		void addEntry( gamma_t red, gamma_t green, gamma_t blue );
		const entry_list& red( void ) const;
		const entry_list& green( void ) const;
		const entry_list& blue( void ) const;

	protected:

		operator GLFWgammaramp( void ) const noexcept;

		entry_list		red_ = entry_list();
		entry_list		green_ = entry_list();
		entry_list		blue_ = entry_list();
	};

	//========================================
	//	Monitor
	//========================================
	class Monitor
	{
	public:

		friend class Window;

		//========================================
		//	Events
		//========================================

		// ConnectionEvent( Monitor monitor, ConnectionStatus status )
		using ConnectionEvent = Event<Monitor, ConnectionStatus>;


		Monitor( void ) = delete;
		Monitor( GLFWmonitor* monitor );


		// Returns the primary monitor.
		static Monitor PrimaryMonitor( void );
		// Returns the currently connected monitors.
		static MonitorList AllMonitors( void );
		// Register callback for monitor configuration updates.
		static ConnectionEvent& ConnectedEvent( void );

		// Returns the scale of content on this monitor.
		Point2f contentScale( void ) const;
		// Returns the name of this monitor.
		std::string name( void ) const;
		// Returns the position of the monitor's viewport on the virtual screen.
		Point2i position( void ) const;
		// Returns the physical size of the monitor.
		Point2i physicalSize( void ) const;
		// Returns the current mode of this monitor.
		VideoMode videoMode( void ) const;
		// Returns the available video modes for this monitor.
		VideoModeList availableVideoModes( void ) const;
		// Generates a gamma ramp and sets it for this monitor.
		void gamma( float value );
		// Sets the current gamma ramp for this monitor.
		void gammaRamp( const GammaRamp& gammaRamp ) const;
		// Returns the current gamma ramp for this monitor.
		GammaRamp gammaRamp( void ) const;
		// Returns if this is a valid monitor.
		bool valid( void ) const noexcept;
		// Sets the user pointer ( user data ) of this monitor.
		template<class UserPointerType>
		void userPointer( UserPointerType* pointer );
		// Returns the user pointer ( user data ) of this monitor.
		template<class UserPointerType>
		UserPointerType* userPointer( void ) const;

		bool operator==( const Monitor& rhs ) const noexcept;

	protected:

		operator GLFWmonitor*( void ) const noexcept;

		GLFWmonitor*		monitor_ = nullptr;
	};
}
#include "monitor.inl"
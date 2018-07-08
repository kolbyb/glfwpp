#include "pch.hpp"
#include "monitor.hpp"

#include "aspectratio.hpp"
#include "event.hpp"
#include "point.hpp"

namespace glfw
{
	//========================================
	//	VideoMode
	//========================================
	VideoMode::VideoMode( int width, int height, int redBits, int greenBits, int blueBits, int refreshRate ) :
		GLFWvidmode( {width, height, redBits, greenBits, blueBits, refreshRate} )
	{
	}

	VideoMode::VideoMode( const GLFWvidmode& rhs ) :
		VideoMode( rhs.width, rhs.height, rhs.redBits, rhs.greenBits, rhs.blueBits, rhs.refreshRate )
	{
	}

	AspectRatio VideoMode::aspectRatio( void ) const
	{
		int		gcd = std::gcd( width, height );
		return AspectRatio( width / gcd, height / gcd );
	}

	bool operator==( const AspectRatio& lhs, const VideoMode& rhs ) noexcept
	{
		return static_cast<int>( rhs.width * lhs.denominator ) == static_cast<int>( rhs.height * lhs.numerator );
	}

	bool operator==( const VideoMode& lhs, const AspectRatio& rhs ) noexcept
	{
		return static_cast<int>( lhs.width * rhs.denominator ) == static_cast<int>( lhs.height * rhs.numerator );
	}


	GammaRamp::GammaRamp( const entry_list& red, const entry_list& green, const entry_list& blue ) :
		red_( red ), green_( green ), blue_( blue )
	{
		assert( red_.size() == green_.size() == blue_.size() );
	#if defined( _WIN32 )
		assert( red_.size() == green_.size() == ( blue_.size() == 256 ) );
	#endif
	}

	void GammaRamp::addEntry( gamma_t red, gamma_t green, gamma_t blue )
	{
		red_.push_back( red );
		green_.push_back( green );
		blue_.push_back( blue );
	}

	const GammaRamp::entry_list& GammaRamp::red( void ) const
	{
		return red_;
	}

	const GammaRamp::entry_list& GammaRamp::green( void ) const
	{
		return green_;
	}

	const GammaRamp::entry_list& GammaRamp::blue( void ) const
	{
		return blue_;
	}

	GammaRamp::operator GLFWgammaramp( void ) const noexcept
	{
	#if defined( _WIN32 )
		assert( red_.size() == green_.size() == ( blue_.size() == 256 ) );
	#endif
		GLFWgammaramp gammaRamp = {
			&const_cast<GammaRamp::gamma_t&>( red_[0] ),
			&const_cast<GammaRamp::gamma_t&>( green_[0] ),
			&const_cast<GammaRamp::gamma_t&>( blue_[0] ),
			static_cast<unsigned int>( red_.size() )
		};
		return gammaRamp;
	}

	//========================================
	//	MonitorHolder
	//========================================
	struct MonitorHolder
	{
		static MonitorHolder& instance( void ) noexcept
		{
			static MonitorHolder holder_ = MonitorHolder();
			return holder_;
		}

		Monitor::ConnectionEvent	connectionEvent_ = Monitor::ConnectionEvent();

	protected:

		MonitorHolder( void )
		{
			::glfwSetMonitorCallback( MonitorCallback_ );
		}

		//========================================
		//	Events
		//========================================
		static void MonitorCallback_( GLFWmonitor* monitor, int event )		{ instance().connectionEvent_( monitor, static_cast<ConnectionStatus>( event ) ); }
	};
	static MonitorHolder s_monitorHolder = MonitorHolder::instance();

	//========================================
	//	Monitor
	//========================================
	Monitor::Monitor( GLFWmonitor* monitor ) :
		monitor_( monitor )
	{
	}

	Monitor Monitor::PrimaryMonitor( void )
	{
		return ::glfwGetPrimaryMonitor();
	}

	MonitorList Monitor::AllMonitors( void )
	{
		int		count = 0;
		auto**	monitors = ::glfwGetMonitors( &count );

		return monitors == nullptr ? MonitorList() : MonitorList( monitors, monitors + count );
	}

	Monitor::ConnectionEvent& Monitor::ConnectedEvent( void )
	{
		return MonitorHolder::instance().connectionEvent_;
	}

	Point2f Monitor::contentScale( void ) const
	{
		if ( monitor_ )
		{
			Point2f		scale = Point2f( 1.0f, 1.0f );

			::glfwGetMonitorContentScale( monitor_, &scale.x, &scale.y );
			return scale;
		}
		return Point2f::One;
	}

	std::string Monitor::name( void ) const
	{
		return monitor_ ? ::glfwGetMonitorName( monitor_ ) : "";
	}

	Point2i Monitor::position( void ) const
	{
		if ( monitor_ )
		{
			Point2i		position = Point2i();

			::glfwGetMonitorPos( monitor_, &position.x, &position.y );
			return position;
		}
		return Point2i::Zero;
	}

	Point2i Monitor::physicalSize( void ) const
	{
		if ( monitor_ )
		{
			Point2i		sizeMM = Point2i();

			::glfwGetMonitorPhysicalSize( monitor_, &sizeMM.x, &sizeMM.y );
			return sizeMM;
		}
		return Point2i::Zero;
	}

	VideoMode Monitor::videoMode( void ) const
	{
		return monitor_ ? *::glfwGetVideoMode( monitor_ ) : VideoMode::Invalid;
	}

	VideoModeList Monitor::availableVideoModes( void ) const
	{
		if ( monitor_ )
		{
			int		count = 0;
			auto*	videoModes = ::glfwGetVideoModes( monitor_, &count );

			return VideoModeList( videoModes, videoModes + count );
		}
		return VideoModeList();
	}

	void Monitor::gamma( float value )
	{
		if ( monitor_ )
		{
			::glfwSetGamma( *this, value );
		}
	}

	void Monitor::gammaRamp( const GammaRamp& gammaRamp ) const
	{
		if ( monitor_ )
		{
			GLFWgammaramp ramp = gammaRamp;
			::glfwSetGammaRamp( *this, &ramp );
		}
	}

	GammaRamp Monitor::gammaRamp( void ) const
	{
		if ( monitor_ )
		{
			GLFWgammaramp ramp = *::glfwGetGammaRamp( *this );
			return GammaRamp(
				GammaRamp::entry_list( &ramp.red[0], &ramp.red[ramp.size] ),
				GammaRamp::entry_list( &ramp.green[0], &ramp.green[ramp.size] ),
				GammaRamp::entry_list( &ramp.blue[0], &ramp.blue[ramp.size] )
			);
		}
		return GammaRamp();
	}

	bool Monitor::valid( void ) const noexcept
	{
		return monitor_ != nullptr;
	}

	Monitor::operator GLFWmonitor*( void ) const noexcept
	{
		return monitor_;
	}

	bool Monitor::operator==( const Monitor& rhs ) const noexcept
	{
		return monitor_ == rhs.monitor_;
	}
}
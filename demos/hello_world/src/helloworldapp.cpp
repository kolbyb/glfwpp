#include "pch.hpp"
#include "helloworldapp.hpp"

#include <iostream>


HelloWorldApp::HelloWorldApp( std::string_view title )
{
	// Ensure our current hints are set to default
	glfw::Window::DefaultHints();
	// You can set enum, int, bool, and string hints with glfw::Window::Hint
	glfw::Window::Hint( glfw::WindowHint::ClassName, "" );
	glfw::Window::Hint( glfw::WindowHint::ClientAPI, glfw::ClientAPI::None );
	/// Uncomment the following line to intentionally create an error in GLFW.
	/// glfw::Window::Hint( glfw::WindowHint::ClientAPI, 3 );
	glfw::Window::Hint( glfw::WindowHint::Resizable, false );

	// Get the video mode of the primary monitor
	// Note glfw::VideoMode provides an operator to convert to a glfw::Point2i, where x=width, y=height.
	glfw::Point2i		primaryVideoMode = glfw::Monitor::PrimaryMonitor().videoMode();
	// Note we're using glfw::Point2f, but size is defined as a glfw::Point2i.
	// The cast from double, float, and integer to one another will happen automatically for glfw::Point2/3 types.
	glfw::Point2i		size = glfw::Point2f( primaryVideoMode.x * 0.6667f, primaryVideoMode.y * 0.6667f );

	window_ = std::make_shared<glfw::Window>( size.x, size.y, title );

	assert( window_ );
	if ( initialized() )
	{
		// Register a handler for keyboard character input events
		window_->characterEvent() += [this]( const auto& codepoint ){ handleCharacter( codepoint ); };
		// Register a handler for file drop events
		window_->fileDropEvent() += [this]( const auto& pathList ){ handleFileDrops( pathList ); };

		// Set an initial position.
		size *= 0.5f;
		primaryVideoMode *= 0.5f;
		window_->position( primaryVideoMode - size );
	}
}

bool HelloWorldApp::initialized( void ) const noexcept
{
	return window_ != nullptr && window_->valid();
}

void HelloWorldApp::run( void )
{
	if ( initialized() )
	{
		while ( !window_->shouldClose() )
		{
			glfw::Window::PollEvents();
		}
	}
}

void HelloWorldApp::handleCharacter( const glfw::unicode_t codepoint )
{
	std::wcout << static_cast<wchar_t>( codepoint ) << std::endl;
}

void HelloWorldApp::handleFileDrops( const std::vector<std::string_view>& pathList )
{
	for ( auto& path : pathList )
	{
		std::cout << "Received file drop: " << path << std::endl;
	}
}
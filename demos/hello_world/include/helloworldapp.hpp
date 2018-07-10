#pragma once

struct HelloWorldApp
{
	HelloWorldApp( std::string_view title );


	// Returns whether or not the app has initialized into a non-error state.
	bool initialized( void ) const noexcept;
	// Runs the app.
	void run( void );
	// Handle unicode character input.
	void handleCharacter( const glfw::unicode_t codepoint );
	// Handle file drops onto the window.
	void handleFileDrops( const std::vector<std::string_view>& pathList );

protected:

	glfw::WindowPtr	window_ = nullptr;
};
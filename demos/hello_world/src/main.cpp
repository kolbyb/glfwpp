#include "pch.hpp"
#include "helloworldapp.hpp"

#include <iostream>


int main( void )
{
	int		result = EXIT_FAILURE;

	// Register an event handler for errors before doing anything.
	glfw::GetErrorEvent() += []( glfw::Error error, std::string_view description )
	{
		std::cout << "[GLFW_ERR] " << error << ": " << description << std::endl;
	};

	// Initialize glfw
	if ( glfw::Initialize() )
	{
		auto app = HelloWorldApp( "Hello World" );
		app.run();
		result = EXIT_SUCCESS;
	}
	// Ensure to terminate glfw when done
	glfw::Terminate();

	return result;
}
#include "pch.hpp"
#include "rectangle.hpp"
#include "point.hpp"

namespace glfw
{
	Rectangle::Rectangle( int left, int top, int right, int bottom ) :
		left( left ), top( top ), right( right ), bottom( bottom )
	{
	}

	Rectangle::Rectangle( const Point2i& point ) :
		left( 0 ), top( 0 ), right( point.x ), bottom( point.y )
	{
	}
}
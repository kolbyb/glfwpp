#pragma once

namespace glfw
{
	struct Rectangle
	{
		Rectangle( void ) = default;
		Rectangle( int left, int top, int right, int bottom );
		Rectangle( const Point2i& point );

		int		left = 0;
		int		top = 0;
		int		right = 0;
		int		bottom = 0;
	};
}
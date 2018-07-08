#include "pch.hpp"
#include "aspectratio.hpp"

namespace glfw
{
	//========================================
	//	AspectRatio
	//========================================
	AspectRatio::AspectRatio( int numerator, int denominator ) :
		numerator( numerator ), denominator( denominator )
	{
	}

	bool AspectRatio::operator==( const AspectRatio& rhs ) const noexcept
	{
		return static_cast<int>( rhs.numerator * denominator ) == static_cast<int>( rhs.denominator * numerator );
	}

	const AspectRatio	AspectRatio::Wide_21x9( 21, 9 );	// 7:3
	const AspectRatio	AspectRatio::Wide_18x9( 18, 9 );	// 2:1
	const AspectRatio	AspectRatio::Wide_16x9( 16, 9 );
	const AspectRatio	AspectRatio::Wide_16x10( 16, 10 );	// 8:5
	const AspectRatio	AspectRatio::Wide_3x2( 3, 2 );
	const AspectRatio	AspectRatio::Wide_3x1( 3, 1 );
	const AspectRatio	AspectRatio::Standard_5x4( 5, 4 );
	const AspectRatio	AspectRatio::Standard_4x3( 4, 3 );
	const AspectRatio	AspectRatio::Any = AspectRatio();
}
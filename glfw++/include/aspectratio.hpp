#pragma once

namespace glfw
{
	//========================================
	//	AspectRatio
	//========================================
	struct AspectRatio
	{
		AspectRatio( void ) = default;
		AspectRatio( int numerator, int denominator );


		bool operator==( const AspectRatio& rhs ) const noexcept;

		static const AspectRatio	Wide_21x9;		// 7:3
		static const AspectRatio	Wide_18x9;		// 2:1
		static const AspectRatio	Wide_16x9;
		static const AspectRatio	Wide_16x10;		// 8:5
		static const AspectRatio	Wide_3x2;
		static const AspectRatio	Wide_3x1;
		static const AspectRatio	Standard_5x4;
		static const AspectRatio	Standard_4x3;
		static const AspectRatio	Any;

		int		numerator = GLFW_DONT_CARE;
		int		denominator = GLFW_DONT_CARE;
	};
	template<class T>
	bool operator==( const AspectRatio& lhs, const Point2<T>& rhs ) noexcept;
	template<class T>
	bool operator==( const Point2<T>& lhs, const AspectRatio& rhs ) noexcept;
	template<class T>
	bool operator==( const AspectRatio& lhs, const Point3<T>& rhs ) noexcept;
	template<class T>
	bool operator==( const Point3<T>& lhs, const AspectRatio& rhs ) noexcept;
}
#include "aspectratio.inl"
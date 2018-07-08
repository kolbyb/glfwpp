#pragma once

namespace glfw
{
	//========================================
	//	AspectRatio
	//========================================
	template<class T>
	bool operator==( const AspectRatio& lhs, const Point2<T>& rhs ) noexcept
	{
		return static_cast<int>( rhs.x * lhs.denominator ) == static_cast<int>( rhs.y * lhs.numerator );
	}

	template<class T>
	bool operator==( const Point2<T>& lhs, const AspectRatio& rhs ) noexcept
	{
		return static_cast<int>( lhs.x * rhs.denominator ) == static_cast<int>( lhs.y * rhs.numerator );
	}

	template<class T>
	bool operator==( const AspectRatio& lhs, const Point3<T>& rhs ) noexcept
	{
		return static_cast<int>( rhs.x * lhs.denominator ) == static_cast<int>( rhs.y * lhs.numerator );
	}

	template<class T>
	bool operator==( const Point3<T>& lhs, const AspectRatio& rhs ) noexcept
	{
		return static_cast<int>( lhs.x * rhs.denominator ) == static_cast<int>( lhs.y * rhs.numerator );
	}
}
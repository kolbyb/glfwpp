#pragma once

namespace glfw
{
	template<class T>
	struct Point2
	{
		static_assert( std::is_arithmetic<T>::value, "Element Type must be an arithmetic type." );
		using element_type = T;

		Point2( void ) = default;
		Point2( const element_type& x, const element_type& y ) :
			x( x ), y( y )
		{
		}
		template<class OtherType = element_type>
		Point2( const Point2<OtherType>& rhs ) :
			x( static_cast<element_type>( rhs.x ) ), y( static_cast<element_type>( rhs.y ) )
		{
		}
		template<class OtherType = element_type>
		Point2( const Point3<OtherType>& rhs ) :
			x( static_cast<element_type>( rhs.x ) ), y( static_cast<element_type>( rhs.y ) )
		{
		}

		inline static const Point2<T>	One = Point2<T>{1, 1};
		inline static const Point2<T>	Zero = Point2<T>{0, 0};

		element_type	x = 0;
		element_type	y = 0;
	};

	template<class T>
	struct Point3
	{
		static_assert( std::is_arithmetic<T>::value, "Element Type must be an arithmetic type." );
		using element_type = T;

		Point3( void ) = default;
		Point3( const element_type& x, const element_type& y, const element_type& z ) :
			x( x ), y( y ), z( z )
		{
		}
		template<class OtherType = element_type>
		Point3( const Point3<OtherType>& rhs ) :
			x( static_cast<element_type>( rhs.x ) ), y( static_cast<element_type>( rhs.y ) ), z( static_cast<element_type>( rhs.z ) )
		{
		}
		template<class OtherType = element_type>
		Point3( const Point2<OtherType>& rhs ) :
			x( static_cast<element_type>( rhs.x ) ), y( static_cast<element_type>( rhs.y ) ), z( 0 )
		{
		}

		inline static const Point3<T>	One = Point3<T>{1, 1, 1};
		inline static const Point3<T>	Zero = Point3<T>{0, 0, 0};

		element_type	x = 0;
		element_type	y = 0;
		element_type	z = 0;
	};
}
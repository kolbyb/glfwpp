#pragma once
#include "point.hpp"

namespace glfw
{
	//========================================
	//	Pixel
	//========================================
	struct Pixel
	{
		using type = std::int8_t;

		Pixel( void ) = default;
		Pixel( type red, type green, type blue, type alpha );

		type	r = 0u;
		type	g = 0u;
		type	b = 0u;
		type	a = 0u;
	};

	//========================================
	//	Image
	//========================================
	class Image
	{
	public:

		Image( void ) = default;
		Image( int width, int height );
		Image( int width, int height, const PixelList& pixels );


		const Point2i& size( void ) const;
		const PixelList& pixels( void ) const;
		const Pixel& pixel( const Point2i& point ) const;
		void pixel( const Point2i& point, const Pixel& pixel );

		void makeGrid( int subdivisions, const Pixel& color1, const Pixel& color2 );

		operator GLFWimage( void ) const noexcept;

	protected:

		// The size( width, height ), in pixels, of this image.
		Point2i		size_ = Point2i{0, 0};
		// The pixel data of this image, arranged left-to-right, top-to-bottom.
		PixelList	pixels_ = {};
	};
}
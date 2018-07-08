#include "pch.hpp"
#include "image.hpp"

namespace glfw
{
	//========================================
	//	Pixel
	//========================================
	Pixel::Pixel( Pixel::type red, Pixel::type green, Pixel::type blue, Pixel::type alpha ) :
		r( red ), g( green ), b( blue ), a( alpha )
	{
	}

	//========================================
	//	Image
	//========================================
	Image::Image( int width, int height ) :
		size_( {width, height} ),
		pixels_( width * height, Pixel{} )
	{
		makeGrid( std::max( std::min( width / 8, height / 8 ), 1 ), Pixel( 63u, 63u, 63u, 255u ), Pixel( 127u, 127u, 127u, 255u ) );
	}

	Image::Image( int width, int height, const PixelList& pixels ) :
		size_( {width, height} ),
		pixels_( pixels )
	{
		assert( pixels_.size() == (width * height) );
	}

	const Point2i& Image::size( void ) const
	{
		return size_;
	}

	const PixelList& Image::pixels( void ) const
	{
		return pixels_;
	}

	const Pixel& Image::pixel( const Point2i& point ) const
	{
		return pixels_[( point.y * size_.x ) + point.x];
	}

	void Image::pixel( const Point2i& point, const Pixel& pixel )
	{
		pixels_[( point.y * size_.x ) + point.x] = pixel;
	}

	void Image::makeGrid( int subdivisions, const Pixel& color1, const Pixel& color2 )
	{
		int		widthMod = size_.x / subdivisions;
		int		heightMod = size_.y / subdivisions;

		for ( int y = 0; y < size_.y; ++y )
		{
			int		offset = ( y / heightMod % 2 ? 1 : 0 );
			for ( int division = 0; division < subdivisions; ++division )
			{
				int		begin = ( y * size_.x )+ ( widthMod * division );
				int		end = begin + widthMod;
				std::fill( pixels_.begin() + begin, pixels_.begin() + end, (( division + offset ) % 2 ? color2 : color1) );
			}
		}
	}

	Image::operator GLFWimage( void ) const noexcept
	{
		return GLFWimage{size_.x, size_.y, reinterpret_cast<unsigned char*>( const_cast<Pixel*>( &pixels_[0] ) )};
	}
}
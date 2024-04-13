#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
	private:
		int _raw;
		static const int _bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed &toCopy );
		Fixed& operator=( const Fixed &toCopy );
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};


#endif
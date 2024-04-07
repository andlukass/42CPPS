#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
	private:
		int decimal;
		static const int bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed &toCopy );
		Fixed& operator=(const Fixed &other);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};


#endif
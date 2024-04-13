#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
	private:
		int _raw;
		static const int _bits = 8;

	public:
		Fixed();
		Fixed( const int number );
		Fixed( const float number );
		~Fixed();
		Fixed( const Fixed &toCopy );
		Fixed& operator=( const Fixed &toCopy );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		int toInt( void ) const ;
		float toFloat( void ) const ;
};

	std::ostream & operator << (std::ostream &out, Fixed const &number);


#endif
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
		Fixed& operator=( Fixed const &toCopy );
		Fixed operator*( Fixed const &number );
		Fixed operator+( Fixed const &number );
		Fixed operator-( Fixed const &number );
		Fixed operator/( Fixed const &number );
		Fixed& operator++( void );
		Fixed operator++( int );
		Fixed& operator--( void );
		Fixed operator--( int );
		bool operator==( Fixed const &number );
		bool operator!=( Fixed const &number );
		bool operator>( Fixed const &number );
		bool operator<( Fixed const &number );
		bool operator<=( Fixed const &number );
		bool operator>=( Fixed const &number );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		int toInt( void ) const;
		float toFloat( void ) const;

		static Fixed& min(Fixed &number1, Fixed &number2);
		static const Fixed& min(Fixed const &number1, Fixed const &number2);
		static Fixed& max(Fixed &number1, Fixed &number2);
		static const Fixed& max(Fixed const &number1, Fixed const &number2);
};

	std::ostream& operator<< (std::ostream &out, Fixed const &number);


#endif
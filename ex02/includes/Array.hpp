#ifndef  ARRAY_HPP
#define  ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

template<typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &source);
		~Array();

		Array &	operator=(Array const &original_copy);
		T	&	operator[](int n) const;
		T &		operator[](int n);
		unsigned int		size() const;
		
		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		T *	input_array;
		unsigned int	input_size;
};

#include "./srcs/Array.tpp"

#endif

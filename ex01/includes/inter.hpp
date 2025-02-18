#ifndef  ITER_HPP
#define  ITER_HPP

#include <iostream>
#include <string>


template<typename T>
void	iter(T *address, int len, void (*func)(T& element));

template<typename T>
void	printValue(T& element);

template <typename T>
void squareValue(T& element)


#endif

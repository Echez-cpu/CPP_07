#ifndef   WHATEVER_HPP
#define   WHATEVER_HPP

#include <iostream>
#include <string>

typedef std::string str;

template<typename T>
void	swap(T &a, T &b);

template<typename T>
T	min(const T &a, const T &b);

template<typename T>
T	max(const T &a, const T &b);

#endif

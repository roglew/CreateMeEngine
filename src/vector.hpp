#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

template <class T>
class Vector2
{
	public:
	T x, y;

	Vector2<T>();
	Vector2<T>(T x, T y);
	// Constructor

	Vector2<T>(const Vector2& copyfrom);
	// Copy constructor

	Vector2<T>& operator = (const Vector2<T>& other);
	Vector2<T> operator + (const Vector2<T>& other);
	Vector2<T>& operator += (const Vector2<T>& other);
	Vector2<T> operator - (const Vector2<T>& other);
	Vector2<T>& operator -= (const Vector2<T>& other);
};

#include "vector.cpp"

#endif


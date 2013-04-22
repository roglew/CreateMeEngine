
template<class T>
Vector2<T>::Vector2(T init_x, T init_y)
{
	x = init_x;
	y = init_y;
}

template<class T>
Vector2<T>::Vector2(const Vector2& copyfrom)
{
	x = copyfrom.x;
	y = copyfrom.y;
}

template<class T>
Vector2<T>& Vector2<T>::operator = (const Vector2<T>& other)
{
	x = other.x;
	y = other.y;
}

template<class T>
Vector2<T> Vector2<T>::operator + (const Vector2<T>& other)
{
	return Vector2<T>(x + other.x, y + other.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator += (const Vector2<T>& other)
{
	x += other.x;
	y += other.y
}

template<class T>
Vector2<T> Vector2<T>::operator - (const Vector2<T>& other)
{
	return Vector2<T>(x - other.x, y - other.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator -= (const Vector2<T>& other)
{
	x -= other.x;
	y -= other.y;
}


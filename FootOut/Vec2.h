#ifndef VEC2_H
#define VEC2_H

template <class T>
struct Vec2
{
	T x;
	T y;

	Vec2(T px = 0, T py = 0)
	{
		x = px;
		y = py;
	}

	T Lenght()
	{
		return sqrt(SquareLenght());
	}

	T SquareLenght()
	{
		return (x * x) + (y * y);
	}

	Vec2<T> operator*(T f) const
	{
		return Vec2(x * f, y * f);
	}

	Vec2<T> operator%(T f) const
	{
		return Vec2(x % f, y % f);
	}

	void operator +=(const Vec2<T>& v)
	{
		x += v.x;
		y += v.y;
	}

	void operator -=(const Vec2<T>& v)
	{
		x -= v.x;
		y -= v.y;
	}

	Vec2<T> operator - (const Vec2<T>& v)
	{
		return Vec2<T>(x - v.x, y - v.y); 
	}

	bool operator ==(const Vec2<T>& v)
	{
		if((x == v.x) && (y == v.y))
		{
			return true;
		}
		return false;
	}

	bool operator !=(const Vec2<T>& v)
	{
		if((x != v.x) && (y != v.y))
		{
			return true;
		}
		return false;
	}

	bool operator>(const Vec2<T>& v) const
	{
		T myArea = x * y;
		T vArea = v.x * v.y;
			if (myArea > vArea)
			{
				return true;
			}
			return false;
	}
};

typedef Vec2<float> Vec2f;

typedef Vec2<int> Vec2i;


#endif
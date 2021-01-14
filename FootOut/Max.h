#ifndef MAX_H
#define MAX_H

template <class T>
T Max(const T& t1, const T& t2)
{
	if(t1 > t2)
	{
		return t1;
	}

	return t2;
};

#endif
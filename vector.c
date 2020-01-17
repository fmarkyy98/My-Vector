#include <stdlib.h>
#include "vector.h"

static bool set_capacity(Vector* l_vector, const int capacity)
{
	if(capacity > l_vector->currentSize)
	{
		if(realloc(l_vector->v, capacity))
		{
			for(int i = l_vector->capacity; i < capacity; ++i)
			{
				l_vector->v[i] = 0;
			}
			l_vector->capacity = capacity;
			return true;
		}
	}
	return false;
}

bool initialize(Vector* l_vector, const int capacity)
{
	l_vector->capacity = 0;
	l_vector->currentSize = 0;
	if(capacity < 0)
	{
		return false;
	}
	
	l_vector->v = calloc(capacity, sizeof(int));
	l_vector->capacity = capacity;
	return true;
}

void dispose(Vector* l_vector)
{
	l_vector->capacity = 0;
	l_vector->currentSize = 0;
	free(l_vector->v);
}

bool safe_append(Vector* l_vector, const int value)
{
	if(l_vector->currentSize < l_vector->capacity)
	{
		l_vector->v[l_vector->currentSize] = value;
		++l_vector->currentSize;
		return true;
	}
	if(set_capacity(l_vector, l_vector->capacity * 2))
	{
		safe_append(l_vector, value);
	}
	
	return false;
}

int retrieve(Vector* l_vector, const int index)
{
	int result = l_vector->v[index];
	return result;
}

bool safe_insert(Vector* l_vector, const int index, const int value)
{
	if(l_vector->currentSize < l_vector->capacity)
	{
		for(int i = l_vector->currentSize - 1 ; i >= index ; --i)
		{
			l_vector->v[i+1] = l_vector->v[i];
		}
		l_vector->v[index] = value;
		++l_vector->currentSize;
		return true;
	}
	if(set_capacity(l_vector, l_vector->capacity * 2))
	{
		safe_insert(l_vector, index, value);
	}
	return false;
}

bool erase(Vector* l_vector, const int index)
{
	for(int i = index; i < l_vector->currentSize; ++i)
		{
			l_vector->v[i] = l_vector->v[i+1];
		}
		l_vector->v[l_vector->currentSize - 1] = 0;
		--l_vector->currentSize;
		return true;
}





















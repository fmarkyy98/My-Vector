#ifndef VECTOR
#define VECTOR

#include <stdbool.h>

typedef struct Vector
{
	int* v;
	int currentSize;
	int capacity;
} Vector;

bool initialize(Vector* l_vector, const int capacity);

void dispose(Vector* l_vector);

bool safe_append(Vector* l_vector, const int value);

int retrieve(Vector* l_vector, const int index);

bool safe_insert(Vector* l_vector, const int index, const int value);

bool erase(Vector* l_vector, const int index);

#endif //VECTOR
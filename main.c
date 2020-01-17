#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("incorrect parameters\n");
		return 1;
	}
	
	Vector vector;
	
	char *a = argv[1];
    int num = atoi(a);
	
    initialize(&vector, num);
	printf("----inicialized-------------------------------\n");
	printf("Capacity: %d\n", vector.capacity);
	printf("Size: %d\n", vector.currentSize);
	for(int i = 0; i < vector.capacity; ++i)
	{
		printf("#%d: %d\n", i, vector.v[i]);
	}
	
	safe_append(&vector, 1);
	safe_append(&vector, 12);
	safe_append(&vector, 123);
	printf("----appended 3 item-----------------------------------\n");
	for(int i = 0; i < vector.currentSize; ++i)
	{
		printf("#%d: %d\n", i, vector.v[i]);
	}
	
	printf("----2nd item-----------------------------------\n");
	printf("%d\n",retrieve(&vector, 1));
	
	safe_insert(&vector, 2, 21);
	printf("----inserted 21 to 2nd index---------------------------\n");
	for(int i = 0; i < vector.currentSize; ++i)
	{
		printf("#%d: %d\n", i, vector.v[i]);
	}
	
	erase(&vector, 2);
	printf("----erased value from 2nd index-------------------------\n");
	for(int i = 0; i < vector.currentSize; ++i)
	{
		printf("#%d: %d\n", i, vector.v[i]);
	}
	
	
	
	dispose(&vector);
	printf("----disposed-----------------------------------\n");
	
	printf("Capacity: %d\n", vector.capacity);
	printf("Size: %d\n", vector.currentSize);
	
	return 0;
}
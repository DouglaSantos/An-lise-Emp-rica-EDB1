#include "algorithmsearch.h"

//BUSCA LINEAR ITERATIVA
const int *linear_search( const int *first,  const int *last, int value){//OK
	int dist = std::distance(first,last);
	for (int i = 0; i < dist; ++i)
	{
		if (*first == value)
		{
			return first;
		}
		first++;
	}
	return last;
}

//BUSCA BINARIA ITERATIVA
const int *binary_search(const int *first, const int *last, int value){//OK
	const int *f = first, *l = last;
	const int *mid;
	int aux;
	while(f <= l){
		aux = std::distance(f, l);
		aux = aux/2;
		mid = f + aux;
		if (*mid == value)
		{
			return mid;
		}
		else{
			if (value < *mid)
			{
				l = mid-1;
			}
			if (*mid < value)
			{
				f = mid+1;
			}
		}

	}

    return last;
}

//BUSCA BINARIA RECURSIVA
const int *recursive_binary_search( const int *first, const int *last, int value){//OK
	
	if (value < *first || *(last-1) < value)
	{
		return last;
	}
	if(std::distance(first, last) > 0)
	{
		const int *mid = first + (std::distance(first, last)/2);

		if (value == *mid)
		{
			return mid;
		}

		if (value < *mid)
		{
			return recursive_binary_search(first, mid, value);
		}

		return recursive_binary_search(mid+1, last, value);
	}

	return last;
	
}

// JUMP SEARCH
const int *jump_search(const int *first, const int *last, int value)//HELP
{
	const int *l = last;
	int n_jump = std::distance(first, last)/sizeof(*first);
	const int *jumper = first;
	const int *aux;

	if (value < *first || *(last-1) < value)
	{
		return last;
	}
	while(jumper < l){
		std::cout << n_jump << std::endl;
		if (*jumper == value)
		{
			return jumper;
		}

		if (*jumper < value)
		{
			aux = jumper;
			jumper = jumper + (int)sqrt(n_jump);
		}

		if (value < *jumper)
		{	
			l = jumper;
			n_jump = std::distance(aux, jumper)/sizeof(*first);
			jumper = aux;
			jumper = jumper + (int)sqrt(n_jump);
		}
	}

	return last;
}

//BUSCA TERNARIA ITERATIVA
const int *ternary_search( const int *first,  const int *last, int value){//OK
	const int *f = first, *l = last;
	const int *mid1, *mid2;
	int aux;

	if (value < *first || *(last-1) < value)
	{
		return last;
	}

	while(f <= l){
		aux = std::distance(f, l);
		aux = aux/3;
		mid1 = f + aux;
		mid2 = f + 2*aux;

		if (*mid1 == value)
		{
			return mid1;
		}
		if (*mid2 == value)
		{
			return mid2;
		}
		
		if (value < *mid1)
		{
			l = mid1;
		}

		if (*mid2 < value)
		{
			f = mid2+1;
		}
		if (*mid1 < value && value < *mid2)
		{
			f = mid1+1;
			l = mid2;
		}
	}


    return last;
}

//BUSCA TERNARIA RECURSIVA
const int *recursive_ternary_search(const int *first, const int *last, int value){//OK

	if (value < *first || *(last-1) < value)
	{
		return last;
	}
	if(std::distance(first, last) > 0)
	{
		const int *mid1 = first + (std::distance(first, last)/3);
		const int *mid2 = first + 2*(std::distance(first, last)/3);
		
		if (value == *mid1)
		{
			return mid1;
		}
		if (value == *mid2)
		{
			return mid2;
		}

		if (value < *mid1)
		{
			return recursive_binary_search(first, mid1, value);
		}
		if (*mid2 < value)
		{
			return recursive_binary_search(mid2+1, last, value);
		}

		return recursive_binary_search(mid1+1, mid2, value);
	}

	return last;
	
}


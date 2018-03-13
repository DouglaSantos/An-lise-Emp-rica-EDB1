#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()

const int *lsearch(const int *first, const int *last, int value )
{
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


int *bsearch( int *first, int *last, int value )
{
	int *f = first, *l = last;
	int *mid;
	int aux;
	while(f <= l){
		aux = std::distance(f, l);
		aux = aux/2;
		mid = f+aux;
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

    return last; // STUB
}

int *rbSearch(int *first, int *last, int value){

	 if(last>=first){

		 int *mid = std::distance(first, last);
		 if(if value == *mid){
			 return mid;
		 }
		 if(value < *mid){
			 rbSearch(first, mid-1, value);
		 }
		 if(value > *mid){
			 rbSearch(mid+1, last, value);
		 }
	}else{
		return last;
	}
 }


// Driver function.
int main()
{
    int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Data container.
    int targets[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , -4, 20 }; // Target values for testing.

    // Prints out the original data container.
    std::cout << "Array: [ ";
    std::copy( std::begin(A), std::end(A), std::ostream_iterator<int>( std::cout , " " ) );
    std::cout << "]\n";

    // Executes several searchs in the data container.
    #ifdef BINARY
    	std::cout << "SEACH BINARY"<< std::endl;
	    for( const auto & e : targets )
	    {
	        // Look for target in the entire range.
	        int *result = const_cast<int*> (bsearch( std::begin(A), std::end(A), e ));

	        // Process the result
	        if ( result != std::end(A) )
	        {
	            std::cout << ">>> Found \"" << e << "\" at position "
	                      << std::distance(std::begin(A),result) << ".\n";
	        }
	        else
	        {
	            std::cout << ">>> Value \"" << e << "\" not found in array!\n";
	        }
	    }
	#else
	    std::cout << "SEACH LINEAR"<< std::endl;
	    for( const auto & e : targets )
    	{
	        // Look for target in the entire range.
	        int *result = const_cast<int*> (bsearch( std::begin(A), std::end(A), e ));

	        // Process the result
	        if ( result != std::end(A) )
	        {
	            std::cout << ">>> Found \"" << e << "\" at position "
	                      << std::distance(std::begin(A),result) << ".\n";
	        }
	        else
	        {
	            std::cout << ">>> Value \"" << e << "\" not found in array!\n";
	        }
   		}
   	#endif

    return 0;
}

/*#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()*/
#include "algorithmsearch.h"


// Driver function.
int main()
{
	Func *f_search[]{ 	
					linear_search,
					binary_search,
					recursive_binary_search,
					jump_search,
					ternary_search,
					recursive_ternary_search 
				}
    int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Data container.
    int targets[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -4, 20}; // Target values for testing.

    // Prints out the original data container.
    std::cout << "Array: [ ";
    std::copy( std::begin(A), std::end(A), std::ostream_iterator<int>( std::cout , " " ) );
    std::cout << "]\n";

    // Executes several searchs in the data container.
    
	std::cout << "SEACH JUMP"<< std::endl;
    for( const auto & e : targets )
    {
        // Look for target in the entire range.
        int *result = const_cast<int*> (f_search[0]( std::begin(A), std::end(A), e ));

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
	

    return 0;
}

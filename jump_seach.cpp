#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()
#include <cmath>

const int *jsearch(const int *first, const int *last, int value)
{
	const int *jumper = first;
	const int *aux = first;
	int tam_vector = std::distance(first, last);
	int tam_jump = sqrt(tam_vector);
	while(jumper < last){
		if (std::distance(jumper, last) < tam_jump)//Se o tamanho do salto é maior que a distancia
		{										  // entre o ponteiro jumper e o last, ele corrige o salto.
			tam_vector = std::distance(jumper, last);
			tam_jump = sqrt(tam_vector);
		}

		if (*jumper == value)
		{
			return jumper;
		}
		else{
			if (*jumper < value)
			{
				aux = jumper;
				jumper = jumper + tam_jump;
			}
			if (value < *jumper)
			{
				tam_vector = std::distance(aux+1, jumper);
				tam_jump = sqrt(tam_vector);
				jumper = aux + 1;
			}
		}

		if (jumper == last && value < *jumper)
		{
			return last;
		}

	}

return last;
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
    
	std::cout << "JUMP SEACH"<< std::endl;
    for( const auto & e : targets )
    {
        // Look for target in the entire range.
        int *result = const_cast<int*> (jsearch( std::begin(A), std::end(A), e ));

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
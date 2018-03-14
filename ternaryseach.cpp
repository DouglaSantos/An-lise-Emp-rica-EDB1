#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()

int *ternarysearch( int *first, int *last, int value )
{
	int *f = first, *l = last;
	int *mid1;
	int *mid2;	
	int tam_vector;
	while(tam_vector <= 0){
		tam_vector = std::distance(f, l);		
		//Calcula a primeira parte do vetor
		//std::cout << value << ": "<< tam_vector << std::endl;
		mid1 = f + ((int)(tam_vector/3));
		//Calcula a segunda parte do vetor 
		mid2 = l - ((int)(tam_vector/3));
		//Caso o value esteja em um dos meios encerra o metodo e retorna a posição
		if(value == *mid1){
			return mid1;
		}

		if (value == *mid2)
		{
			return mid2;
		}
		//Atualiza os indices f e l caso nao seja encontrado o elemento
		if (value < *mid1)
		{
			l = mid2;
		}
		if (*mid2 < value)
		{
			f = mid1 + 1;
		}
		if (*mid1 < value && value >*mid2)
		{
			f = mid1 + 1;
			l = mid2;
		}
	}	


    return last; // STUB
}


// Driver function.
int main()
{
    int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Data container.
    int targets[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , -4, 20 }; // Target values for testing.

    // Prints out the original data container.
    std::cout << "Array: [ ";
    std::copy( std::begin(A), std::end(A), std::ostream_iterator<int>( std::cout , " " ) );
    std::cout << "]\n";

    // Executes several searchs in the data container.
   
	std::cout << "SEACH BINARY"<< std::endl;
    for( const auto & e : targets )
    {
        // Look for target in the entire range.
        int *result = const_cast<int*> (ternarysearch( std::begin(A), std::end(A), e ));

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
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>

//BUSCA LINEAR ITERATIVA
const int *linear_search(const int *first, const int *last, int value);
//BUSCA BINARIA ITERATIVA
const int *binary_search(const int *first, const int *last, int value);
//BUSCA BINARIA RECURSIVA
const int *recursive_binary_search(const int *first, const int *last, int value);
//JUMP SEARCH
const int *jump_search(const int *first, const int *last, int value);
//BUSCA TERNARIA ITERATIVA
const int *ternary_search(const int *first, const int *last, int value);
//BUSCA TERNARIA RECURSIVA
const int *recursive_ternary_search(const int *first, const int *last, int value);


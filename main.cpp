#ifndef DYNAMIC_STACK_H
	#include "dstack.h"
#endif

// include on embarcadero #include <stdlib>
#include <iostream>

 int main(int argc, char* argv[])
{
	IStack<int*> *stack = factoryStack<int*>() ;

	int arrayToStack[ 10 ] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0 } ;
	for( int idx = 0 ; idx < 10 ; idx++ ) {
		stack->push( &arrayToStack[ idx ] ) ;
	}
	for( int idx = 0 ; idx < 10 ; idx++ ) {
		std::cout << stack->peek() << std::endl ;
		std::cout << stack->pop( ) << std::endl ;

	}
	for( int idx = 0 ; idx < 10 ; idx++ ) {
		stack->push( &arrayToStack[ idx ] ) ;
	}
	for( int idx = 0 ; idx < 10 ; idx++ ) {
		std::cout << *(stack->peek()) << std::endl ;
		std::cout << *(stack->pop()) << std::endl ;
	}

// if stdlib included:	system( "pause" ) ;
	delete stack ;
	return 10;
}

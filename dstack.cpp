#ifndef DYNAMIC_STACK_H
	#include "dstack.h"
#endif

// PRIVATE

// PUBLIC
template <class ItemType>
DStack<ItemType>::DStack( void ) {
	top = nullptr ;
	usedSpaces = 0 ;
}
template <class ItemType>
DStack<ItemType>::~DStack( void ) {
	while ( top != nullptr ) {
		usedSpaces-- ;
		Node *oldTop = top ;
		top = oldTop->next ;

		delete oldTop ;
	}
	if( top ) delete top ;
}

template <class ItemType>
void DStack<ItemType>::push( ItemType value ) {
	Node *newNode ;
	newNode = new Node() ;

	newNode->value = value ;

	Node *oldTop ;
	oldTop = top ;
	top = newNode ;
	top->next = oldTop ;

	usedSpaces++ ;
}
template <class ItemType>
ItemType DStack<ItemType>::pop( void ) {
	ItemType toReturn = NULL ;

	if( top != nullptr ) {
		usedSpaces-- ;

		Node *oldTop = top ;
		top = oldTop->next ;

		toReturn = oldTop->value ;

		delete oldTop ;
	}

	return toReturn ;
}
template <class ItemType>
ItemType DStack<ItemType>::peek( void ) {
	return top->value ;
}

template <class ItemType>
bool DStack<ItemType>::isEmpty( void ) {
	return ( usedSpaces == 0 ) ;
}
template <class ItemType>
size DStack<ItemType>::stackSize( void ) {
	return usedSpaces ;
}

template <class ItemType>
bool DStack<ItemType>::release( void ){ }
template <class ItemType>
bool DStack<ItemType>::appendRef( void ) { }
template<class ItemType>
bool DStack<ItemType>::delRef( void ) { }

template class DStack<int*> ;

//
// template specialization
//
template<>
class DStack<std::string>: IStack<std::string> {
   // to implement
};

#ifndef ISTACK_H
	#include "istack.h"
#endif

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#define nullptr 0
#define NULL 0

template <class ItemType>
class DStack: public IStack<ItemType> {
	private:
		struct Node {
			ItemType value ;
			Node *next ;

			Node( void ) {
				value = NULL ;
				next = nullptr ;
			}
			virtual ~Node( void ) {}

			private:
			Node ( const Node &node ) ;
			Node& operator= (const Node &node ) ;
		};

		Node *top ;

		size usedSpaces ;

		// copy constructor ;
		DStack(const DStack &stack ) ;
		// operator=
		DStack& operator=( const DStack& otherStack );

		//helpers
	public:
		DStack( void ) ;
		virtual ~DStack( void ) ;

		// métodos heredados de la interfaz
		virtual void push( ItemType value ) ;
		virtual ItemType pop( void ) ;
		virtual ItemType peek( void ) ;
		virtual bool isEmpty( void ) ;
		virtual size stackSize( void ) ;
		virtual bool release( void ) ;
		//
		virtual bool appendRef( void ) ;
   		virtual bool delRef( void ) ;
};

template <class ItemType>
IStack<ItemType>* factoryStack( void ) {
	return new DStack<ItemType> ;
}
#endif // STACK_H

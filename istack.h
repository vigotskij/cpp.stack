#ifndef ISTACK_H
#define ISTACK_H
typedef unsigned long size ;

template <class ItemType>
class IStack {
	public:
		virtual void push( ItemType value ) = 0 ;
		virtual ItemType pop( void ) = 0 ;
		virtual ItemType peek( void ) = 0 ;
		virtual bool isEmpty( void ) = 0 ;
		virtual size stackSize( void ) = 0 ;
		virtual bool release( void ) = 0 ;
		virtual bool appendRef( void ) = 0 ;
		virtual bool delRef( void ) = 0 ;
};

#endif // ISTACK_H

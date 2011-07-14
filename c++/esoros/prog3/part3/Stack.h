 /*  Eric Soros
  *  CS 33001
  *  April 10, 2011
  *  Prog3, Part3
  */ 
#ifndef Stack_H_
#define Stack_H_
#include <cassert>
#include <iostream>
////////////////////////////////////////////////////////////////////////////
//Declaration and Implementation for the Node class
template<typename T>
class Node
{
	public:
		Node(): data(),next(0){};	
		Node(T item): data(item),next(0){};
		T data;
		Node<T> * next;
};
////////////////////////////////////////////////////////////////////////////
//Implemenation for the Stack Class
template<typename T>
class Stack
{
	public:
		Stack():tos(0){};
		~Stack();
		Stack(const Stack<T>&);
		void swap(Stack<T>&);
		Stack<T>& operator=(Stack<T>);
		Node<T>* getTos() const {return tos;};
		void Push(T);
		T Pop();
		bool isEmpty() const {return tos == 0;};
		bool isFull() const {return false;}
		//I'm not to sure why I need a new typename, but we do. 
		template<typename U> friend std::ostream& operator<<(std::ostream&,const Stack<U>&);
	private:
		Node<T> * tos;
};
//Put an item on top of the Stack.
template <typename T> 
void Stack<T>::Push(T item)
{
	Node<T> * temp = new Node<T>(item);
	temp->next = tos;
	tos = temp;
}
//remove and return an item from the stack
template<typename T>
T Stack<T>::Pop()
{
	assert(!isEmpty());
	Node<T> * temp = tos;
	T result = temp->data;
	tos = tos->next;
	delete temp;
	return result;
}
//Destructor
template <typename T>
Stack<T>::~Stack()
{
	Node<T>* temp;
	while(tos != 0)
	{
		temp = tos;
		tos = tos->next;
		delete temp;
	}
}
//swap two stacks. Constant Time
template<typename T>
void Stack<T>::swap(Stack<T>& rhs)
{
	Node<T> * temp = tos;
	tos = rhs.tos;
	rhs.tos = temp;
}
//Copy Constructor
template <typename T>
Stack<T>::Stack(const Stack<T> & actual)
{
	Node<T> * temp = actual.tos;
	Node<T> * bottom;
	tos = 0;
	while(temp!= 0)
	{
		if (tos == 0)
		{
			tos = new Node<T>(temp->data);
			bottom = tos;
		}
		else
		{
			bottom-> next = new Node<T>(temp->data);
			bottom = bottom->next;
		}
     temp = temp->next;	
	}
}
//asignment operator
template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> rhs)
{
	swap(rhs);
	return *this;
}
//Print out all of the data in the Stack, from top to the bottom. 
template <typename U>
std::ostream& operator<<(std::ostream& out, const Stack<U>& rhs)
{
	Node<U> * temp = rhs.tos;
	while(temp != 0)
	{
		out << temp->data << std::endl;
		temp = temp->next;
	}	
	return out;
}
#endif 

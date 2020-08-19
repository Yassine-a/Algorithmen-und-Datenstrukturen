#ifndef _NODE_H
#define _NODE_H

template <typename T>
class Node
{
public:
	T key;
	Node<T> * next, * prev;
public:
	Node();
	Node(T key, Node<T> * next = 0, Node<T> * prev = 0);
	~Node();
};
template <typename T>
Node<T>::Node()
{
	next = 0;
	prev = 0;
}
template <typename T>
Node<T>::Node(T key, Node<T> * next, Node<T> * prev)
{
	this->key = key;
	this->next = next;
	this->prev = prev;
}
template <typename T>
Node<T>::~Node()
{
}


#endif
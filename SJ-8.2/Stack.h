#pragma once
#include<iostream>
using namespace std;

template <typename T> class Stack;

template <typename T>
class Node {
	friend class Stack<T>;
	T m_date;
	Node* m_next = nullptr;
public:
	Node(const T& val) :m_date(val) {}
	const T& date()const { return m_date; }
	Node* next() { return m_next; }
};

template <typename T>
class Stack {
	Node<T>* m_top = nullptr;
public:
	Stack() = default;
	Stack(const Stack&) = delete;
	Stack operator=(const Stack&) = delete;
	~Stack();
	void clear();
	void push(const T& val);
	void pop();
	bool empty()const { return m_top == nullptr; }
	const T& top() { return m_top->m_date; }
};

//进栈操作
template <typename T>
void Stack<T>::push(const T& val)
{
	Node<T>* node = new Node<T>(val);
	node->m_next = m_top;
	m_top = node;
}

//出栈操作
template<typename T>
void Stack<T>::pop()
{
	if (empty())
		return;
	Node<T>* p = m_top;
	m_top = m_top->m_next;
	delete p;
}

template<typename T>
void Stack<T>::clear()
{
	Node<T>* p = nullptr;
	while (m_top != nullptr)
	{
		p = m_top;
		m_top = m_top->m_next;
		delete p;
	}
}

template <typename T>
Stack<T>::~Stack()
{
	clear();
}
#pragma once
#include<iostream>
using namespace std;

template <typename T>
class MyVector
{
	T* m_arr;
	size_t m_size = 0;
public:
	MyVector(const T* arr = nullptr);

	MyVector(const size_t& size, const T& val = 0);		//���ι��캯��

	MyVector(const MyVector& vec);		//�������캯��

	MyVector(const MyVector&& vec);

	MyVector(const initializer_list<T>& l);	//�б��ʼ��

	MyVector<T>& operator=(const MyVector& vec);		//��ֵ�����

	MyVector<T>& operator=(const MyVector&& vec);

	~MyVector() { delete[]m_arr; }

	size_t& size();

	const T& operator[](size_t i);

	const T& at(size_t i);

	const T& front();

	const T& back();

	void push_back(const T& s);

	void pop_back();

	void insert(const size_t& a, const size_t& b, const T& s); //�ڵ�a���͵�b��a+1����Ԫ��֮�����s

	void erase(const size_t& a, const size_t& b);//ɾ����a�͵�b��a+2��֮���Ԫ��

	void clear() { m_size = 0; }

	void sort();

	size_t binary_search(const T& value);

};

template <typename T>
MyVector<T>::MyVector(const size_t& size, const T& val)
{
	m_size = size;
	m_arr = new T[m_size];
	for (int i = 0; i < m_size; ++i)
	{
		m_arr[i] = val;
	}
} 

template <typename T>
MyVector<T>::MyVector(const MyVector& vec)
{
	if (m_arr != vec.m_arr)
	{
		delete[]m_arr;
		m_size = vec.m_size;
		m_arr = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_arr[i] = vec.m_arr[i];
		}
	}
}

template <typename T>
MyVector<T>::MyVector(const MyVector&& vec)
{
	if (m_arr != vec.m_arr)
	{
		delete[]m_arr;
		m_size = vec.m_size;
		m_arr = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_arr[i] = vec.m_arr[i];
		}
	}
}

template <typename T>
MyVector<T>::MyVector(const initializer_list<T>& l)
{
	m_size = l.size();
	m_arr = new T[m_size];
	size_t i = 0;
	for (auto it = l.begin(); it != l.end(); it++)
	{
		m_arr[i] = *it;
		++i;
	}
};

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& vec)
{
	if (m_arr != vec.m_arr)
	{
		delete[]m_arr;
		m_size = vec.m_size;
		m_arr = new T[m_size];
		for (int i = 0; i < m_size; ++i)
		{
			m_arr[i] = vec.m_arr[i];
		}
	}
	return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector&& vec)
{
	if (m_arr != vec.m_arr)
	{
		delete[]m_arr;
		m_size = vec.m_size;
		m_arr = new T[m_size];
		for (int i = 0; i < m_size; ++i)
		{
			m_arr[i] = vec.m_arr[i];
		}
	}
	return *this;
}

template <typename T>
size_t& MyVector<T>::size()
{
	return m_size;
}

template <typename T>
const T& MyVector<T>::operator[](size_t i)
{
	if (i < m_size)
		return m_arr[i];
	else
		abort();
}

template <typename T>
const T& MyVector<T>::at(size_t i)
{
	if (i < m_size)
		return m_arr[i];
	else
		abort();
}

template <typename T>
const T& MyVector<T>::front()
{
	if (m_size == 0)
		abort();
	else
		return this->at(0);
}

template <typename T>
const T& MyVector<T>::back()
{
	if (m_size == 0)
		abort();              //�쳣�жϺ���
	else
		return this->at(m_size - 1);
}

template <typename T>
void MyVector<T>::push_back(const T& s)
{
	T* arr = new T[m_size + 1];
	for (int i = 0; i < m_size; i++)
	{
		arr[i] = m_arr[i];
	}
	arr[m_size] = s;
	delete[]m_arr;
	m_arr = arr;
	m_size++;
	arr = nullptr;
}

template <typename T>
void MyVector<T>::pop_back()
{
	if (m_size == 0)
		abort();
	else
	{
		T* arr = new T[m_size - 1];
		for (int i = 0; i < m_size - 1; i++)
		{
			arr[i] = m_arr[i];
		}
		delete[]m_arr;
		m_arr = arr;
		m_size--;
		arr = nullptr;
	}
}

template <typename T>
void MyVector<T>::insert(const size_t& a, const size_t& b, const T& s)
{
	if (a > 0 && b == a + 1 && b <= m_size)
	{
		T* arr = new T[m_size + 1];
		for (size_t i = 0; i < m_size + 1; i++)
		{
			if (i < a)
				arr[i] = m_arr[i];
			else if (i == a)
				arr[i] = s;
			else if (i > a)
				arr[i] = m_arr[i - 1];
		}
		delete[] m_arr;
		m_arr = arr;
		m_size++;
		arr = nullptr;
	}
	else
		abort();
}

template <typename T>
void MyVector<T>::erase(const size_t& a, const size_t& b)
{
	if (a > 0 && b == a + 2 && b <= m_size)
	{
		T* arr = new T[m_size - 1];
		for (size_t i = 0; i < m_size - 1; i++)
		{
			if (i < a)
				arr[i] = m_arr[i];
			else if (i >= a)
				arr[i] = m_arr[i + 1];
		}
		delete[] m_arr;
		m_arr = arr;
		m_size--;
		arr = nullptr;
	}
	else
		abort();
}

template <typename T>
void MyVector<T>::sort()
{
	for (int i = 0; i < m_size - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < m_size; ++j)
		{
			if (m_arr[j] < m_arr[min])
				min = j;
		}
		T  a = m_arr[i];
		m_arr[i] = m_arr[min];
		m_arr[min] = a;
	}
}

template <typename T>
size_t MyVector<T>::binary_search(const T& value)
{
	if (m_size > 0)
	{
		size_t left = 0;
		size_t	right = m_size - 1;
		while (left <= right)
		{
			size_t middle = (left + right) / 2;
			if (m_arr[middle] == value)
				return middle + 1;
			else if (m_arr[middle] > value)
				right = middle - 1;
			else
				left = middle + 1;
		}
		return -1;
	}
	else
		abort();
}
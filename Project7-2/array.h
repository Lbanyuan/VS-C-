#include <iostream>
using namespace std;
template<typename T>
struct Less 
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

template <typename T=int,size_t N=10>
class Array
{
	T m_ele[N];
public:
	Array() {};
	Array(const std::initializer_list<T>& list);
	T& operator[](size_t i);
	constexpr size_t size()
	{
		return N;
	}

	template<typename F=Less<T>>
	void selectSort(F f = F());

	template<typename F = Less<T>>
	void insertSort(F f = F());

	template<typename F = Less<T>>
	void bubbleSort(F f = F());
private:
	void swap(int i,int j)
	{
		T t = m_ele[i];
		m_ele[i] = m_ele[j];
		m_ele[j] = t;
	}

};

template <typename T,size_t N>
Array<T, N>::Array(const std::initializer_list<T>& list) :m_ele{ T() }
{
	size_t m = list.size() < N ? list.size() : N;
	for (size_t i = 0; i < m; i++)
	{
		m_ele[i] = *(list.begin() + i);
	}
}

template <typename T, size_t N>
T& Array<T,N>::operator[](size_t i)
{
	return m_ele[i];
}

template <typename T, size_t N>
template<typename F >
void Array<T,N>::selectSort(F f)
{
	for (int i = 0; i < N - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < N; ++j)
		{
			if (f(m_ele[j], m_ele[min]))
				min = j;
		}
		swap(i, min);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << m_ele[i];
	}
}
template <typename T, size_t N>
template<typename F >
void Array<T, N>::insertSort(F f)
{
	for (int i = 1, j; i < N; ++i)
	{
		T t = m_ele[i];
		for(j=i;j>0;--j)
		{
			if (f(m_ele[j - 1], t)) break;
			m_ele[j] = m_ele[j - 1];
		}
		m_ele[j] = t;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << m_ele[i];
	}
}

template <typename T, size_t N>
template<typename F >
void Array<T, N>::bubbleSort(F f)
{
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j <= i - 1; ++j)
		{
			if (f(m_ele[j + 1], m_ele[j]))
			{
				swap(j, j + 1);
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << m_ele[i];
	}
}

#ifndef SET_H
#define SET_H


#include<iostream>
#include<vector>
using namespace std;

class Set
{
	vector<char>m_elems;
public:
	Set()= default; //有复制构造函数时依然可以使用默认构造函数
	Set(const vector<char>& elem);
	bool is_elem(char chr );
	void insert(char chr);
	void erase(char chr);
	Set& operator=(const Set& s);
	Set(const Set& s);
	friend ostream& operator<<(ostream& os, const Set& b);
	friend Set common(const Set& a, const Set& b);
	friend Set sum(const Set& a, const Set& b);
};

	Set::Set(const vector<char>& elem) :m_elems(elem) {};// 构造函数
    bool Set::is_elem(char chr)
{
	for (auto it = m_elems.begin(); it != m_elems.end(); ++it)
	{
		if (*it != chr)
		{
			continue;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
    void Set::insert(char chr)
{
	if (is_elem(chr))
		;
	else
	m_elems.push_back(chr);
}
	void Set::erase(char chr)
	{
		if (is_elem(chr))
		{
			for (auto it = m_elems.begin(); it != m_elems.end(); ++it)
			{
				if (*it == chr)
				{
					m_elems.erase(it);
					break;
				}	
			}	
		}
	}
	Set& Set::operator=(const Set& s)
	{
		m_elems = s.m_elems;
		return *this;
	}
	Set::Set(const Set& s):m_elems(s.m_elems){}//复制构造函数
	
	ostream& operator<<(ostream& os, const Set& s);
	ostream& operator<<(ostream& os, const Set& s)
	{
		os << "{";
		for (auto it = s.m_elems.begin(); it != s.m_elems.end(); ++it)
		{
			if (it != s.m_elems.end() - 1)
				os << *it << ',';
			else
				os << *it;
		}
		os << "}";
		return os;
	}

	Set common(const Set& a, const Set& b);
	Set common(const Set& a, const Set& b)
	{
		Set s;
		for (auto it1 = a.m_elems.begin(); it1 != a.m_elems.end(); ++it1)
		{
			for (auto it2 = b.m_elems.begin(); it2 != b.m_elems.end(); ++it2)
			{
				if (*it1 == *it2)
				{
					s.m_elems.push_back(*it1);
					break;
				}
			}
		}
		return s;
	}

	Set sum(const Set& a, const Set& b);
	Set sum(const Set& a, const Set& b)
	{
		Set s(a);
		for (auto it = b.m_elems.begin(); it != b.m_elems.end(); ++it)
		{
			if (s.is_elem(*it))
			{
				continue;
			}
			else
			{
				s.m_elems.push_back(*it);
			}
		}
		return s;
	}

#endif 


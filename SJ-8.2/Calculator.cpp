#include "Calculator.h"

using namespace std;

int Calculator::precedence(const char& a, const char & b) const {
	int i, j;
	int pre[13][13] = {                       //定义运算符之间的优先级
		{1,1,1,1,0,0,0,1,1,1,1,1,1},
		{1,1,1,1,0,0,0,1,1,1,1,1,1},
		{0,0,1,1,0,0,0,1,1,1,1,1,1},
		{0,0,1,1,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,1,1,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,1,1,1,1},
	};
	switch (a) {
	case '+': i = 0; break;
	case '-': i = 1; break;
	case '*': i = 2; break;
	case '/': i = 3; break;
	case '(': i = 4; break;
	case '#': i = 5; break;
	case '=': i = 6; break;
	case '%': i = 7; break;
	case '^': i = 8; break;
	case 'i': i = 9; break;
	case 'o': i = 10; break;
	case 'a': i = 11; break;	
	case 'q': i = 12; break;
	}
	switch (b) {
	case '+': j = 0; break;
	case '-': j = 1; break;
	case '*': j = 2; break;
	case '/': j = 3; break;
	case '(': j = 4; break;
	case '#': j = 5; break;
	case '=': j = 6; break;
	case '%': j = 7; break;
	case '^': j = 8; break;
	case 'i': j = 9; break;
	case 'o': j = 10; break;
	case 'a': j = 11; break;
	case 'q': j = 12; break;
	}
	return pre[i][j];
}

double Calculator::readNum(string::const_iterator &it){
	string num;
	while (isNum(it))
		num += *it++;
	return stod(num);
}

void Calculator::calculate(){
	if (m_opr.top() >= 0 && m_opr.top() <= 96)
	{
			double b = m_num.top();
			m_num.pop();
			double a = m_num.top();
			m_num.pop();
			if (m_opr.top() == '+')
				m_num.push(a + b);
			else if (m_opr.top() == '-')
				m_num.push(a - b);
			else if (m_opr.top() == '*')
				m_num.push(a * b);
			else if (m_opr.top() == '/')
				m_num.push(a / b);
			else if (m_opr.top() == '%')
				m_num.push((int)a % (int)b);
			else if (m_opr.top() == '^')
				m_num.push(pow(a, b));
			m_opr.pop();
	}
	else
	{
		double b = m_num.top();
			m_num.pop();
		if (m_opr.top() == 'i')
			m_num.push(sin(b));
		else if(m_opr.top() == 'o')
			m_num.push(cos(b));
		else if (m_opr.top() == 'a')
			m_num.push(tan(b));
		else if (m_opr.top() == 'q')
			m_num.push(sqrt(b));
		m_opr.pop();
	}
}

double Calculator::doIt(const string & exp){
	m_num.clear();
	for (auto it = exp.begin(); it != exp.end();) {
		if (isNum(it))
		m_num.push(readNum(it));
		else
		{
			if (*it <97 ||*it>122)
			{
				if (*it != ')')
				{
					while (precedence(*it, m_opr.top())) {
						if (m_opr.top() == '#')
							break;
						calculate();
					}
					if (*it != '=')
						m_opr.push(*it);
					++it;
				}
				else {
					while (m_opr.top()!='(') {
						if (m_opr.top() == '#')
							break;
						calculate();
					}
					m_opr.pop();
					++it;
				}
			}
			else
			{
				string ch;
				while (*it >= 97 && *it <= 122)
				{
					ch += *it;
					it++;
				}
				const char* p = ch.c_str();
				while (precedence(*(p + 1), m_opr.top())) {
					if (m_opr.top() == '#')
						break;
					calculate();
				}
				if (*it != '=')
					m_opr.push(*(p+1));
			}
		}
	}
	return m_num.top();
}

class X
{
	void* m_p = nullptr; //void类型的指针可以指向任何对象
public:
	template<typename T>
	void reset(T * p) //模板自动推断实参类型
	{
		m_p = p;
	}
};

int main()
{
	int i = 0;
	X x;
	x.reset(&i);
	double b =0;
	x.reset(&b);
}
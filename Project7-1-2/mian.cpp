class X
{
	void* m_p = nullptr; //void���͵�ָ�����ָ���κζ���
public:
	template<typename T>
	void reset(T * p) //ģ���Զ��ƶ�ʵ������
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
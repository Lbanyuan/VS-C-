#include "CurriculumDesign.h"

int main()
{
	Student si[100];
	Credit ci;
	while(1)
	{
		Read(si,ci);
		switch (menu())
		{
		case 1:
			Delete(si);
			system("pause");
			break;
		case 2:
			Entergrade(si);
			system("pause");
			break;
		case 3:
			Revise(si);
			system("pause");
			break;
		case 4:
			Add(si);
			system("pause");
			break;
		case 5:
			Find(si);
			system("pause");
			break;
		case 6:

			system("pause");
			break;
		case 7:
			 Statistics( si);
			system("pause");
			break;
		case 0:
			cout << endl << "================��л��ʹ��ѧ���ɼ�����ϵͳ==============\n" << endl;
			exit(0);
		}
	}
	return 0;
}
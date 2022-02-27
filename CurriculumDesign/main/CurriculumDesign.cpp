#include "CurriculumDesign.h"
#include <sstream>
#include <iomanip>
#include<cmath>


int menu()
{
	int c;
	do {
		system("cls");
		cout << "******************************************************" << endl;
		cout << "    *" << setw(28) << "��1��ɾ��ѧ����Ϣ" << setw(16) << "*    " << endl;
		cout << "    *" << setw(24) << "��2���ɼ�¼��" << setw(20) << "*    " << endl;
		cout << "    *" << setw(24) << "��3���ɼ��޸�" << setw(20) << "*    " << endl;
		cout << "    *" << setw(24) << "��4���ɼ����" << setw(20) << "*    " << endl;
		cout << "    *" << setw(20) << "��5������" << setw(24) << "*    " << endl;
		cout << "    *" << setw(20) << "��6������" << setw(24) << "*    " << endl;
		cout << "    *" << setw(20) << "��7��ͳ��" << setw(24) << "*    " << endl;
		cout << "    *" << setw(28) << "��0���˳�����ϵͳ" << setw(16) << "*    " << endl;
		cout << "******************************************************" << endl;
		cout << "��ѡ�����Ĳ��� (0-7):" << endl;
		cin >> c;
	} while (c < 0 || c >7);
	return (c);
}

void Read(Student si[],Credit & ci)
{
	Enterinf(si);
	Entergrade(si);
	Entercredit(ci);
	Readcredit(si, ci);
	ofstream out("newfile.txt");
	if (out)
	{
		out << "";
		out.close();
	}
}
void Entergrade(Student si[])
{

	int i = 1;
	int j = 0;
	string a;
	//�����ļ�·��
	string strFile = "score.txt";			    /*�ļ�·��*/
	ifstream FileIn(strFile, ifstream::in);		 //����һ���ļ���
	string strLine;								//��ȡһ�б����������ݵ����string
	while (getline(FileIn, strLine))			//ѭ����ȡ����
	{
		istringstream StringIn;					//����һ��string��
		StringIn.str(strLine);					//��strLine������StringIn��
		if (strLine == "#END")					//������������
		{
			break;
		}

		StringIn >> a;
		if (a == "#ѧ��")
			continue;
		if (a == "#END")
			break;
		if (a == si[i].m_ID)
		{
			StringIn >> a >> si[i].m_course[j] >> si[i].m_grade[j];
			j++;
		}
		else
		{
			j = 0;
			i++;
			StringIn >> a >> si[i].m_course[j] >> si[i].m_grade[j];
			j++;
		}
	}

}
void Enterinf(Student si[])
{
	int i = 0;
	//�����ļ�·��
	string strFile = "student.txt";			    /*�ļ�·��*/
	ifstream FileIn(strFile, ifstream::in);		 //����һ���ļ���
	string strLine;								//��ȡһ�б����������ݵ����string
	while (getline(FileIn, strLine))			//ѭ����ȡ����
	{
		istringstream StringIn;					//����һ��string��
		StringIn.str(strLine);					//��strLine������StringIn��
		if (strLine == "#END")					//������������
		{
			break;
		}

		StringIn >> si[i].m_ID >> si[i].m_name >> si[i].m_classes >> si[i].m_major;
		i++;
	}
}
void Entercredit(Credit& ci)
{
	int i = 0;
	string a;
	//�����ļ�·��
	string strFile = "module.txt";			    /*�ļ�·��*/
	ifstream FileIn(strFile, ifstream::in);		 //����һ���ļ���
	string strLine;								//��ȡһ�б����������ݵ����string
	while (getline(FileIn, strLine))			//ѭ����ȡ����
	{
		istringstream StringIn;					//����һ��string��
		StringIn.str(strLine);					//��strLine������StringIn��
		if (strLine == "#END")					//������������
		{
			break;
		}
		StringIn >> a;
		if (a == "#�γ̱��")
		continue;
		StringIn >> ci.m_course[i] >> ci.m_credit[i];
		i++;
	}
}
void Readcredit(Student si[], Credit ci)
{
	for (int i = 1; i <= 99; i++)
	{
		for (int j = 0; si[i].m_course[j] != "1"; j++)
		{
			for (int n = 0; n <= 24; n++)
			{
				if (si[i].m_course[j] == ci.m_course[n] && si[i].m_grade[j] >= 60)
				{
					si[i].m_completedcredits += ci.m_credit[n];
					break;
				}
			}
		}
	}
	for (int i = 1; i <= 99; i++)
	{
		int n = 0;
		for (int j = 0; si[i].m_course[j] != "1"; j++)
		{
			if (si[i].m_grade[j] < 60)
				n++;
		}
		si[i].m_failingcourse = n;
	}
}


void outgrade(Student si[])
{
	ofstream out("score.txt");
	if (out)
	{
		out << "#ѧ��" << setw(10) << "����" << setw(10) << "�γ�" << setw(10) << "�ɼ�" << endl;
		int i = 1;
		while (i <= 99)
		{
			for (int j = 0; si[i].m_course[j] != "1"; j++)
				out << si[i].m_ID << "  " << si[i].m_name << "  " << si[i].m_course[j] << "  " << si[i].m_grade[j] << endl;
			i++;
		}
		out << "#END";
		out.close();
	}

}

void Delete(Student si[])
{
			string name, sure;
			cout << "��������Ҫɾ����ѧ������:";
			cin >> name;
			for (int i = 0; i <= 99; i++)
			{
				if (si[i].m_name == name)
				{
					cout << "#ѧ��(ID)" << "\t" << "����" << "\t" << "�༶" <<"\t" << "רҵ" << endl;
					cout << si[i].m_ID << "  " << si[i].m_name << "      " << si[i].m_classes << "     " << si[i].m_major << endl;
					break;
				}
				if (i == 99)
					cout << "δ�ҵ���ѧ����Ϣ" << endl;
			}
		cout << "�Ƿ�ȷ��ɾ����ѧ����Ϣ(Y/N):";
		cin >> sure;
		if (sure == "y" || sure == "Y")
		{
			{
				ofstream out("student.txt");
				if (out)
				{
					out << setw(10) << "#ѧ��(ID)" << setw(10) << "����" << setw(10) << "�༶" << setw(10) << "רҵ" << endl;
					int i = 1;
					while (i <= 99)
					{
						if (si[i].m_name != name)
							out << setw(10) << si[i].m_ID << setw(10) << si[i].m_name << setw(10) << si[i].m_classes << setw(15) << si[i].m_major << endl;
						i++;
					}
					out.close();
				}
			}

			{
				ofstream out("score.txt");
				if (out)
				{
					out  << "#ѧ��" << setw(10) << "����" << setw(10) << "�γ�" << setw(10) << "�ɼ�" << endl;
				}
				int i = 1;
				while (i <= 99)
				{
					if (si[i].m_name != name)
						for (int j = 0; si[i].m_course[j] != "1"; j++)
							out  << si[i].m_ID << "  " << si[i].m_name << "  " << si[i].m_course[j] << "  " << si[i].m_grade[j] << endl;
					i++;
				}
				out << "#END";
				out.close();
			}
		}
}

void Revise(Student si[])
{
	string name;
	cout << "������Ҫ�޸ĳɼ���ѧ����������";
	cin >> name;
	int i,n=0;
	for (i = 1; i <= 99; i++)
	{
		if (si[i].m_name == name)
		{
			for ( int j = 0; si[i].m_course[j] != "1"; j++)
			cout << si[i].m_course[j] << ":" << si[i].m_grade[j] << endl;
			n = i;
			break;
		}
	}
	string course;
	double grade;
	cout << "������Ҫ�޸ĵĿ�Ŀ�����ƺͳɼ�:";
	cin >> course>>grade;
	int j = 0;
	for (int j=0;j<=99; j++)
	{
		if (si[n].m_course[j] == course)
		{
			si[n].m_grade[j] = grade;
			cout << "�޸ĳɹ�!"<<endl;
			outgrade(si);
			break;
		}
	}
}

void Add(Student si[])
{
	string name,course;
	double grade;
	cout << "��������Ҫ���ӿ�Ŀ��ѧ�������֣�";
	cin >> name;
	cout << "��������Ҫ���ӵĿγ����ƺͳɼ���";
	cin >> course >> grade;
	for (int i = 1; i <= 99; i++)
	{
		if (si[i].m_name == name)
		{
			for (int j = 0; j <= 99; j++)
			{
				if (si[i].m_course[j] == "1")
				{
					si[i].m_course[j] = course;
					si[i].m_grade[j] =grade;
					break;
				}
			}
			outgrade(si);
			cout << "��ӳɹ���";
			break;
		}
	}
}

void Find(Student si[])
{
	cout  << "(a)������������ĳѧ�������пγ̳ɼ���Ϣ��" << endl;
	cout  << "(b)���ݰ�Ų���ĳ��������ѧ������ѧ�γ̵ĳɼ���Ϣ��" << endl;
	cout  << "(c)���ݿγ�������ѡ�޸��ſ�����ѧ���ĳɼ���Ϣ��" << endl;
	cout  << "(d)��������ѧ������ѡ�γ̵ĳɼ���Ϣ��"<<endl;		
	char choice;
	do
	{
		cout << "��ѡ����Ҫ���ҵķ�ʽ(a/b/c/d)��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 97:
			finda(si);
			break;
		case 98:
			findb(si);
			break;
		case 99:
			findc(si);
			break;
		case 100:
			findd(si);
			break;
		default:
			cout << "������(a/b/c/d):";
		}
	} while (97 > choice&& choice >100);
}
void finda(Student si[])
{
	string name;
	cout << "������Ҫ���ҵ�ѧ����������" << endl;
	cin >> name;
	for (int i = 1; i <= 99; i++)
	{
		if (si[i].m_name == name)
		{
			for (int j = 0; si[i].m_course[j] != "1"; j++)
			cout << si[i].m_course[j] << ":" << si[i].m_grade[j] << endl;
			break;
		}
	}

}
void findb(Student si[])
{
	string classes,choice;
	cout << "������Ҫ���ҵİ༶��:" << endl;
	cin >> classes;
	cout << "�Ƿ�����ѧ������(y/n)" << endl;
	cin >> choice;
	if (choice == "y" || choice == "Y")
	{
		vector<int>n(100, 0);

		for (int m = 1, j = 0; m <= 99; m++, j++)
		{
			double maxcredit = 0;
			for (int i = 1; i <= 99; i++)
			{
				if (si[i].m_classes == classes)
				{
					if (judge(n, i))
					{
						if (si[i].m_completedcredits >= maxcredit)
						{
							maxcredit = si[i].m_completedcredits;
							n[j] = i;
						}
					}
				}
			}
		}

		for (int i = 0; n[i] != 0; i++)
		{
			cout << si[n[i]].m_name << ":" << "�����ѧ��" << si[n[i]].m_completedcredits << endl;
			for (int j = 0; si[n[i]].m_course[j] != "1"; j++)
				cout << si[n[i]].m_course[j] << ":" << si[n[i]].m_grade[j] << endl;
			cout << endl;
		}
		ofstream out("newfile.txt");
		if (out)
		{
			for (int i = 0; n[i] != 0; i++)
			{
				out << si[n[i]].m_name << ":" << "�����ѧ��" << si[n[i]].m_completedcredits << endl;
				for (int j = 0; si[n[i]].m_course[j] != "1"; j++)
					out << si[n[i]].m_course[j] << ":" << si[n[i]].m_grade[j] << endl;
				out << endl;
			}
			cout << "#END";
			out.close();
		}
	}
	else
	{
		vector<int>n(100, 0);
		for (int k = 1, m = 0; k <= 99; k++, m++)
		{
			string ID = "0";
			for (int i = 1; i <= 99; i++)
			{
				if (judge(n, i))
				{
					if (si[i].m_ID >= ID)
					{
						ID = si[i].m_ID;
						n[m] = i;
					}
				}
			}
		}
		for (int i = 0; n[i] != 0; i++)
		{
			if (si[n[i]].m_classes==classes)
			{
				cout << si[n[i]].m_ID<<" "<<si[n[i]].m_name << ":" << "�����ѧ��" << si[n[i]].m_completedcredits << endl;
				for (int j = 0; si[n[i]].m_course[j] != "1"; j++)
					cout << si[n[i]].m_course[j] << ":" << si[n[i]].m_grade[j] << endl;
				cout << endl;
			}
		}
		ofstream out("newfile.txt");
		if (out)
		{
			for (int i = 0; n[i] != 0; i++)
			{
				if (si[n[i]].m_classes == classes)
				{
					out << si[n[i]].m_ID << " " << si[n[i]].m_name << ":" << "�����ѧ��" << si[n[i]].m_completedcredits << endl;
					for (int j = 0; si[n[i]].m_course[j] != "1"; j++)
						out << si[n[i]].m_course[j] << ":" << si[n[i]].m_grade[j] << endl;
					out << endl;
				}
			}
			cout << "#END";
			out.close();
		}
	}
}
void findc(Student si[])
{
	string course,choice;
	cout << "������Ҫ��ѯ�Ŀγ����ƣ�" << endl;
	cin >> course;
	cout << "�Ƿ񰴸ߵͳɼ�����(y/n)" << endl;
	cin >> choice;
	if (choice == "y" || choice == "Y")
	{
		vector<int>n(100, 0);
		vector<int>m(100, 0);
		for (int k = 1, t = 0; k <= 99; k++, t++)
		{
			double maxgrade = 0;
			for (int i = 1; i <= 99; i++)
			{
				if (judge(n, i))
				{
					for (int j = 0; si[i].m_course[j] != "1"; j++)
					{
						if (si[i].m_course[j] == course)
						{
							if (si[i].m_grade[j] >= maxgrade)
							{
								maxgrade = si[i].m_grade[j];
								n[t] = i;
								m[t] = j;
							}
						}
					}
				}
			}
		}
		for (int i = 1; n[i] != 0; i++)
		{
			cout << si[n[i]].m_name << ":" << si[n[i]].m_grade[m[i]] << endl;
		}
		ofstream out("newfile.txt");	
			if (out)
			{
				for (int i = 1; n[i] != 0; i++)
				{
					out << si[n[i]].m_name << ":" << si[n[i]].m_grade[m[i]] << endl;
				}
				out.close();
			}
	}
	else
	{ 
		vector<int>n(100, 0);
		for (int k = 1,m=0; k <= 99; k++,m++)
		{
			string ID = "0";
			for (int i = 1; i <= 99; i++)
			{
				if (judge(n, i))
				{
					if (si[i].m_ID >= ID)
					{
						ID = si[i].m_ID;
						n[m] = i;
					}
				}
			}
		}
		for (int i = 0; i <= 99; i++)
		{
			for (int j = 0; si[i].m_course[j] != "1"; j++)
			{
				if (si[n[i]].m_course[j] == course)
				{
					cout <<si[n[i]].m_ID<<" "<< si[n[i]].m_name<<":" << si[i].m_grade[j] << endl;
				}
			}
		}
		ofstream out("newfile.txt");
		if (out)
		{
			for (int i = 0; i <= 99; i++)
			{
				for (int j = 0; si[i].m_course[j] != "1"; j++)
				{
					if (si[n[i]].m_course[j] == course)
					{
						out << si[n[i]].m_ID << " " << si[n[i]].m_name << ":" << si[i].m_grade[j] << endl;
					}
				}
			}
			out << "#END" << endl;
			out.close();
		}
	}
}
void findd(Student si[])
{
	string choice;
	cout << "�Ƿ�������ѧ������?(y/n)"<<endl;
	cin >> choice;
	if (choice == "y" || choice == "Y")
	{
		vector<int>n(100, 0);
		for (int m = 1, j = 0; m <= 99; m++, j++)
		{
			double maxcredit = 0;
			for (int i = 1; i <= 99; i++)
			{
				if (judge(n, i))
				{
					if (si[i].m_completedcredits >= maxcredit)
					{
						maxcredit = si[i].m_completedcredits;
						n[j] = i;
					}
				}
			}
		}
		for (int i = 0; n[i] != 0; i++)
		{
			if (si[n[i]].m_course[0] != "1")
			{
				cout << si[n[i]].m_name << ":" << "�����ѧ��" << si[n[i]].m_completedcredits << endl;
				for (int j = 0; si[n[i]].m_course[j] != "1"; j++)
					cout << si[n[i]].m_course[j] << ":" << si[n[i]].m_grade[j] << endl;
				cout << endl;
			}
		}
		ofstream out("newfile.txt");
		if (out)
		{
			for (int i = 0; n[i] != 0; i++)
			{
				if (si[n[i]].m_course[0] != "1")
				{
					out << si[n[i]].m_name << ":" << "�����ѧ��" << si[n[i]].m_completedcredits << endl;
					for (int j = 0; si[n[i]].m_course[j] != "1"; j++)
						out << si[n[i]].m_course[j] << ":" << si[n[i]].m_grade[j] << endl;
				}
				out << endl;
			}
			cout << "#END";
			out.close();
		}
	}
	else
	{
		vector<int>n(100, 0);
		for (int k = 1, m = 0; k <= 99; k++, m++)
		{
			string ID = "0";
			for (int i = 1; i <= 99; i++)
			{
				if (judge(n, i))
				{
					if (si[i].m_ID >= ID)
					{
						ID = si[i].m_ID;
						n[m] = i;
					}
				}
			}
		}
		for (int i = 0; n[i] != 0; i++)
		{
			if (si[n[i]].m_course[0] != "1")
			{
				cout <<si[n[i]].m_ID<<" "<< si[n[i]].m_name << ":" << "�����ѧ��" << si[n[i]].m_completedcredits << endl;
				for (int j = 0; si[n[i]].m_course[j] != "1"; j++)
					cout << si[n[i]].m_course[j] << ":" << si[n[i]].m_grade[j] << endl;
				cout << endl;
			}
		}
		ofstream out("newfile.txt");
		if (out)
		{
			for (int i = 0; n[i] != 0; i++)
			{
				if (si[n[i]].m_course[0] != "1")
				{
					out << si[n[i]].m_ID << " " << si[n[i]].m_name << ":" << "�����ѧ��" << si[n[i]].m_completedcredits << endl;
					for (int j = 0; si[n[i]].m_course[j] != "1"; j++)
					out << si[n[i]].m_course[j] << ":" << si[n[i]].m_grade[j] << endl;
					out << endl;
				}
			}
			out << "#END";
			out.close();
		}
	}
}
int judge(vector<int>n,int i)
{
	for (int j = 0; j <= 99; j++)
	{
		if (n[j] == i)
			return 0;
	}
	return 1;
}

void Statistics(Student si[])
{
	char choice;
	cout << "(a)ͳ�Ƴɼ�" << endl;
	cout << "(b)ͳ��ѧ�ֺ�δ��ɿγ�" << endl;
	cout << "��ѡ��ͳ�Ʒ�ʽ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 97:
		statistics1(si);
		break;
	case 98:
		statistics2(si);
		break;
	}
}
void statistics1(Student si[])
{
	string classes, course;
	cout << "��������Ҫͳ�Ƶİ༶�ţ�" << endl;
	cin >> classes;
	cout << "��������Ҫͳ�ƵĿγ̣�" << endl;
	cin >> course;
	double grade = 0;
	int n = 0, m = 0;
	vector<string>name(100, "0");
	for (int i = 1; i <= 99; i++)
	{
		if (si[i].m_classes == classes)
		{
			for (int j = 0; si[i].m_course[j] != "1"; j++)
			{
				if (si[i].m_course[j] == course)
				{
					grade += si[i].m_grade[j];
					n++;
					if (si[i].m_grade[j] < 60)
					{
						name[m] = si[i].m_name;
						m++;
					}
					break;
				}
			}
		}
	}
	double Grade = grade / n;
	cout << "�ÿγ̵�ƽ���ɼ�Ϊ��" << Grade << endl;
	cout << "���ſγ̲�����ѧ��Ϊ��" << endl;;
	if (name[0] != "0")
	{
		for (int i = 0; name[i] != "0"; i++)
			cout << name[i] << endl;
	}
	else
		cout << "�ÿγ�û�в�����ѧ��" << endl;
	double grade1 = 0;
	int k=0;
	for (int i = 1; i <= 99; i++)
	{
		if (si[i].m_classes == classes)
		{
			for (int j = 0; si[i].m_course[j] != "1"; j++)
			{
				if (si[i].m_course[j] == course)
				{
					grade1 += (si[i].m_grade[j] - Grade) * (si[i].m_grade[j] - Grade);
					k++;
					break;
				}
			}
		}
	}
	cout << "���༶�ÿγ̷���Ϊ��" << sqrt(grade1 / n) <<endl;
	cout << "���༶�ÿγ̺ϸ���Ϊ��" << (double(n - m) /double (n))*100 << "%" << endl;
}
void statistics2(Student si[])
{
	cout << "ÿ��ѧ����ɵ���ѧ�֡�������γ�����δ��ѧ��������£�" << endl;
	for (int i = 1; i <= 99&&si[i].m_course[0]!="1"; i++)
	{
		double nocredit = 0;
		if (si[i].m_completedcredits < si[i].m_Requiredcredits)
			nocredit = si[i].m_Requiredcredits - si[i].m_completedcredits;
		cout << si[i].m_name << ":" << endl;
		cout << "\t" << "�����ѧ�֣�" << si[i].m_completedcredits << "      " << "������γ���:"<<si[i].m_failingcourse<<"\t"<<"δ��ѧ�֣�"<<nocredit<<endl;
	}
}

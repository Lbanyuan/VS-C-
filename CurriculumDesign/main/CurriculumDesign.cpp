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
		cout << "    *" << setw(28) << "【1】删除学生信息" << setw(16) << "*    " << endl;
		cout << "    *" << setw(24) << "【2】成绩录入" << setw(20) << "*    " << endl;
		cout << "    *" << setw(24) << "【3】成绩修改" << setw(20) << "*    " << endl;
		cout << "    *" << setw(24) << "【4】成绩添加" << setw(20) << "*    " << endl;
		cout << "    *" << setw(20) << "【5】查找" << setw(24) << "*    " << endl;
		cout << "    *" << setw(20) << "【6】排序" << setw(24) << "*    " << endl;
		cout << "    *" << setw(20) << "【7】统计" << setw(24) << "*    " << endl;
		cout << "    *" << setw(28) << "【0】退出管理系统" << setw(16) << "*    " << endl;
		cout << "******************************************************" << endl;
		cout << "请选择您的操作 (0-7):" << endl;
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
	//定义文件路径
	string strFile = "score.txt";			    /*文件路径*/
	ifstream FileIn(strFile, ifstream::in);		 //定义一个文件流
	string strLine;								//读取一行保存整行数据到这个string
	while (getline(FileIn, strLine))			//循环读取数据
	{
		istringstream StringIn;					//定义一个string流
		StringIn.str(strLine);					//将strLine拷贝到StringIn中
		if (strLine == "#END")					//读到空行跳出
		{
			break;
		}

		StringIn >> a;
		if (a == "#学号")
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
	//定义文件路径
	string strFile = "student.txt";			    /*文件路径*/
	ifstream FileIn(strFile, ifstream::in);		 //定义一个文件流
	string strLine;								//读取一行保存整行数据到这个string
	while (getline(FileIn, strLine))			//循环读取数据
	{
		istringstream StringIn;					//定义一个string流
		StringIn.str(strLine);					//将strLine拷贝到StringIn中
		if (strLine == "#END")					//读到空行跳出
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
	//定义文件路径
	string strFile = "module.txt";			    /*文件路径*/
	ifstream FileIn(strFile, ifstream::in);		 //定义一个文件流
	string strLine;								//读取一行保存整行数据到这个string
	while (getline(FileIn, strLine))			//循环读取数据
	{
		istringstream StringIn;					//定义一个string流
		StringIn.str(strLine);					//将strLine拷贝到StringIn中
		if (strLine == "#END")					//读到空行跳出
		{
			break;
		}
		StringIn >> a;
		if (a == "#课程编号")
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
		out << "#学号" << setw(10) << "姓名" << setw(10) << "课程" << setw(10) << "成绩" << endl;
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
			cout << "请输入你要删除的学生姓名:";
			cin >> name;
			for (int i = 0; i <= 99; i++)
			{
				if (si[i].m_name == name)
				{
					cout << "#学号(ID)" << "\t" << "姓名" << "\t" << "班级" <<"\t" << "专业" << endl;
					cout << si[i].m_ID << "  " << si[i].m_name << "      " << si[i].m_classes << "     " << si[i].m_major << endl;
					break;
				}
				if (i == 99)
					cout << "未找到该学生信息" << endl;
			}
		cout << "是否确定删除该学生信息(Y/N):";
		cin >> sure;
		if (sure == "y" || sure == "Y")
		{
			{
				ofstream out("student.txt");
				if (out)
				{
					out << setw(10) << "#学号(ID)" << setw(10) << "姓名" << setw(10) << "班级" << setw(10) << "专业" << endl;
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
					out  << "#学号" << setw(10) << "姓名" << setw(10) << "课程" << setw(10) << "成绩" << endl;
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
	cout << "请输入要修改成绩的学生的姓名：";
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
	cout << "请输入要修改的科目的名称和成绩:";
	cin >> course>>grade;
	int j = 0;
	for (int j=0;j<=99; j++)
	{
		if (si[n].m_course[j] == course)
		{
			si[n].m_grade[j] = grade;
			cout << "修改成功!"<<endl;
			outgrade(si);
			break;
		}
	}
}

void Add(Student si[])
{
	string name,course;
	double grade;
	cout << "请输入你要增加科目的学生的名字：";
	cin >> name;
	cout << "请输入你要增加的课程名称和成绩：";
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
			cout << "添加成功！";
			break;
		}
	}
}

void Find(Student si[])
{
	cout  << "(a)根据姓名查找某学生的所有课程成绩信息；" << endl;
	cout  << "(b)根据班号查找某个班所有学生的已学课程的成绩信息；" << endl;
	cout  << "(c)根据课程名查找选修该门课所有学生的成绩信息；" << endl;
	cout  << "(d)查找所有学生的已选课程的成绩信息；"<<endl;		
	char choice;
	do
	{
		cout << "请选择你要查找的方式(a/b/c/d)：" << endl;
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
			cout << "请输入(a/b/c/d):";
		}
	} while (97 > choice&& choice >100);
}
void finda(Student si[])
{
	string name;
	cout << "请输入要查找的学生的姓名：" << endl;
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
	cout << "请输入要查找的班级号:" << endl;
	cin >> classes;
	cout << "是否按已修学分排序？(y/n)" << endl;
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
			cout << si[n[i]].m_name << ":" << "已完成学分" << si[n[i]].m_completedcredits << endl;
			for (int j = 0; si[n[i]].m_course[j] != "1"; j++)
				cout << si[n[i]].m_course[j] << ":" << si[n[i]].m_grade[j] << endl;
			cout << endl;
		}
		ofstream out("newfile.txt");
		if (out)
		{
			for (int i = 0; n[i] != 0; i++)
			{
				out << si[n[i]].m_name << ":" << "已完成学分" << si[n[i]].m_completedcredits << endl;
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
				cout << si[n[i]].m_ID<<" "<<si[n[i]].m_name << ":" << "已完成学分" << si[n[i]].m_completedcredits << endl;
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
					out << si[n[i]].m_ID << " " << si[n[i]].m_name << ":" << "已完成学分" << si[n[i]].m_completedcredits << endl;
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
	cout << "请输入要查询的课程名称：" << endl;
	cin >> course;
	cout << "是否按高低成绩排序(y/n)" << endl;
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
	cout << "是否按照已修学分排序?(y/n)"<<endl;
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
				cout << si[n[i]].m_name << ":" << "已完成学分" << si[n[i]].m_completedcredits << endl;
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
					out << si[n[i]].m_name << ":" << "已完成学分" << si[n[i]].m_completedcredits << endl;
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
				cout <<si[n[i]].m_ID<<" "<< si[n[i]].m_name << ":" << "已完成学分" << si[n[i]].m_completedcredits << endl;
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
					out << si[n[i]].m_ID << " " << si[n[i]].m_name << ":" << "已完成学分" << si[n[i]].m_completedcredits << endl;
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
	cout << "(a)统计成绩" << endl;
	cout << "(b)统计学分和未完成课程" << endl;
	cout << "请选择统计方式：" << endl;
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
	cout << "请输入你要统计的班级号：" << endl;
	cin >> classes;
	cout << "请输入你要统计的课程：" << endl;
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
	cout << "该课程的平均成绩为：" << Grade << endl;
	cout << "该门课程不及格学生为：" << endl;;
	if (name[0] != "0")
	{
		for (int i = 0; name[i] != "0"; i++)
			cout << name[i] << endl;
	}
	else
		cout << "该课程没有不及格学生" << endl;
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
	cout << "本班级该课程方差为：" << sqrt(grade1 / n) <<endl;
	cout << "本班级该课程合格率为：" << (double(n - m) /double (n))*100 << "%" << endl;
}
void statistics2(Student si[])
{
	cout << "每个学生完成的总学分、不及格课程数、未修学分情况如下：" << endl;
	for (int i = 1; i <= 99&&si[i].m_course[0]!="1"; i++)
	{
		double nocredit = 0;
		if (si[i].m_completedcredits < si[i].m_Requiredcredits)
			nocredit = si[i].m_Requiredcredits - si[i].m_completedcredits;
		cout << si[i].m_name << ":" << endl;
		cout << "\t" << "完成总学分：" << si[i].m_completedcredits << "      " << "不及格课程数:"<<si[i].m_failingcourse<<"\t"<<"未修学分："<<nocredit<<endl;
	}
}

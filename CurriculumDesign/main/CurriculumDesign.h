#ifndef __CURRICULUMDESIGN_H__
#define	__CURRICULUMDESIGN_H__
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
 
class Credit;
class Student;
class Student
{
	string m_ID;
	string m_name;
	string m_classes;
	string m_major;
	vector<string>m_course = { "1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1" };
	vector<double>m_grade = { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 , 0,0,0,0,0 , 0,0,0,0,0 };
	double m_completedcredits=0;
	int m_failingcourse=0;
	const double m_Requiredcredits = 50;
public:
	friend class Credit;

	friend void Read(Student si[], Credit& ci);
	friend void Entergrade(Student si[]);
	friend void Enterinf(Student si[]);
	friend void Readcredit(Student si[], Credit ci);

	friend void outgrade(Student si[]);

	friend void Delete( Student si[]);

	friend void Revise(Student si[]);
	

	friend void Add(Student si[]);

	friend void Find(Student si[]);
	friend void finda(Student si[]);
	friend void findb(Student si[]);
	friend void findc(Student si[]);
	friend void findd(Student si[]);

	friend void Statistics(Student si[]);
	friend void statistics1(Student si[]);
	friend void statistics2(Student si[]);
};

void Delete( Student si[]);

void Revise(Student si[]);

void Read(Student si[],Credit &ci);
void Entergrade(Student si[]);
void Enterinf(Student si[]);
void Entercredit(Credit& ci);
void Readcredit(Student si[], Credit ci);

void outgrade(Student si[]);

void Add();

void Find(Student si[]);
void finda(Student si[]);
void findb(Student si[]);
void findc(Student si[]);
void findd(Student si[]);

void Statistics(Student si[]);
void statistics1(Student si[]);
void statistics2(Student si[]);
int judge(vector<int>n,int i);
int menu();

class Credit
{
	vector<string>m_course{ "1","1","1","1","1","1","1","1","1","1", "1","1","1","1","1", "1","1","1","1","1", "1","1","1","1","1" };
	vector<double>m_credit{0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 };
public:
 friend void Entercredit(Credit &ci);
 friend void Read(Student si[],Credit &ci);
 friend void Readcredit(Student si[], Credit ci);
};

#endif
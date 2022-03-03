#include<iostream>
#include"Set.h"

using namespace std;
int main()
{
	vector<char>temp1 = { 'a','s','d','f','g' };
	vector<char>temp2 = { 'a','c','g','h','t' };
	Set s1(temp1);
	Set s2(temp2);
	//s1.is_elem('h');
	//s1.insert('t');
	//s1.erase('f');
	//s1 = s2;
 	//Set s3(s1);
	// cout << s1;
 	//Set s4 = common(s1,s2);
	Set s4 = sum(s1, s2);
}

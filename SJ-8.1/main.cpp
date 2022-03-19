#include "MyVector.h"
#include<iostream>

int main()
{
	//char
	MyVector<string>ba = { "da","hf","of","gw"};
	MyVector<string>cd = { "ad","hy" };
	ba = cd;
	cout << ba.size() << endl;
	//cout << ba[3] << endl;
	//cout << ba.at(2) << endl;
	//cout << ba.front() << endl;
	//cout << ba.back() << endl;
	//ba.push_back("t");
	//cout << ba.back() << endl;
	//ba.pop_back();
	//cout << ba.back() << endl;
	//ba.insert(1, 2, "k");
	//cout << ba.at(1) << endl;
	//ba.erase(1, 3);
	//cout << ba.at(1) << endl;
	////ba.clear();
	////cout << ba[0]<<endl;
	////ba.sort();
	//cout << ba.binary_search("h");
	//return 0;
} 
#include <iostream>

using namespace std;
int main()
{
	int grade;
	cout << "Please input grade:" << endl;
	cin >> grade;
	if (grade >= 90)
		cout << "grade A";
	else if (grade >= 80)
		cout << "grade B";
	else if (grade >= 70)
		cout << "grade C";
	else if (grade >= 60)
		cout << "grade D";
	else
		cout << "Failed";
	return 0;
}

/*
#include <iostream>

using namespace std;
int main()
{
	int grade;
	cout << "Please input grade:" << endl;
	cin >> grade;
	switch (grade / 10)
	{
	case 10: case 9:
		cout << "grade A";
		break;
	case 8:
		cout << "grade B";
		break;
	case 7:
		cout << "grade C";
		break;
	case 6:
		cout << "grade D";
		break;
	default:
		cout << "Failed";
		break;
	}
	return 0;
}
*/
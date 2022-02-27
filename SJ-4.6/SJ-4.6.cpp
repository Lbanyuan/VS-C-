#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int NUM = 26;
	const string wordlist[NUM] =
	{
		"program","cat","cereal","danger","good","florid",
		"garage","heal","insult","joke","keeper","loaner",
		"nonce","onset","ok","quilt","remote","stolen","train",
		"useful","valid","where","xenon","cool","result"
	};
	srand(time(0));
	char play;
	cout << "Will you play a word game?<y/n>" << endl;
	cin >> play;
	while (play == 'y' || play == 'Y')
	{
		string target = wordlist[rand() % NUM];
		int length = target.length();
		string attempt(length, '*'), badchars;
		int guesses = 6;
		cout << "������׼���ã�����" << length << "����ĸ��" << attempt << endl;
		do
		{
			char letter;
			cout << "��²�һ����ĸ:" << endl;
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "�Ѿ��¹�����ĸ�����ز�" << endl;
				continue;
			}
			auto loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "û�д���ĸ��" << endl;
				--guesses;
				badchars += letter;
			}
			else
			{
				cout << "�������ĸ���������ͣ�" << endl;
				do
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				} while (loc != string::npos);
			}
			cout << "��²�ĵ��ʣ�" << attempt << endl;
			if (attempt != target)
				cout << "ʣ��" << guesses << "�β´����" << endl;
		} while (guesses > 0 && attempt != target);
		if (guesses > 0)
			cout << "�ɹ��ˣ���ϲ�ˣ�" << endl;
		else
			cout << "�Բ���ʧ���ˣ��´�����ս�ɣ�������" << target << endl;
		cout << "Will you play another?<y/n>";
		cin >> play;
	}
	cout << "Bye." << endl;
	return 0;
}
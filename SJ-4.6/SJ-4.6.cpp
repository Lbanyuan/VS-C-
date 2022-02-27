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
		cout << "单词已准备好，它有" << length << "个字母：" << attempt << endl;
		do
		{
			char letter;
			cout << "请猜测一个字母:" << endl;
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "已经猜过该字母，请重猜" << endl;
				continue;
			}
			auto loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "没有此字母！" << endl;
				--guesses;
				badchars += letter;
			}
			else
			{
				cout << "有这个字母，继续加油！" << endl;
				do
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				} while (loc != string::npos);
			}
			cout << "你猜测的单词：" << attempt << endl;
			if (attempt != target)
				cout << "剩余" << guesses << "次猜错机会" << endl;
		} while (guesses > 0 && attempt != target);
		if (guesses > 0)
			cout << "成功了，恭喜了！" << endl;
		else
			cout << "对不起，失败了，下次在挑战吧，单词是" << target << endl;
		cout << "Will you play another?<y/n>";
		cin >> play;
	}
	cout << "Bye." << endl;
	return 0;
}
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<cstdlib>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

using HuffmanCode = char**;
const int INF = 0x3f3f3f3f;
typedef struct {
    char c;
    int weight;
    int parent, lchild, rchild;
}Node, * HuffmanTree;

map<char, int, greater<char> > mp;        //使用 键值对  存储输入字符串中各字符的数量
set<char> st;                           //使用 集合     保存输入字符串的各个字符

void Select(HuffmanTree HT, int range, int& s1, int& s2) {
    /*挑选两个权重最小且双亲为0的结点，并将其下标赋给s1和s2*/
    int min = INF;
    for (int i = 1; i <= range; ++i) {
        if (HT[i].parent == 0 && HT[i].weight < min) {
            min = HT[i].weight;
            s1 = i;
        }
    }
    min = INF;
    for (int i = 1; i <= range; ++i) {
        if (HT[i].parent == 0 && HT[i].weight < min && i != s1) {
            min = HT[i].weight;
            s2 = i;
        }
    }
}

void CreateHuffmanTree(HuffmanTree& HT, int n) {
    /*创建哈夫曼树并将哈夫曼树保存到文件*/
    if (n <= 1) return;
    int m = 2 * n - 1;                //哈夫曼树结点个数
    HT = new Node[m + 1];         //0号单元弃用
    for (int i = 1; i <= m; ++i) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    set<char>::iterator it = st.begin();
    for (int i = 1; i <= n; ++i, ++it) {
        HT[i].c = *it;
        HT[i].weight = mp[*it];
    }
    /*----------至此初始化结束，下面开始构建哈夫曼树----------*/
    for (int i = n + 1; i <= m; ++i) {
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1; HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) {
    /*从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中*/
    HC = new char* [n + 1];
    char* cd = new char[n];
    cd[n - 1] = '\0';
    for (int i = 1; i <= n; ++i) {
        int start = n - 1;
        int c = i;
        int f = HT[i].parent;
        while (f != 0) {
            --start;
            if (HT[f].lchild == c) {
                cd[start] = '0';
            }
            else {
                cd[start] = '1';
            }
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
    }
    delete[]cd;
}



int main() {
    string str;
    size_t len;
    ifstream in("huffman.txt");
    if (in)
    {
        stringstream ss; // 创建字符串流对象
        ss << in.rdbuf(); // 把文件流中的字符输入到字符串流中
        str = ss.str(); // 获取流中的字符串
        len = str.length();
        in.close();
    }
    for (int i = 0; i < len; ++i) {        //创建map
        st.insert(str[i]);          //创建set
        if (mp.count(str[i])) {
            ++mp[str[i]];
        }
        else {
            mp[str[i]] = 1;
        }
    }
    int n = mp.size();
    HuffmanTree HT;

    CreateHuffmanTree(HT, n);        //创建哈夫曼树

    //for (int i = 1; i <= 2 * n - 1; ++i) {
    //        cout << i << "\t" << HT[i].c << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
    //}
    //cout << endl;

    HuffmanCode HC;
    CreatHuffmanCode(HT, HC, n);    //求哈夫曼编码
    ofstream out("new.txt");            //打印到文件"new.txt"中
    if (out) {
        out << "字符" << "\t" << "次数" << "\t" << "哈夫曼编码" << endl;
        set<char>::iterator it = st.begin();
        for (int i = 1; i <= n; ++i, ++it) {            //首先输出字符，然后是字符的数量，最后是字符对应的编码
            out << *it << "\t" << HT[i].weight << "\t" << HC[i] << endl;
        }
        out.close();
    }
}









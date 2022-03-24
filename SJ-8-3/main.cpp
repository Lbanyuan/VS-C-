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

map<char, int, greater<char> > mp;        //ʹ�� ��ֵ��  �洢�����ַ����и��ַ�������
set<char> st;                           //ʹ�� ����     ���������ַ����ĸ����ַ�

void Select(HuffmanTree HT, int range, int& s1, int& s2) {
    /*��ѡ����Ȩ����С��˫��Ϊ0�Ľ�㣬�������±긳��s1��s2*/
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
    /*���������������������������浽�ļ�*/
    if (n <= 1) return;
    int m = 2 * n - 1;                //��������������
    HT = new Node[m + 1];         //0�ŵ�Ԫ����
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
    /*----------���˳�ʼ�����������濪ʼ������������----------*/
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
    /*��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��*/
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
        stringstream ss; // �����ַ���������
        ss << in.rdbuf(); // ���ļ����е��ַ����뵽�ַ�������
        str = ss.str(); // ��ȡ���е��ַ���
        len = str.length();
        in.close();
    }
    for (int i = 0; i < len; ++i) {        //����map
        st.insert(str[i]);          //����set
        if (mp.count(str[i])) {
            ++mp[str[i]];
        }
        else {
            mp[str[i]] = 1;
        }
    }
    int n = mp.size();
    HuffmanTree HT;

    CreateHuffmanTree(HT, n);        //������������

    //for (int i = 1; i <= 2 * n - 1; ++i) {
    //        cout << i << "\t" << HT[i].c << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
    //}
    //cout << endl;

    HuffmanCode HC;
    CreatHuffmanCode(HT, HC, n);    //�����������
    ofstream out("new.txt");            //��ӡ���ļ�"new.txt"��
    if (out) {
        out << "�ַ�" << "\t" << "����" << "\t" << "����������" << endl;
        set<char>::iterator it = st.begin();
        for (int i = 1; i <= n; ++i, ++it) {            //��������ַ���Ȼ�����ַ���������������ַ���Ӧ�ı���
            out << *it << "\t" << HT[i].weight << "\t" << HC[i] << endl;
        }
        out.close();
    }
}









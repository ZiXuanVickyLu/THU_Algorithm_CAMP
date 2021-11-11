#include <bits/stdc++.h>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

const int M = 505, L = 1000005;

// c��trie���ϵıߣ�c[x][y]��ʾ�ӽڵ�x������x��1��ʼ�����ַ�Ϊy�ıߣ�y��Χ��0��25��
// sz��sz[x]��ʾx�ڵ����������ֹ�ڵ����������������x����
// cnt��trie���Ͻڵ����Ŀ
int c[L][26], sz[L], cnt;

// ���ַ���s���뵽trie����
// s����Ҫ������ַ���
void add(char* s) {
    int x = 0;
    for (; *s; ++s)
    {
        int y = *s - 'a';
        if (!c[x][y])
            c[x][y] = ++cnt;
        x = c[x][y];
    }
    ++sz[x];
}

// ���ڼ���sz����
// x����ǰ�ڵ�
void dfs(int x) {
    for (int y = 0; y < 26; ++y)
    {
        int z = c[x][y];
        if (z) {
            dfs(z);
            sz[x] += sz[z];
        }
    }
}

// ���ַ���s����trie�����ߣ��ҵ���Ӧ�Ľڵ�
// s�������ַ���
// ����ֵ���ߵ��Ľڵ�
int walk(char* s) {
    int x = 0;
    for (; *s; ++s)
    {
        int y = *s - 'a';
        if (!c[x][y])
            return 0;
        x=c[x][y];
    }
    return x;
}

// ================= ����ʵ�ֽ��� =================

char s[M];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (; n--;) {
        scanf("%s", s);
        add(s);
    }
    dfs(0);
    sz[0] = 0;
    for (; m--;) {
        scanf("%s", s);
        printf("%d\n", sz[walk(s)]);
    }
    return 0;
}

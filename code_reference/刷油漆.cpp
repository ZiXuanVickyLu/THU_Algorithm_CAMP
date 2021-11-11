#include <iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

/* �������ﶨ������Ҫ��ȫ�ֱ��� */
int f[21][21][21][21][21][5];
long long dp(int a, int b, int c, int d, int e, int last)
{
    if ((a | b | c | d | e) == 0)
        return 1;
    if (last <5)
    {
        if (f[a][b][c][d][e][last] != -1)
            return f[a][b][c][d][e][last];
    }
    long long ret = 0;
    if (a)
        ret += dp(a - 1, b, c, d, e, 0) * (long long)(a - (last == 1));
    if (b)
        ret += dp(a + 1, b - 1, c, d, e, 1) * (long long)(b - (last == 2));
    if (c)
        ret += dp(a, b + 1, c - 1, d, e, 2) * (long long)(c - (last == 3));
    if (d)
        ret += dp(a, b, c + 1, d - 1, e, 3) * (long long)(d - (last == 4));
    if (e)
        ret += dp(a, b, c, d + 1, e - 1, 4) *(long long) (e);   

    f[a][b][c][d][e][last] = ret%23333;

    return f[a] [b] [c] [d] [e] [last] ;
}
// n������m�����ᣬ��i�����ṻͿai������ͬʱ��������ǡ����Ϳ��n�������������������ڵĳ���ɫ������ͬ���ж�����Ϳ����ķ���
// m������
// a������Ϊm�����飬��������
// ����ֵ��������
int b[6];
int getAnswer(int m, vector<int> a) {
    memset(f, -1, sizeof f);
    for (int i = 0; i < m; ++i)
        b[a[i]]++;
    return dp(b[1], b[2], b[3], b[4], b[5], 5);
}

// ================= ����ʵ�ֽ��� =================

int main() {
    int m;
    scanf("%d", &m);
    vector<int> a;
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    printf("%d\n", getAnswer(m, a));
    return 0;
}

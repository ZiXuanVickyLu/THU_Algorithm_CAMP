#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
using namespace std;


// ================= ����ʵ�ֿ�ʼ =================
const int N = 505 * 2, M = N * N;
struct E {
    int next, to;
    //next:��һ���ڽӱ�
    //to:��������ָ����յ�
}e[M];

//ihead���ڽӱ��ͷ
//cnt:�ڽӱ��С
//mc����ʾÿ������ƥ�����һ����
//vis:Y��Ԫ�ط��ʱ�־
int cnt, ihead[N], mc[N];
bool vis[N];

//�ӱߣ�x->y���ߣ������
void add(int x, int y)
{
    ++cnt;
    e[cnt].next = ihead[x];
    e[cnt].to = y;
    ihead[x] = cnt;
}

//�������㷨
//x:X���ϵĵ㣬�ӵ�ǰ������ҵ�����·
//����ֵ�����ҵ�����·�򷵻�true�����򷵻�false
bool dfs(int x)
{
    for (int i = ihead[x]; i; i = e[i].next) {
        int y = e[i].to;
        if (!vis[y])
        {
            vis[y] = true;
            if (mc[y] == 0 || dfs(mc[y])) {
                mc[y] = x;
                mc[x] = y;
                return true;
            }
        }
    }
    return false;
}
// �������������ܷŶ��ٸ�������
// n�����̵Ĵ�СΪn��n��
// board���������̣�����ĳ��λ���ϵ�������ֵΪ1��ʾ���Էš���������ֵΪ0��ʾ���ܷš�����
// ����ֵ���ܷš�������������
int getAnswer(int n, vector<vector<int>> board) {
    cnt = 0;
    for (int i = 1; i <= n * 2; i++) {
        ihead[i] = 0;
        mc[i] = 0;
    }
    //����
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (board[i - 1][j - 1] == 1)
                add(i, j+n);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!mc[i]) {
            memset(vis, 0, sizeof(bool) * (n * 2 + 1));
            if (dfs(i))
                ++ans;
        }
    }
    return ans;
}

// ================= ����ʵ�ֽ��� =================

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> e;
    for (int i = 0; i < n; ++i) {
        vector<int> t;
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            t.push_back(x);
        }
        e.push_back(t);
    }
    printf("%d\n", getAnswer(n, e));
    return 0;
}


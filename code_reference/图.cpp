#include <bits/stdc++.h>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

const int N = 10005;

// Ϊ�˼��ٸ��ƿ���������ֱ�Ӷ�����Ϣ��ȫ�ֱ����У���ͳ����ÿ�������ȵ�����in��
// n, m�������ͱ���
// in��in[i]��ʾ��i�����
// e��e[i][j]��ʾ��i�ĵ�j����ָ��ĵ�
int n, m, in[N];
vector<int> e[N];

/* �������ﶨ������Ҫ��ȫ�ֱ��� */

// �ж����������޻�ͼ�Ƿ����Ψһ�ĺϷ�����
// ����ֵ�������ڷ���1�����򷵻�0��
bool getAnswer() {
    int x = 0;
    for (int i = 1; i <=n; i++)
    {
        if (in[i] == 0)
        {
            if (x == 0)
                x = i;
            else
                return 0;
        }
    }

    for (int i = 1; i <=n; i++)
    {
        int z = 0;
        for (int j = 0; j < e[x].size(); j++)
        {
            int mark=--in[e[x][j]];
            if (mark== 0) 
            {
                if (z == 0)
                    z = e[x][j];
                else
                    return 0;
            }
        }
        x = z;
    }
    return 1;
}

// ================= ����ʵ�ֽ��� =================

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            in[i] = 0;
            e[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            e[x].push_back(y);
            ++in[y];
        }
        printf("%d\n", getAnswer());
    }
    return 0;
}


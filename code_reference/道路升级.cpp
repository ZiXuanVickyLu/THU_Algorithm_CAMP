#include <iostream>
#include<vector>
using namespace std;
const int N = 500000;
struct UnionSet {
    int f[N];
    void init(int n);
    int find(int x);
    bool merge(int x, int y);
};
void UnionSet::init(int n) {
    for (int i = 1; i <= n; i++)
        f[i] = -1;
}
int UnionSet::find(int x) {
    int y = x;
    while (f[y] > 0)
    {
        y = f[y];
    }
    return y;
}

bool UnionSet::merge(int x, int y)
{
    if (find(x) != find(y))//����һ������
    {
        if (find(x) != x && find(y) != y)//x y�����Ǹ�������Ϊ������ϲ���
        {
            merge(find(x), find(y));
            return true;
        }
        else if (find(x) == x && find(y) == y)//x,y ���Ǹ�,Ԫ���ٵĹ鲢��Ԫ�ش�ġ�
        {
            if (f[x] <= f[y])//x������y
            {
                f[x] += f[y];
                f[y] = x;
                return true;
            }
            else
            {
                f[y] += f[x];
                f[x] = y;
                return true;
            }

        }
        else if (find(x) == x && find(y) != y)//x ��
        {
            merge(x, find(y));
            return true;
        }
        else if (find(x) != x && find(y) == y)//y��
        {
            merge(find(x), y);
            return true;
        }
    }

    return false;//��bug�˻����Ѿ���һ���������ˡ�
}
struct UnionSet us;

// ����һ��n����m���ߵ�����ͼ����i���߱�ȨΪi����������Ҫ�����ı�
// n��������
// m��������
// U����СΪm�����飬��ʾm���ߵ�����һ���˵�
// V����СΪm�����飬��ʾm���ߵ���һ���˵�
// ����ֵ��������Ҫ�����ıߣ���С�������У���һС�ʵĴ���Ȼ��Ϊ����ֵ��size�������㲻�ؿ�����η���size
vector<int> getAnswer(int n, int m, vector<int> U, vector<int> V) {
    vector<int> ans;
    us.init(n);
    for (int i =1,j=0; j<n-1;i++)
    {
        if (us.merge(U[m - i ], V[m - i]))
        {
            ans.push_back(m+1-i);
            ++j;
        }
    }
    vector<int> re;
    for (int i = 0; i < int(ans.size()); i++)
        re.push_back(ans[int(ans.size()) - i-1]);

    return re;
}

// ================= ����ʵ�ֽ��� =================

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> U, V;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        U.push_back(u);
        V.push_back(v);
    }
    vector<int> ans = getAnswer(n, m, U, V);
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < int(ans.size()); ++i)
        printf("%d\n", ans[i]);
    return 0;
}

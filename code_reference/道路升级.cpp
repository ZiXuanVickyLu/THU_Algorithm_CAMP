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
    if (find(x) != find(y))//不在一个集合
    {
        if (find(x) != x && find(y) != y)//x y均不是根，划归为根向根合并。
        {
            merge(find(x), find(y));
            return true;
        }
        else if (find(x) == x && find(y) == y)//x,y 均是根,元素少的归并至元素大的。
        {
            if (f[x] <= f[y])//x不少于y
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
        else if (find(x) == x && find(y) != y)//x 根
        {
            merge(x, find(y));
            return true;
        }
        else if (find(x) != x && find(y) == y)//y根
        {
            merge(find(x), y);
            return true;
        }
    }

    return false;//卡bug了或者已经在一个集合里了。
}
struct UnionSet us;

// 给定一个n个点m条边的无向图，第i条边边权为i，求所有需要升级的边
// n：如题意
// m：如题意
// U：大小为m的数组，表示m条边的其中一个端点
// V：大小为m的数组，表示m条边的另一个端点
// 返回值：所有需要升级的边，从小到大排列；第一小问的答案自然即为返回值的size，所以你不必考虑如何返回size
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

// ================= 代码实现结束 =================

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

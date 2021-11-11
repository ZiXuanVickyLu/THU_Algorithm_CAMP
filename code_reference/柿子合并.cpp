#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 100000;
struct Edge {
    int u; int v; int w;
    Edge(int u,int v,int w):w(w),u(u),v(v){}
    Edge() = default;
    bool operator<(const Edge& E)const
    {
        return w < E.w;
    }
    bool operator>(const Edge& E)const {
        return w > E.w;
    }
};


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

/* 请在这里定义你需要的全局变量 */

// 给定n个点m条边的有权无向图，求最小的k-生成森林的边权和
// k-生成森林：k-生成森林是原图的一个生成子图，并且使得其中存在k个森林
// n：如题意
// m：如题意
// k：如题意
// E：大小为m的数组，表示m条情报
// 返回值：若能构成k-生成森林，则返回最小k-生成森林的边权和，否则返回-1
int getAnswer(int n, int m, int k, priority_queue<Edge,vector<Edge>,greater<Edge>> E)
{
    us.init(n);
    int sum = 0;
    for (int i = 0; E.size(); )
    {
        if (i == n - k)
            return sum;
        
        if (us.merge(E.top().u, E.top().v))
        {
            sum += E.top().w;
            i++;
        }
        E.pop();
    }
    
    return -1;
}

// ================= 代码实现结束 =================

int main()
{
    int n, m, k;
    priority_queue<Edge,vector<Edge>,greater<Edge>> E;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        E.push(Edge(u, v, w));
    }
    cout << getAnswer(n, m, k, E) << endl;
    return 0;
}
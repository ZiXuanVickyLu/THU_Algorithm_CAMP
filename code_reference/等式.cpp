#include <iostream>
#include<vector>
#include<string>
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
// 给定n个变量以及m个约束，判定是否能找出一种赋值方案满足这m个约束条件
// n：如题意
// m：如题意
// A：大小为m的数组，表示m条约束中的a
// B：大小为m的数组，表示m条约束中的b
// E：大小为m的数组，表示m条约束中的e
// 返回值：若能找出一种方案，返回"Yes"；否则返回"No"（不包括引号）。
string getAnswer(int n, int m, vector<int> A, vector<int> B, vector<int> E) {
    int cou=0;
    us.init(n);
    string ans="Yes";
    int i;
    vector<int> fa, fb;
    for (i = 0; i < m; i++)
    {
        if (E[i] == 1)
        {
            cou++;
            us.merge(A[i], B[i]);
        }
        else
        {
            fa.push_back(A[i]);
            fb.push_back(B[i]);
        }
    }
    for(i=0;i<m-cou;i++)
    {
        if (us.find(fa[i]) == us.find(fb[i]))
            ans = "No";
    }    
    return ans;
}
int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> A, B, E;
        for (int i = 0; i < m; ++i) {
            int a, b, e;
            scanf("%d%d%d", &a, &b, &e);
            A.push_back(a);
            B.push_back(b);
            E.push_back(e);
        }
        printf("%s\n", getAnswer(n, m, A, B, E).c_str());
    }
    return 0;
}
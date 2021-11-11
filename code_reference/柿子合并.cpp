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

/* �������ﶨ������Ҫ��ȫ�ֱ��� */

// ����n����m���ߵ���Ȩ����ͼ������С��k-����ɭ�ֵı�Ȩ��
// k-����ɭ�֣�k-����ɭ����ԭͼ��һ��������ͼ������ʹ�����д���k��ɭ��
// n��������
// m��������
// k��������
// E����СΪm�����飬��ʾm���鱨
// ����ֵ�����ܹ���k-����ɭ�֣��򷵻���Сk-����ɭ�ֵı�Ȩ�ͣ����򷵻�-1
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

// ================= ����ʵ�ֽ��� =================

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
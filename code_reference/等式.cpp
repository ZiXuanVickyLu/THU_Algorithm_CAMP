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
// ����n�������Լ�m��Լ�����ж��Ƿ����ҳ�һ�ָ�ֵ����������m��Լ������
// n��������
// m��������
// A����СΪm�����飬��ʾm��Լ���е�a
// B����СΪm�����飬��ʾm��Լ���е�b
// E����СΪm�����飬��ʾm��Լ���е�e
// ����ֵ�������ҳ�һ�ַ���������"Yes"�����򷵻�"No"�����������ţ���
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
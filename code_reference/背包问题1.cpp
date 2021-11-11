#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ================= ����ʵ�ֿ�ʼ =================

const int N = 5005;
int f[N];

// n����Ʒ����
// V�����������
// t������Ϊn�����飬��i��Ԫ����Ϊ0����ʾ��ƷiΪ������Ʒ����Ϊ1����ʾ��ƷiΪ�����Ʒ����i�±��0��ʼ������ͬ��
// w������Ϊn�����飬��i��Ԫ�ر�ʾ��i����Ʒ�ļ�ֵ
// v������Ϊn�����飬��i��Ԫ�ر�ʾ��i����Ʒ�����
// ����ֵ������ֵ֮��
int getAnswer(int n, int V, vector<int> t, vector<int> w, vector<int> v) {
    for (int i = 0; i < n; ++i) {
        if (t[i] == 0)
        {
            for (int j = V; j >= v[i]; --j)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
        else
        {
            for (int j = v[i]; j <= V; ++j)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }

    }
    return f[V];

}

// ================= ����ʵ�ֽ��� =================

int main() {
    int n, V;
    scanf("%d%d", &n, &V);
    vector<int> T, W, _V;
    for (int i = 0; i < n; ++i) {
        int t, w, v;
        scanf("%d%d%d", &t, &w, &v);
        T.push_back(t);
        W.push_back(w);
        _V.push_back(v);
    }
    printf("%d\n", getAnswer(n, V, T, W, _V));
    return 0;
}

#include <vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

/* �������ﶨ������Ҫ��ȫ�ֱ��� */
const int inf = 1e9;
vector<int> pos, f;
// ��������������еĳ���
// n����ʾ�����г���
// a���������� a��������Ҫע����ǣ����� a ���±�� 1 ��ʼ����� a[0] ��ֵΪ-1������Ժ�������ֵ��ֻ��֪�����Ǵ��±� 1 ��ʼ�����Ч��Ϣ���ɣ� 
// b����������b��ͬ���أ�b[0] ��ֵΪ -1��
// ����ֵ������������еĳ���
int LCS(int n, vector<int> a, vector<int> b) {
    pos.resize(n + 1);
    f.resize(n + 2, inf);
    for (int i = 1; i <= n; i++)
    {
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        b[i] = pos[b[i]];

    for (int i = 1; i <= n; ++i)
        *upper_bound(f.begin(), f.end(), b[i]) = b[i];

    for (int i = n+1; i >= 1; i--)
      {
          if (f[i] < inf)
                return i+1;
      }

    return 1;
}

// ================= ����ʵ�ֽ��� =================

int main() {
    int n, tmp;
    vector<int> a, b;
    scanf("%d", &n);
    a.clear();
    b.clear();
    a.push_back(-1);
    b.push_back(-1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        b.push_back(tmp);
    }
    int ans = LCS(n, a, b);
    printf("%d\n", ans);
    return 0;
}

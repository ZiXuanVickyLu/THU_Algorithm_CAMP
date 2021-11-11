#include <bits/stdc++.h>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

typedef long long ll;
const int N = 300005;

// �洢��άƽ���
struct ip {
    int x, y, i;
    ip(int x = 0, int y = 0) : x(x), y(y), i(0) { }
    void ri(int _i) {
        scanf("%d%d", &x, &y);
        i = _i;
    }
};

// iv��ʾһ���������ͣ���洢��ʽ��ipһ��
typedef ip iv;

// �ȱȽ�x���ٱȽ�y�ᣬ
bool operator < (const ip& a, const ip& b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool operator==(const ip& a, const ip& b) {
    return a.x == b.x && a.y == b.y;
}

// ��������õ�������
iv operator - (const ip& a, const ip& b) {
    return iv(a.x - b.x, a.y - b.y);
}

// ����a��b�Ĳ���������
ll operator ^ (const iv& a, const iv& b) {
    return (ll)a.x * b.y - (ll)a.y * b.x;
}

/* �������ﶨ������Ҫ��ȫ�ֱ��� */

// �����ά������a��͹������͹������b�����У��±����0��ʼ
// a, b������
// n����ʾa��Ԫ�ظ���
// ����͹��Ԫ�ظ���
int convex(ip* a, ip* b, int n) {
    sort(a, a + n);
    n = unique(a, a + n) - a;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (; m > 1 && ((b[m - 1] - b[m - 2]) ^ (a[i] - b[m - 2])) > 0; --m);
        b[m++] = a[i];
    }

    for (int i = n - 2, t = m; i >= 0; --i)
    {
        for(;m>t&& ((b[m - 1] - b[m - 2]) ^ (a[i] - b[m - 2])) > 0; --m);
        b[m++] = a[i];
    }
    return m - 1;
}

// ================= ����ʵ�ֽ��� =================

ip a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        a[i].ri(i + 1);
    int m = convex(a, b, n), ans = m;
    for (int i = 0; i < m; ++i)
        ans = ((ll)ans * b[i].i) % (n + 1);
    printf("%d\n", ans);
    return 0;
}

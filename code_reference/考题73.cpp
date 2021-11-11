#include <iostream>
#include<algorithm>
#define MAXN 1000000
typedef long long ll;

using namespace std;

int a[MAXN + 10];
ll pr[MAXN + 10];
bool pro[MAXN + 10];
ll ba[MAXN + 10];
int n;

// 在此实现你的算法
long long get_ans() {
    long long ans = 0;
    ll thismax = 0;
    ll mmax = 0;
    for (int i = 0; i < n; i++)
    {
        thismax += a[i];
        if (thismax > mmax)
        {
            mmax = thismax; pro[i] = 1;
        }
        if (thismax < 0)
            thismax = 0;
        pr[i] = mmax;
    }
    thismax = 0;
    mmax = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        thismax += a[i];
        if (thismax > mmax)
        {
            mmax = thismax;
            pro[i] &= 1;
        }
        if (thismax < 0)
            thismax = 0;
        ba[i] = mmax;

    }
        for (int i = 0; i < n; i++)
            ans = max(ans, (pr[i] + ba[i]-(ll)a[i]*((pro[i]==1)?1:0)));
        return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }

    printf("%lld\n", get_ans());

    return 0;
}

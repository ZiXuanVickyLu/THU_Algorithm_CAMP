#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long  ll;
priority_queue<ll, vector<ll>,greater<ll>> pq;

long long getAnswer(int n, vector<long long > w) {
    for (int i = 0; i < n; ++i)
        pq.push(w[i]);
    ll sum = 0;
    while (pq.size() > 1)
      {
        ll newEle = 0;
        for (int k = 0; k < 2; k++)
        {
            newEle += pq.top();
            pq.pop();
        }
        pq.push(newEle);
        sum += newEle;
           
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> w;
    for (int i = 0; i < n; ++i) {
        long long x;
        scanf("%lld", &x);
        w.push_back(x);
    }
    printf("%lld\n", getAnswer(n, w));
    return 0;
}

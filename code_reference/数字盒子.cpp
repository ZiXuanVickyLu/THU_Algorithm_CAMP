#include <iostream>
#include<set>
#include<iterator>
#include<utility>

using namespace std;

// ================= 代码实现开始 =================

typedef long long ll;
set<ll> se;
pair<set<ll>::iterator, bool> r;
/* 请在这里定义你需要的全局变量 */

// 执行操作时会调用这个函数
// op：对应该次操作的 op（具体请见题目描述）
// x：对应该次操作的 x（具体请见题目描述）
// 返回值：如果输出为"Succeeded"，则这个函数返回 1，否则返回 0
bool check(int op, ll x) {
    if (op == 1)
    {
        r = se.insert(x);
        return r.second;
   }
    if (op == 2)
    {
        return se.erase(x);
        
    }
}

// ================= 代码实现结束 =================

int main() {
    int Q, op;
    ll x;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%lld", &op, &x);
        puts(check(op, x) ? "Succeeded" : "Failed");
    }
    return 0;
}

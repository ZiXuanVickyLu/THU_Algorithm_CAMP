#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int a[300005];
vector<int> getAnswer(int n, int m, vector<int> q, vector<int> qn) {
    vector<int> ans;
    ans.clear();//对ans进行清空
    //二分查找是建立在有序情况下的
    sort(q.begin(), q.end());
    for (int i = 0; i < n; i++)
        a[i] = q[i];
    int totalmax = unique(a, a + n) - a;

    for (int i = 0; i < m; i++) {
        int key = qn[i];//用key代表询问值

        int L = -1, R = totalmax, mid;
        //当L + 1 = R时，则R 存在不小于整数（可验证）
        while (L + 1 < R) {
            mid = (L + R) >> 1;//向左移位 <==> 取中间值
            if (a[mid] < key)
                L = mid;//当q[mid] < key时 舍去左半边
            else
                R = mid;//当q[mid] >= key时 舍去右半边
        }
        if (R >= totalmax)//此时说明所有的元素都比查询的值小 返回-1
            ans.push_back(-1);
        else
            ans.push_back(a[R]);
    }
    return ans;
}
int main(int argc, char const* argv[]) {
    //n代表元素的个数
    //q是元素集合
    int n;
    scanf("%d", &n);
    vector<int> q;
    for (int i = 0; i < n; i++) {
        int ai;
        scanf("%d", &ai);
        q.push_back(ai);
    }

    //m代表询问个数
    //qn代表询问的值
    int m;
    scanf("%d", &m);
    vector<int> qn;
    for (int i = 0; i < m; i++) {
        int bi;
        scanf("%d", &bi);
        qn.push_back(bi);
    }

    //返回询问结果
    vector<int> fin = getAnswer(n, m, q, qn);
    for (int i = 0; i < m; i++) {
        printf("%d\n", fin[i]);

    }
    return 0;
}
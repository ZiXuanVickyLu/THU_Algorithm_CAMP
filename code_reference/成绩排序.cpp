#include <iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

// ================= 代码实现开始 =================

class code {
public:
    int total;
    int A;
    int DS;
    code(int A, int DS) :A(A), DS(DS), total(A + DS) {}
    code() :A(0), DS(0), total(0) {}
    bool operator<(const code& x)const;
    void set(int A, int DS) { this->A = A; this->DS = DS; this->total = A + DS; }
};
bool code::operator<(const code& x)const
{
    if ((this->total) < x.total)
        return true;
    else if ((this->total) > x.total)
        return false;
    else if ((this->A) < x.A)
        return true;
    else if ((this->A) > x.A)
        return false;
    else if ((this->DS) < x.DS)
        return true;
    else return false;
}

// n：题目描述中的 n
// A：各同学的算法训练营成绩
// DS：各同学的数据结构训练营成绩
// 返回值：将要输出的数字依次加入到返回值的数组中
vector<int> getAnswer(int n, vector<int> A, vector<int> DS) {
    map<code, int> seq;
    code tempc;
    int i, j;
    for (i = 0; i < n; i++)
    {
        tempc.set(A[i], DS[i]);
        seq.insert(pair<code, int>(tempc, i + 1));
    }

    vector<pair<code, int>> temp(seq.begin(), seq.end());
    vector<int> lis;

    for (i = 0; i < n; i++)
    {
        lis.push_back(temp[n - 1 - i].second);
    }
    int sum = 0;

    for (j = 0; j < n; j++)
    {
        for (i = j + 1; i < n; i++)
        {
            if (lis[j ] > lis[i])
                sum++;
        }
    }
    vector<int> resu;
    for (i = 0; i < n; i++)
    {
        resu.push_back(temp[n-1-i].second);
        resu.push_back(temp[n - 1 - i].first.total);
        resu.push_back(temp[n - 1 - i].first.A);
        resu.push_back(temp[n - 1 - i].first.DS);
    }
    resu.push_back(sum);

    return resu;
}

// ================= 代码实现结束 =================

int main() {
    int n;
    scanf("%d", &n);
    vector<int> A, DS;
    for (int i = 0; i < n; ++i) {
        int a, ds;
        scanf("%d%d", &a, &ds);
        A.push_back(a);
        DS.push_back(ds);
    }
    vector<int> ans = getAnswer(n, A, DS);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d %d\n", ans[cnt], ans[cnt + 1], ans[cnt + 2], ans[cnt + 3]);
        cnt += 4;
    }
    printf("%d\n", ans[cnt]);
    return 0;
}
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

vector<vector<int>>dp;


// ����������𰸣���󾭹�λ�������ܺͣ�
// n���������������δ�С������ͬ��Ŀ����
// a�������������������Σ��� i �еĵ� j ��������� a[i][j]
// �У�����Ҫ�ر�ע����ǣ������±���� 1 ��ʼ��Ҳ����˵�±�Ϊ 0 ��λ�ý������Ч��Ϣ��
// ����ֵ����󾭹�λ�������ܺ�
int getAnswer(int n, vector<vector<int>> a) {
    dp.resize(n + 1);
    for (int i = 0; i <= n; i++)
        dp[i].resize(i + 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1)
                dp[i][j] = dp[i - 1][j] + a[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            else
            dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i - 1][j] + a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[n][i]);

    return ans;
}

// ================= ����ʵ�ֽ��� =================

int main() {
    int n;
    vector<vector<int>> a;
    scanf("%d", &n);
    a.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        a[i].resize(i + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);
    int ans = getAnswer(n, a);
    printf("%d\n", ans);
    return 0;
}

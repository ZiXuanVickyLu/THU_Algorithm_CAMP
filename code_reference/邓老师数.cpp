#include <bits/stdc++.h>
#include<vector>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

vector<bool> isPrime, isDeng;

// ������������������ʦ���������������ܺϲ�����һ��
// n, k�����������Ŀ�������
// ����ֵ����� k=0�����������������С�����˳����뷵��ֵ�У���� k=1��������ĵ���ʦ������С�����˳����뷵��ֵ�С�
vector<int> getAnswer(int n, int k) {
    isDeng.resize(n + 1, 1);
    isPrime.resize(n + 1, 1);
    vector<int> ans;
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
            isDeng[i] = 0;
        if (k == 0 && isPrime[i])
            ans.push_back(i);
        if (k == 1 && isDeng[i])
            ans.push_back(i);
        for (int j = i + i; j <= n; j += i)
        {
            isPrime[j] = 0;
            if (!isPrime[i])
                isDeng[j] = 0;
        }
    }
    return ans;
}

// ================= ����ʵ�ֽ��� =================

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> ans = getAnswer(n, k);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
        printf("%d\n", *it);
    return 0;
}

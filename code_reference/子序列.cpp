#include <bits/stdc++.h>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

const int N = 500005, mo = 23333;
int f[N], p[N], last[26];


// Ϊ�˼��ٸ��ƿ���������ֱ�Ӷ�����Ϣ��ȫ�ֱ�����
// s����Ŀ�����ַ������±��1��ʼ
// n���ַ�������
int n;
char s[N];

// ����ַ���s�ж��ٲ�ͬ��������
// ����ֵ��s��ͬ�����е�����������ֵ��moȡģ
int getAnswer() {
    for (int i = 1; i <= n; ++i)
    {
        int a = s[i] - 'a';
        p[i] = last[a];
        last[a] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == 0)
            f[i] = (f[i - 1]*2 + 1)%mo;
        else
            f[i] =(f[i - 1]*2 - f[p[i] - 1]+mo)%mo;
    }
    
    return f[n];
}

// ================= ����ʵ�ֽ��� =================

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    printf("%d\n", getAnswer());
    return 0;
}
    
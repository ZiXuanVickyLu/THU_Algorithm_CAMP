#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int a[300005];
vector<int> getAnswer(int n, int m, vector<int> q, vector<int> qn) {
    vector<int> ans;
    ans.clear();//��ans�������
    //���ֲ����ǽ�������������µ�
    sort(q.begin(), q.end());
    for (int i = 0; i < n; i++)
        a[i] = q[i];
    int totalmax = unique(a, a + n) - a;

    for (int i = 0; i < m; i++) {
        int key = qn[i];//��key����ѯ��ֵ

        int L = -1, R = totalmax, mid;
        //��L + 1 = Rʱ����R ���ڲ�С������������֤��
        while (L + 1 < R) {
            mid = (L + R) >> 1;//������λ <==> ȡ�м�ֵ
            if (a[mid] < key)
                L = mid;//��q[mid] < keyʱ ��ȥ����
            else
                R = mid;//��q[mid] >= keyʱ ��ȥ�Ұ��
        }
        if (R >= totalmax)//��ʱ˵�����е�Ԫ�ض��Ȳ�ѯ��ֵС ����-1
            ans.push_back(-1);
        else
            ans.push_back(a[R]);
    }
    return ans;
}
int main(int argc, char const* argv[]) {
    //n����Ԫ�صĸ���
    //q��Ԫ�ؼ���
    int n;
    scanf("%d", &n);
    vector<int> q;
    for (int i = 0; i < n; i++) {
        int ai;
        scanf("%d", &ai);
        q.push_back(ai);
    }

    //m����ѯ�ʸ���
    //qn����ѯ�ʵ�ֵ
    int m;
    scanf("%d", &m);
    vector<int> qn;
    for (int i = 0; i < m; i++) {
        int bi;
        scanf("%d", &bi);
        qn.push_back(bi);
    }

    //����ѯ�ʽ��
    vector<int> fin = getAnswer(n, m, q, qn);
    for (int i = 0; i < m; i++) {
        printf("%d\n", fin[i]);

    }
    return 0;
}
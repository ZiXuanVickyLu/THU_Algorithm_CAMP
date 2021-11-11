#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 300005;
//max_value:���ڴ洢solve�����е�ǰ׺���ֵ
//min_value:���ڴ洢solve�����е�ǰ׺��Сֵ
int n, d, max_value[N], min_value[N];
vector<int> a;
//���μ�������[l,r]���ж��ٸ������������������ֵ��Сֵ֮�����d
//l:������߽�
//r�������ұ߽�
//����ֵ���������������������еĸ���
long long solve(int l, int r) {
    if (l == r)
        return 0;
    int mid = (l + r) >> 1;//�е�
    long long ans = solve(l, mid) + solve(mid + 1, r);//����������������ֵ
    //���Ǽ�������[mid+1,r]��ǰ׺��Сֵ��Ҳ����˵min_value = min(a[mid+1...i]),max_valueͬ��
    for (int i = mid + 1; i <= r; ++i) {
        min_value[i] = (i == mid + 1) ? a[i] : min(min_value[i - 1], a[i]);
        max_value[i] = (i == mid + 1) ? a[i] : max(max_value[i - 1], a[i]);
    }
    //���ǵ���ö�������е���˵�i��i��ȡֵ��Χ��[1,mid]
    //pos��ʾ�����������е���˵���i����ô�����е��Ҷ˵���Զ����չ��posλ�ã���Ȼposȡֵ��Χ��[mid+1,r],һ��ʼ��ʼ��Ϊr
    //mn�Ǻ�׺��Сֵ��mx�Ǻ�׺���ֵ����Ҳ����˵mn=min(a[i...mid]),mxͬ��
    //��ô��iΪ��˵�����������У��Ҷ˵���[mid+1,r]�ڣ�����Ӧ����pos-mid��
    int mn = 0, mx = 0, pos = r;
    for (int i = mid; i >= l && pos > mid; --i) {
        //����mn��mx
        mn = (i == mid) ? a[i] : min(mn, a[i]);
        mx = (i == mid) ? a[i] : max(mx, a[i]);
        for (; pos > mid && max(mx, max_value[pos]) - min(mn, min_value[pos]) > d; --pos);
        ans += pos - mid;//���´�
    }
    return ans;
}
// ����ж��ٸ�a�����е����������У����ȴ���1��������������е����ֵ��Сֵ֮�����d
// n��a����ĳ���
// d������d
// a������a������Ϊn
// ����ֵ���������������������еĸ���
long long getAnswer(int n, int d, vector<int> a) {
    //���Ƶ�ȫ�ֱ�����
    ::n = n;
    ::d = d;
    ::a = a;
    return solve(0, n - 1);
}

int main() {
    int n, d;
    scanf("%d%d", &n, &d);
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("%lld\n", getAnswer(n, d, a));
    return 0;
}


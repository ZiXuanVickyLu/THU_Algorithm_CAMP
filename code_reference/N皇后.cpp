#include <bits/stdc++.h>
using namespace std;
int ans, allOne;
// ================= ����ʵ�ֿ�ʼ =================
void dfs(int pos, int left, int right)
{
	if (pos == allOne)
	{
		++ans;
		return;
	}
	for (int t = allOne & (~(pos | left | right)); t;){
		int p = t & -t;
		dfs(pos | p, (left | p) << 1, (right | p) >> 1);
		t ^= p;
	}
}

// һ��n��n�����̣��������ϰ�n���ʺ����������������ʺ�����ͬһ�С�ͬһ�л�ͬһб���ϵķ�����
// n������n
// ����ֵ��������	
int getAnswer(int n) {
	ans = 0;
	allOne = (1 << n) - 1;
	dfs(0, 0, 0);
	return ans;
}

// ================= ����ʵ�ֽ��� =================

int main() {
	int n;
	cin >> n;
	cout << getAnswer(n) << endl;
	return 0;
}

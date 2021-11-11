#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int s,c;
	vector<int> ans;
	for (scanf("%d", &s),c=s; s--;)
	{
		int temp;
		scanf("%d", &temp);
			ans.push_back(temp);
	}
	sort(ans.begin(), ans.end());
	for (int i=0;i<c;i++)
	{
		printf("%d", ans[i]);
		if (c-i-1)
			cout << " ";
	}
}
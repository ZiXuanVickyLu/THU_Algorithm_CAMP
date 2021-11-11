#include<iostream>
#include<string.h>
using namespace std;
int a[100005];
int c[50005];
int b[50005];
int getAnswer(int n)
{
	int ans = 0;
	for (int i = 1,j=-1; i <=n&&j<n-1; ++i)
	{
		while (j < n-1 && b[++j] < c[i]);
		if(b[j]>c[i])
			ans++;
	}
	return ans;
}
int main()
{
	int n; cin >> n;
	memset(a, 0, sizeof(a));//1 mine;0 their -1 uesed;
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	int tmp;
	for (int i = 0, j = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		a[tmp] = 1;
	}
	for (int i = 1, j = 0,k=0; i <= 2 * n; i++)
		if (a[i] == 0)
			b[j++] = i;
		else
			c[++k] = i;

	cout << getAnswer(n);
	return 0;
}
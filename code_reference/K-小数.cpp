#include<iostream>
using namespace std;
int ser[30000005];
bool swap(int& a, int& b)//decline
{
	int tmp;
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
		return true;
	}
	else
		return false;
}
int quickselect(int k,int n)
{
	int pri;
	for (int lo = 0, hi = n - 1; lo < hi;)
	{
		int i = lo;
		int j = hi;
		pri = ser[lo];
		while (i < j)
		{
			while (i < j && pri <= ser[j])j--;
				ser[i]=ser[j];
			while (i < j && ser[i] <= pri)i++;
				ser[j]=ser[i];
		}
		ser[i]=pri;
		if (i <=k-1)
			lo = i + 1;
		else if (i >=k-1)
			hi = i - 1;
	}
	return ser[k-1];
}
int main()
{
	int n, k;
	int  p, q, a1, M;
	scanf("%d%d", &n, &k);
	scanf("%d%d%d%d", &a1, &p, &q, &M);
	ser[0] = a1;
	for (int i = 1; i < n; ++i)
		ser[i] = ((long long)p * ser[i - 1] + q) % M;
	cout << quickselect(k, n);

	return 0;

}
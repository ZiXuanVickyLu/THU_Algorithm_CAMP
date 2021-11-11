#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int a[200005];
long long sum = 0;
void superswap(int& a, int& b)//·Ç½µÐò
{
	int temp;
	if(a>b)
	{
		temp = a; a = b; b = temp;
		sum++;
	}
	return;
}
void mergesort(int lo, int hi)//[lo,hi)
{
	if ((hi - lo) > 2)
	{
		mergesort(lo, (lo + hi) / 2); mergesort((lo + hi) / 2, hi);
		//merge with single stack
		queue<int> temp;
		int L_ind = lo, R_ind = (lo + hi) / 2;
		while (R_ind<hi&&L_ind<(lo+hi)/2)
		{
			if (a[L_ind] < a[R_ind])
				;
			else
				sum += ((lo + hi) / 2 -L_ind);
			a[L_ind] < a[R_ind] ? temp.push(a[L_ind++]): temp.push(a[R_ind++]);
		}
		
		if (R_ind == hi)
			while (int(temp.size()) < (hi - lo))
				temp.push(a[L_ind++]);
		else
			while (int(temp.size()) < (hi - lo))
				temp.push(a[R_ind++]);

		for (int i = lo; i < hi; i++)
		{
			a[i] = temp.front(); temp.pop();
		}
	}
	else if ((hi - lo) == 2)
		superswap(a[lo], a[hi-1]);
	else return;
}
long long getAnswer(int n)
{
	mergesort(0, n);
	return sum;
	
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	cout << getAnswer(n);
	return 0;
}
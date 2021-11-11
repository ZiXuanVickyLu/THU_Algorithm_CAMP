#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long int ll ;
ll merge(priority_queue< ll, vector<ll>, greater<ll>>& num, int k)
{
	ll ans=0;
	int r;
	if (k != 2)
	{
		r = num.size() % (k - 1) == 1 ? 0 : k - num.size() % (k - 1);
		for (int i = 0; i < r; i++)
			num.push(0);
	}
	for (int i = 0; i < k; i++)
	{
		if (num.size())
		{
			ans += num.top();
			num.pop();
		}
		else
			break;
	}
	num.push(ans);
	return ans;
}
ll getAnswer(priority_queue < ll, vector<ll>, greater<ll>> &num, int k/*k-code*/)
{

	ll sum = 0;
	while (num.size() > 1)
	{
		sum += merge(num,k);
	}
	return sum;
}
int main()
{
	int n, k;
	priority_queue < ll, vector<ll>, greater<ll> > num;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		ll temp;
		cin >> temp;
		num.push(temp);
	}
	cout << getAnswer(num,k);

}
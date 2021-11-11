#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
string s;
typedef int  ll;
const int mo = 23333;
vector<string>smalls;
int dp[30005];
vector<int> length;
int n;
bool issub(int longs, int num,string &tmp) {
	
	if (longs - length[num] < 0)
		return false;
	int j = longs - 1;
	for (int i = length[num] - 1; i >= 0; i--)
		if (tmp[j--] != smalls[num][i])
			return false;
	return true;
}
void getdp(int longs )
{
	string tmp = s.substr(0, longs);
	for (int i = 0; i < n; i++) {

		if (issub(longs, i,tmp))
			dp[longs] =(dp[longs]+max( dp[longs - length[i]],1))%mo;
	}
}
int getAnswer(ll len)
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= len; i++)
		getdp(i);

	return dp[len];

}
int main()
{
	cin >> s;
	ll len = s.size();
	cin >> n;
	smalls.resize(n);
	length.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin>>smalls[i];
		length[i]=smalls[i].size();

	}
	cout << getAnswer(len);
	return 0;
}
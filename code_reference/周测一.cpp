#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a > b ? b : a;
}
int outgreat(const vector<int> a, const deque<int>b,int n)
{
	vector<int> c;
	if (a.empty())
		return n;

	c.insert(c.end(),a.begin(), a.end());
	c.insert(c.end(), b.begin(), b.end());
	sort(c.begin(), c.end());
	int tempgreat =n;
	int i = 0;
	while (i < int(c.size()) && (c[int(c.size() - (i+1))] == tempgreat))
	{
		--tempgreat; i++;
	}

	return tempgreat;

}
int ispush(int a, deque<int>& b,vector<int> &totalsmall,int n,int outgreats)
{
	if (a < outgreats)
	{
		b.push_back(a);
		return outgreats;
	}

	totalsmall.push_back(a);
	return outgreat(totalsmall,b,n);
}
bool ispop(deque<int>& b,vector<int>&ans,int outgreat)
{
	if (int(b.size()))
	{
		if (outgreat < b.front() || outgreat < b.back())
		{
			ans.push_back(max(b.front(), b.back()));

			if (b.back() > b.front())
				b.pop_back();
			else
				b.pop_front();

			return true;
		}


	}
	return false;
}
vector<int> getAnswer(int n, vector<int> a)
{
	vector<int> ans;
	vector<int> spring;
	deque<int> b;
	int outgreat = n;
	for (int j = 0; j < n; j++)
	{
		outgreat= ispush(a[j], b, ans,n,outgreat);
		while(ispop(b, ans, outgreat));
	}
	while (int(b.size()))
	{
		ans.push_back(max(b.front(), b.back()));
		if (b.back() > b.front())
			b.pop_back();
		else
			b.pop_front();
	}

	return ans;
}
int main()
{
	int n;
	vector<int> a,ans;
	int c;
	
	for (scanf("%d",&n),c=n;n--; )
	{
		int temp;
		scanf("%d", &temp);
		a.push_back(temp);
	}
	ans = getAnswer(c, a);
	for (int k = 0; k < int(ans.size())-1; ++k)
		printf("%d ", ans[k]);


	printf("%d", ans[int(ans.size())- 1]);
		return 0;
}
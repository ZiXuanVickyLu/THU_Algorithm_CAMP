#include<iostream>
#include<vector>
#include<queue>
using namespace std;
pair<int,int> getsplice(const vector<int> n, int gap)
{
	priority_queue<int,vector<int>,less<int>> local_max;
	int i = 0;
	while(i<int(n.size()))
	{
		int sum = 0;
		while ((sum+=n[i] )<= gap && i<int(n.size()-1))
			i++;
		if (i != int(n.size() - 1))
		{
			if (sum != n[i])
			{
				sum -= n[i];
			}
			else
			{
				i++;
			}
			local_max.push(sum);
		}
		else
		{
			if (sum == n[i] || sum <= gap)
				local_max.push(sum);
			else
			{
				local_max.push(sum - n[i]);
				local_max.push(n[i]);
			}
				
			break;
		}
	}
	return pair<int, int>(local_max.size(), local_max.top());
}
int getAnswer(vector<int> num, int n,int sum)
{
	pair<int,int> tempn(1,sum);
	int gap_temp = tempn.second;
	while (tempn .first <= n)
	{
		gap_temp = tempn.second;
		tempn = getsplice(num, (tempn.second) / 2);
	}
	for (int i = gap_temp / 2; i < gap_temp; i++)
	{
		pair<int, int> temp = getsplice(num, i);
		if (temp.first <= n)
			return temp.second;
	}
	return getsplice(num, gap_temp).second;
		

}
int main()
{
	int n, m;
	int sum=0;
	vector<int> num;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		num.push_back(temp);
		sum += temp;
	}
	cout << getAnswer(num, m, sum);
	



	
}

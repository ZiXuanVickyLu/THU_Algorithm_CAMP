#include<iostream>
#include<memory.h>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
#define fi first
#define se second
const int N = 2003;
int mind[N][N];
pii q[N * N];
int qh, qt;
pii to(pii p, int k, int n, int m)
{
	if (k == 0)
		return pii(0, p.se);
	else if (k == 1)
		return pii(p.fi, 0);
	else if (k == 2)
		return pii(n, p.se);
	else if (k == 3)
		return pii(p.fi, m);
	else if (k == 4)
		return pii(p.fi+p.se>=n? n:p.fi+p.se,p.se>=(n-p.fi)?p.se-(n-p.fi):0);
	else if (k == 5)
		return pii( p.fi >= (m - p.se) ? p.fi - (m - p.se) : 0, p.fi + p.se >= m ? m : p.fi + p.se);
	else
		return p;

}
int getAnswer(int n, int m, int t, int d)
{
	memset(mind, -1, sizeof mind);
	qh = qt = 0;
	q[++qt] = pii(0, 0);
	mind[0][0] = 0;

	while (qh < qt)
	{
		pii u = q[++qh];
		if (mind[u.fi][u.se] == t)
			break;
		for (int k = 0; k < 6; ++k)
		{
			pii v = to(u, k, n, m);
			if (mind[v.fi][v.se]!=-1)
				continue;
			q[++qt] = v;
			mind[v.fi][v.se] = mind[u.fi][u.se]+1;
		}
	}
	int ans = d;
	for(int i=0;i<=n;++i)
		for (int j = 0; j <= m; ++j)
		{
			if (mind[i][j] != -1)
				ans = min(ans, abs(d - (i + j)));
		}
	return ans;
}
int main()
{
	int n, m, t, d;
	scanf("%d%d%d%d", &n, &m, &t, &d);
	cout << getAnswer(n, m, t, d);
}

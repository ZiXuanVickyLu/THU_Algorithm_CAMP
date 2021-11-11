#include <vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<bits/stdc++.h>
constexpr auto MAXN=100000;
constexpr auto les =- 100000;
using namespace std;
int a[MAXN + 10];//w
vector<int> to[MAXN + 10];//edge
int nod_flux_max[MAXN + 10];//weight
int nod_flux_min[MAXN + 10];
set<int> loop[MAXN + 10];
bool isloop(int call_node, int a_node)
{
    return bool(loop[call_node].count(a_node));
}
void dfs(int node,int flux_max,int flux_min)
{
    nod_flux_max[node] = max(nod_flux_max[node], flux_max);
    nod_flux_min[node] = min(nod_flux_min[node], flux_min);
    while(to[node].size() != 0)
    {
       
        int son_node = *(to[node].end() - 1);
        if (!isloop(son_node, node))
        {
            loop[son_node].insert(node);
            dfs(son_node, nod_flux_max[node], nod_flux_min[node]);
            to[node].erase(to[node].end() - 1);
        }
        else break;

        
    }

}
int get_ans(int n) {
        
    dfs(1, a[1],a[1]);
    return max(0,nod_flux_max[n]-nod_flux_min[n]);
}


int main() {
    int n, m;
    cin >> n >> m;


    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        nod_flux_max[i] = *(a+i);
        nod_flux_min[i] = *(a+i);
    }

    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        to[u].push_back(v);
    }

    int ans = get_ans(n);

    printf("%d\n", ans);

    return 0;
    }
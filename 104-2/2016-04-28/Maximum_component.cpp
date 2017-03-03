#include <iostream>
#include <vector>
#define N 50100
using namespace std;
int sum, node[N], n, m;
vector<int> edge[N];
bool visit[N];
void dfs(int start)
{
    visit[start] = true;
    sum += node[start];
    int i;
    for (i = 0; i < edge[start].size(); i++)
        if (!visit[edge[start][i]])
            dfs(edge[start][i]);
}
int main()
{
    ios::sync_with_stdio(false);
    int ncase, i, max, u, v;
    cin>>ncase;
    while(ncase--)
    {
        for(i = 0; i < N; i++)
            edge[i].clear();
        fill(visit, visit + N, false);
        cin>>n>>m;
        for(i = 0; i < n; i++)
            cin>>node[i];
        for(i = 0; i < m; i++)
        {
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        max = 0;
        for(i = 0; i < n; i++)
        {
            sum = 0;
            if(!visit[i])
                dfs(i);
            if(sum > max)
                max = sum;
        }
        cout<<max<<endl;
    }
    return 0;
}

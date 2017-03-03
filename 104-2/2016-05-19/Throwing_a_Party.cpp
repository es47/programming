#include <iostream>
#include <cstring>
#include <queue>
#define N 5100
using namespace std;
typedef struct
{
    int rating;
    int parent;
    int child;
    int with;
    int without;
} Data;
Data data[N];
int main()
{
    ios::sync_with_stdio(false);
    int ncase, n, i;
    cin>>ncase;
    while(ncase--)
    {
        memset(data, 0, sizeof(data));
        queue<int> q;
        cin>>n>>data[1].rating;
        data[1].with = data[1].rating;
        for(i = 2; i <= n; i++)
        {
            cin>>data[i].parent>>data[i].rating;
            data[data[i].parent].child++;
            data[i].with = data[i].rating;
        }
        for(i = 2; i <= n; i++)
            if(!data[i].child)
            q.push(i);
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            data[data[temp].parent].without += max(data[temp].with, data[temp].without);
            data[data[temp].parent].with += data[temp].without;
            data[data[temp].parent].child--;
            if(!data[data[temp].parent].child)
                q.push(data[temp].parent);
        }
        cout<<max(data[1].with, data[1].without)<<endl;
    }
    return 0;
}

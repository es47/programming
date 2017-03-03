#include <stdio.h>
#include <iostream>
#include <queue>
#define MAX 15000
using namespace std;
int main()
{
    int n, m, i, j, k, s, ncase;
    priority_queue<int> pq;
    cin>>ncase;
    while(ncase--)
    {
        cin>>n>>m;
        for (i = 0; i < m; i++)
            pq.push(0);
        for (i = 0; i < n; i++)
        {
            cin>>k;
            s = pq.top();
            pq.pop();
            pq.push(s - k);
        }
        for (i = 0; i < m - 1; i++)
            pq.pop();
        cout<<-pq.top()<<endl;
        pq.pop();
    }
    return 0;
}

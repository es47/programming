#include <iostream>
#include <queue>
#define N 200000
using namespace std;
int com(int n, int s, int t[])
{
    int i, j, k;
    priority_queue<int> pq;
    for (i = 0; i < s; i++)
            pq.push(0);
        for (i = 0; i < n; i++)
        {
            k = t[i];
            j = pq.top();
            pq.pop();
            pq.push(j - k);
        }
        for (i = 0; i < s - 1; i++)
            pq.pop();
    return -pq.top();
}
int main()
{
    int ncase, n, m, down, up, s, k, max, i, sum;
    int t[N];
    cin>>ncase;
    while(ncase--)
    {
        cin>>n>>m;
        for (i = 0; i < n; i++)
            cin>>t[i];
        sum = max = 0;
        for (i = 0; i < n; i++)
        {
            sum += t[i];
            max = (max > t[i])? max: t[i];
        }
        if (m < max)
        {
            cout<<"-1"<<endl;
            continue;
        }
        down = sum / m;
        up = n;
        while(down < up)
        {
            s = (down + up) / 2;
            k = com(n, s, t);
            if (k <= m)
                up = s;
            else
                down = s + 1;
        }
        cout<<up<<endl;
    }
    return 0;
}

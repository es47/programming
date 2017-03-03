#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int count, sum=0, max=0, num;
        cin>>count;
        while(count--)
        {
            cin>>num;
            sum += num;
            sum = sum>0 ? sum : 0;
            max = max>sum ? max :sum;
        }
        cout<<max<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MM 100000000000000
void solve(const vector<vector<int> > &matrix, int current, const int &N, vector<bool> row, vector<bool> maind, vector<bool> secondaryd, ll ans, ll &Mans, ll &mans)
{
    if(current == N)
    {
        Mans = max(Mans, ans);
        mans = min(mans, ans);
        return;
    }
    for(int x = 0; x < N; x++)
    {
        if(row[x])
            continue;
        if(maind[current - x + N - 1])
            continue;
        if(secondaryd[x + current])
            continue;
        row[x] = true;
        maind[current - x + N - 1] = true;
        secondaryd[x + current] = true;
        ans += matrix[x][current];
        solve(matrix, current + 1, N, row, maind, secondaryd, ans, Mans, mans);
        row[x] = false;
        maind[current - x + N - 1] = false;
        secondaryd[x + current] = false;
        ans -= matrix[x][current];
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin>>cases;
    while(cases--)
    {
        int N;
        cin>>N;
        vector<vector<int> > matrix(N,vector<int>(N,0));
        for(int x = 0; x < N; x++)
            for(int y = 0; y < N; y++)
                cin>>matrix[x][y];
        ll ans = 0, Mans = -MM, mans = MM;
        vector<bool> row(N, 0);
        vector<bool> maind(2 * N - 1, 0);
        vector<bool> secondaryd(2 * N - 1, 0);
        solve(matrix, 0, N, row, maind, secondaryd, ans, Mans, mans);
        if(mans != MM)

            cout<<Mans<<" "<<mans<<"\n";
        else

            cout<<"-1 -1\n";
    }
    return 0;
}

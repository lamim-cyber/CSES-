#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
using namespace std;

const int N = 200;
const int M = 1e6 + 10;
int n , x;
int w[N];
int dp[M];

int minimizing_coins(int p){
    if(p == 0)return 0;
    if(dp[p] != -1) return dp[p];

    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        if(w[i] <= p){
            ans = min(ans , minimizing_coins(p - w[i]) + 1);
        }
    }

    return dp[p] = ans;
}

void solve(int test) {
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }

    memset(dp , -1 , sizeof dp);
    int d = minimizing_coins(x);
    if(dp[x] == 1e9)cout << -1 << nl;
    else cout << dp[x] << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

// iterative 
// dp[i] = min(dp[i] , dp[i - x] + 1);

#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define nl '\n'
#define gap ' '
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int dp[105][N] , a[105];
int n , k;

void solve(int test){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)dp[i][0] = 1;

    for(int i = n; i >= 1; i--){
        for(int sum = 1; sum <= k; sum++){
            if(a[i] <= sum)dp[i][sum] += dp[i][sum - a[i]];
            dp[i][sum] %= mod;
            dp[i][sum] += dp[i + 1][sum];
            dp[i][sum] %= mod;
        }
    }

    cout << dp[1][k] << nl;
}
int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

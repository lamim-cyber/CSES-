#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
using namespace std;

const int N = 105;
const int M = 1e6 + 10;
const int mod = 1e9 + 7;

int n , x;
int a[N];
int dp[M];

int coin(int p){
    if(p == 0)return 1;
    if(dp[p] != -1) return dp[p];

    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(a[i] <= p){
            ans += coin(p - a[i]);
            ans %= mod;
        }
    }
    return dp[p] = ans;
}

void solve(int test) {
    cin >> n >> x;
    for(int i = 1; i <= n; i++)cin >> a[i];

    memset(dp , -1 , sizeof dp);
    cout << coin(x) << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

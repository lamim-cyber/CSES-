#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int N = 1001;
char a[N][N];
int dp[N][N];
int n;

int grid_path(int i , int j){
    if(i == n and j == n)return a[i][j] == '.' and 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i][j] == '*') return dp[i][j] = 0;
    int ans = 0;
    if(i < n and j < n){
        ans += grid_path(i + 1 , j);
        ans %= mod;
        ans += grid_path(i , j + 1);
        ans %= mod;
    }else if(i < n){
        ans += grid_path(i + 1 , j);
        ans %= mod;
    }else if(j < n){
        ans += grid_path(i , j + 1);
        ans %= mod;
    }

    return dp[i][j] = ans;
}

void solve(int test) {
    cin >> n ;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)cin >> a[i][j];
    }
    memset(dp , -1 , sizeof dp);
    cout << grid_path(1 , 1) << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

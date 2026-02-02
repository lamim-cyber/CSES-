#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int N = 2e6 + 10;
int dp[N];

int number_of_ways(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }
    if(dp[n] != 0){
        return dp[n];
    }

    for (int i = 1; i <= 6; i++)dp[n] = (dp[n] + number_of_ways(n - i)) % mod;
    return dp[n] % mod;
}

void solve(int test) {
    int n ;
    cin >> n;
    cout << number_of_ways(n) << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

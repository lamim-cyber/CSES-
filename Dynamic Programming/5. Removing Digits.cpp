#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
using namespace std;

const int N = 1e6 + 10;
const int inf = 1e9 + 7;
int n;
int dp[N];

int Removing_digits(int i){
  
    if(i <= 0)return 0;
    if(dp[i] != -1)return dp[i];

    int x = i;
    int ans = inf;
    while(x > 0){
        int d = x % 10;
        x /= 10;
        if(d > 0)
        ans = min(ans , 1 + Removing_digits(i - d));
    }

    return dp[i] = ans;
}

void solve(int test) {
    cin >> n;
    memset(dp , -1 , sizeof dp);
    cout << Removing_digits(n) << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

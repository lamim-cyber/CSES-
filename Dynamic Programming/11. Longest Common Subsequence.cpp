#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define gap ' '
using namespace std;

const int N = 1001;
int dp[N][N];
int s[N] , t[N];
int n , m;

int lcs(int i , int j){
    if(i > n or j > m)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = -1;
    if(s[i] == t[j]){
        ans = 1 + lcs(i + 1 , j + 1);
        return dp[i][j] = ans;
    }

    ans = max(ans , lcs(i + 1 , j));
    ans = max(ans , lcs(i , j + 1));

    return dp[i][j] = ans;
}

void print_lcs(int i , int j){
    if(i > n or j > m)return ;

    if(s[i] == t[j]){
        cout << s[i] << gap;
        print_lcs(i + 1 , j + 1);
        return;
    }

    int x = lcs(i + 1 , j);
    int y = lcs(i ,  j + 1);

    if(x >= y){
        print_lcs(i + 1 , j);
    }else {
        print_lcs(i , j + 1);
    }
}

void solve(int test){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> s[i];
    for(int i = 1; i <= m; i++)cin >> t[i];
    memset(dp , -1 , sizeof dp);
    cout << lcs(1 , 1) << nl;
    print_lcs(1 , 1);
}
int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

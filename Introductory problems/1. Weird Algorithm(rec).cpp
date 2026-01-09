#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define S second
#define nl '\n'
#define gap ' '
using namespace std;

void rec(ll n){
    if(n == 1){
      cout << 1 << nl;
      return ;
    }
    cout << n << gap;
    if(n % 2)rec(3 * n + 1);
    else rec(n / 2);
}

void solve(int test){
    ll n;
    cin >> n;
    rec(n);
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

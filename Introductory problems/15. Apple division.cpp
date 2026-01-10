#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define S second
#define nl '\n'
using namespace std;
 
const int N = 25;
ll a[N] , sum , res;
 
void rec(ll s , ll st , ll tot){
 
    ll p = sum - s;
    res = min(abs(p - s) , res);
 
    if(st + 1 <= tot){
        rec(s , st + 1 , tot);
        rec(s + a[st] , st + 1, tot);
    }
 
}
 
void solve(int test){
 
    ll n;
    cin >> n;
    for(int i = 1; i<= n; i++)cin >> a[i];
 
    sum = 0;
    res = INT_MAX;
    for(int i = 1; i <= n; i++)sum += a[i];
  
    rec(0 , 1 , n);
    cout << res << nl;
}
 
int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

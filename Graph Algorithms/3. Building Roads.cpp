#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define nl '\n'
#define gap ' '
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N] ;
bitset<N> visited;

void dfs(int n , int p){
    for(auto x : g[n]){
        if(!visited[x]){
            visited[x] = true;
            col[p] = x ;
            dfs(x , p);
        }
    }
}


void solve(int test){

    int n , m;
    cin >> n >> m;
    while(m--){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
  
    vector<int> ans;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            ans.push_back(i);
            dfs(i , p);
        }
    }
    cout << ans.size() - 1 << nl;
    for(int i = 0; i < ans.size() - 1 ; i++){
        cout << ans[i] << gap << ans[i + 1] << nl;
    }
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}
//https://cses.fi/problemset/task/1666

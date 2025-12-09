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

const int N = 2e5 + 10;
vector<int> g[N] ;
int col[N] ;
bitset<N> visited;
bool pos;

void dfs(int n , int p){
    for(auto x : g[n]){
        if(!visited[x]){
            col[x] = col[n] ^ 1;
            visited[x] = true;
            dfs(x , col[x]);
        }else {
            if(col[x] == col[n]){
                pos = false;
            }
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
    pos = true;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i , 0);
        }
    }
    if(pos){
        for(int i = 1; i <= n; i++){
            cout << col[i] + 1 << gap;
        }
        cout << nl;
    }else {
        cout << "IMPOSSIBLE" << nl;
    }

}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

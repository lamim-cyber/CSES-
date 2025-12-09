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
int par[N] ;
bitset<N> visited;

void solve(int test){

    int n , m;
    cin >> n >> m;

    while(m--){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    par[1] = 0;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto v : g[x]){
            if(!visited[v]){
                visited[v] = true;
                par[v] = x;
                q.push(v);
            }
        }
    }

    if(visited[n]){
        vector<int> path;
        int x = n;
        while(x != 0){
            path.push_back(x);
            x = par[x];
        }
        reverse(all(path));
        cout << path.size() << nl;
        for(auto val : path)cout << val << gap;
        cout << nl;
    }else{
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

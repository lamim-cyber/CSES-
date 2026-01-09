#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
#define gap ' '
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
int visited[N];
int child[N];

void dfs(int x){

    visited[x] = 1;
    child[x]++; // oi node er jonno child++ kora hoise 

    for(auto val : g[x]){
        if(!visited[val]){
            dfs(val);
            child[x] += child[val]; // adjacent child gular child add kora hoise 
        }
    }
}


void solve(int test){

    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << child[i] - 1 << gap;
    }
    cout << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

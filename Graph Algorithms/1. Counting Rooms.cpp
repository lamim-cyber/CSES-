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

const int N = 1005;
char a[N][N];
int visited[N][N];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int n , m;

bool valid(int i , int n){
    if(i >= 1 and i <= n)return true;
    else return false;
}

void DFS(int u , int v){
    for(int i = 0; i < 4; i++){
        int uu = u + dx[i];
        int vv = v + dy[i];
        if(valid(uu , n) and valid(vv , m) and !visited[uu][vv] and a[uu][vv] != '#'){
            visited[uu][vv] = 1;
            DFS(uu , vv);
        }
    }
}

void solve(int test){

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)cin >> a[i][j];
    }
    
    int cnt = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] != '#' and !visited[i][j]){
                cnt++;
                visited[i][j] = 1;
                DFS(i , j);
            }
        }
    }

    cout << cnt << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}
//https://cses.fi/problemset/task/1192/

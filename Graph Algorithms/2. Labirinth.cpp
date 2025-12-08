#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
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
 
pair< pair<int , int> , char> par[N][N];
int n , m;
 
bool valid(int i , int n){
    if(i >= 1 and i <= n)return true;
    else return false;
}
 
void solve(int test){
 
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)cin >> a[i][j];
    }
    
    int cnt = 0;
 
    int ax , ay , bx , by;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 'A'){
                ax = i;
                ay = j;
            }
            if(a[i][j] == 'B'){
                bx = i;
                by = j;
            }
        }
    }
 
    visited[ax][ay] = 1;
    
    queue<pair<int , int>> q;
    q.push({ax , ay});
 
    while(!q.empty()){
        pair<int , int> p = q.front();
        q.pop();
 
        int u = p.F;
        int v = p.S;
 
        for(int i = 0; i < 4; i++){
        int uu = u + dx[i];
        int vv = v + dy[i];
        if(valid(uu , n) and valid(vv , m) and !visited[uu][vv] and a[uu][vv] != '#'){
            visited[uu][vv] = 1;
            char ch;
            if(i == 0)ch = 'D';
            if(i == 1)ch = 'U';
            if(i == 2)ch = 'R';
            if(i == 3)ch = 'L';
 
            par[uu][vv] = {{u , v} , ch};
            q.push({uu , vv});
        }
    }

    }
 
    vector<char> path;
 
    if (visited[bx][by]) {
    int x = bx, y = by;
    yes
    while (x != ax || y != ay) {
        pair<int , int> p = par[x][y].first;
        char ch = par[x][y].second;
        path.push_back(ch);
        x = p.F;
        y = p.S;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (char c : path) cout << c;
    cout << "\n";
}else no
      
}
 
int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);  
}

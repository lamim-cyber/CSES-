#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
using namespace std;

const int N = 1e6 + 10;
int nod[N];

void build(){
    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j += i){
            nod[j]++;
        }
    }
}

void solve(int test){

    int x ;
    cin >> x ;
    cout << nod[x] + 1 << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    build();
    cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i);
    
}

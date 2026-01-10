#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define S second
#define nl '\n'
#define gap ' '
using namespace std;

//the intuition is to move n -1 disks to the other rod and then place the nth rod to the destination

void Tower_of_hanoi(int n , int st , int en){
    if(n == 1){
      cout << st << gap << en << nl;
      return;
    }

    int other = 6 - (st + en);
    Tower_of_hanoi(n - 1 , st , other);
    cout << st << gap << en << nl;
    Tower_of_hanoi(n - 1 , other , en);
}

void solve(int test){

    int n;
    cin >> n;
    cout << (1 << n) - 1 << nl;
    Tower_of_hanoi(n , 1 , 3);
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}

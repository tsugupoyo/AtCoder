#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int n;
   cin >> n;
   int rem  = n%1000;
   if(rem == 0) cout << 0 << endl;
   else cout << 1000 - rem << endl;
}
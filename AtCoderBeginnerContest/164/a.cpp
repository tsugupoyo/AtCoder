#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int s,w;
   cin >> s >> w;

   if(s <= w) cout << "unsafe"<< endl;
   else cout << "safe" << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int k;
   string s;
   cin >> k >> s;

   if(s.size() <= k) cout << s << endl;
   else{
       cout << s.substr(0,k)+ "..." << endl;;
   }
}
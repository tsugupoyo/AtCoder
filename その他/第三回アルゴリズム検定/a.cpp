#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   string s, t;
   cin >> s >> t;
   if(s == t) cout << "same" <<endl;
   else if(strcasecmp(&s[0],&t[0]) == 0) cout << "case-insensitive"<< endl;
   else cout << "different" << endl;
}

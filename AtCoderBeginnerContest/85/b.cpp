#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n;
   cin >> n;
   vector<int> d(n);
   rep(i,n) cin >> d[i];

   set<int> s;
   rep(i,n) s.insert(d[i]);
   cout << s.size() << endl;
}
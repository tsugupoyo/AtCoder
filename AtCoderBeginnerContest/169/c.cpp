#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   ll a;
   long double b;
   cin >> a >> b;
   long double tmp = a*b;
   string s = to_string(tmp);
   int i = s.find('.');
   cout << s.substr(0,i)<< endl;
}
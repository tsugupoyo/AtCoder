#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

const string str[4] = {"AC", "WA", "TLE", "RE"};

int main(void) 
{
   int n;
   cin >> n;
    map<string, int> mp;
   rep(i,n){
       string s;
       cin >> s;
       mp[s]++;
   }
   rep(i,4) printf("%s x %d \n",str[i].c_str(), mp[str[i]]);
}
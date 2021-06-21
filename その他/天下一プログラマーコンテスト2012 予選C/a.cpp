#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
  int n;
  cin >> n;
  vector<bool> isPrime(n+1, true);
  isPrime[0] == isPrime[1] == false;
  ll ans = 0;
  for(int i = 2 ;i < n; i++)
  {
     if(isPrime[i])
     {
        for(int j = 2*i; j <n; j += i) isPrime[j] = false;
        ans ++;
     }
  }
  cout << ans << endl;
}

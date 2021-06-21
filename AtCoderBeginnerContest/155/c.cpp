#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using P = pair<string,int>;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int longest = 0;
    map<string, int> ansMap;
    for(string str : s)
    {
        ansMap[str] += 1;
    }
    vector <string> ans;
    for(auto data : ansMap)
    {
        if(longest < data.second) longest = data.second;
    }

    for(auto data : ansMap) if(data.second == longest) ans.emplace_back(data.first);

    rep(i,ans.size()) cout << ans[i] << endl;
}
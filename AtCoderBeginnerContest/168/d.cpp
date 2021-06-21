#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;


int main(void) 
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n];

    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> que;
    vector<int> ans (n, -1);
    que.push(0);
    while(!que.empty()){
        int a = que.front(); que.pop();

       // cout << a << endl;
        for(int b : graph[a])
        {
            if(ans[b] == -1) 
            {
                ans[b] = a;
                que.push(b);
            }
        }
    }

    rep(i,n-1) if(ans[i+1] == -1)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep(i,n-1) cout << ans[i+1]+1 << endl;
}
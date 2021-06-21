#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using P = pair<int,int>;

struct UnionFind {
  vector<int> d;
  UnionFind(int n): d(n,-1) {}
  int root(int x) {
    if (d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  int size(int x) { return -d[root(x)];}
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int follow[100005];
    vector<int> block[100005];

    UnionFind tree(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        //友達インクリメント
        follow[a]++;
        follow[b]++;
        //結合
        tree.unite(a,b);      
    }

    rep(i,k){
        int a, b;
        cin >> a >> b;
        --a; --b;
        block[a].emplace_back(b);
        block[b].emplace_back(a);
    }

    rep(i,n){
        //友達のグループから　自分と既に友達の数を引く
        int ans = tree.size(i) - 1 - follow[i];
        //ブロックされているペアも引く(同じグループに限る)
        for(int b : block[i]){
            if(tree.same(i,b)) --ans;
        }
        printf("%d ",ans);
    }
    cout << endl;
} 
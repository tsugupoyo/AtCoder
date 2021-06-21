#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(void) 
{
    #pragma region Vector
    //vector push
    vector<int> vec;
    vec.emplace_back(1);
    vec.emplace_back(2);
    vec.emplace_back(3);

    //size
    printf("vector\n");
    rep(i,vec.size()) cout << vec[i] << endl;

    #pragma endregion

    #pragma region Queue
    //queue
    queue<int> q;
    //push
    rep(i,3) q.push(i);

    //pop front
    rep(i,3) {
        q.front(); q.pop();
    }

    #pragma endregion

    #pragma region  Sort
    vector<int> target = {4,7,3,5,9,1};
    sort(target.begin(),target.end());
    printf("sort\n");
    rep(i,target.size()) cout << target[i] << endl;
    sort(target.rbegin(),target.rend());
    printf("reverse\n");
    rep(i,target.size()) cout << target[i] << endl;
    
    #pragma endregion
    
    #pragma region map
    map<string,int> m;
    // 挿入
    m.insert(make_pair("string1", 30));
    m.insert(make_pair("string2", 10));
    m.insert(make_pair("string", 20));

    // 検索 : キーを指定し、値を得る
    int value = m.at("string1");
    cout << "map: "<< value << endl;

    #pragma endregion
    
    
    return 0;
}

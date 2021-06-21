#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

struct menu
{
  int s;
  int p;
};

void Step1()
{
  int m;
  cin >> m;
  map<int, menu> data;
  rep(i,m)
  {
    int d;
    menu tmp;
    cin >> d >> tmp.s >> tmp.p;
    data[d] = tmp;
  }
  while(1)
  {
    string order;
    cin >> order;
    if(order != "order") break;
    int t,d,n;
    cin >> t >> d >> n;

    int rem = data[d].s;
    if(rem >= n)
    {
      data[d].s -= n;
      rep(i,n) cout << "received order " << t << " " << d << endl;
    }
    else 
    {
      cout << "sold out " << t << endl;
    }
  }
}

void Step2()
{
  int m, k;
  cin >> m >> k;
  map<int, menu> data;
  rep(i,m)
  {
    int d;
    menu tmp;
    cin >> d >> tmp.s >> tmp.p;
    data[d] = tmp;
  }
  vector<int> oven(k,-1);
  queue<int> waits;
  vector<int> orders;
  while(1)
  {
    string response;
    cin >> response;
    if(response == "received")
    {
      string order;
      int t,d;
      cin >> order >> t >> d;
      int openIndex = -1;
      rep(i,k) if(oven[i] == -1)
      {
        openIndex = i;
        break;
      }
      if(openIndex == -1)
      {
        waits.push(d);
        cout << "wait" << endl;
      }
      else 
      {  
        oven[openIndex] = d;
        cout << d << endl;
      }
      orders.push_back(d);
    }
    else if(response == "complete")
    {
      int d;
      cin >> d;
      int open = -1;
      bool hasOrder = false;
      rep(i,orders.size()) 
      {
        if(orders[i] == d) 
        {
          hasOrder = true;
          orders.erase(orders.begin() + i);
          break;
        }
      }
      if(!hasOrder)
      {
        cout << "unexpected input" << endl;
        continue;
      }
      rep(i,k) 
      {
        if(oven[i] == d) 
        {
          oven[i] = -1;
          open = i;
          break;
        }
      }
      if(waits.size() == 0)
      {
        cout << "ok" << endl;
      }
      else
      {
        int tmp = waits.front(); waits.pop();
        cout << "ok " << tmp << endl;
        oven[open] = tmp;
      }   
    }
    else break;    
  }
}

void Step3()
{
  int m;
  cin >> m;
  map<int, menu> data;
  rep(i,m)
  {
    int d;
    menu tmp;
    cin >> d >> tmp.s >> tmp.p;
    data[d] = tmp;
  }
  vector<vector<int>> orders(10000000);

  while(1)
  {
    string response;
    cin >> response;
    if(response == "received")
    {
      string order;
      int t, n;
      cin >> order >> t >> n;
      orders[n].push_back(t);
    }
    else if(response == "complete")
    {
      int n;
      cin >> n;
      cout << "ready " << orders[n][0] << " " << n << endl;
      orders[n].erase(orders[n].begin());
    }
    else break;   
  }
}

void Step4()
{
  int m;
  cin >> m;
  map<int, menu> data;
  rep(i,m)
  {
    int d;
    menu tmp;
    cin >> d >> tmp.s >> tmp.p;
    data[d] = tmp;
  }

  vector<vector<int>> orders(10000000);

  while(1)
  {
    string response;
    cin >> response;
    if(response == "received")
    {
      string order;
      int t, n;
      cin >> order >> t >> n;
      orders[n].push_back(t);
    }
    else if(response == "readby")
    {
      int n;
      cin >> n;
      cout << "ready " << orders[n][0] << " " << n << endl;
      orders[n].erase(orders[n].begin());
    }
    else if(response == "check")
    {
      
    }
    else break;   
  }

}

int main(int argc, char *argv[]) {
  int step;
  cin >> step;
  if(step == 1)
  {
    Step1();
  } 
  else if(step == 2)
  {
    Step2();
  }
  else if(step == 3)
  {
    Step3();
  }
  else
  {
    Step4();
  }
  
  return 0;
}
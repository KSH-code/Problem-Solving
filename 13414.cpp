#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

void solve(){
  int a,b;cin>>a>>b;
  map<string,int>m;
  vector<pair<string,int>>v;
  for (int i = 0; i < b; i++) {
    string s; cin >> s;
    m[s]++;
    v.push_back({s,m[s]});
  }
  for (auto [c,d] : v) {
    if (m[c]==d && a) {
      a--;
      cout << c << '\n';
    }
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}

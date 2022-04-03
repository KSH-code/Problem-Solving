#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <memory.h>
using namespace std;

typedef long long ll;

const int MAX = 3e6;
pair<int,int> parent[MAX];
map<string,int> mp;
int parent_count = 0;

void merge(int x,int y);

pair<int,int> find(int x) {
  if (parent[x].first == x) return parent[x];
  return parent[x] = find(parent[x].first);
}

void merge(int x, int y) {
  auto [a,b] = find(x);
  auto [c,d] = find(y);
  if (a == c) return;
  parent[a] = {c, b+d};
  parent[c] = {c, b+d};
}

void solve(){
  mp.clear();
  parent_count = 0;
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    string a,b; cin >> a>>b;
    if (!mp.count(a)) {
      mp[a] = ++parent_count;
      parent[parent_count] = {parent_count,1};
    }
    if (!mp.count(b)) {
      mp[b] = ++parent_count;
      parent[parent_count] = {parent_count,1};
    }
    merge(mp[a],mp[b]);
    cout << find(mp[a]).second<< '\n';
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  while(T--) solve();
  return 0;
}

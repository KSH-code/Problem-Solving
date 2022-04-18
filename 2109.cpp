#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long ll;


void solve(){
  int N; cin >>N;
  pair<int,int> arr[N];
  for (int i = 0; i < N; i++) {
    cin >>  arr[i].second>>arr[i].first;
  }
  sort(arr, arr+N);
  multiset<int> s;
  for (int i = 0; i < N; i++) {
    auto [a,b] = arr[i];
    s.insert(b);
    if (a < s.size()) s.erase(s.begin());
  }
  int result = 0;
  for (auto r : s) {
    result += r;
  }
  cout << result;
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}

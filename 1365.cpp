#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

void solve(){
  int N; cin >> N;
  set<int> arr;
  for (int i =0;i<N;i++) {
    int t; cin >> t;
    if (arr.lower_bound(t) != arr.end()) arr.erase(arr.lower_bound(t));
    arr.insert(t);
  }
  cout << N-arr.size();
}

int main(){
  cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}

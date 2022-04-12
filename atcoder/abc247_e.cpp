#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

void solve(){
  int N, X, Y; cin >> N >> Y >> X;
  queue<pair<int,int>> xq;
  queue<pair<int,int>> yq;
  int arr[N+1];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] == X) xq.push({arr[i], i});
    if (arr[i] == Y) yq.push({arr[i], i});
  }

  ll result = 0;
  int lq = 0;
  while(xq.size()) {
    auto [x, l] = xq.front();
    while(yq.size()) {
      auto [y, r] = yq.front(); yq.pop();
      bool found = true;
      for (int i = l; i <= r; i++) {
        found &= arr[i] > y;
      }
      if (found) {
        result += r - l + 1;
        lq = i;
      }
    }
  }
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}

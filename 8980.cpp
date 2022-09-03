#include <bits/stdc++.h>

using tiii = std::tuple<int,int,int>;
using pii = std::pair<int,int>;

void solve(){
  int c,N, K; std::cin >> c>>K >> N;
  tiii arr[N]; for (auto &[a,b,c] : arr) std::cin >> a>>b>>c;

  auto compare = [](tiii a, tiii b){
    auto [x1,x2,x3] = a;
    auto [y1,y2,y3] = b;
    if (x1 == y1)
      return x2 <= y2;
    return x1 <= y1;
  };
  sort(arr,arr+N,compare);

  std::multiset<pii> s;
  int cur = 0;
  int result = 0;
  for (int i = 0; i < N; i++) {
    auto [a,b,c] = arr[i];
    while (s.size()) {
      auto [x1,x2] = *s.begin();
      if (x1 > a) break;
      s.erase(s.begin());
      cur -= x2;
      result += x2;
    }
    if (cur + c <= K) {
      cur += c;
      s.insert({b,c});
    } else {
      while (s.size()) {
        auto it = --s.end();
        auto [x1,x2] = *it;
        if (b >= x1) {
          break;
        } else {
          if (K - cur >= c) break;
          if (K - cur + x2 <= c) {
            s.erase(it);
            cur -= x2;
          } else {
            int r = c - (K - cur);
            s.erase(it);
            s.insert({x1, x2 - r});
            cur -= r;
            break;
          }
        }
      }
      int n = std::min(K - cur, c);
      if (!n) continue;
      cur += n;
      s.insert({b, n});
    }
  }
  for (auto [a,b] : s) {
    result += b;
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}

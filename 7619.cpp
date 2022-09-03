#include <bits/stdc++.h>

typedef long long ll;

void solve(int N){
  ll arr[10]; memset(arr, 0, sizeof arr);
  std::priority_queue<ll> q;
  for (int i = 0; i < N; i++) {
    ll t; std::cin >> t;
    if (t) q.push(t);
    for (int j = 0; j < 10; j++) {
      ll a; std::cin >> a;
      arr[j] += a;
    }
  }

  ll xxxx[] = {1,5,10,25,100,500,1000,2000,5000,10000};
  while (q.size()) {
    auto remains = q.top(); q.pop();
    int t = 9;
    for (; (!arr[t] || arr[t] > remains) && t > 0; t--) {}
    ll c = std::min(remains / xxxx[t], arr[t]);
    ll f = remains - (25 * c);
    if (c & 1 && t == 3 && f >= 1 && f <= 5 && arr[2] >= 3) {
      if (arr[0] < f && (f == 5 && !arr[1])) {
        c--;
        remains -= 30;
        arr[2] -= 3;
      }
    }
    f = remains - (5000 * c);
    if (c & 1 && t == 8 && f >= 1000 && arr[7] >= 3) {
      for (int i = 0; i <= 6; i++) f -= arr[i] * xxxx[i];
      if (f > 0) {
        c--;
        remains -= 6000;
        arr[7] -= 3;
      }
    }
    remains -= xxxx[t] * c;
    arr[t] -= c;
    if (remains) q.push(remains);
    if (!c) {
      std::cout << "NO";
      return;
    }
  }

  std::cout << "YES";
}

int main(){
  int i = 1;
  while (1) {
    int T; std::cin >> T;
    if (!T) break;
    printf("Case %d: ", i++);
    solve(T);
    std::cout << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>

void solve(){
  int N, K; std::cin >> N >> K;
  long long arr[N]; for (auto &a : arr) std::cin >> a;
  std::sort(arr, arr+N);
  unsigned long long l = 0, r = std::pow(2,63);
  while (l + 1 < r) {
    long long result = 0;
    unsigned long long m = (l + r) / 2;
    long long temp_arr[N]; for (int i = 0; i < N; i++) temp_arr[i] = arr[i];
    while (1) {
      long long temp = arr[N-1];
      int idx = std::lower_bound(temp_arr, temp_arr+N, 1) - temp_arr;
      if (N - idx < K) break;
      result += temp_arr[idx];
      for (int i = K - 1; i >= 0; i--) {
        temp_arr[idx + i] -= temp_arr[idx];
      }
    }
    if (m <= result) l = m;
    else r = m;
  }

  std::cout << l;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}

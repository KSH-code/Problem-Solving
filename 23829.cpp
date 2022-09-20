#include <bits/stdc++.h>

using ll = long long;
void solve(){
  ll N, M; std::cin >> N >> M;
  int arr[N]; for (auto &a : arr) std::cin >> a;
  std::sort(arr, arr+N);

  ll prefix_sum_left[N]; prefix_sum_left[0] = arr[0];
  for (int i = 1; i < N; i++) prefix_sum_left[i] = arr[i] + prefix_sum_left[i - 1];
  ll prefix_sum_right[N]; prefix_sum_right[N-1] = 0;
  for (int i = N-2; i >= 0; i--) prefix_sum_right[i] = arr[N-1] - arr[i] + prefix_sum_right[i + 1];

  while (M--) {
    ll cur; std::cin >> cur;
    int l = std::upper_bound(arr, arr+N, cur) - arr - 1; // same or less
    int r = l + 1; // upper bound
    ll result = 0;
    if (r == 0) result += prefix_sum_left[N-1] - cur * N;
    else if (r != N) result += prefix_sum_left[N-1] - prefix_sum_left[r-1] - cur * (N-r);

    if (l + 1 < N) result += prefix_sum_right[0] - prefix_sum_right[l+1] - (arr[N-1] - cur) * (l+1);
    else if (l == N - 1) result += prefix_sum_right[0] + std::abs(arr[N-1] - cur) * N;
    std::cout << result << '\n';
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}

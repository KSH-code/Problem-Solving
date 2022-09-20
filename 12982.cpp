#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  long long result = 0;
  int arr[N]; for (auto &a : arr) {
    std::cin >> a;
    result += a/N;
    a %= N;
  }
  std::sort(arr, arr+N);

  int cur = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i] <= cur) continue;

    int count = N - i;
    int diff = (arr[i]-cur)%N;
    if (diff > count) {
      result += 1;
      result += (arr[i]-cur)/N;
    } else {
      cur += diff;
      result += diff;
    }
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}

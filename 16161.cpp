#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;

  int arr[N]; for (auto &a : arr) std::cin >> a;

  int result = 1;
  int s = 0;
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (!i || arr[i] > arr[i-1]) {
      count++;
    } else {
      bool is_even = i && arr[i-1] == arr[i];
      int temp_result = !is_even;
      for (int j = 0; j < count-(!is_even); j++) {
        int c = i+j;
        if (c < N) {
          if (arr[c] == arr[i-1-j-(!is_even)]) {
            temp_result += 2;
          } else break;
        }
      }
      result = std::max(result, temp_result);
      s = i;
      count = 1;
    }
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}

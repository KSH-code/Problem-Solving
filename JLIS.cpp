#include <bits/stdc++.h>

void solve(){
  int a,b; std::cin >> a >> b;
  int N = a + b;
  int A[10000]; for (int i = 0; i < a; i++) std::cin >> A[i];
  int B[10000]; for (int i = 0; i < b; i++) std::cin >> B[i];
  int arr[10000];
  for (int i = 0; i < a; i++) arr[i] = A[i];
  for (int i = 0; i < b; i++) arr[i + a] = B[i];

  int result = 0;
  int memo[10000]; memset(memo, 0, sizeof memo);
  for (int i = N - 1; i >= 0; i--) {
    memo[i] = 1;
    for (int j = i + 1; j < N; j++) {
      memo[i] = std::max(memo[i], arr[i] < arr[j] ? memo[j] + (arr[i] < arr[j]) : 0);
    }
    result = std::max(result, memo[i]);
  }

  for (int i = 0; i < b; i++) arr[i] = B[i];
  for (int i = 0; i < a; i++) arr[i + b] = A[i];
  int memo2[10000]; memset(memo2, 0, sizeof memo2);
  for (int i = N - 1; i >= 0; i--) {
    memo2[i] = 1;
    for (int j = i + 1; j < N; j++) {
      memo2[i] = std::max(memo2[i], arr[i] < arr[j] ? memo2[j] + (arr[i] < arr[j]) : 0);
    }
    result = std::max(result, memo2[i]);
  }

  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  int T; std::cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
    std::cout << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>

void solve(){
  int N, Q;
  scanf("%d%d",&N,&Q);
  int fibo[N+1];
  fibo[0] = 0;
  fibo[1] = 1 % Q;
  for (int i = 2; i <= N; i++) fibo[i] = (fibo[i-1] + fibo[i-2]) % Q;
  std::cout << fibo[N];
}

int main(){
  // std::cin.tie(0)->sync_with_stdio(false);
  int N; std::cin >> N;
  for (int i = 1; i <= N; i++) {
    printf("Case #%d: ", i);
    solve();
    printf("\n");
  }
  return 0;
}

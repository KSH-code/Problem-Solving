#include <bits/stdc++.h>

void solve(){
  int N, M, Q; std::cin >> N >> M >> Q;
  int arr[M+2]; for (int i = 1; i <= M; i++) std::cin >> arr[i];
  arr[0] = 0;
  arr[M+1] = Q;
  std::sort(arr,arr+M+2);

  while(N--) {
    int z; std::cin >> z;
    int l = 0, r = Q + 1;
    while (l + 1 < r) {
      int m = (l + r) / 2;
      int f = 0;
      int c = 0;
      for (int i = 1; i <= M + 1; i++)  {
        f += arr[i] - arr[i - 1];
        if (m <= f) {
          c++;
          f = 0;
        }
      }
      if (c > z) l = m;
      else r = m;
    }
    std::cout << l << '\n';
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}

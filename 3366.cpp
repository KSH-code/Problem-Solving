#include <bits/stdc++.h>

using pii = std::pair<int,int>;

const int MAX = 1e6;
int parents[MAX];
pii go[MAX];

int find(int x) {
  if (parents[x] == x) return x;
  auto [l,r] = go[x];
  auto [pl,pr] = go[parents[x]];
  go[parents[x]] = go[x] = {
    std::min(l, pl),
    std::max(r, pr)
  };
  return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
  parents[find(x)] = parents[find(y)];
  find(x);
}

void solve(){
  int N; std::cin >> N;
  pii arr[N];
  pii arr2[N];
  int arr3[N];
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i].first;
    arr[i].second = i;
    arr3[i] = arr[i].first;
    parents[i] = i;
    go[i] = {std::max(0,i-1), std::min(N-1, i+1)};
  }
  sort(arr,arr+N);
  long long result = 0;
  for (int i = 0; i < N - 1; i++) {
    auto [a,b] = arr[i];
    int d = 2e9;
    int index = -1;
    auto [l,r] = go[find(b)];
    if (d >= arr3[l] && find(b) != find(l)) {
      index = find(l);
      d = arr3[index];
    }
    if (d >= arr3[r] && find(b) != find(r)) {
      index = find(r);
      d = arr3[index];
    }
    d = std::max(a,d);
    merge(b, index);
    arr3[index] = arr3[b] = d;
    result += d;
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}

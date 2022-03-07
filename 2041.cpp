#include <iostream>
using namespace std;
typedef long long ll;
ll a = 1;
ll c = 1;
ll f() { return (a *= -1) * c++; }

int main(){
  cin.tie(nullptr) -> sync_with_stdio(false);

  int N, M; cin >> N >> M;
  ll arr[N][M]; for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) arr[i][j] = 0;
  if (N + M == 2) {
    cout << 0;
    return 0;
  }
  arr[0][0] = 2 * N * M;
  for (int i = 1; i < M; i++) arr[0][i] = arr[0][i - 1] + f();
  if (M % 2 == 0) a *= -1;

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < M; j++) {
      arr[i][j] = arr[i - 1][j] + f();
    }
    for (int j = 0; j < M - 1; j++) f();
  }

  for (int i = 0; i < N ; i++) {
    for (int j = 0; j < M; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}

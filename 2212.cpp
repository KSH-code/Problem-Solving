#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


void solve(){
  int N, K; cin >> N >> K;

  int arr[N];
  for (int i = 0; i < N; i++) cin >> arr[i];

  sort(arr, arr+N);

  int dis[N-1];
  for (int i = 1; i < N; i++) dis[i-1] = arr[i] - arr[i-1];
  sort(dis, dis+N-1);

  int result = 0;
  for (int i = 0; i < N-K; i++) result += dis[i];

  cout << result;
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}

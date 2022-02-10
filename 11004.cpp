#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int N, K; cin >> N >> K;
  int arr[N];
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);

  cout << arr[K - 1];
  return 0;
}

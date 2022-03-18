#include <iostream>
using namespace std;
typedef long long ll;

int N;
pair<int,int> arr[10];

int solve(int x){
  if (x == N) return 0;
  if (arr[x].first <= 0) return solve(x + 1);

  int result = 0;
  int temp_result = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i].first <= 0) continue;
    if (i == x) continue;

    arr[x].first -= arr[i].second;
    arr[i].first -= arr[x].second;
    result = max(result, solve(x + 1) + (arr[x].first <= 0) + (arr[i].first <= 0));
    arr[x].first += arr[i].second;
    arr[i].first += arr[x].second;
  }
  return result;
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  cout << solve(0);
  return 0;
}

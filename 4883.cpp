#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

bool dp(int r){
  int N;
  cin >> N;
  if (N == 0) return false;

  ll arr[N][3]; for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  ll result[N][3];
  result[0][1] = arr[0][1];
  result[0][0] = 1e9;
  result[0][2] = arr[0][2] + result[0][1];
  for (int i = 1; i < N; i++) {
    result[i][0] = result[i][1] = result[i][2] = 1e9;
    for (int j = 0; j <= 1; j++) result[i][0] = min(result[i][0], result[i-1][j]);
    result[i][0] += arr[i][0];

    for (int j = 0; j <= 2; j++) result[i][1] = min(result[i][1], result[i-1][j]);
    result[i][1] = min(result[i][0], result[i][1]);
    result[i][1] += arr[i][1];

    for (int j = 1; j <= 2; j++) result[i][2] = min(result[i][2], result[i-1][j]);
    result[i][2] = min(result[i][1], result[i][2]);
    result[i][2] += arr[i][2];
  }

  cout << r << ". " << result[N-1][1] << '\n';
  return true;
}

int main(){
  int i = 1;
  while (dp(i++));
  return 0;
}

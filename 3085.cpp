#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

string arr[50];
int N;

int check() {
  int result = 0;
  for (int i = 0; i < N; i++) {
    int count = 1;
    char a = arr[i][0];
    for (int j = 1; j < N; j++) {
      if (a == arr[i][j]) {
        count++;
      } else {
        result = max(result, count);
        count = 1;
        a = arr[i][j];
      }
    }
    result = max(result, count);
  }
  for (int i = 0; i < N; i++) {
    int count = 1;
    char a = arr[0][i];
    for (int j = 1; j < N; j++) {
      if (a == arr[j][i]) {
        count++;
      } else {
        result = max(result, count);
        count = 1;
        a = arr[j][i];
      }
    }
    result = max(result, count);
  }
  return result;
}

void solve(){
  cin >> N;
  for (int i =0;i<N; i++) {
    cin >> arr[i];
  }
  int result = 0;
  for (int i = 0; i <N; i++) {
    for (int j = 0; j <N;j++) {
      if (j+1<N) {
        swap(arr[i][j], arr[i][j+1]);
        result = max(result, check());
        swap(arr[i][j], arr[i][j+1]);
      }

      if (i+1<N) {
        swap(arr[i][j], arr[i+1][j]);
        result = max(result, check());
        swap(arr[i][j], arr[i+1][j]);
      }
    }
  }
  cout << result;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}

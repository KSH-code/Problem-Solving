#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  bool arr[N+1];
  for (int i=1;i<=N;i++) cin >> arr[i];

  int T;
  cin >> T;
  while (T--) {
    int g, n;
    cin >> g >> n;
    if (g==1) {
      for (int i = n; i <= N; i += n) arr[i] = !arr[i];
    } else {
      arr[n] = !arr[n];
      int c = 1;
      while (n + c <= N && n - c > 0) {
        if (arr[n + c] == arr[n - c]) {
          arr[n + c] = !arr[n + c];
          arr[n - c] = !arr[n - c];
        } else break;
        c++;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << (arr[i] ? 1 : 0) << " ";
    if (i % 20 == 0) cout << "\n";
  }
}

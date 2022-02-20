#include <iostream>
#include <deque>
using namespace std;

int main(){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  int arr[N]; for (int i = 0;i < N; i++) cin >> arr[i];

  deque<int> dq;
  for (int i = N-1; i >= 0; i--) {
    int j = N - i;
    switch(arr[i]) {
      case 1:
        dq.push_front(j);
        break;
      case 2: {
        int f = dq.front();
        dq.pop_front();
        dq.push_front(j);
        dq.push_front(f);
        break;
      }
      case 3:
        dq.push_back(j);
        break;
    }
  }

  for (int j : dq) cout << j << " ";
  return 0;
}

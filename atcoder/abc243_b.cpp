#include <iostream>
#include <set>
using namespace std;

int main(){
  int N; cin >> N;
  int A[N], B[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  int same = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == B[i]) same++;
  }

  cout << same << '\n';

  set<int> s;

  for (int i = 0; i < N; i++) {
    s.insert(A[i]);
  }

  int diff = 0;
  for (int i = 0; i < N; i++) {
    if (s.find(B[i]) != s.end()) diff++;
  }

  cout << diff - same;
  return 0;
}

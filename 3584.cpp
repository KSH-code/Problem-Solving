#include <iostream>
#include <set>
using namespace std;
typedef long long ll;


void solve(){
  int N; cin >> N;
  int parent[N+1];
  for (int i = 1; i<= N;i++) parent[i]=i;
  for (int i = 1; i < N; i++) {
    int a, b; cin >> a >> b;
    parent[b] = a;
  }
  int a,b; cin >> a>>b;
  set<int> s;
  while (!s.count(a)) {
    s.insert(a);
    a = parent[a];
  }
  while (!s.count(b)) {
    b = parent[b];
  }
  cout << b;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int T;cin>>T;while(T--) {
    solve();
    cout <<'\n';
  }

  return 0;
}

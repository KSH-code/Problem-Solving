#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

typedef long long ll;

void solve(){
  int V,E;
  cin >> V>>E;
  vector<vector<int>> adj(V+1);

  while(E--){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  unordered_set<int> A, B;


  for (int i = 1; i <= V; i++) {
    queue<int> q;
    if (A.find(i) == A.end() && B.find(i) == B.end()) {
      q.push(i);
    }
    while (q.size()) {
      auto a = q.front();
      for (auto next : adj[a]) {
        if (A.find(a) != A.end()) {
          if (B.find(next) == B.end()) {
            q.push(next);
            B.insert(next);
          }
        } else {
          if (A.find(next) == A.end()) {
            q.push(next);
            A.insert(next);
          }
        }
      }
      q.pop();
    }
  }

  for (int i = 1; i <= V; i++) {
    bool a = A.find(i) != A.end();
    bool b = B.find(i) != B.end();
    if (a && b) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int K;
  cin >> K;
  while (K--) solve();
  return 0;
}

#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Node {
  map<string, Node*> nodes;

  Node* insert(string n) {
    if (!nodes.count(n)) nodes[n] = new Node;
    return nodes[n];
  }
};

void dfs(Node *head, int count) {
  for (auto [key, node] : head->nodes) {
    cout << string(count, '--') << key << '\n';
    dfs(node, count+2);
  }
}

void solve(){
  int N; cin >> N;
  Node *head = new Node;
  for (int i = 0; i < N; i++) {
    int M; cin >> M;
    Node *temp = head;
    for (int j = 0; j < M; j++) {
      string s; cin >> s;
      temp = temp->insert(s);
    }
  }
  dfs(head, 0);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}

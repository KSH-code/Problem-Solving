#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

struct Node {
  Node *nodes[10];
  bool is_end;

  Node() : is_end(false) {
    memset(nodes, 0, sizeof(nodes));
  }

  ~Node(){
    for (int i = 0; i < 10; i++) if (nodes[i]) delete nodes[i];
  }

  Node* insert(int n) {
    if (!nodes[n]) nodes[n] = new Node;
    return nodes[n];
  }
};

void solve(){
  int N; cin >> N;
  string arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
  Node *head = new Node;
  string result = "YES";
  for (int i = 0; i < N; i++) {
    string str = arr[i];
    Node *temp = head;
    for (int j = 0; j < str.size(); j++) {
      temp = temp->insert(str[j] - '0');
      if (temp->is_end) result = "NO";
    }
    for (int j = 0; j < 10; j++) {
      if (temp->nodes[j]) result = "NO";
    }
    temp->is_end = true;
  }
  cout << result;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int T; cin >> T;
  while (T--){
    solve();
    cout <<'\n';
  }
  return 0;
}

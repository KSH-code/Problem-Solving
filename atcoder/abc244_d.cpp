#include <iostream>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

const ll MAX = 1e18;
struct Node{
  char a,b,c;
  ll count;
};
void solve(){
  char s1,s2,s3; cin >> s1 >> s2 >> s3;
  char t1,t2,t3; cin >> t1 >> t2 >> t3;

  queue<Node> q;
  q.push({s1,s2,s3,0});
  while (q.size()) {
    auto [a,b,c,count] = q.front(); q.pop();
    if (count % 2 == 0 && (t1 == a && t2 == b && t3 == c)) {
      cout << "Yes";
      return;
    }
    int nc=count+1;
    if (nc >= 15) break;
    q.push({b,a,c,nc});
    q.push({c,b,a,nc});
    q.push({a,c,b,nc});
  }
  cout << "No";
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}

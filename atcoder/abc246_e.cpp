#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;
struct Node {
    int x, y,c;
};
struct Compare {
    bool operator()(const Node& m1, const Node& m2) {
        return m1.c > m2.c;
    }
};
void solve(){
  int N; cin >> N;
  int ax,ay; cin >> ax>>ay;
  int bx,by; cin >> bx>>by;
  ax--,ay--,bx--,by--;

  string map[N]; for (int i = 0; i<N;i++) cin >> map[i];
  bool visited[N][N]; memset(visited,0,sizeof(visited));
  int counts[N][N]; memset(counts,-1,sizeof(counts));

  priority_queue<Node,vector<Node>,Compare> q; q.push({ax,ay,0});
  while(q.size()) {
    auto [x,y,count] = q.top(); q.pop();
    if (x == bx && y == by) {
      cout << count << endl;
      return;
    }
    int xxxx[]= {-1,-1,1,1};
    int yyyy[]= {-1,1,1,-1};
    int nc = count+1;
    for (int i = 0; i < 4; i++) {
      int nx = x+xxxx[i];
      int ny = y+yyyy[i];
      while (nx >=0 && ny >=0 && nx < N && ny < N && map[nx][ny] == '.') {
        if ((!visited[nx][ny]) && (counts[nx][ny] == -1 || counts[nx][ny] > nc)) {
          visited[nx][ny] = true;
          counts[nx][ny]=nc;
          q.push({nx,ny,nc});
        }
        nx += xxxx[i];
        ny += yyyy[i];
      }
    }
  }
  cout << -1;
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}

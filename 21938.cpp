#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef long long ll;

struct RGB{
  int r,g,b;
};

void solve(){
  int N, M; cin >> N >> M;

  RGB rgbs[N][M];
  int arr[N][M];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> rgbs[i][j].r >> rgbs[i][j].g >> rgbs[i][j].b;
    }
  }

  int T; cin >> T;

  queue<pair<int,int>> q;
  bool visited[N][M]; memset(visited, false, sizeof(visited));
  int result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (rgbs[i][j].r+rgbs[i][j].g+rgbs[i][j].b >= T*3) {
        arr[i][j]=255;
      } else arr[i][j] = 0;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j]==255 && !visited[i][j]) {
        result++;
          q.push({i,j});
          int xxxx[]= {-1,1,0,0};
          int yyyy[]= {0,0,-1,1};
          while (q.size()) {
            auto [x,y]=q.front(); q.pop();
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
              int nx = x + xxxx[i];
              int ny = y + yyyy[i];
              if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
              if (arr[nx][ny] ==0 || visited[nx][ny]) continue;
              visited[nx][ny]=true;
              q.push({nx,ny});
            }
          }
      }
    }
  }
  cout << result;
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
int map[11][11];
vector<vector<pair<int,int>>> v(2);

bool vertical[2][100];
bool horizontal[2][100];

int dfs(int x, int z) {
  int result = 0;
  while (x < v[z].size()) {
    auto [i,j] = v[z][x];
    if (!horizontal[z][i + j] && !vertical[z][N - j - 1 + i]) {
      vertical[z][N - j - 1 + i] = horizontal[z][i + j] = true;
      result = max(result, dfs(x + 1, z) + 1);
      vertical[z][N - j - 1 + i] = horizontal[z][i + j] = false;
    }
    x++;
  }
  return result;
}

int solve(){
  cin >> N;
  for (int i =0; i<N; i++)for(int j=0;j<N;j++){
    cin >> map[i][j];
    if(map[i][j]) v[(i+j)%2].push_back({i,j});
  }
  return dfs(0, 0) + dfs(0, 1);
}

int main(){
  cin.tie(0) -> sync_with_stdio(false);

  cout << solve();
  return 0;
}

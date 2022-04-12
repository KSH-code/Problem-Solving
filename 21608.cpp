#include <iostream>
using namespace std;

typedef long long ll;

const int MAX = 900;
int arr[MAX][MAX];
int likes[MAX][4];
int N;

int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

bool ob(int x,int y) {
  return x<1 || y < 1 || x > N || y > N;
}
int sum(int x, int y) {
  int a=0, n = arr[x][y];
  for (int i = 0; i < 4; i++) {
    int nx=x+xxxx[i];
    int ny=y+yyyy[i];
    if(ob(nx,ny)) continue;

    for (int j = 0; j < 4; j++) {
      if (arr[nx][ny] == likes[n][j]) {
        a ? a*=10 : a=1;
        break;
      }
    }
  }
  return a;
}

pair<int,int> point(int x, int y, int n) {
  int a=0,b=0;
  for (int i = 0; i < 4; i++) {
    int nx=x+xxxx[i];
    int ny=y+yyyy[i];
    if(ob(nx,ny)) continue;
    if (arr[nx][ny] == 0) {
      b++;
      continue;
    }

    for (int j = 0; j < 4; j++) {
      if (arr[nx][ny] == likes[n][j]) {
        a++;
        break;
      }
    }
  }
  return {a,b};
}

void solve(){
  cin >> N;
  for (int i = 1; i<=N*N;i++) {
    int a; cin >> a;
    for(int j = 0; j < 4; j++) {
      int b; cin >> b;
      likes[a][j] = b;
    }
    pair<int,int> p = {-1,0};
    int c,d;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (arr[i][j]) continue;
        if (p < point(i,j,a)) {
          p = point(i,j,a);
          c = i;
          d = j;
        }
      }
    }
    arr[c][d]=a;
  }
  ll result = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      result += sum(i,j);
    }
  }
  cout << result;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
int map[50][50];
int dp[50][50][50][50];

struct Node {
    int a,b;
};

int check(const Node &xx, const Node &yy) {
    int count = 0;
    for (int i = xx.a; i <=xx.b; i++) {
        for (int j = yy.a; j <= yy.b; j++) {
            count += map[i][j];
        }
    }
    return count;
}

int go (const Node &xx, const Node &yy) {
    if (dp[xx.a][xx.b][yy.a][yy.b]) return dp[xx.a][xx.b][yy.a][yy.b];

    int result = check(xx,yy);
    int t=1e9;
    for (int i = xx.a; i < xx.b; i++) {
        int r = go({xx.a,i},yy) + go({i+1,xx.b},yy);
        t =min({t,r});
    }
    for (int i = yy.a; i < yy.b; i++) {
        int r = go(xx,{yy.a,i}) + go(xx,{i+1,yy.b});
        t =min({t,r});
    }
    if (t==1e9) return 0;
    return dp[xx.a][xx.b][yy.a][yy.b]=result+t;
}

void solve(){
    cin >> N >> M;
    for (int i = 0; i < N ;i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int result = go({0,N-1}, {0,M-1});
    cout << result;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

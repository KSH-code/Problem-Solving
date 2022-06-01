#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={0,0,1,-1};
int yyyy[]={1,-1,0,0};

int N;

bool visited[51][51];

long double t[4];
long double result=0;

void dfs(int x, int y, int count, long double moved) {
    if (count == 0) {
        result += moved;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (!t[i]) continue;

        int nx = x+xxxx[i];
        int ny = y+yyyy[i];
        int nc = count-1;

        if (visited[nx][ny]) continue;

        visited[nx][ny]=true;

        dfs(nx,ny,nc, moved*t[i]);

        visited[nx][ny]=false;
    }
}

void solve(){
    cin >> N;

    for (int i = 0; i < 4; i++) cin >> t[i];
    for (int i = 0; i < 4; i++) t[i]=t[i]/100;

    visited[25][25]=true;

    dfs(25,25, N,1);

    printf("%.10Lf", result);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

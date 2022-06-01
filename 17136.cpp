#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

int m[10][10];

int result = 26;

int arr[5];

bool f() {
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) if (m[i][j]) return false;
    return true;
}

bool check(int x, int y, int c) {
    if (!arr[c]) return false;

    for (int i = 0; i <= c; i++) {
        for (int j = 0; j <= c; j++) {
            auto nx = x+i;
            auto ny = y+j;
            if (nx > 9 || ny > 9) return false;
            if (!m[nx][ny]) return false;
        }
    }
    return true;
}

int r(){
    int t = 25;
    for (int i = 0; i < 5; i++) t-=arr[i];
    return t;
}

void dfs() {
    if (f()) {
        result = min(result,r());
        return;
    }

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (!m[x][y]) continue;

            for (int c = 4; c >= 0; c--) {
                if (!check(x,y,c)) continue;

                arr[c]--;
                for (int i = 0; i <= c; i++) for (int j = 0; j <= c; j++) m[x+i][y+j] = 0;

                dfs();

                arr[c]++;
                for (int i = 0; i <= c; i++) for (int j = 0; j <= c; j++) m[x+i][y+j] = 1;
            }
            return;
        }
    }
}

void solve(){
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) cin >> m[i][j];
    fill(arr, arr+5, 5);

    dfs();

    if (result == 26) result = -1;
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

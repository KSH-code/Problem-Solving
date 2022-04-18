#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;
int N;
int map[20][20];

struct Node {
    int a,b;
};

int check(const Node &xx, const Node &yy) {
    int count = 0;
    int f = 0;
    for (int i = xx.a; i <=xx.b; i++) {
        for (int j = yy.a; j <= yy.b; j++) {
            if (map[i][j] == 2) count++;
            if (map[i][j] == 1) f++;
        }
    }
    if (count == 1 && f == 0) return 1;
    if (count - f >= 1) return 2;
    return 0;
}

int go (const Node &xx, const Node &yy, bool direction) {
    if (check(xx,yy)==0) return 0;
    if (check(xx,yy)==1) return 1;

    int result = 0;
    for (int i = xx.a; i <= xx.b; i++) {
        for (int j = yy.a; j <= yy.b; j++) {
            if (map[i][j] != 1) continue;
            if (direction) {
                bool no = false;
                for (int z = yy.a; z <= yy.b; z++)
                    if (map[i][z] == 2) no = true;
                if (!no) result += go({xx.a, i-1}, yy, !direction) * go({i+1, xx.b}, yy, !direction);
            } else {
                bool no = false;
                for (int z = xx.a; z <= xx.b; z++)
                    if (map[z][j] == 2) no = true;
                if (!no) result += go(xx, {yy.a,j-1}, !direction) * go(xx, {j+1,yy.b}, !direction);
            }
        }
    }
    return result;
}

void solve(){
    cin >> N;
    for (int i = 0; i < N ;i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int result = go({0,N-1},{0,N-1},0)+go({0,N-1},{0,N-1},1);
    cout << (!result ? -1 : result);
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

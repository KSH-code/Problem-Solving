#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

struct Node {
    int a,b,c;
    int count;
};
int n_map[3][3];
tuple<int,int,int> destructure(int a) {
    return {a/100, a/10%10,a%10};
}
int structure(int a[3]) {
    return a[0]*100+a[1]*10+a[2];
}
void solve(){
    int map[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> map[i][j];
        }
    }
    if (structure(map[0]) == 123 && structure(map[1]) == 456 && structure(map[2]) == 780) {
        cout << 0;
        return;
    }

    set<tuple<int,int,int>> s;

    queue<Node> q;
    q.push({123,456,780,0});

    while (q.size()) {
        auto [a,b,c,count] = q.front(); q.pop();

        auto [a1,a2,a3] = destructure(a);
        auto [b1,b2,b3] = destructure(b);
        auto [c1,c2,c3] = destructure(c);

        n_map[0][0] = a1;
        n_map[0][1] = a2;
        n_map[0][2] = a3;

        n_map[1][0] = b1;
        n_map[1][1] = b2;
        n_map[1][2] = b3;

        n_map[2][0] = c1;
        n_map[2][1] = c2;
        n_map[2][2] = c3;

        int fx = 0;
        int fy = 0;
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
            if (n_map[i][j] == 0) {
                fx=i;
                fy=j;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = fx + xxxx[i];
            int ny = fy + yyyy[i];
            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;

            int next_map[3][3]; for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) next_map[j][k] = n_map[j][k];
            swap(next_map[nx][ny], next_map[fx][fy]);
            int na=structure(next_map[0]);
            int nb=structure(next_map[1]);
            int nc=structure(next_map[2]);
            if (s.count({na,nb,nc})) continue;
            if (structure(map[0]) == na && structure(map[1]) == nb && structure(map[2]) == nc) {
                cout << count + 1;
                return;
            }
            s.insert({na,nb,nc});
            q.push({na,nb,nc,count+1});
        }
    }
    cout << -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

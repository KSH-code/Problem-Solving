#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long ll;

string map[5];
vector<pair<int, int>> positions;
bool used[5];

int found[5];
int result = 1e10;

void distance(int x, int d) {
    if (x == positions.size()) {
        result = min(result, d);
        return;
    }

    int temp_result = 9999;
    for (int i = 0; i < positions.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        auto [px,py] = positions[x];
        int dx = found[i]/5, dy = found[i]%5;
        distance(x+1, d+abs(px-dx)+abs(py-dy));
        used[i] = false;
    }
    result = min(result, temp_result);
}

bool check(){
    queue<pair<int,int>> q;
    bool visited[5][5]; memset(visited, 0, sizeof(visited));
    int first = found[0];
    q.push({first/5, first%5}); visited[first/5][first%5] = true;
    int count = 1;
    while (q.size()) {
        auto [x,y] = q.front(); q.pop();
        int xxxx[] = {-1,0,1,0};
        int yyyy[] = {0,-1,0,1};
        for (int i = 0; i < 4; i++) {
            int nx = x + xxxx[i];
            int ny = y + yyyy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (visited[nx][ny]) continue;
            bool ch = false;
            for (int j = 0; j < positions.size(); j++) {
                if (found[j] == nx*5+ny) ch = true;
            }
            if (!ch) continue;
            visited[nx][ny] = true;
            q.push({nx,ny});
            count++;
        }
    }

    if (count != positions.size()) return false;

    return true;
}

void combination(int x, int f) {
    if (x == positions.size()) {
        if (check()) distance(0,0);
        return;
    }

    for (int i = f; i < 25; i++) {
        found[x] = i;
        combination(x+1, i+1);
    }
}

void solve(){
    for (int i = 0; i < 5; i++) {
        cin >> map[i];
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == '*') positions.push_back({i,j});
        }
    }
    combination(0,0);
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

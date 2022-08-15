#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

typedef pair<int,int> pii;

void solve(){
    int N, M, L; cin >> N >> M >> L;
    string arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
    string name; cin >> name;
    int data[26]; memset(data, 0, sizeof data);
    for (auto c : name) data[c - 'a']++;

    queue<pii> str_queue[26];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        str_queue[arr[i][j]-'a'].push({i,j});
    }

    int result = 9999;
    for (int i = 0; i < 26; i++) if (data[i]) result = min(result, (int) str_queue[i].size() / data[i]);

    vector<char> result_move;
    int x = 0, y = 0;
    for (int _i = 0; _i < result; _i++) {
        for (auto c : name) {
            auto [nx,ny] = str_queue[c-'a'].front(); str_queue[c-'a'].pop();
            if (nx < x) {
                for (int i = 0; i < x - nx; i++) result_move.push_back('U');
            }
            if (nx > x) {
                for (int i = 0; i < nx - x; i++) result_move.push_back('D');
            }
            if (ny < y) {
                for (int i = 0; i < y - ny; i++) result_move.push_back('L');
            }
            if (ny > y) {
                for (int i = 0; i < ny - y; i++) result_move.push_back('R');
            }
            result_move.push_back('P');
            x = nx;
            y = ny;
        }
    }

    int nx = N-1;
    int ny = M-1;
    if (nx < x) {
        for (int i = 0; i < x - nx; i++) result_move.push_back('U');
    }
    if (nx > x) {
        for (int i = 0; i < nx - x; i++) result_move.push_back('D');
    }
    if (ny < y) {
        for (int i = 0; i < y - ny; i++) result_move.push_back('L');
    }
    if (ny > y) {
        for (int i = 0; i < ny - y; i++) result_move.push_back('R');
    }

    cout << result << ' ' << result_move.size() << '\n';
    for (auto c : result_move) cout << c;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

int N;
int cc[26];
int ns[10];
string arr[10];
set<char> letters;
set<int> candidates;
ll result;

bool visited[26];
bool n_visited[26];


void calculate() {
    ll z = 0;
    for (int i = 0; i < N; i++) {
        ll t = 0;
        for (auto letter : arr[i]) {
            if (!visited[letter-'A']) return;

            t *= 10;
            t += cc[letter-'A'];
        }
        z += t;
    }

    result=max(result,z);
}

void dfs() {
    calculate();

    for (auto letter : letters) {
        auto f = letter-'A';
        if (visited[f]) continue;

        visited[f] = true;

        for (int j = 0; j < 10; j++) {
            if (n_visited[j]) continue;

            cc[f]=j;n_visited[j]=true;

            dfs();
            n_visited[j]=false;
        }

        visited[f] = false;
        return;
    }
}

void solve(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) for (int j = 0; j < arr[i].size(); j++) letters.insert(arr[i][j]);

    dfs();

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

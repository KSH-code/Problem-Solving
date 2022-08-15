#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

using pci = pair<char,int>;
void solve(){
    int N, M; cin >> N >> M;
    bool chain[2*N+1];
    for (int i = 1; i <= 2*N; i++) chain[i] = true;
    set<int> chains;
    set<int> blocks;
    queue<pci> q;
    for (int i = 0; i < M; i++) {
        char user;
        string type;
        int number;
        cin >> user >> type >> number;
        chain[number] = false;
        blocks.insert(-number);
        q.push({user, number});
    }

    for (int i = 1; i <= 2*N; i++) if (chain[i]) chains.insert(i);

    queue<string> result;

    int fn;
    char ut;
    while (q.size()) {
        auto [u, n] = q.front(); q.pop();
        ut = u;
        fn = n;
        result.push(string(1,u) + " BLOCK " + to_string(n));
        blocks.erase(-n);

        if (q.size()) {
            auto [nu, _] = q.front();

            bool even = nu != u;

            auto it = blocks.upper_bound(-n);
            int limit = 0;
            if (it == blocks.end()) limit = *(--blocks.end()) * -1;

            int c = 0;
            it = chains.upper_bound(fn);
            while (it != chains.end() && *it <= limit) {
                ut = ut == 'A' ? 'B' : 'A';
                result.push(string(1,ut) + " CHAIN " + to_string(*it));
                chains.erase(it);
                c++;
                it = chains.upper_bound(fn);
            }

            if ((even && c % 2 == 1) || (!even && c % 2 == 0)) {
                it = chains.upper_bound(fn);
                if (it == chains.end()) break;

                ut = ut == 'A' ? 'B' : 'A';
                result.push(string(1,ut) + " CHAIN " + to_string(*it));
                chains.erase(it);
            }
        }
    }

    while (chains.upper_bound(fn) != chains.end()) {
        ut = ut == 'A' ? 'B' : 'A';
        auto it = chains.upper_bound(fn);
        result.push(string(1,ut) + " CHAIN " + to_string(*it));
        chains.erase(it);
    }

    if (result.size() != 2*N) {
        cout << "NO";
        return;
    }

    cout << "YES\n";
    while (result.size()) {
        cout << result.front() << '\n';
        result.pop();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

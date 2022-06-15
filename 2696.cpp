#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


void solve(){
    int N; cin >> N;

    queue<int> rq;

    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;

    for (int i = 0; i < N; i++) {
        int r; cin >> r;
        min_q.push(r);

        if (i%2==0) {
            while (min_q.size() - 1 != max_q.size()) {
                if (max_q.empty() || min_q.top() >= max_q.top()) {
                    max_q.push(min_q.top()); min_q.pop();
                } else {
                    min_q.push(max_q.top()); max_q.pop();
                }
            }

            rq.push(min_q.top());
        }
    }


    cout << rq.size() << '\n';

    int i = 0;
    while (rq.size()) {
        if (i == 10) {
            i = 0;
            cout << '\n';
        }
        cout << rq.front() << ' ';
        rq.pop();
        i++;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >> N;
    while (N--) {
        solve();
        cout << '\n';
    }
    return 0;
}

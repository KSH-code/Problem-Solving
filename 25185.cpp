#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void isolve(){
    string arr[4];
    for (int i = 0; i < 4; i++) cin >> arr[i];

    set<string> s;

    bool found = false;
    for (int i = 0; i < 4; i++) s.insert(arr[i]);
    found |= s.size() <= 2;


    for (int i = 0; i < 4; i++) {
        bool d[10]; memset(d, 0, sizeof(d));
        for (int j = 0; j < 4; j++) {
            if (arr[j][1] == arr[i][1]) d[arr[j][0]-'0']=true;
        }

        int count = 0;
        for (int j = 1; j < 10; j++) {
            if (d[j]&&d[j-1]) {
                count++; found |= count == 2;
            }
            else count = 0;
        }

        found |= count>=2;
    }

    cout << (found?":)":":(");
}

void solve(){
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        isolve();
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

typedef pair<int,int> pii;

const int MAX=1e6;

void solve(){
    int N; cin >> N;
    set<int> x_list;
    set<int> y_list;

    pii data[N];
    for (int i = 0; i < N; i++) {
        int a,b; cin >> a >> b;
        x_list.insert(a);
        y_list.insert(b);
        data[i]={a,b};
    }

    map<int,int> x_table, y_table;
    for (auto x : x_list) x_table[x]=x_table.size()+1;
    for (auto y : y_list) y_table[y]=y_table.size()+1;

    int arr[x_list.size()+1][y_list.size()+1]; memset(arr, 0, sizeof arr);
    for (auto [x,y] : data) arr[x_table[x]][y_table[y]]++;

    for (int i = 1; i <= x_table.size(); i++) {
        for (int j = 1; j <= y_table.size(); j++) {
            arr[i][j] += arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
        }
    }

    int result = N;

    for (int i = 1; i <= x_table.size(); i++) {
        for (int j = 1; j <= y_table.size(); j++) {
            int temp_result = max({
                arr[i][j],
                arr[i][y_table.size()] - arr[i][j],
                arr[x_table.size()][j] - arr[i][j],
                arr[x_table.size()][y_table.size()] + arr[i][j] - arr[x_table.size()][j] - arr[i][y_table.size()],
            });

            result = min(result, temp_result);
        }
    }


    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

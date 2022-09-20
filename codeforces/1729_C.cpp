#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string str; cin >> str;

    int N = str.size();
    int result = 0;
    char last = str[N - 1];
    char first = str[0];
    pair<int,int> arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = {str[i] - 'a', i};
    }
    sort(arr,arr+N);

    if (first <= last) {
        int start = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i].first == first - 'a') {
                start = i;
                break;
            }
        }
        int end = 0;
        for (int i = N-1; i >= 0; i--) {
            if (arr[i].first == last - 'a') {
                end = i;
                break;
            }
        }
        cout << last - first << ' ' << end - start + 1 << '\n';
        while (start <= end) {
            auto [a,b] = arr[start];
            cout << b+1 << ' ';
            start++;
        }
    } else {
        int start = 0;
        for (int i = N-1; i >= 0; i--) {
            if (arr[i].first == first - 'a') {
                start = i;
                break;
            }
        }
        int end = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i].first == last - 'a') {
                end = i;
                break;
            }
        }
        cout << first - last << ' ' << start - end + 1 << '\n';
        cout << 1 << ' ';
        while (start >= end) {
            auto [a,b] = arr[start];
            if (b != N-1 && b != 0) cout << b+1 << ' ';
            start--;
        }
        cout << N << ' ';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}

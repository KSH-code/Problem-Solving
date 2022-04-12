#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
void solve(){
    int N,M; cin >> N>>M;
    string strs[N];
    for (int i = 0; i < N; i++) cin >> strs[i];
    string result = "";
    int result_distance = 0;

    for (int j = 0; j < M; j++) {
        char c;
        map<char,int> m;
        int max_distance = 0;
        for (int i = 0; i < N; i++) m[strs[i][j]]++;
        for (auto [dna, count]: m) {
            if (count > max_distance) {
                max_distance = count;
                c = dna;
            }
            result_distance += count;
        }
        result_distance -= max_distance;
        result += c;
    }
    cout << result << '\n' << result_distance;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}

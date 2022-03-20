#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >> N;
    int arr[N]; for (int i =0 ;i<N;i++) cin >> arr[i];
    set<int> s;
    for (int i = 1; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            s.insert(arr[i] + arr[j]);
        }
    }

    int result = 0;
    set<int> s; for (int i = 0; i < N; i++) s.insert(arr[i]);
    for (int i = 0; i < N - 2; i++) {
        int z = arr[i] + m[i];
        if (s.find(z) != s.end()) result = max(result, z);
    }
    cout << result;
    return 0;
}

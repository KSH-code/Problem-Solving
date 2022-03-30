#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >> N;
    int arr[N]; for (int i =0 ;i<N;i++) cin >> arr[i];
    map<int, int > m;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            m[arr[j]-arr[i]]=arr[j];
        }
    }
    int result = 0;
    for (int i = 0;i<N; i++) {
        for (int j = i;j<N;j++) {
            int k = arr[i]+arr[j];
            if (!m.count(k)) continue;

            result = max(result, m[k]);
        }
    }
    cout << result;
    return 0;
}

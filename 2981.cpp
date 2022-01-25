#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N ;cin>>N;
    vector<int> arr(N);
    for (int i = 0; i < N;i++) cin >> arr[i];
    sort(arr.begin(),arr.end());


    int gcd_result = arr[1] - arr[0];
    for (int i = 0; i < N - 1;i++) gcd_result = gcd(gcd_result, arr[i + 1] - arr[i]);

    vector<int> result;
    for (int i = 2; i * i <= gcd_result; i++) {
        if (gcd_result % i > 0) continue;
        result.push_back(i);
        if (i * i == gcd_result) continue;
        result.push_back(gcd_result / i);
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << gcd_result;
    return 0;
}

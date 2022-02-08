#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int T;
    cin >> T;

    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i = 2; i < 1e9; i++)
    {
        int f = fibo[i - 1] + fibo[i - 2];
        if (f >= 1e9)
            break;
        fibo.push_back(f);
    }
    while (T--)
    {
        int n;
        cin >> n;

        vector<int> result;
        while (n)
        {
            vector<int>::iterator iter = upper_bound(fibo.begin(), fibo.end(), n);
            result.push_back(fibo[iter - fibo.begin() - 1]);
            n -= fibo[iter - fibo.begin() - 1];
        }

        for (int i = result.size() - 1; i >= 0; i--)
            cout << result[i] << " ";
        cout << "\n";
    }
    return 0;
}
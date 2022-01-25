#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{
    int N;
    cin >> N;
    ll distances[N];
    ll prices[N];
    N--;
    for (int i = 0; i < N; i++)
        cin >> distances[i];
    for (int i = 0; i < N; i++)
        cin >> prices[i];

    ll next_price = prices[0];
    ll total_price = distances[0] * next_price;
    for (int i = 1; i < N; i++)
    {
        next_price = min(prices[i], next_price);
        total_price += distances[i] * next_price;
    }

    cout << total_price;
    return 0;
}
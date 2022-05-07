#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 500;

int parent[MAX];
map<string, int> dict;

vector<string> split(string input, char delimiter) {
	vector<string> strs;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		strs.push_back(temp);
	}

	return strs;
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(string k1, string k2) {
    int x = dict[k1];
    int y = dict[k2];
    int px = find(x);
    int py = find(y);
    if (px == py) {
        parent[x] = parent[px] = parent[py] = x;
    } else parent[find(y)] = parent[find(x)];
}

void solve(){
    string str;
    getline(cin, str);
    auto data = split(str, ' ');
    int N = stoi(data[0]);
    int M = stoi(data[1]);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        string str; getline(cin, str);
        string kingdom = split(str, ' ').back();
        dict[kingdom] = i;
    }

    for (int i = 0; i < M; i++) {
        string str; getline(cin, str);
        auto data = split(str, ',');
        string kingdom1 = split(data[0], ' ').back();
        string kingdom2 = split(data[1], ' ').back();
        if (data.back() == "2") {
            merge(kingdom2, kingdom1);
        } else {
            merge(kingdom1, kingdom2);
        }
    }

    set<string> result;
    for (auto [kingdom, x] : dict) {
        if (parent[x] == x) result.insert(kingdom);
    }
    cout << result.size() << '\n';
    for (auto kingdom : result) {
        cout << "Kingdom of " << kingdom << '\n';
    }
}

int main()
{
    solve();
    return 0;
}

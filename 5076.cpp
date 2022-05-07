#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> split(string input, char delimiter) {
	vector<string> strs;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		strs.push_back(temp);
	}

	return strs;
}

void solve(string str){
    stack<string> tags;
    vector<string> tokens;
    bool is_parsing = false;

    bool yes = true;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];

        if (c == '<') {
            string tag;
            bool yes = false;
            for (int j = i + 1; j < str.size(); j++) {
                i = j;
                if (str[j] == '>') {
                    yes = true;
                    break;
                }
                tag += str[j];
            }
            auto go = split(tag, ' ');
            if (go.back() == "/") {

            } else if (go[0][0] == '/') {
                if (tags.empty() || tags.top() != go.back()) {
                    cout << "illegal";
                    return;
                }
                 tags.pop();
            } else {
                tags.push("/" + go[0]);
            }
            if (!yes) {
                cout << "illegal";
                return;
            }
        } else if (c == '>') {
            cout << "illegal";
            return;
        }
    }
    if (tags.empty()) {
        cout << "legal";
    } else {
        cout << "illegal";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    while (true) {
        string str; getline(cin, str);
        if (str == "#") break;
        solve(str);
        cout << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Student {
    int n, solved, penalty;
    string last_time;
    int point;
    bool operator <(const Student &user) const {
        if (user.solved == solved) {
            if (user.penalty == penalty) {
                // 마지막 정답 제출 시간이 빠른 참가자
                return last_time > user.last_time;
            }
            // 패널티의 총합이 더 적은 참가자
            return penalty > user.penalty;
        }
        // 해결한 문제의 수가 더 많은 참가자
        return solved < user.solved;
    }
};

struct Compare {
    bool operator()(const Student& s1, const Student& s2) {
        return s1 < s2;
    }
};


struct Data {
    string time;
    int n,p,s;
};

const int MAX = 5e4;

Student students[MAX+1];
vector<Data> freezed[MAX+1];

int N,M;

void apply(Student &student, const Data data) {
    auto [t,n,p,s] = data;
    student.n = n;
    student.last_time = t;
    student.solved++;
    int a = (t[1]-'0')*60+((t[3]-'0')*10+t[4]-'0');
    student.penalty += (s-1)*20+a;
}

void solve(){
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        string time; cin >> time;
        int n,p,s; cin >> n >> p >> s;
        Data data = {time,n,p,s};
        if (data.time >= "03:00") {
            freezed[n].push_back(data);
        } else {
            apply(students[n-1], data);
        }
    }

    priority_queue<Student, vector<Student>, Compare> q;
    for (int i = 0; i < N; i++) {
        q.push(students[i]);
    }
    sort(students, students + N);

    int max_point = 0;
    while (q.size()) {
        auto student = q.top(); q.pop();

        int before = 0;
        while (students[before].n != student.n) before++;
        for (auto data : freezed[student.n]) apply(students[before], data);

        sort(students, students + N);

        int after = 0;
        while (students[after].n != student.n) after++;

        int point = before - after;
        students[after].point = point;
        max_point = max(point, max_point);
    }

    for (int i = N-1; i >= 0; i--) {
        if (students[i].point == max_point) {
            cout << students[i].n;
            return;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}

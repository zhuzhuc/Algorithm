#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Attack {
    int damage;
    int cooldown;
    int next_use;

    bool operator<(const Attack &other) const {
        return damage < other.damage;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int h, n;
        cin >> h >> n;

        vector<int> a(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        priority_queue<Attack> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({a[i], c[i], 0});
        }

        int turns = 0;
        int current_time = 0;

        while (h > 0) {
            vector<Attack> ready;
            while (!pq.empty() && pq.top().next_use <= current_time) {
                ready.push_back(pq.top());
                pq.pop();
            }

            if (ready.empty()) {
                current_time = pq.top().next_use;
                continue;
            }

            int total_damage = 0;
            for (const auto &attack : ready) {
                total_damage += attack.damage;
                pq.push({attack.damage, attack.cooldown, current_time + attack.cooldown});
            }

            h -= total_damage;
            turns++;
            current_time++;
        }

        cout << turns << "\n";
    }

    return 0;
}

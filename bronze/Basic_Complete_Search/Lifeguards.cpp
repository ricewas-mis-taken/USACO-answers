#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> lifeguard;

    for (int i{}; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        lifeguard.push_back({a, b}); // records start and end time
    }
    int time{};
    for (int i{}; i < n; ++i)
    {
        vector<bool> slots(1001, false); // marks if each "slot" of time has a lifeguard on duty
        for (int j{}; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            for (int k{lifeguard[j].first}; k < lifeguard[j].second; ++k)
            {

                slots[k] = true;
            }
        }
        int tempTime = count(slots.begin(), slots.end(), true);
        time = max(time, tempTime);
    }
    cout << time;
}

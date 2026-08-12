#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    vector<vector<int>> rankings;
    for (int i{}; i < k; ++i)
    {
        vector<int> temp;
        for (int j{}; j < n; ++j)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        rankings.push_back(temp);
    }
    int consistent{};            // consistent pairs
    vector<pair<int, int>> done; // pairs that have already been recorded as consistent
    for (int i{}; i < n; ++i)
    {
        int first = rankings[0][i]; // first of the pair
        for (int j{}; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }

            int second = rankings[0][j];        // second of the pair
            bool always{true};                  // declared here so goto can work
            for (int a{}; a < done.size(); ++a) // making sure pair hasn't been recorded yet
            {
                if ((done[a].first == first && done[a].second == second) || (done[a].first == second && done[a].second == first))
                {
                    goto end;
                }
            }

            if (i > j)
            {
                for (int a{}; a < k; ++a)
                {
                    // getting the positions of the next time the pair shows up
                    auto pfirst = find(rankings[a].begin(), rankings[a].end(), first);
                    auto psecond = find(rankings[a].begin(), rankings[a].end(), second);
                    if (pfirst < psecond)
                    {
                        always = false;
                        break;
                    }
                }
            }
            else
            {
                for (int a{}; a < k; ++a)
                {
                    auto pfirst = find(rankings[a].begin(), rankings[a].end(), first);
                    auto psecond = find(rankings[a].begin(), rankings[a].end(), second);
                    if (pfirst > psecond)
                    {
                        always = false;
                        break;
                    }
                }
            }
            if (always)
            {
                ++consistent;
                done.push_back({first, second}); // record the pair
            }

        end:;
        }
    }
    cout << consistent;
}

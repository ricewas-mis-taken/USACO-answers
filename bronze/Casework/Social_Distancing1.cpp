#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef set<int> si;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int n;
    cin >> n;

    vector<int> positions; // get positions of the cows, this is the best way over marking over every spot
    for (int i{}; i < n; ++i)
    {
        char c;
        cin >> c;

        if (c == '1')
        {
            positions.pb(i);
        }
    }
    int minD{INT_MAX};         // the smallest gap, we need to record this b/c we insert into BIGGEST gap
    vi one;                    // gap size once we insert one cow
    int both{};                // gap size once we insert both into one gap
    if (positions.size() == 0) // edge case
    {
        cout << (n - 1);
        return 0;
    }
    else if (positions.size() == 1) // edge case
    {
        goto target;
    }

    for (int i{1}; i < positions.size(); ++i) // get minD
    {
        minD = min(minD, (positions[i] - positions[i - 1]));
    }

    for (int i{1}; i < positions.size(); ++i) // find all the gaps for one cow or two
    {
        one.pb((positions[i] - positions[i - 1]) / 2);
        both = max(both, ((positions[i] - positions[i - 1]) / 3));
    }
target:;
    int lead = positions[0];              // how many before the first position
    int trail = n - 1 - positions.back(); // how many after the last one

    one.pb(lead);
    one.pb(trail);

    both = max(both, lead / 2);
    both = max(both, trail / 2);

    sort(one.rbegin(), one.rend());
    cout << min(minD, max(one[1], both));
}

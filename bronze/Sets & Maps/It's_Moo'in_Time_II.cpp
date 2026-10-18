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

    int n;
    cin >> n;

    set<int> unique;         // amount of unique #s
    vi uniquebefore(n);      // amount of unique #s before a certain # was put in
    map<int, vector<int>> m; // map to check how many of a # exist
    for (int i{}; i < n; ++i)
    {
        int x;
        cin >> x;

        uniquebefore[i] = unique.size();
        unique.insert(x);

        m[x].pb(i);
    }

    ll moos{};
    auto it = m.begin();
    for (auto it = m.begin(); it != m.end(); ++it) // iterate over whole smap
    {
        int subtract1{}; // might need to subtract 1 if second > 3
        if (it->second.size() < 2)
        {
            continue;
        }

        else if (it->second.size() >= 3)
        {
            ++subtract1;
        }
        moos += (1LL * uniquebefore[*(it->second.rbegin() + 1)] - subtract1); // rbegin is reverse iterator, needs to plus 1,
    }
    cout << moos;
}

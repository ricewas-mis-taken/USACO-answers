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

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;

    string mailboxes;
    cin >> mailboxes;

    for (int i{}; i < n; ++i)
    {                      // how many in each test string
        bool twice{false}; // will be set to true if something ever comes up twice
        set<string> seen;
        for (int j{}; j < (n - i); ++j)
        { // the amount of test strings
            string test;
            for (int k{j}; k <= (j + i); ++k)
            { // putting it into the test string
                test.pb(mailboxes[k]);
            }
            auto check = seen.insert(test); // use an auto to get the nice return of pair<iterator,bool> (position,true/false if already in set)
            if (check.second == false)      // does already exist in the set
            {
                twice = true;
                break;
            }
        }
        if (!twice)
        {
            cout << (i + 1);
            break;
        }
    }
}

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

    int n, x;
    cin >> n >> x;

    map<int, int> m;  // use map, unordered map is technically faster, but hashing kills it
    bool impos{true}; // toggle false if a different answer happens
    for (int i{}; i < n; ++i)
    { // use the key as the value to find the position very easily

        int a;
        cin >> a;

        auto it = m.find(x - a);
        if (it != m.end())
        {
            cout << it->second << " " << (i + 1); // don't forget to add 1!
            impos = false;
            break;
        }
        else
        {
            m[a] = (i + 1); // here too! zero indexing ugh
        }
    }
    if (impos)
    {
        cout << "IMPOSSIBLE";
    }
}

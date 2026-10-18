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

    map<int, int> m;
    bool impos{true};
    for (int i{}; i < n; ++i)
    {
        int temp;
        cin >> temp;

        if (m.count(x - temp) == 1)
        {
            cout << (i + 1) << " " << m[x - temp];
            impos = false;
            break;
        }
        m[temp] = (i + 1);
    }
    if (impos)
    {
        cout << "IMPOSSIBLE";
    }
}

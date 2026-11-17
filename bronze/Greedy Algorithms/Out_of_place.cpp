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

    freopen("outofplace.in", "r", stdin);

    freopen("outofplace.out", "w", stdout);
    int n;
    cin >> n;

    vector<int> heights;

    for (int i{}; i < n; ++i)
    {
        int x;
        cin >> x;
        heights.pb(x);
    }
    vi sorted_heights = heights;
    sort(sorted_heights.begin(), sorted_heights.end());
    int swaps{};
    for (int i{}; i < n; ++i)
    {
        if (sorted_heights[i] != heights[i]) // if not equal, need to swap
        {
            ++swaps;
        }
    }
    --swaps; // subtract one, this is essential, I discovered this by working out the sample case manually
    cout << swaps;
}

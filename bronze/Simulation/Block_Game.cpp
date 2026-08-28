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
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n;
    cin >> n;

    int letters[26] = {}; // array, zeroes for all 26 letters

    for (int i{}; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        int top[26] = {};    // to see how many characters we need on the top
        int bottom[26] = {}; // same for bottom

        for (int j{}; j < a.size(); ++j)
        {
            top[a[j] - 97]++; // subtract 97, ascii code stuff, then increment that specific letter
        }
        for (int j{}; j < b.size(); ++j)
        {
            bottom[b[j] - 97]++; // subtract 97, ascii code stuff, then increment that specific letter
        }
        for (int j{}; j < 26; ++j)
        {
            letters[j] += max(bottom[j], top[j]); // find the max of the top and bottom and add to the master list
        }
    }
    for (int i : letters)
    {
        cout << i << "\n";
    }
}

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
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<char> original, given;

    for (char c : a)
    {
        original.pb(c);
    }
    for (char c : b)
    {
        given.pb(c);
    }

    int uses{};    // amount of times you have to use machine
    int counter{}; // use counter to keep track of if previous cows had needed a flip or not
    for (int i{}; i < n; ++i)
    {
        if (original[i] != given[i]) // add one to the counter, showing that at least one cow before next one needs a machine use
        {
            ++counter;
        }
        else
        {
            if (counter > 0) // we have arrived at a place where flipping is not neccessary, flip everythign before
            {
                ++uses;
            }
            counter = 0; // then reset the usage
        }
    }

    cout << uses;
}

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
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y;
    cin >> x >> y;
    int distance_traveled{};
    int cpos{};     // current position, not required, but its easier than writing out round(pow()),etc
    int counter{};  // counter of the power multiplier
    bool foo{true}; // just for the edge case below
    if (x == y)
    {
        foo = false;
    }
    while (true)
    {
        cpos = 0;
        cpos = x + round(pow(2, counter)); // notice that in the question, Farmer John walks in powers of 2
        if (x < y)
        {
            if (cpos >= y)
            {
                distance_traveled += (y - x);
                break;
            }
        }
        distance_traveled += (2 * (round(pow(2, counter)))); // has to walk over to cpos, then back to x, this tripped me up too
        ++counter;
        cpos = 0;
        cpos = x - round(pow(2, counter));
        if (x > y)
        {
            if (y >= cpos)
            {
                distance_traveled += (x - y);
                break;
            }
        }
        distance_traveled += 2 * ((round(pow(2, counter))));
        ++counter;
    }
    cout << distance_traveled;
}

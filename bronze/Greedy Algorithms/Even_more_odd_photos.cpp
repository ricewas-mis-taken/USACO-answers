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

    int evens{}, odds{}; // # evens, # odds

    for (int i{}; i < n; ++i)
    {
        int x;
        cin >> x;

        if (x % 2 == 0) // use modulo to find
        {
            ++evens;
        }
        else
        {
            ++odds;
        }
    }

    int groups{};
    bool needodd{false}; // does the next group need to be odd?
    while (true)
    {
        if (!needodd)
        {
            if (evens > 0) // cheapest way to get even
            {
                --evens;
                ++groups;
            }
            else if (odds >= 2) // only other way
            {
                odds -= 2;
                ++groups;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (odds > 0) // only way to get even
            {
                --odds;
                ++groups;
            }
            else
            {
                break;
            }
        }
        needodd = !needodd;
    }

    if (odds != 0 && (odds % 2 != 0)) // two odds can be reassigned to not change the parity, however with one odd, you need to subtract one group
    {
        --groups;
    }

    cout << groups;
}

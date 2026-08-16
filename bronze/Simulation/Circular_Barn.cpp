#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;

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

    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n;

    deque<int> room; // use a deque so we can dynamically move the rooms around
    for (int i{}; i < n; ++i)
    {
        int temp;
        cin >> temp;
        room.pb(temp);
    }

    int distance{INT_MAX};

    for (int i{}; i < n; ++i)
    {
        int counter{}; // increment this to symbolize distance walked
        int temp{};    // temp compared to distance
        for (int j{}; j < n; ++j)
        {
            temp += (room.front() * counter); // the # of cows that fill the room, multiplied by the counter
            ++counter;                        // increment counter
            room.pb(room.front());            // move the cows to the back, they will not be calculated until next "i" iteration
            room.pop_front();                 // remove the extra copy in the front
        }
        distance = min(distance, temp);
        room.pb(room.front()); // do one extra cow move, so the next "i" iteration doesn't repeat over the exact same values
        room.pop_front();
    }
    cout << distance;
}

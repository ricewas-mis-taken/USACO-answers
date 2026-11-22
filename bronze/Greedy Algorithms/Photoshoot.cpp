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

    string s;
    cin >> s;

    bool switched{false};             // if we just switched all cows to the left, therefore all pairs need to be switched
    int switches{};                   // how many switches needed
    for (int i{n - 1}; i > 0; i -= 2) // start from back and move forward, this way we only worry about cows to our left
    {
        char left = s[i - 1]; // the left cow in the two-cow pair
        char right = s[i];    // the right cow
        if (switched)
        {
            swap(left, right); // simply swap them
        }
        if (left == 'G' && right == 'H') // incorrect order, swap!
        {
            ++switches;
            switched = !switched;
        }
    }
    cout << switches;
}

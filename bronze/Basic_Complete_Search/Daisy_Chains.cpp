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

    int n;
    cin >> n;
    vi flowers;
    for (int i{}; i < n; ++i)
    {
        int temp;
        cin >> temp;
        flowers.pb(temp);
    }

    int perfect{}; // amount of photos with perfect flowers

    for (int i{}; i < n; ++i)
    {

        for (int j{}; j < n; ++j)
        {
            if (i > j) // making sure that each pair is only computed once
            {
                continue;
            }
            int tPetals{}; // amount of total petals in the image
            for (int k{i}; k <= j; ++k)
            {
                tPetals += flowers[k];
            }
            int remainder = tPetals % (j - i + 1);
            int average = tPetals / (j - i + 1);
            if (remainder == 0)
            {
                for (int k{i}; k <= j; ++k)
                {
                    if (flowers[k] == average)
                    {
                        ++perfect;
                        break; // so can't add more then one
                    }
                }
            }
        }
    }
    cout << perfect;
}

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

    vi weights;

    for (int i{}; i < n * 2; ++i)
    {
        int temp;
        cin >> temp;
        weights.pb(temp);
    }
    vi master_weights = {weights.begin(), weights.end()}; // NEED THIS OR WEIGHTS WILL NEVER BE RESTORED
    int min_unstable{INT_MAX};
    for (int i{}; i < n * 2; ++i)
    {
        for (int j{}; j < n * 2; ++j) // literally brute force everything, go through every possible and find the minimum
        {
            if (i <= j)
            {
                continue;
            }
            swap(weights[i], weights.back()); // neat little trick to get the beautiful O(1) time on removing the value
            weights.pop_back();
            swap(weights[j], weights.back()); // used again!
            weights.pop_back();

            sort(weights.begin(), weights.end()); // sort it, we could use the neat little trick above because we had no need for order until now
            int unstable{};

            for (int k{}; k < weights.size(); k += 2) // increment by 2, make sure to use weights.size() and not n *2!
            {
                unstable += (abs(weights[k] - weights[k + 1]));
            }
            min_unstable = min(unstable, min_unstable);
            weights = master_weights;
        }
    }

    cout << min_unstable;
}

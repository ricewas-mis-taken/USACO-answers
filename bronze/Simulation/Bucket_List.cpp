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

    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n;
    cin >> n;

    priority_queue<int, vi, greater<int>> pq; // the bucket that frees up first comes up top
    vector<tuple<int, int, int>> order;

    for (int i{}; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        order.pb({a, b, c});
    }
    sort(order.begin(), order.end()); // sort

    int buckets{};
    for (int i{}; i < n; ++i)
    {
        int needed = get<2>(order[i]); // amount of buckets needed
        int begin = get<0>(order[i]);
        int end = get<1>(order[i]);
        for (int j{}; j < needed; ++j)
        {
            if (pq.empty())
            {
                buckets++;
                pq.push(end);
            }
            else if (pq.top() < begin) // bucket will free up before milking begins, use the bucket, update the bucket
            {
                pq.pop();
                pq.push(end);
            }
            else // all buckets are in use, add a new bucket
            {
                buckets++;
                pq.push(end);
            }
        }
    }
    cout << buckets;
}

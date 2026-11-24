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
// subtract, add, subtract, add
si readings;

void find_reading(int index, int tank1, vi at1, vi at2)
{
    if (index == 4)
    {
        readings.insert(tank1);
        return;
    }

    if (index == 0 || index == 2) // notice that tuesday and thursday are both days when barn one loses milk
    {
        for (int i{}; i < at1.size(); ++i)
        {
            vi temp = at1;
            vi temp2 = at2;
            temp2.pb(at1[i]);
            swap(temp[i], temp.back());
            temp.pop_back();
            find_reading(index + 1, tank1 - at1[i], temp, temp2);
        }
    }
    else
    {
        for (int i{}; i < at2.size(); ++i) // days when barn one gains milk
        {
            vi temp = at1;
            vi temp2 = at2;
            temp.pb(at2[i]);
            swap(temp2[i], temp2.back());
            temp2.pop_back();
            find_reading(index + 1, tank1 + at2[i], temp, temp2);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vi b1, b2;
    for (int i{}; i < 10; ++i)
    {
        int x;
        cin >> x;
        b1.pb(x);
    }
    for (int i{}; i < 10; ++i)
    {
        int x;
        cin >> x;
        b2.pb(x);
    }
    find_reading(0, 1000, b1, b2);
    cout << readings.size();
}

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
string temp;
vector<char> n;
set<string> final;
// at every branch, choose one of the 5 to put in, and at every branch also remember what it already put in and what's left
// this version is one that doesn't use next_permuation, however my code is trash b/c it checks all positions, it's horrible time wise
void make_all(string make, vector<int> left)
{
    if (make.size() == temp.size()) // at the size needed, insert
    {
        final.insert(make);
        return;
    }
    for (int i{}; i < left.size(); ++i)
    {
        vi x = left; // use a copy so we don't modify left and accidently break the for loop
        swap(x[i], x.back());
        x.pop_back();
        make_all(make + n[left[i]], x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> temp;
    for (char c : temp)
    {
        n.pb(c);
    }
    sort(n.begin(), n.end());
    vi x;
    for (int i{}; i < n.size(); ++i)
    {
        x.pb(i);
    }
    make_all("", x);
    cout << final.size() << "\n";
    for (string s : final)
    {
        cout << s << "\n";
    }
}

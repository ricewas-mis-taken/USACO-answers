#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> pos; // the final position
    vector<int> id;  // cow id
    for (int i{}; i < n; ++i)
    {
        int temp;
        cin >> temp;
        --temp; // for vector zero index
        pos.push_back(temp);
    }
    for (int i{}; i < n; ++i)
    {
        int temp;
        cin >> temp;
        id.push_back(temp);
    }
    vector<int> initialPos; // initial position
    for (int i{}; i < n; ++i)
    {
        int p = pos[i]; // goes from end to third position
        p = pos[p];     // goes from end to second position
        p = pos[p];     // goes from end to initial position
        initialPos.push_back(p);
    }
    for (int i{}; i < n; ++i)
    {
        cout << id[initialPos[i]] << "\n";
    }
}

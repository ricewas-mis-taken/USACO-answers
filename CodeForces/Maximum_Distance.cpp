#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> xcord; // the coordinates of all x points
    vector<int> ycord; // the coordinates of all y points
    for (int i{}; i < n; ++i)
    {
        int temp;
        cin >> temp;
        xcord.push_back(temp);
    }
    for (int i{}; i < n; ++i)
    {
        int temp;
        cin >> temp;
        ycord.push_back(temp);
    }
    vector<pair<int, int>> coords;
    for (int i{}; i < n; ++i)
    {
        coords.push_back({xcord[i], ycord[i]}); // coalescing the points together to form coordinates
    }
    long long distance{};

    for (int i{}; i < n; ++i)
    {
        for (int j{}; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            int xtype = coords[j].first - coords[i].first;              // x2-x1
            int ytype = coords[j].second - coords[i].second;            // y2-y1
            long long tempDistance = (xtype * xtype) + (ytype * ytype); // no need to square root since problem doesn't require it
            distance = max(tempDistance, distance);
        }
    }
    cout << distance;
}

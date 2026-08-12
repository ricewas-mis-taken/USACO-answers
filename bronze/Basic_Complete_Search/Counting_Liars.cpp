#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> greater; // stores values of G
    vector<int> lesser;  // stores values of L
    vector<int> all;     // stores all points for testing against Bessie
    for (int i{}; i < n; ++i)
    {
        char a;
        int b;
        cin >> a >> b;
        if (a == 'G')
        {
            greater.push_back(b);
        }
        else
        {
            lesser.push_back(b);
        }
        all.push_back(b);
    }
    sort(greater.begin(), greater.end()); // sort so auto will work correctly
    sort(lesser.begin(), lesser.end());   // same thing

    int liars{INT_MAX};
    for (int i{}; i < n; ++i)
    {
        int tempLiars{};                                                 // temp variable that is compared to liars
        int bessie = all[i];                                             // gets a possible bessie position
        auto more = upper_bound(greater.begin(), greater.end(), bessie); // all values greater than bessie, these are the liars
        tempLiars += (greater.end() - more);
        auto less = lower_bound(lesser.begin(), lesser.end(), bessie); // all values less than bessie, these are liars
        tempLiars += (less - lesser.begin());
        liars = min(liars, tempLiars);
    }
    cout << liars;
}

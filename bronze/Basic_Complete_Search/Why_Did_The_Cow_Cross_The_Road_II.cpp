#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    vector<char> order; // order of cows
    for (int i{}; i < 52; ++i)
    {
        char temp;
        cin >> temp;
        order.push_back(temp);
    }

    int crossing{};
    for (int i{}; i < 26; ++i)
    {
        for (int j{}; j < 26; ++j)
        {
            if (i <= j) // using <= to only compare each possible pair once, and pairs can't be the same
            {
                continue;
            }
            auto first = find(order.begin(), order.end(), i + 65);     // find first position of first of the pair
            auto second = find(order.begin(), order.end(), j + 65);    // find second posiiton of first of the pair
            auto first2 = find(first + 1, order.end(), i + 65);        // find first position of second of the pair
            auto second2 = find(second + 1, order.end(), j + 65);      // find second position of second of the pair
            if (first < second && second < first2 && first2 < second2) // only will cross if this specific order happens, might help to draw it out on paper
            {
                crossing++;
            }
            else if (second < first && first < second2 && second2 < first2) // flipped order of second & first
            {
                crossing++;
            }
        }
    }
    cout << crossing;
}

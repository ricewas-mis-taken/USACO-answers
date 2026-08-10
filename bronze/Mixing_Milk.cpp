#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int m1, m2, m3, c1, c2, c3; // m stands for milk in bucket, c stands for capacity
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    for (int i{}; i < 33; ++i)
    {                     // simulate 99 pours, problem explicitly states that bucket one is poured into bucket two first
        int r2 = c2 - m2; // r2 is the room in bucket 2
        if (r2 >= m1)
        {

            m2 += m1;
            m1 = 0;
        }
        else
        {
            m1 -= r2;
            m2 += r2;
        }

        int r3 = c3 - m3; // r3 is the room in bucket 3
        if (r3 >= m2)
        {

            m3 += m2;
            m2 = 0;
        }
        else
        {
            m2 -= r3;
            m3 += r3;
        }

        int r1 = c1 - m1; // r1 is the room in bucket 1
        if (r1 >= m3)
        {

            m1 += m3;
            m3 = 0;
        }
        else
        {
            m3 -= r1;
            m1 += r1;
        }
    }
    int r2 = c2 - m2; // manually simulate last pour
    if (r2 >= m1)
    {

        m2 += m1;
        m1 = 0;
    }
    else
    {
        m1 -= r2;
        m2 += r2;
    }
    cout << m1 << "\n"
         << m2 << "\n"
         << m3;
}

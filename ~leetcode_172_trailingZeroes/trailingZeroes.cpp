#include <iostream>

using namespace std;

int main()
{
    long long int res = 1;

    for (int n = 1; n < 100; n++)
    {
        res = n * res;
        cout << n << " " << res << endl;
    }

    return 0;
}
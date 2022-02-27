#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int a;
    double x1 = 1.0, x2, x3;
    cout << "Please input a:";
    cin >> a;
    do
    {
        x2 = (x1 + a / x1) / 2;
        x3 = x1;
        x1 = x2;
    } while (fabs(x1 - x3) >= 1e-5);
    cout << x1;
}

/*
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int a;
    double x1,x2;
    cin >> a;
    for (x1 = 1.0, x2 = (x1 + a / x1) / 2; fabs(x2 - x1) >= 1e-5; x2 = (x1 + a / x1) / 2)
    {
        x1 = x2;
    }
        cout <<x2<<endl;
    return 0;
*/

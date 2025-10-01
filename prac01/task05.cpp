#include <iostream>
using namespace std;

int main ()
{
    float hours1, hours2, payment1, payment2, sum1, sum2;

    cout << "First worker`s hours worked: ";
    cin >> hours1;

    cout << "First worker`s hourly payment: ";
    cin >> payment1;

    cout << "Second worker`s hours worked: ";
    cin >> hours2;

    cout << "Second worker`s hourly payment: ";
    cin >> payment2;

    sum1 = hours1*payment1;
    sum2 = hours2*payment2;

    if (sum1 > sum2){
        cout << "Worker 1 earned more\n";
    } else if (sum1 < sum2) {
        cout << "Worker 2 earned more\n";
    } else {
        cout << "Workers earned the same\n";
    }
    cout << "Workers 1 and 2 earned " << sum1+sum2 << " together";

    return 0;
}
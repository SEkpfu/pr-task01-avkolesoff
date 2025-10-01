#include <iostream>
using namespace std;

int main ()
{
    float totalSum = 0;

    for (int i = 1; i < 6; i++)
    {
        float hours, payment, sum;

        cout << "Hours worked for worker " << i << " ";
        cin >> hours;
        cout << "Hourly payment for worker " << i << " ";
        cin >> payment;
        
        sum = hours*payment;
        totalSum += sum;

        cout << "Worker " << i << " earned: " << sum << endl;
    }
    cout << "Medium salary: " << totalSum/5.0;

    return 0;
}
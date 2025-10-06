#include <iostream>
using namespace std;

void inputWorkerData (float &hours, float &payment, int i)
{
    cout << "Hours worked for worker " << i << " ";
    cin >> hours;
    cout << "Hourly payment for worker " << i << " ";
    cin >> payment;
}

int main ()
{
    float totalSum = 0.0;

    for (int i = 1; i <= 5; i++)
    {
        float hours, payment, sum;
        inputWorkerData(hours, payment, i);
        
        sum = hours*payment;
        totalSum += sum;

        cout << "Worker " << i << " earned: " << sum << endl;
    }
    cout << "Medium salary: " << totalSum/5.0;

    return 0;
}
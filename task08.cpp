#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void inputWorkerData (double &hours, double &payment, int num)
{
    cout << "Worker`s " << num << " hours: ";
    cin >> hours;
    cout << "Worker`s " << num << " payment: ";
    cin >> payment;
}

int main ()
{   
    constexpr double INCOMETAX = 13.0/100.0;

    int workers;
    cout << "Quantity of workers: ";
    cin >> workers;

    double hours[workers] = {};
    double payments[workers] = {};
    double salaries[workers] = {};
    double taxes[workers] = {};

    for (int i = 0; i < workers; i++)
    {
        inputWorkerData(hours[i], payments[i], i+1);
    }

    for (int i = 0; i < workers; i++)
    {
        double salary = hours[i]*payments[i];
        double tax = salary*INCOMETAX;
        
        salaries[i] = salary - tax;
        taxes[i] = tax;
    }

    double totalTax = 0, minSalary = salaries[0], maxSalary = salaries[0];
    int minNum = 1, maxNum = workers, more50000Qnt = 0; 

    for (int i = 0; i < workers; i++)
    {
        totalTax += taxes[i];

        if (salaries[i] > maxSalary)
        {
            maxSalary = salaries[i];
            maxNum = i+1;
        }
        if (salaries[i] < minSalary)
        {
            minSalary = salaries[i];
            minNum = i+1;
        }
        if (salaries[i] > 50000)
        {
            more50000Qnt += 1;
        }
    }   

    cout << "--------------------------" << endl;
    cout << "Worker " << minNum << " earned the least" << endl;
    cout << "Worker " << maxNum << " earned the most (" << maxSalary << ")" << endl;

    if (more50000Qnt > 0)
    {   
        cout << more50000Qnt << " worker(s) earnes more than 50000: ";
        for (int i = 0; i < workers; i++)
        {
            if (salaries[i] > 50000)
            {
                cout << i+1 << " ";
            }
        }
        cout << endl;
    } 
    else
    {
        cout << "Noone earned more than 50000" << endl;
    }
    cout << "Total tax sum is " << totalTax;

    return 0;
}
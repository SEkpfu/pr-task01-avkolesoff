#include <iostream>
#include <cmath>

using namespace std;

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
        cout << "Worker`s " << i+1 << " hours: ";
        cin >> hours[i];
        cout << "Worker`s " << i+1 << " payment: ";
        cin >> payments[i];
    }

    for (int i = 0; i < workers; i++)
    {
        double salary = hours[i]*payments[i];
        double tax = salary*INCOMETAX;
        
        salaries[i] = salary - tax;
        taxes[i] = tax;
    }

    double totalTax = 0, minSalary = salaries[0], maxSalary = salaries[0];
    int minNum, maxNum, more50000Qnt = 0; 

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
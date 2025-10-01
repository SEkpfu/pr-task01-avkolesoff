#include <iostream>

int main ()
{
    using namespace std;

    const int MONTHS = 3;
    const int WORKERSQUANTITY = 4;
    constexpr float INCOMETAX = 13.0/100.0;

    int hoursWorked[WORKERSQUANTITY][MONTHS];
    float hourlyPayments[WORKERSQUANTITY][MONTHS];
    float anualPayroll[WORKERSQUANTITY][MONTHS][2];

    for (int worker = 0; worker < WORKERSQUANTITY; worker++)
    {
        cout << "-------------------------" << endl;
        cout << "INPUTTING DATA FOR WORKER " << worker+1 << endl;
        
        for (int month = 0; month < MONTHS; month++)
        {
            cout << "Hours worked in month " << month+1 << " : ";
            cin >> hoursWorked[worker][month];

            cout << "Hourly payment in month " << month+1 << " : ";
            cin >> hourlyPayments[worker][month];
        }
    }

    for (int worker = 0; worker < WORKERSQUANTITY; worker++)
    {
        for (int month = 0; month < MONTHS; month++)
        {
            int hours = hoursWorked[worker][month];
            float payment = hourlyPayments[worker][month];

            float earned = hours * payment;
            float tax = earned * INCOMETAX;
            float salary = earned - tax;

            anualPayroll[worker][month][0] = salary;
            anualPayroll[worker][month][1] = tax;
        }
    }

    for (int worker = 0; worker < WORKERSQUANTITY; worker++)
    {
        //cout << "WORKER" << worker+1 << endl;
        for (int month = 0; month < MONTHS; month++)
        {
            //cout << "MONTH" << month+1;

            int hours = hoursWorked[worker][month];
            float payment = hourlyPayments[worker][month];

            float earned = hours * payment;
            float tax = earned * INCOMETAX;
            float salary = earned - tax;

            anualPayroll[worker][month][0] = salary;
            anualPayroll[worker][month][1] = tax;

            //cout << " " << salary << " " << tax << endl;
        }
    }

    cout << "--------------------------"<< endl;
    cout << "1st worker earned" << anualPayroll[0][1][0] << " in 2nd month" << endl;
    
    float taxSum = 0;
    for (int month = 0; month < MONTHS; month++)
    {
        taxSum += anualPayroll[2][month][1];
    }
    cout << "3d worker`s anual tax is " << taxSum << endl;

    int maxEarnedWorkerNum = 0;
    float maxSalary = anualPayroll[0][2][0];
    for (int worker = 0; worker < WORKERSQUANTITY; worker++)
    {
        float salary = anualPayroll[worker][2][0];
        if (salary > maxSalary)
        {
            maxSalary = salary;
            maxEarnedWorkerNum = worker;
        }
    }
    cout << "Worker " << maxEarnedWorkerNum << " earned the most in 3d month" << endl;

    float totalSum = 0;
    for (int worker = 0; worker < WORKERSQUANTITY; worker++)
    {
        for (int month = 0; month < MONTHS; month++)
        {
            totalSum += anualPayroll[worker][month][0];
        }
    }
    cout << "The team earned "<< totalSum << " for the whole year";
}
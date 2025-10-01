#include <iostream>
#include <cstring>

using namespace std;

void inputWorkerData(float &hours, float &payment, string &lastname)
{       
    do {
        cout << "Worker`s lastname: ";
        cin >> lastname;
        if (lastname.length() > 20) {
            cout << "Lastname length must be less than 21! Try again!\n";
        } else {
            cout << lastname << "`s hours worked: ";
            cin >> hours;
            cout << lastname << "`s hourly payment: ";
            cin >> payment;
        }
    } while (lastname.length() > 20);
}

void calculateSalaryAndTax(float hours, float payment, float &salary, float &tax)
{
    float sum = hours * payment;
    tax = (sum*13)/100.0;
    salary = sum - tax;
}

int main ()
{
    float hours1, hours2, payment1, payment2, real1, real2, tax1, tax2;
    string lastname1, lastname2;

    inputWorkerData(hours1, payment1, lastname1);
    inputWorkerData(hours2, payment2, lastname2);

    calculateSalaryAndTax(hours1, payment1, real1, tax1);
    calculateSalaryAndTax(hours2, payment2, real2, tax2);

    bool foundLess1000 = (real1 < 1000) || (real2 < 1000);
    if (real1 < 1000) cout << lastname1 << " earned less than 1000\n";
    if (real2 < 1000) cout << lastname2 << " earned less than 1000\n";
    if (!foundLess1000) cout << "No one earned less than 1000\n";

    bool foundTaxOver50 = (tax1 > 50) || (tax2 > 50);
    if (tax1 > 50) cout << lastname1[0] << '-' << lastname1.back() << " has tax more than 50\n";
    if (tax2 > 50) cout << lastname2[0] << '-' << lastname2.back() << " has tax more than 50\n";
    if (!foundTaxOver50) cout << "No one has tax more than 50\n";

    return 0;
}
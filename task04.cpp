#include <iostream>
using namespace std;

void inputWorkerData (float &hoursWorked, float &hourlyPayment, float &premiumPercentage)
{
    cout << "Hours you worked: ";
    cin >> hoursWorked;

    cout << "Your hourly payment: ";
    cin >> hourlyPayment;

    cout << "Your percent of premium: "; 
    cin >> premiumPercentage;
}

void calculateSalaryData(float hours, float payment, float premium, 
                        float &totalSum, float &incomeTax, float &realSalary)                                      
{
    totalSum = hours * payment + (hours*payment*premium)/100.0;
    incomeTax = (totalSum*13)/100.0;
    realSalary = totalSum - incomeTax;
}

int main()
{
    float hoursWorked, hourlyPayment, premiumPercentage;
    inputWorkerData(hoursWorked, hourlyPayment, premiumPercentage);

    float totalSum, incomeTax, realSalary;
    calculateSalaryData(hoursWorked, hourlyPayment, premiumPercentage, 
                        totalSum, incomeTax, realSalary);
    
    cout << "You have earned: " << totalSum << endl;
    cout << "Your income tax: " << incomeTax << endl; 
    cout << "Your real salary: " << realSalary << endl;  

    return 0;
}

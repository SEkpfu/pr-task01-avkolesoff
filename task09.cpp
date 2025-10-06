#include <iostream>

using namespace std;


int getMinElementIndex (float array[], const int size) 
{
    float minElement = array[0];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < minElement) 
        {
            minElement = array[i];
            index = i;
        }
    }
    return index;
}

void getMaxElement(float array[], int size, float &element, int &index)
{
    element = array[0];
    index = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > element)
        {
            element = array[i];
            index = i;
        }
    }
}

int getNumOfElementsAboveNumber (float array[], int size, float number)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > number)
        {
            count += 1;
        }
    }
    return count;
}

float getSumOfElements (float array[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

void calculateSalaryAndTax(float hours, float payment, float &salary, float &tax)
{
    float sum = hours * payment;
    tax = sum * 0.13f;
    salary = sum - tax;
}

void inputWorkerData(float &hours, float &payment, int num)
{
    cout << "Enter hours worked for worker " << num << ": ";
    cin >> hours;
    cout << "Enter hourly payment for worker " << num << ": ";
    cin >> payment;
}

int main ()
{   
    int workers;
    int more50000Qnt;

    cout << "Quantity of workers: ";
    cin >> workers;

    int maxEarnedWorkerNum, minEarnedWorkerNum;

    float hours[workers] = {};
    float payments[workers] = {};

    float salaries[workers] = {};
    float maxSalary, minSalary;

    float taxes[workers] = {};
    float totalTaxSum;

    for (int i = 0; i < workers; i++)
    {
        inputWorkerData(hours[i], payments[i], i+1);
    }

    for (int i = 0; i < workers; i++)
    {
        calculateSalaryAndTax(hours[i], payments[i], salaries[i], taxes[i]);
    }

    minEarnedWorkerNum = getMinElementIndex(salaries, workers);
    more50000Qnt = getNumOfElementsAboveNumber(salaries, workers, 50000);
    totalTaxSum = getSumOfElements(taxes, workers);

    getMaxElement(salaries, workers, maxSalary, maxEarnedWorkerNum);

    cout << endl << "The worker " << minEarnedWorkerNum << " earned the least" << endl;
    cout << "Max salary is " << maxSalary << endl;
    cout << "THe worker " << maxEarnedWorkerNum << " earned the most" << endl;

    cout << "Worker(s)";
    for (int i = 0; i < workers; i++)
    {
        if (salaries[i] > 50000)
        {
            cout << " " << i+1;
        }
    }
    cout << " earned more than 50000";
    cout << endl << "Totaly " << more50000Qnt << " worker(s) earned more than 50000" << endl;
    cout << "Total tax sum payed: " << totalTaxSum;

    return 0;
}
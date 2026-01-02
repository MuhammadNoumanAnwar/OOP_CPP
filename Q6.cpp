//Write a program that reads the name of a salesperson followed by the total sales they made for a series of
//months. The program should:
//o Output the salesperson’s name.
//o Output all monthly sales rounded to two decimal places.
//o Compute and display the average monthly sales with two decimal places.
//o Identify and print the month with the highest sales and the corresponding sales amount.
//Sample Output
//Salesperson name: Michael Lee
//Monthly sales: 5200.75 4300.50 6100.25 7000.00 5600.80
//Average monthly sales: 5640.46
//Highest sales: Month 4: 7000.00
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float average = 0, max = 0, month;
    char name[20] = {"Michael Lee"};
    float sales[5] = {5200.273, 3440.393, 2023.22, 9999.203, 2344.12};
    int length = sizeof(sales) / sizeof(sales[0]);

    for (int i = 0; i < length; i++) {
        if (sales[i] > max) {
            max = sales[i];
            month = i + 1; 
        }
    }

    for (int i = 0; i < length; i++) {
        average += sales[i];
    }
    average = average / length;

    cout << "Salesperson name: " << name << endl;
    cout << "Monthly Sales: ";
    for (int i = 0; i < length; i++) {
        cout << fixed << setprecision(2) << sales[i] << " ";
    }
    cout << endl;

    cout << "Average monthly sales: " << fixed << setprecision(0) << average << endl;
    cout << "Highest sales: Month " << month << ": " << fixed << setprecision(2) << max << endl;

    return 0;
}


#include <iostream>
using namespace std;

void readMarks(int marks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> marks[i];

        while (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid! Enter between 0 and 100: ";
            cin >> marks[i];
        }
    }
}

int findTotal(int marks[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += marks[i];
    }
    return total;
}

double findAverage(int marks[], int n)
{
    int total = findTotal(marks, n);
    return (double)total / n;
}

int findHighest(int marks[], int n)
{
    int max = marks[0];
    for (int i = 1; i < n; i++)
    {
        if (marks[i] > max)
        {
            max = marks[i];
        }
    }
    return max;
}

int findLowest(int marks[], int n)
{
    int min = marks[0];
    for (int i = 1; i < n; i++)
    {
        if (marks[i] < min)
        {
            min = marks[i];
        }
    }
    return min;
}

int countPassed(int marks[], int n)
{
    int pass = 0;
    for (int i = 0; i < n; i++)
    {
        if (marks[i] >= 40)
        {
            pass++;
        }
    }
    return pass;
}

void printReport(int marks[], int n)
{
    int passed = countPassed(marks, n);
    int failed = n - passed;

    cout << "\n--- Marks Report ---\n";
    cout << "Total Marks    : " << findTotal(marks, n) << endl;
    cout << "Average Marks  : " << findAverage(marks, n) << endl;
    cout << "Highest Mark   : " << findHighest(marks, n) << endl;
    cout << "Lowest Mark    : " << findLowest(marks, n) << endl;
    cout << "Students Passed: " << passed << endl;
    cout << "Students Failed: " << failed << endl;
}

int main()
{
    int n;
    char ch;

    do
    {
        cout << "\nEnter number of students (1-100): ";
        cin >> n;

        while (n < 1 || n > 100)
        {
            cout << "Invalid count! Enter between 1 and 100: ";
            cin >> n;
        }

        int *marks = new int[n];

        readMarks(marks, n);
        printReport(marks, n);

        delete[] marks;

        cout << "\nRun again? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return 0;
}
#include <iostream>
using namespace std;

void readMarks(int marks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter mark of student " << i + 1 << ": ";
        cin >> marks[i];

        while (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid mark! Enter again: ";
            cin >> marks[i];
        }
    }
}

int findTotal(int marks[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total = total + marks[i];
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
    int highest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

int findLowest(int marks[], int n)
{
    int lowest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}

int countPassed(int marks[], int n)
{
    int passed = 0;

    for (int i = 0; i < n; i++)
    {
        if (marks[i] >= 40)
        {
            passed++;
        }
    }

    return passed;
}

void printReport(int marks[], int n)
{
    int total = findTotal(marks, n);
    int passed = countPassed(marks, n);

    cout << "\n===== STUDENT MARKS REPORT =====\n";

    cout << "Total Marks: " << total << endl;
    cout << "Average: " << findAverage(marks, n) << endl;
    cout << "Highest Mark: " << findHighest(marks, n) << endl;
    cout << "Lowest Mark: " << findLowest(marks, n) << endl;
    cout << "Passed Students: " << passed << endl;
    cout << "Failed Students: " << n - passed << endl;
}

int main()
{
    int n;
    char choice;

    do
    {
        cout << "\nEnter number of students (1-100): ";
        cin >> n;

        while (n < 1 || n > 100)
        {
            cout << "Invalid count! Enter again: ";
            cin >> n;
        }

        int *marks = new int[n];

        readMarks(marks, n);
        printReport(marks, n);

        delete[] marks;

        cout << "\nDo you want to analyse again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you!\n";

    return 0;
}

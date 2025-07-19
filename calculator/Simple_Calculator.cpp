#include <iostream>
using namespace std;

class Simple_Calculator
{
private:
    int a, b;

public:
    void getData()
    {
        cout << "Simple Calculator" << endl;
        cout << "Enter the value of a : " << endl;
        cin >> a;
        cout << "Enter the value of b : " << endl;
        cin >> b;
    }
    void PerformOperation()
    {
        int choice;
        do
        {
            cout << "\nChoose operation:\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Division\n";
            cout << "5. Exit\n";
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Addition of a + b is :  " << a + b << endl;
                break;
            case 2:
                cout << "Subtraction of a - b is :  " << a - b << endl;
                break;
            case 3:
                cout << "Multiplication of a * b is :  " << a * b << endl;
                break;
            case 4:
                if (b != 0)
                    cout << "Division of a / b is :  " << static_cast<double>(a) / b << endl;
                else
                    cout << "Division by zero is not allowed." << endl;
                break;
            case 5:
                cout << "Exiting the calculator." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
        } while (choice != 5);
    }
};
int main()
{
    Simple_Calculator calc;
    calc.getData();
    calc.PerformOperation();
    cout << "Thank you for using the Simple Calculator!" << endl;
    return 0;
}
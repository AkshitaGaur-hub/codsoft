#include <iostream>
#include <string>
#include <vector>
using namespace std;

class To_Do_Item
{
private:
    int id;
    string description;
    bool isCompleted;

public:
    To_Do_Item(int id, string description, bool isCompleted = false)
    {
        this->id = id;
        this->description = description;
        this->isCompleted = isCompleted;
    }
    void markCompleted()
    {
        isCompleted = true;
    }
    void display() const
    {
        cout << "ID: " << id << "\nDescription: " << description
             << "\nCompleted: " << (isCompleted ? "Yes" : "No") << endl;
    }
    int getID()
    { // <-- Return int, not string
        return id;
    }
};
int main()
{
    cout << "Welcome to the To-Do List Application!" << endl;

    vector<To_Do_Item> toDoList;
    int choice, id;
    string description;
    do
    {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. Mark Item as Completed\n";
        cout << "3. Display All Items\n";
        cout << "4. Remove Item\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(); // Clear the newline character from the input buffer
            cout << "Enter Description: ";
            getline(cin, description);
            toDoList.push_back(To_Do_Item(id, description));
            break;
        case 2:
            cout << "Enter ID of item to mark as completed: ";
            cin >> id;
            for (auto &item : toDoList)
            {
                if (item.getID() == id)
                {
                    item.markCompleted();
                    cout << "Item marked as completed." << endl;
                    break;
                }
            }
            break;
        case 3:
            for (const auto &item : toDoList)
            {
                item.display();
                cout << "------------------------" << endl;
            }
            break;
        case 4:
            cout << "Enter ID of item to remove: ";
            cin >> id;
            {
                bool found = false;
                for (auto it = toDoList.begin(); it != toDoList.end(); ++it)
                {
                    if (it->getID() == id)
                    {
                        toDoList.erase(it);
                        cout << "Item removed successfully." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Item with ID " << id << " not found." << endl;
                }
            }
            break;
        case 5:
            cout << "Exiting To-Do List." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
    cout << "Thank you for using the To-Do List application!" << endl;

    return 0;
}

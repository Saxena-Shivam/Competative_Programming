#include <iostream>
using namespace std;
const int m = 50;
class ITEMS
{
    int itemCode[m];
    float itemPrice[m];
    int count;

public:
    void CNT() { count = 0; } // initialize count to 0
    void getitem();
    void displaySum();
    void remove();
    void displayItems();
};

// ========== Function Definitions ==========

void ITEMS::getitem()
{
    if (count >= m)
    {
        cout << "Cannot add more items, limit reached.\n";
        return;
    }
    cout << "Enter item code: ";
    cin >> itemCode[count];
    cout << "Enter item cost: ";
    cin >> itemPrice[count];
    count++;
}

void ITEMS::displaySum()
{
    float sum = 0;
    for (int i = 0; i < count; i++)
        sum += itemPrice[i];
    cout << "\nTotal value: " << sum << "\n";
}

void ITEMS::remove()
{
    int a;
    cout << "Enter item code to remove: ";
    cin >> a;
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (itemCode[i] == a)
        {                     // use == for comparison
            itemPrice[i] = 0; // mark price as 0
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Item not found.\n";
}

void ITEMS::displayItems()
{
    cout << "\nCode\tPrice\n";
    for (int i = 0; i < count; i++)
        cout << itemCode[i] << "\t" << itemPrice[i] << "\n";
}

// ========== Main Function ==========

int main()
{
    ITEMS order;
    order.CNT();
    int x;
    do
    {
        cout << "\nYou can do the following; Enter appropriate number\n";
        cout << "1: Add an item\n";
        cout << "2: Display total value\n";
        cout << "3: Delete an item\n";
        cout << "4: Display all items\n";
        cout << "5: Quit\n";
        cout << "What is your option? ";
        cin >> x;

        switch (x)
        {
        case 1:
            order.getitem();
            break;
        case 2:
            order.displaySum();
            break;
        case 3:
            order.remove();
            break;
        case 4:
            order.displayItems();
            break;
        case 5:
            break;
        default:
            cout << "Error in input; try again\n";
        }
    } while (x != 5);

    return 0;
}

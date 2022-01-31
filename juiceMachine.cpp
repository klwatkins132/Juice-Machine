#include <iostream>
#include <string>
using namespace std;

class cashRegister
{
public:
    int getCurrentBalance() const;

    void acceptAmount(int amountIn);

    cashRegister(int cashIn = 500);

private:
    int cashOnHand;
};

class dispenserType
{
public:
    int getNoOfItems() const;

    int getCost() const;

    void makeSale();

    dispenserType(int setNoOfItems = 50, int setCost = 50);

private:
    int numberOfItems;
    int cost;
};

int cashRegister::getCurrentBalance() const
{
    return cashOnHand;
}
void cashRegister::acceptAmount(int amountIn)
{
    cashOnHand = cashOnHand + amountIn;
}

cashRegister::cashRegister(int cashIn)
{
    if (cashIn >= 0)
        cashOnHand = cashIn;
    else
        cashOnHand = 500;
}

int dispenserType::getNoOfItems() const
{
    return numberOfItems;
}

int dispenserType::getCost() const
{
    return cost;
}

void dispenserType::makeSale()
{
    numberOfItems--;
}

dispenserType::dispenserType(int setNoOfItems, int setCost)
{
    if (setNoOfItems >= 0)
        numberOfItems = setNoOfItems;
    else
        numberOfItems = 50;

    if (setCost >= 0)
        cost = setCost;
    else
        cost = 50;
};

void showSelection()
{
    cout << "*** Welcome to Kelsys Juice Shop ***" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for orange juice" << endl;
    cout << "2 for apple juice" << endl;
    cout << "3 for mango juice" << endl;
    cout << "4 for strawberry banana juice" << endl;
    cout << "9 to exit" << endl;
};

void sellProduct(dispenserType &product, cashRegister &pCounter)
{
    int amount;
    int amount2;

    if (product.getNoOfItems() > 0)
    {
        cout << "Please deposit " << product.getCost() << " cents" << endl;
        cin >> amount;

        if (amount < product.getCost())
        {
            cout << "Please deposit another " << product.getCost() - amount << " cents" << endl;
            cin >> amount2;
            amount = amount + amount2;
        }

        if (amount >= product.getCost())
        {
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout << "Collect your item at the bottom and enjoy" << endl;
        }
        else
            cout << "The amount is not enough. Collect what you deposited." << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-* \n"
             << endl;
    }
    else
        cout << "Sorry, this item is sold out." << endl;
}

int main()
{
    cashRegister counter;
    dispenserType orange(100, 50);
    dispenserType apple(100, 65);
    dispenserType mango(75, 45);
    dispenserType strawberryBanana(100, 85);

    int choice;
    showSelection();
    cin >> choice;

    while (choice != 9)
    {
        switch (choice)
        {
        case 1:
            sellProduct(orange, counter);
            break;
        case 2:
            sellProduct(apple, counter);
            break;
        case 3:
            sellProduct(mango, counter);
            break;
        case 4:
            sellProduct(strawberryBanana, counter);
            break;
        default:
            cout << "Invalid selection." << endl;
        }
        showSelection();
        cin >> choice;
    }
    return 0;
}
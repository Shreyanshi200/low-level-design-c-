#include <iostream>
#include <string>

using namespace std;

// Abstract base Pizza class
class Pizza {
public:
    virtual ~Pizza() = default;
    virtual string getDes() const = 0;
    virtual int cost() const = 0;
};

// Concrete MargheritaPizza class
class MargheritaPizza : public Pizza {
public:
    string getDes() const override {
        return "Margherita Pizza";
    }
    int cost() const override {
        return 300;
    }
};

// Concrete FarmhousePizza class
class FarmhousePizza : public Pizza {
public:
    string getDes() const override {
        return "Farmhouse Pizza";
    }
    int cost() const override {
        return 600;
    }
};

// Abstract toppings decorator class
class Toppings : public Pizza {
protected:
    Pizza* orderedPizza;
public:
    Toppings(Pizza* order) : orderedPizza(order) {}
    virtual ~Toppings() {
        delete orderedPizza;
    }
};

// Concrete Cheese topping class
class Cheese : public Toppings {
public:
// it calls the constructor of the base class Toppings and passes order to it. 
    Cheese(Pizza* order) : Toppings(order) {}
    string getDes() const override {
        return orderedPizza->getDes() + " with Cheese";
    }
    int cost() const override {
        return orderedPizza->cost() + 25;
    }
};

// Concrete Olives topping class
class Olives : public Toppings {
public:
    Olives(Pizza* order) : Toppings(order) {}
    string getDes() const override {
        return orderedPizza->getDes() + " with Olives";
    }
    int cost() const override {
        return orderedPizza->cost() + 20;
    }
};

class Tomatoes : public Toppings {
public:
    Tomatoes(Pizza* order) : Toppings(order) {}
    string getDes() const override {
        return orderedPizza->getDes() + " with Tomatoes";
    }
    int cost() const override {
        return orderedPizza->cost() + 20;
    }
};

int main() {
    Pizza* pizza = nullptr;
    int choice;

    cout << "Select a Pizza:\n";
    cout << "1. Margherita Pizza\n";
    cout << "2. Farmhouse Pizza\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            pizza = new MargheritaPizza();
            break;
        case 2:
            pizza = new FarmhousePizza();
            break;
        default:
            cout << "Invalid choice. Exiting...\n";
            return 1;
    }

    cout << "Selected: " << pizza->getDes() << " - Cost: " << pizza->cost() << endl;

    while (true) {
        cout << "\nSelect a Topping:\n";
        cout << "1. Cheese - 25\n";
        cout << "2. Olives - 20\n";
        cout << "3. Tomatoes -20 \n";
        cout << "4. Done\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1:
                pizza = new Cheese(pizza);
                break;
            case 2:
                pizza = new Olives(pizza);
                break;
            case 3:
                pizza = new Tomatoes(pizza);
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                continue;
        }

        cout << "Updated Pizza: " << pizza->getDes() << " - Cost: " << pizza->cost() << endl;
    }

    cout << "\nFinal Order: " << pizza->getDes() << " - Total Cost: " << pizza->cost() << endl;

    delete pizza;

    return 0;
}

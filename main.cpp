// Akashdeep Singh || Coms-210 || Final Part 2 || Vendor Booth Queue Simulation

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//Constants

const int NAME_COUNT = 10;
const int DRINK_COUNT = 8;

//Structs

//customer struct
struct Customer {
    string name;
    string order;
};

//Linked list node
struct Node {
    Customer data;
    Node* next;
};

// Function Prototypes 

Customer create_customer(const string orders[], int size);
void enqueue(Node*& head, Node*& tail, Customer c);
void print_linked_list(Node* head);

// Main

int main()
{
    srand(time(0));

    string names[NAME_COUNT] = {
      "Ava", "Liam", "Emma", "Noah", "Sophia",
        "Mason", "Olivia", "Lucas", "Mia", "Ethan"
    };

    string drinks[DRINK_COUNT] = {
        "Latte", "Mocha", "Espresso", "Tea",
        "Americano", "Cold Brew", "Cappuccino", "Hot Chocolate"
    };

    // Linked list head/tail
    Node* coffeeHead = nullptr;
    Node* coffeeTail = nullptr;

    // Add 3 initial customers
    for (int i = 0; i < 3; i++)
    {
        enqueue(coffeeHead, coffeeTail,
                create_customer(drinks, DRINK_COUNT));
    }

    cout << "Initial Coffee Booth Queue:\n";
    print_linked_list(coffeeHead);

    return 0;
}

//Function definations
Customer create_customer(const string orders[], int size)
{
    string names[NAME_COUNT] = {
        "Ava", "Liam", "Emma", "Noah", "Sophia",
        "Mason", "Olivia", "Lucas", "Mia", "Ethan"
    };

    Customer c;
    c.name = names[rand() % NAME_COUNT];
    c.order = orders[rand() % size];
    return c;
}

void enqueue(Node*& head, Node*& tail, Customer c)
{
    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void print_linked_list(Node* head)
{
    if (head == nullptr)
    {
        cout << "Queue is empty.\n";
        return;
    }

    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data.name
             << " (" << current->data.order << ")\n";
        current = current->next;
    }
}
// Akashdeep Singh || Coms-210 || Final Part 2 || Vendor Booth Queue Simulation

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//Constants

const int ROUNDS = 10;
const int INITIAL_CUSTOMERS = 3;
const int NAME_COUNT = 10;
const int DRINK_COUNT = 8;


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
void dequeue(Node*& head, Node*& tail);
void print_linked_list(Node* head);

// Main

int main()
{
    srand(time(0));
  
    string drinks[DRINK_COUNT] = {
        "Latte", "Mocha", "Espresso", "Tea",
        "Americano", "Cold Brew", "Cappuccino", "Hot Chocolate"
    };

    // Linked list head/tail
    Node* coffeeHead = nullptr;
    Node* coffeeTail = nullptr;

    //Initialize queue with 3 customers
    for (int i = 0; i < INITIAL_CUSTOMERS; i++)
    {
        enqueue(coffeeHead, coffeeTail,
                create_customer(drinks, DRINK_COUNT));
    }

    //Run 10-round simulation
    for (int round = 1; round <= ROUNDS; round++)
    {
        cout << "\n==============================\n";
        cout << "ROUND " << round << "\n";
        cout << "==============================\n";

        // Serve customer
        if (coffeeHead != nullptr)
        {
            cout << "Served: "
                 << coffeeHead->data.name
                 << " ordered "
                 << coffeeHead->data.order << endl;

            dequeue(coffeeHead, coffeeTail);
        }
        else
        {
            cout << "No customers to serve.\n";
        }

        // 50% chance someone joins
        if (rand() % 2 == 0)
        {
            Customer newCustomer =
                create_customer(drinks, DRINK_COUNT);

            enqueue(coffeeHead, coffeeTail, newCustomer);

            cout << "Joined: "
                 << newCustomer.name
                 << " ordered "
                 << newCustomer.order << endl;
        }

        // Print queue
        cout << "Current Queue:\n";
        print_linked_list(coffeeHead);
    }

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

void dequeue(Node*& head, Node*& tail)
{
    if (head == nullptr)
        return;

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr)
            tail = nullptr;
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
// Akashdeep Singh || Coms-210 || Final Part 2 || Vendor Booth Queue Simulation

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

//Constants

const int ROUNDS = 10;
const int INITIAL_CUSTOMERS = 3;
const int NAME_COUNT = 10;
const int DRINK_COUNT = 8;
const int MUFFIN_COUNT = 6;
const int BRACELET_COUNT = 6;
const int STICKER_COUNT = 6;

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
void print_deque(deque<Customer> d);
void print_vector(vector<Customer> v);
void print_queue(queue<Customer> q);

// Main

int main()
{
    srand(time(0));
  
    string drinks[DRINK_COUNT] = {
        "Latte", "Mocha", "Espresso", "Tea",
        "Americano", "Cold Brew", "Cappuccino", "Hot Chocolate"
    };

    string muffins[MUFFIN_COUNT] = {
       "Blueberry Muffin", "Chocolate Muffin",
       "Banana Muffin", "Apple Muffin",
       "Pumpkin Muffin", "Strawberry Muffin"
    };

    string bracelets[BRACELET_COUNT] = {
        "Rainbow Bracelet", "Heart Bracelet",
        "Friendship Bracelet", "Glow Bracelet",
        "Charm Bracelet", "Beaded Bracelet"
    };

    string stickers[STICKER_COUNT] = {
        "Cat Sticker", "Dog Sticker",
        "Gaming Sticker", "Space Sticker",
        "Music Sticker", "Skull Sticker"
    };

    // Linked list head/tail
    Node* coffeeHead = nullptr;
    Node* coffeeTail = nullptr;

    //muffin booth deque
    deque<Customer> muffinQueue;

    //Bracelet booth (vector)
    vector<Customer> braceletQueue;

    //Sticker booth (queue)
    queue<Customer> stickerQueue;

    //Initialize both booths with 3 customers
    for (int i = 0; i < INITIAL_CUSTOMERS; i++)
    {
        enqueue(coffeeHead, coffeeTail,
                create_customer(drinks, DRINK_COUNT));
        
        muffinQueue.push_back(
            create_customer(muffins, MUFFIN_COUNT)
        );
        
        braceletQueue.push_back(
            create_customer(bracelets, BRACELET_COUNT)
        );

        stickerQueue.push(
            create_customer(stickers, STICKER_COUNT)
        );
    }

    //Run 10-round simulation
    for (int round = 1; round <= ROUNDS; round++)
    {
        cout << "\n==============================\n";
        cout << "ROUND " << round << "\n";
        cout << "==============================\n";

        //coffee booth
        cout << "\nCOFFEE BOOTH\n";

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
        
        //Muffin booth
        cout << "\nMUFFIN BOOTH\n";

        if (!muffinQueue.empty())
        {
            cout << "Served: "
                 << muffinQueue.front().name
                 << " ordered "
                 << muffinQueue.front().order << endl;

            muffinQueue.pop_front();
        }
        else
        {
            cout << "No customers to serve.\n";
        }

        if (rand() % 2 == 0)
        {
            Customer newCustomer =
                create_customer(muffins, MUFFIN_COUNT);

            muffinQueue.push_back(newCustomer);

            cout << "Joined: "
                 << newCustomer.name
                 << " ordered "
                 << newCustomer.order << endl;
        }
        
        cout << "Current Queue:\n";
        print_deque(muffinQueue);
    
        // Bracelet Booth
        cout << "\nBRACELET BOOTH\n";

        if (!braceletQueue.empty())
        {
            cout << "Served: "
                 << braceletQueue.front().name
                 << " ordered "
                 << braceletQueue.front().order << endl;

            braceletQueue.erase(braceletQueue.begin());
        }
        else
        {
            cout << "No customers to serve.\n";
        }

        if (rand() % 2 == 0)
        {
            Customer newCustomer =
                create_customer(bracelets, BRACELET_COUNT);

            braceletQueue.push_back(newCustomer);

            cout << "Joined: "
                 << newCustomer.name
                 << " ordered "
                 << newCustomer.order << endl;
        }

        cout << "Current Queue:\n";
        print_vector(braceletQueue);
    
        //Sticker Booth
        cout << "\nSTICKER BOOTH\n";

        if (!stickerQueue.empty())
        {
            cout << "Served: "
                 << stickerQueue.front().name
                 << " ordered "
                 << stickerQueue.front().order << endl;

            stickerQueue.pop();
        }
        else
        {
            cout << "No customers to serve.\n";
        }

        if (rand() % 2 == 0)
        {
            Customer newCustomer =
                create_customer(stickers, STICKER_COUNT);

            stickerQueue.push(newCustomer);

            cout << "Joined: "
                 << newCustomer.name
                 << " ordered "
                 << newCustomer.order << endl;
        }

        cout << "Current Queue:\n";
        print_queue(stickerQueue);
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

void print_deque(deque<Customer> d)
{
    if (d.empty())
    {
        cout << "Queue is empty.\n";
        return;
    }

    for (Customer c : d)
    {
        cout << c.name
             << " (" << c.order << ")\n";
    }
}

void print_vector(vector<Customer> v)
{
    if (v.empty())
    {
        cout << "Queue is empty.\n";
        return;
    }

    for (Customer c : v)
    {
        cout << c.name
             << " (" << c.order << ")\n";
    }
}

void print_queue(queue<Customer> q)
{
    if (q.empty())
    {
        cout << "Queue is empty.\n";
        return;
    }

    while (!q.empty())
    {
        cout << q.front().name
             << " (" << q.front().order << ")\n";
        q.pop();
    }
}
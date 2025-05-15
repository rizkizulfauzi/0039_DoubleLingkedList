#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int NoMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newNode = new Node();

        // Step 2: Assign value to the data fields
        newNode->NoMhs = nim;

        // Step 3: Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->NoMhs)
        {
            if (START != NULL && nim == START->NoMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // Step 4: newNode.next = START
            newNode->next = START;

            // Step 5: START.prev = newNode (if start exists)
            if (START != NULL)
                START->prev = newNode;

            // Step 6: newNode.prev = NULL
            newNode->prev = NULL;

            // Step 7: START = newNode
            START = newNode;
            return;
        }

        // insert in between node
        //  Step 8: locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->NoMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->NoMhs)
        {
            cout << "\nDuplicate roll number not allowed" << endl;
            return;
        }

        // Step 9: Insert between current and current->next
        newNode->next = current->next; // Step 9a
        newNode->prev = current;       // Step 9b

        // Insert last node
        if (current->next != NULL)
            current->next->prev = newNode; // Step 9c

        current->next = newNode; // Step 9d
    }

    void hapus()
    {
        if (START = NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse the list to find the mode
        while (current != NULL && current->NoMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // Step 2: If node is at the beginning
        if (current == START)
        {
            START = current->next; // Step 2a: START = START.next
            if (START != NULL)
                START->prev = NULL; // Step 2b: START.prev = NULL
        }
        else
        {
            // Step 3: Link previous node to next of current
            current->prev->next = current->next;

            // Step 4: If current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // Step 5; Delete the node
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Mark first node as currentNode
        Node *currentNode = START;

        // Step 2: Repeat until currentNode == NULL
        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {

            cout << i + 1 << ". " << currentNode->NoMhs << " " << endl;

            // Step 3: Move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Move to last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        // Step 2: Traverse backward
        cout << "\nRecords in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->NoMhs << " " << endl;

            // Step 3: Move to previous node
            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse to find matching roll number
        while (current != NULL && current->NoMhs != rollNo)
            current = current->next;

        // Step 2: Output result
        if (current == NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll Number: " << current->NoMhs << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {

        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.searchData();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    } while (choice != '6');
}
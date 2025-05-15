#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
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
        string nama;
        cout << "\nEnter the roll number of the student";
        cin >> nim;

        Node *newNode = new Node();

        newNode->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // step 4
            newNode->next = START;
            // Step 5
            if (START != NULL)
                START->prev = NULL;
            // step 6
            newNode->prev = NULL;
            // step 7
            START = newNode;
            return;

            Node *current = START;
            while (current->next != NULL && nim == current->next->noMhs < nim)
            {
                current = current ->next;
            }
        }
    }
};
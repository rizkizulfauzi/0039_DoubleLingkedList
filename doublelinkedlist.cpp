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
                current = current->next;
            }
            if (current->next != NULL && nim == current->next->noMhs)
            {
                cout << "\nDuplicate roll number notallowed" << endl;
                return;
            }

            // step9
            newNode->next = current->next;
            newNode->prev = current;

            // insert last node
            if (current->next != NULL)
                current->next->prev = newNode;

            current->next = newNode;
        }
    }
    void hapus()
    {
        if (START == NULL)
        {
            cout << "\n.List is empty" << endl;
            return;
        }
        cout << "\nEnter Number you want to delete:";
        int rolNo;
        cin >> rolNo;

        Node *current = START;
        while (current != NULL && current->noMhs != rolNo)
        {
            current = current->next;
        }
        if (current == NULL){
            cout << "Record not found" <<endl;
            return;
        }
        if(current == START){
            START = current -> next;
            if (START != NULL){
                START -> prev =NULL;
            }
        }else{
            current ->prev -> next = current->next;
            if (current -> next != NULL){
                current -> next -> prev = current ->prev;
            }
        }
        delete current;
        cout <<  "record with roll number " <<rolNo <<"delete" <<endl;
    }
};
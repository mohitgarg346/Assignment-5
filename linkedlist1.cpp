#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
int main()
{
    Node *head = NULL, *temp, *newNode;
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int key = 1, count = 0;
    for (int i = 0; i < 7; i++)
    {
        newNode = new Node;
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
    while (head != NULL)
    {
        if (head->data == key)
        {
            temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        else
            break;
    }

    temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            newNode = temp->next;
            temp->next = newNode->next;
            delete newNode;
            count++;
        }
        else
            temp = temp->next;
    }

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << "->";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}

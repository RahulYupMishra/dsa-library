#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*head = NULL;

void createList(int n)
{
    struct node *newNode , *temp;
    int data , i;
    head = new node;
    cout<<"Enter data for first node: ";
    cin>>data;
    head -> data = data;
    head->next = NULL;
    temp = head;

    for(i = 2 ; i<=n ; i++)
    {
        newNode = new node;
        cout<<"Enter data for node "<<i<<" :";
        cin>>data;
        newNode -> data = data;
        newNode -> next = NULL;
        temp -> next = newNode;
        temp = newNode;

    }

    cout<<endl<<"List created successfully";
}

int middleNode(node *head)
{
    int i=0 , middle;
    node *count;
    count = head;

    while(count->next != NULL)
    {
        count = count->next;
        i++;
    }

    if(i%2!=0)
    {
        middle = (i+1)/2;
    }
    else
    {
        middle = i/2;
    }

    node *result;
    result = head;

    for(int j =1;j<=middle;j++)
    {
        result = result->next;
    }

    return result->data;
    
}

int main()
{
    int n;
    cout<<"Enter the size of linked list: ";
    cin>>n;
    createList(n);
    cout<<endl<<"Middle node is: "<<middleNode(head);
    return 0;
}
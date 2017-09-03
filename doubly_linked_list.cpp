#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node* head;

void InsertAtHead(int k)
{
	Node* temp = new Node();
	temp->data = k;
	temp->prev = 0;
	temp->next = 0;
	if (head == 0)
	{
		temp->next = 0;
	}
	else {
		temp->next = head;
	}
	
	head = temp;
}

void InsertAtTail(int k)
{
	Node* temp = new Node();
	Node* q = head;
	Node* cur = 0;
	temp->data = k;
	temp->next = 0;
	temp->prev = 0;
	while (q != 0)
	{
		cur = q;
		q = q->next;
	}
	
	if (cur == 0)
	{
		temp->prev = 0;
		head = temp;
	}
	else {
		cur->next = temp;
		temp->prev = cur;
	}
	
}

void Print() 
{
	Node* temp = head;
	printf("Current List is: ");
	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint()
{
	Node* temp = head;
	Node* cur = 0;
	printf("Reversed List: ");
	while (temp != 0)
	{
		cur = temp;        // get last location
		temp = temp->next;
	}

	while (cur != 0)
	{
		printf("%d ", cur->data);
		cur = cur->prev;
	}
	printf("\n");

}

int main()
{
	head = 0;
	InsertAtTail(1);
	InsertAtTail(2);
	InsertAtTail(3);
	InsertAtTail(4);
	printf("%d", head->data);
	Print();
	ReversePrint();
    return 0;
}


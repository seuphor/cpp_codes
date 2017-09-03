#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node* next;
};

Node* head;

void insert(int k) 
{
	Node* temp = new Node();
	temp->data = k;
	temp->next = head;
	head = temp;
}

Node* Delete(Node* head, int n)
{
	// loop to locate the node at n location
	// if n == 1 condition	
	Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next;
		delete temp1;
		return head;
	}
	// other conditions
	Node* temp2 = head;
	for (int i = 0; i<n-1; i++) 
	{
		temp1 = temp2;
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	delete temp2;
	return head;
}

void Print(Node* head) 
{
	Node* temp = head;
	printf("List is: ");
	while (temp != 0)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Node* InsertSpec(Node* head, int k, int loc) 
{
	// get into specific location
	Node* temp1 = new Node();
	temp1->data = k;
	temp1->next = 0;

	if (loc == 1) {
		temp1->next = head;
		head = temp1;
		return head;
	}

	Node* temp2 = head;
	for (int i = 0; i < loc - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
	return head;

	// reset previous Node->next variable
	// set current Node->next to the original previous Node->next

}

Node* Reverse(Node* head)
{
	Node* prev = 0;
	Node* nex = 0;
	Node* cur = head;
	while (cur != 0)
	{
		nex = cur->next; // store the next memory location
		cur->next = prev; // link current->next to the previous location
		prev = cur; // move pre to cur location
		cur = nex; // move cur to next memory location
	}
	head = prev;
	return head;

}

void ReversePrint(Node* point)
{
	if (point == 0)
	{
		printf("reverse list is: ");
		return;
	}

	ReversePrint(point->next);
	printf("%d ", point->data);
}

void ReverseRecur(Node* point)
{
	
	if (point->next == 0)
	{
		head = point;
		return;
	}
	ReverseRecur(point->next);
	Node* nex = point->next;
	nex->next = point;
	point->next = 0;
}

int main()
{
	printf("How many numbers to insert?");
	int n;
	int k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter the exact number you want to insert.");
		scanf("%d", &k);
		insert(k);
		Print(head);
	}
/*
	head = InsertSpec(head, 3, 3);
	Print(head);

	head = Delete(head, 3);
	Print(head);

	head = Reverse(head);
	Print(head);

	ReversePrint(head);
*/
	ReverseRecur(head);
	Print(head);


}


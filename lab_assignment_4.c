#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
node* curr = head;
int count = 0;
while (curr != NULL)
{
	curr = curr -> next;
	count++;
}
return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
char* string = (char*) malloc(sizeof(char) * length(head)+1);	
node* curr = head;
for (int i = 0; i < length(head); i++)
{
	if (curr != NULL)
	{
		string[i] = curr ->letter;
	}
	curr = curr -> next;
}
string[length(head) ] = "\0";
return string;

}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newnode = (node*) malloc(sizeof(node));
	newnode -> letter = c;
	newnode ->next = NULL;
	node* tmp = *pHead;

if (*pHead == NULL)
{
	*pHead = newnode;
	return;
}
while (tmp ->next !=NULL){
	tmp = tmp -> next;
}
	tmp -> next = newnode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	
	*pHead = NULL;

}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
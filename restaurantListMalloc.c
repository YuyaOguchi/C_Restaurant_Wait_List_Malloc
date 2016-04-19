//  Yuya Oguchi
//  COEN11L     Lab5
//  10/24/2014
//  restaurantwaitlist Malloc
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int number;
    char name[20];
    struct node *next;
    struct node *previous;
}Node;

Node *head = NULL;
Node *tail = NULL;

void add(){
    Node *p;
    if ((p = (Node*)malloc (sizeof (Node))) == (Node*)NULL){
		printf ("Node could not be allocated\n");
		return;
	}

    printf("Enter name\n");
	scanf("%s", p->name);
	if (head == NULL){
		head = p;

	}else{
		Node *temp;
		temp = head;
		while (temp != NULL){
			if (strcmp(temp->name, p->name) == 0){//duplicate
				printf("Duplicate, try again\n");
				free(p);
				return;
			}
			else{//no duplicate
				temp = temp->next;
			}
		}
	}//end else check duplicate
    printf("Enter the number\n");
    scanf("%d",&p->number);
    if (tail != NULL){
		tail->next = p;
	}
	tail = p;
        tail->next=NULL;
    return;
}

void delete(){
    int open;
    Node *temp = head;//make temp linklist that is at head
    printf("What is the size of table?\n");
    scanf("%d", &open);

	if (head->number <= open)//checking for head
	{
	head = temp->next;
	free(temp);
	return;
	}
    Node *change;
    Node *temp2;
    change=temp;
    temp=change->next;
    while (temp->next != NULL){
        //change=temp;
        //temp=change->next;
        if (temp->number <= open)//if num is less than open
        {
            temp2 = change->next;
            change->next = change->next->next;
            free(temp2);
            printf("Value taken out\n");
            return;
        }else if (temp->number > open)
        {
	    change = temp;
            temp = temp->next;
        }
    }//close while loop

    if(temp->number <= open){
        printf("Last value taken out\n");
        free(temp);
        tail = change;
        tail->next = NULL;
    }
	return;
}//close void

void stats(){
    Node *temp = head;
    while (temp != NULL){
        printf("Name: %s\tNumber: %d\n", temp->name, temp->number);
		temp = temp->next;
    }
    return;
}

int main()
{
    int command;
    int quit = 0;
    printf("Welcome to Yuya's Restaurant what would you like to do?\n\n");
    printf("Type 1 to add waitlist\n");
    printf("Type 2 to eliminate an entry that fits the table\n");
    printf("Type 3 to show all Waitlist\n");
    printf("Type 4 to quit\n");
    printf("----------------------------\n\n");


    while (quit == 0){

        scanf("%d",&command);

        if (command == 1){
            add();

        }else if (command == 2){
            delete();

        }else if (command == 3){
            stats();

        }else if (command == 4){
            quit = 1;

        }
        printf("What would you like to do?\n");

    }//end while loop

    return 0;
}

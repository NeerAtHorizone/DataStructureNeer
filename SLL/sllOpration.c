#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create(int);
void inLast();
void inBig();
void inLoc();
void display();
void deletBeg();
void deletAt();
void deletEnd();


struct node {
    int data;
    struct node * next;
};
struct node * head , *tail =NULL;

int main()
{
    printf("========< LET'S START >=========\n");
    printf("\n\n\tFirst we'll insert some node\n");
    printf("How many node do you want in starting : ");

    int n,ch=0;
    scanf("%d", &n);

    create(n);
    display();

    while (ch != 7)
    {
        printf("Now Enter the number accordingly:\n");
        printf("\t1.Insert At Bigining\n");
        printf("\t2.Insert At Last\n");
        printf("\t3.Insert At Specific Location\n");
        printf("\t4.Delete first node\n");
        printf("\t5.Delete at given location\n");
        printf("\t6.Delete last node\n");
        printf("\t7.Exit\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            inBig();
            display();  
            break;
        case 2:
            inLast();
            display(); 
            break;
        case 3:
            inLoc();
            display();
            break;
        case 4:
            deletBeg();
            display();
            break;
        case 5:
            deletAt();
            display();
            break;
        case 6:
            deletEnd();
            display();
            break;
        case 7:
            printf("\n=======< THIS IS THE END >=======\n");
            break;
        default:
            printf("Enter valid choice:\n");
            break;
        }
        
    }
    



return 0;
}

void create(int n){

    printf("Enter value/s : ");

    while (n--)
    {   
        struct node * new = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &new ->data);
        new ->next = NULL;
        if(head == NULL){
            head = new;
            tail = new;
        }
        else{
            tail ->next = new;
            tail = new; 
        }
    }
    
}

void display () {
    struct node * current;
    current = head;

    printf("\nYour Entered values so far:\n");
    if(head == NULL){
        printf("\n\t\tNO VALUES RIGHT NOW\n");
    }
    else{
    while (current != NULL )
    {
        printf("\t>>>\t%d\n", current ->data);
        current = current -> next;
    }
    }
    

}


void inBig()
{   struct node * new = (struct node *)malloc(sizeof(struct node));
    int temp;

    printf("Enter value: ");
    scanf("%d", &temp);
    new ->data = temp;
    new ->next = head;
    head = new;

}
void inLast()
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    int temp;

    printf("Enter value: ");
    scanf("%d", &temp);
    new ->data = temp;
    new ->next = NULL;
    
    tail ->next = new;
    tail = new;



}
void inLoc()
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    struct node * current = head;
    int loc, temp;

    printf("Enter location : ");
    scanf("%d", &loc);
    printf("Enter value : ");
    scanf("%d", &temp);
    new ->data = temp;

    loc -= 2;
    while (loc--)
    {
        current = current ->next;
    }
    
    new ->next =  current->next;
    current ->next = new;

}



void deletBeg()
{
    struct node * ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nList is empty, no more can be delete");
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        printf("\nFist node Delted");
    }
    else
    {
        head = ptr ->next;
        printf("\nFist Node Deleted");
    }
    free(ptr);

}


void deletAt()
{
    struct node * ptr1, *ptr;
    ptr = head;

    int loc, temp;
    printf("\nEnter the loc: ");
    scanf("%d", &loc);
    temp = loc;
    loc--;
    if (head == NULL)
    {
        printf("\nList is empty, can not delet further");
    }
    else if(head -> next == NULL)
    {
        printf("\nThere is only one node......");
        head = NULL;
        printf("\nNow Deleted.....Empty List");
    }
    else
    {
         while (loc--)
         {
            if (ptr == NULL)
            {
                printf("\nNO node present at this no. of location");
            }
            else
            {  
                ptr1 = ptr;
                ptr = ptr ->next;
            }
            
         }
         
         ptr1 -> next = ptr -> next;
         free(ptr);
         printf("\nNode deleted at %d location", temp);
         
    }
    
}


void deletEnd()
{
    struct node * ptr1, *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nList is empty , cannot delet anymore");
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        printf("\nLast node deleted");
    }
    else
    {
    while (ptr -> next != NULL)
    {
         ptr1 = ptr;
         ptr = ptr ->next;
    }

    ptr1 -> next = NULL;
    free(ptr);

    printf("\nLast node deleted");
    }

}
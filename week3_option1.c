#include <stdio.h>
#include <stdlib.h>

typedef struct list{int data; struct list *next;} list; //  Singly linked list.

///////////////////////
//  Creates a new node.
list *newNode(int x){
    list *localNode = malloc(sizeof(list));

    localNode->data = x;
    localNode->next = NULL;

    return localNode;
}

//////////////////////////////////////////
//  Attach a new node to an existing head.
void addNodeAtHead(int x, list **inputHead){
    list *localNode = newNode(x);

    localNode->next = *inputHead;
    *inputHead = localNode;
}

////////////////////////////////////////////////////////////////////////////
//  Creates a list of 'inputSize' random elements between the values [0;49].
list *createRandomList(int inputSize, int inputRNGSeed){
    srand(inputRNGSeed);
    list *localHead = newNode(rand() % 50);

    while(inputSize-- - 1 > 0){
        addNodeAtHead(rand() % 50, &localHead);
    }

    return localHead;
}

////////////////
//  Prints list.
void printList(list *inputHead){
    int column=0;

    while(inputHead != NULL){
        if(column % 5 == 0){ printf("\n"); column=0; }
        printf("%5d: ", inputHead->data);
        inputHead = inputHead->next;
        column++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
//  Swaps the position of nodes 'inputArrow' and 'inputArrow->next'.
//  Since 'inputArrow' is a singly linked list, 'inputArrow' previous node must be known.
void swapTwoNodes(list **inputArrow, list *inputPreviousArrow){
    list *localNode1=*inputArrow, *localNode2=(*inputArrow)->next;

    localNode1->next = localNode2->next;
    localNode2->next = localNode1;
    if(inputPreviousArrow){ inputPreviousArrow->next = localNode2; }
    *inputArrow = localNode2;
}

////////////////////////////////////
//  Sorts a list in ascending order.
void sortList(list **inputHead, int inputListSize){
    list *localHead=*inputHead, *localArrow, *localPreviousArrow;
    int i, j, k=inputListSize;

    for(i=1; i < inputListSize; i++){
        localPreviousArrow = NULL;
        localArrow = localHead;      
        for(j=1; j < k; j++){
            if(localArrow->data > localArrow->next->data){
                swapTwoNodes(&localArrow, localPreviousArrow);
                if(j==1){ localHead = localArrow; }
            }
            localPreviousArrow = localArrow;
            localArrow = localArrow->next;
        }
        k--;
    }
    *inputHead = localHead;
}


int main(void){

    //////////////////////////////////////////////////////
    //  User input for the number of elements in the list.
    int listSize;
    printf("Enter number of elements: ");
    scanf("%d", &listSize);
    if(listSize < 1){ return printf("[Invalid input] Number of elements must be an integer bigger than 0."); }

    list *head = createRandomList(listSize, 0);   //  List creation.
    printf("\nOriginal list.");
    printList(head);

    sortList(&head, listSize);  //  Sorting list in ascending order.
    printf("\n\nSorted list.");
    printList(head);

    return 0;
}
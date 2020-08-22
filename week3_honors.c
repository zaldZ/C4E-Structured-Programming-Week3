#include <stdio.h>
#include <stdlib.h>

typedef struct list{int data; struct list *next; struct list *previous;} list;

///////////////////////
//  Creates a new node.
list *newNode(int x){
    list *localNode = malloc(sizeof(list));

    localNode->data = x;
    localNode->next = NULL;
    localNode->previous = NULL;
    return localNode;
}

//////////////////////////////////////////
//  Attach a new node to an existing head.
void addNodeAtHead(int x, list **inputHead){
    list *localNode = newNode(x);
    localNode->next = *inputHead;
    (*inputHead)->previous = localNode;
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

//////////////////////////////////
//  Prints list from head to tail.
void printListNext(list *inputHead){
    int column=0;
    while(inputHead != NULL){
        if(column % 5 == 0){ printf("\n"); column=0; }
        printf("%5d: ", inputHead->data);
        inputHead = inputHead->next;
        column++;
    }
}

////////////////////////////////////////////////////////////////////
//  Swaps the position of nodes 'inputArrow' and 'inputArrow->next'.
void swapTwoNodes(list **inputArrow){
    list *localNode1=*inputArrow, *localNode2=(*inputArrow)->next;
    list *localPointerArray[4];

    localPointerArray[0] = localNode1->next;
    localPointerArray[1] = localNode1->previous;
    localPointerArray[2] = localNode2->next;
    localPointerArray[3] = localNode2->previous;

    localNode1->next = localPointerArray[2];
    localNode1->previous = localPointerArray[0];
    localNode2->next = localPointerArray[3];
    localNode2->previous = localPointerArray[1];

    if(localNode2->previous){ localNode2->previous->next = localNode2; }
    if(localNode1->next){ localNode1->next->previous = localNode1; }

    *inputArrow = localNode2;
}

//////////////////////////////////////////////////////
//  Sorts a list from head to tail in ascending order.
void sortListNext(list **inputHead, int inputListSize){
    list *localHead=*inputHead, *localArrow;
    int i, j, k=inputListSize;
    for(i=1; i < inputListSize; i++){
        localArrow = localHead;
        for(j=1; j < k; j++){
            if(localArrow->data > localArrow->next->data){
                swapTwoNodes(&localArrow);
                if(j==1){ localHead = localArrow; }
            }
            localArrow = localArrow->next;
        }
        k--;
    }
    *inputHead = localHead;
}

//////////////////////////////////////////////////////////////
//  Removes all duplicates in a sorted list from head to tail.
void removeDuplicateNext(list *inputHead, int inputListSize){
    list *localArrow=inputHead, *localNode1, *localNode2;
    
    while(localArrow != NULL){
        localNode1 = localArrow;
        localNode2 = localArrow->next;
        AGAIN:
        if(localNode2 != NULL){
            if(localNode1->data == localNode2->data){ localNode2 = localNode2->next; goto AGAIN; }
            else{
                localNode1->next = localNode2;
                localNode2->previous = localNode1;
            }
            localArrow = localNode2;
        }
        else{
            localNode1->next = NULL;
            localArrow = NULL;
        }
    }
}

int main(void){

    //////////////////////////////////////////////////////
    //  User input for the number of elements in the list.
    int listSize;
    printf("Enter number of elements: ");
    scanf("%d", &listSize);
    if(listSize < 1){ return printf("[Invalid input] Number of elements must be an integer bigger than 0."); }

    list *head = createRandomList(listSize, 0); //  List creation.
    printf("\nOriginal list.");
    printListNext(head);

    sortListNext(&head, listSize);  //  Sorting list in ascending order. (Makes it easier to remove duplicates.)

    removeDuplicateNext(head, listSize);    //  Removing duplicates in the list.
    printf("\n\nUnique list.");
    printListNext(head);

    return 0;
}
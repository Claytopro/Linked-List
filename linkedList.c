/*
By:clayton provan
create linked list with pointers. includes functions to alphabetise data.
check if linked list contains data. reverse linked list. 
*/

#include "linkedList.h"

int main(){
    struct listNode **list = calloc(sizeof(Node),5); 

   
    push(list,newNode("eat"));
    push(list,newNode("cock"));
    push(list,newNode("dick"));
    push(list,newNode("apple"));
    push(list,newNode("butter"));
    
    printLinkedList(*list);
    printf("\n");
    reverseOrder(list);
    printLinkedList(*list);

    alphaSort(list, 5);
       printf("\n");
    printLinkedList(*list);

    deleteList(list);
    
    
    return 0;
}

/* Mandatory: Frees all allocated memory associated with the list pointers iteratively */
void deleteList(Node **list) {
    Node *temp = NULL; 
    while( (*list) != NULL){
        temp = *list;
        *list = (*list)->next;
        free(temp);
       
    }
    free(list);
}

/* Mandatory: Frees all allocated memory associated with a single node */
void deleteNode(Node **toDelete){
    free((*toDelete));
}

/* Mandatory: Allocates memory for a new string and returns a pointer to the memory. */
Node *newNode(char *string) {
        struct listNode *new = malloc(sizeof(Node));
        new->data = string;
        return new;
}

/* Mandatory: Removes a node from the front of a list */
Node *pop(Node **list) {
        struct listNode *temp = *list; 
        *list = temp->next;
    return temp;
}

/* Mandatory: Adds a node to the front of a list */
void push(Node **list, Node *toAdd) {
        toAdd->next = *list; 
        *list = toAdd;
}

/* Mandatory: Return a list of pointers in order */
void reverseOrder(Node **list) {
    /* Hint: your solution should not need to allocate memory */
    /* remember push and pop... */
    
    Node **reverseList = NULL;
    Node *temp =NULL;
    reverseList = malloc(sizeof(Node));
    if(list == NULL){
        return;
    }
 
    while(*list){
        temp = pop(list);
        push(reverseList,temp);

    }
    /*set pointer equal to reversed list pointer, list is null currently*/
    *list = *reverseList;
    free(reverseList);
}

/* Optional: Prints an entire linked list. Nodes are printed from first to last. */
void printLinkedList(Node *list) {

 while(list != NULL){
        /*TODO %p expects pointer*/
        printf("holds %s\n",list->data);
        list = list->next;
    }
}
/*sort words alpha betically by copying them to a list of words, sorting them.
then reassigning the values in the linked list*/
void alphaSort(Node **list,int numStrings){
    char **words = malloc(sizeof(char*) * numStrings);
    Node *start = *list;
    int i=0;
    if(*list == NULL || list == NULL){
        return;
    }

    /*takes in all words stored in the linked list*/
    while(*list){
        words[i] = (*list)->data;
        (*list) = (*list)->next;
        i++;
        
    }

    qsort(words,numStrings,sizeof(char*),cmp);
   
    *list = start;
    i=0;

    /*assigns value alphabetised words to linkedlist*/
    while(*list){
        
        (*list)->data =words[i] ;
        (*list) = (*list)->next;
        i++;    
    }

    *list = start;
    free(words);
}

/*moves pointers around to sort them alphabetically*/
void sortLinks(Node **list){



}

int cmp(const void *a, const void *b){
    return(strcmp(*((char**)a), *((char **)b)));
}
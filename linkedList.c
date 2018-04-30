/*
By:clayton provan
create linked list with pointers. includes functions to alphabetise data.
check if linked list contains data. reverse linked list. 
*/

#include "linkedList.h"

int main(){
    struct listNode **list = calloc(sizeof(Node),6); 

    /*test all with nothing in list*/
    printLinkedList(*list);
    
    reverseOrder(list);
    alphaSort(list,5);
    insertAfter(list,"dick",newNode("hats"));
    deleteList(list);

    list = calloc(sizeof(Node),6);
    
    push(list,newNode("eat"));
    /*test with only 1 entry*/

    reverseOrder(list);
    alphaSort(list,1);
    insertAfter(list,"eat",newNode("hatts"));
    printf("list before deletions\n");
    printLinkedList(*list);
    printf("\n");
    deleteList(list);

    list = calloc(sizeof(Node),6);
    push(list,newNode("cock"));
    push(list,newNode("dick"));
    push(list,newNode("apple"));
    push(list,newNode("butter"));
    
    printLinkedList(*list);
    printf("reversed\n\n");
    reverseOrder(list);
    printLinkedList(*list);

    alphaSort(list,4);
    printf("sorted\n\n");
    printLinkedList(*list);
    printf("insert after\n\n");
    insertAfter(list,"dick",newNode("hats"));
    printLinkedList(*list);
    alphaSort(list,5);
    printf("sorted\n\n");
    printLinkedList(*list);
    deleteList(list);
    
    
    return 0;
}

/*Frees all allocated memory associated with the list pointers iteratively */
void deleteList(Node **list) {
    Node *temp = NULL; 
    while( (*list) != NULL){
        temp = *list;
        *list = (*list)->next;
        free(temp);
       
    }
    free(list);
}

/*Frees all allocated memory associated with a single node */
void deleteNode(Node **toDelete){
    free((*toDelete));
}

/*Allocates memory for a new string and returns a pointer to the memory. */
Node *newNode(char *string) {
        struct listNode *new = malloc(sizeof(Node));
        new->data = string;
        new->next = NULL;
        return new;
}

/*Removes a node from the front of a list */
Node *pop(Node **list) {
        struct listNode *temp = *list; 
        *list = temp->next;
        temp->next = NULL;
    return temp;
}

/*Adds a node to the front of a list */
void push(Node **list, Node *toAdd) {
        toAdd->next = *list; 
        *list = toAdd;
}

/*Return a list of pointers in order */
void reverseOrder(Node **list) {
    /* Hint: your solution should not need to allocate memory */
    /* remember push and pop... */
    Node *temp = NULL;
    Node *tempT =NULL;
    if(list == NULL || (*list)==NULL){
        return;
    }
    temp = pop(list);
    while(*list){
        tempT =pop(list);
        tempT->next = temp;
        temp = tempT;
    }
    *list = temp;
}

/* Optional: Prints an entire linked list. Nodes are printed from first to last. */
void printLinkedList(Node *list) {
   
    while(list != NULL){    
        printf("holds %s\n",list->data);
        list = list->next;
    }
}

void insertAfter(Node **list, char* dataSearch,Node *toAdd){
       Node *start = NULL;

        if(list == NULL || *list == NULL){  
            free(toAdd);
            return;
        }

        start = *list;
        
        while(*list){
            if(!strcmp((*list)->data,dataSearch)){
                toAdd->next = (*list)->next;
                (*list)->next = toAdd;
                (*list) = (*list)->next;  
            }
            (*list) = (*list)->next;
        }
     *list = start;
}

/*sort words alphabetically by copying them to a list of words, sorting them.
then reassigning the values in the linked list*/
void alphaSort(Node **list,int numStrings){
    char **words = malloc(sizeof(char*) * numStrings);
    Node *start = *list;
    int i=0;
    if(*list == NULL || list == NULL){
        free(words);
        return;
    }

    /*takes in all words stored in the linked list*/
    while(*list){
        words[i] = (*list)->data;
        (*list) = (*list)->next;
        i++;
        
    }

    
    if(i == 1){
        *list = start;
        free(words);
        return;
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

/*moves pointers around to sort them alphabetically
better for struct that hold more data (maybe?)*/
void sortLinks(Node **list){



}

int cmp(const void *a, const void *b){
    return(strcmp(*((char**)a), *((char **)b)));
}
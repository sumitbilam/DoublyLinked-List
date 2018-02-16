/** Uses the comparison function in the List struct to place the element in the appropriate position in the list.
*this is intended to be used from the beginning in order to keep the list completely sorted.
*@pre List exists and has memory allocated to it. Node to be added is valid.
*@post The node to be added will be placed immediately before or after the first occurrence of a related node
*@param list a pointer to the dummy head of the list containing function pointers for delete and compare, as well 
as a pointer to the first and last element of the list.
*@param toBeAdded a pointer to data that is to be added to the linked list
**/

void insertSorted(List *list, void *toBeAdded){
    Node *addNode = initializeNode(toBeAdded);
    Node *pos = list->head;
    
    if(list->head == NULL){
        list->head = addNode;
        list->tail = addNode;
        return;
    }
    while(pos!=NULL && list->compare(toBeAdded, pos->data)==1){
        pos = pos->next;
    }
    
    /*if found position at the very beginning of the list*/
    if(pos->previous == NULL){
        addNode->next = list->head;
        list->head->previous = addNode;
        list->head = addNode;
    }
    /*if found position at the end of the list*/
    else if(pos->next == NULL){
        addNode->previous = list->tail;
        list->tail->next = addNode; 
        list->tail = addNode;
    }
    else{
        addNode->previous = pos;
        addNode->next = pos->next;
        pos->next->previous = addNode;
        pos->next = addNode;
    }

}
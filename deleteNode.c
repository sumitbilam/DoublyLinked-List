/**Function to remove a node from the list and alter the pointers accordingly to not disrupt the order of the 
 *data structure. 
 *@pre List must exist and have memory allocated to it
 *@post toBeDeleted will have its memory freed if it exists in the list.
 *@param list pointer to the dummy head of the list containing deleteFunction function pointer
 *@param toBeDeleted pointer to data that is to be removed from the list
 *@return returns EXIT_SUCCESS on success, and EXIT_FAILURE when empty. Returns -1 when the node cannot be found.
 **/
int deleteNodeFromList(List *list, void *toBeDeleted){
    Node *nodePos = NULL;
    nodePos = list->head;
     while(nodePos != NULL && list->compare(toBeDeleted, nodePos->data)!=0){
          nodePos = nodePos->next;
    }
    Node *front, *back;
    front = nodePos->next;
    front->previous = nodePos->previous;
    back = nodePos->previous;
    back->next = nodePos->next;
    free(nodePos);

    return EXIT_SUCCESS;
}
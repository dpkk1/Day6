//Delete nodes having greater value on right 

void _delLesserNodes(struct Node* head)
{
    struct Node* current = head;
    struct Node* maxnode = head;
    struct Node* temp;
 
    while (current != NULL && 
           current->next != NULL) 
    {
        if (current->next->data < maxnode->data) 
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else
        {
            current = current->next;
            maxnode = current;
        }
    }
}


void reverseList(struct Node** headref)
{
    struct Node* current = *headref;
    struct Node* prev = NULL;
    struct Node* next;
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headref = prev;
}

void delLesserNodes(struct Node** head_ref)
{
    reverseList(head_ref);
    _delLesserNodes(*head_ref);
    reverseList(head_ref);
}

Node *compute(Node *head)
{
    delLesserNodes(&head);
    return head;
}

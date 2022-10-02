#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};
// create a node with data as x
struct Node *create_node(int x)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}
// delete the node at `ptr` and free its memory
void delete_node(struct Node *ptr)
{
    free(ptr);
}
// ------------------------------ Node struct definition ends here ------------------------------
// Use this to operate on the list, this will always point at the head of the list.
struct Node *PythonListHead = NULL;
// prints the list in space seperated format
void print_list(struct Node *head)
{
    struct Node *cur = head;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
int len()
{
    int cou = 0;


    struct Node *current = PythonListHead;
    while (current != NULL)
    {
        cou++;
        current = current->next;
    }
    return cou;
}
// Add an item to the end of the list
void append(int x)
{

    struct Node *p = create_node(x);
    struct Node *n;
    n = PythonListHead;
    if (PythonListHead == NULL)
    {
        PythonListHead = create_node(x);
        return;
    }
    while (n->next != NULL)
    {
        n = n->next;
    }
    n->next = p;
}
// Insert an item at a given position.
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x)
{   if (PythonListHead==NULL){
    return;
}
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = PythonListHead;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    if ((position > count) || (position < 0))
    {
        return;
    }
    if (position == 0)
    {
        struct Node *p = PythonListHead;
        ptr->data = x;
        ptr->next = p;

        PythonListHead = ptr;
    }
    else
    {
        int i = 0;
        struct Node *p = PythonListHead;
        while (i != position - 1)
        {
            p = p->next;
            i++;
        }
        ptr->data = x;
        ptr->next = p->next;
        p->next = ptr;
        return;
    }
}

// Remove the item at the end of the list
void pop()
{   struct Node *m = PythonListHead;
    if(PythonListHead==NULL){
        return;
    }
    int count = len();
    if (count==1){
        PythonListHead = NULL;
        delete_node(m);
        return;
    }
    struct Node *p = PythonListHead;
    struct Node *q = PythonListHead->next;
    
    
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    q=p->next;
    p->next = NULL;
    free(q);}


// Remove all items from the list
void clear()
{
    struct Node *t = PythonListHead;
    while (t != NULL)
    {
        t = t->next;
        free(PythonListHead);
        PythonListHead = t;
    }
}

// Return the number of times x appears in the list.

int count(int x)
{
    struct Node *current = PythonListHead;
    int cnt = 0;
    while (current)
    {
        if (current->data == x)
        {
            cnt += 1;
        }
        current = current->next;
    }
    return cnt;
}

// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse()
{
    struct Node *a = PythonListHead;
    struct Node *temp = NULL, *next = NULL;
    while (a != NULL)
    {
        next = a->next;
        a->next = temp;
        temp = a;
        a = next;
    }
    PythonListHead = temp;
}

// Return the number of elements in the list

// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x)
{ 

    struct Node *current = PythonListHead;
    int count = 0;

    while (current != NULL)
    {
        if (count == position)
        {
            (current->data) = x;
        }
        count++;
        current = current->next;
    }
}

// Return the data of the node at `position`
// if no such position, return -1
int getitem(int position)
{   
    struct Node *current = PythonListHead;
    int count = 0;
    int a = len();
    if ((position >= a) || (position < 0))
    {
        return -1;
    }
    while (current != NULL)
    {   if (count == position)
        {
            return (current->data);
        }
        count++;
        current = current->next;
    }
}

// erase the node at position
// if no such position, do nothing
void erase(int position)
{   int a=len();
    if (PythonListHead==NULL){
        return;
    }
    struct Node *p = PythonListHead;
    struct Node *q = PythonListHead->next;
    
    if ((position>a)||(position<0)){
        return;
    }
    if (position==0){
        PythonListHead=q;
        free(p);
    }
    else{
    for (int i = 0; i < position - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    delete_node(q);
    }
}

// Returns a the head of the newly formed Python List
// containing elements present in positions in the original List.
// Note: you have to create new Python List and return its head.
// Here positions is an array of size n.
// eg. if positions = [2, 3, 5], you need to return a newly formed list
// having nodes that were at position 2, 3 and 5 in the original list.
// if there is such a position that is not present in the original list, do nothing
// with that position.
struct Node *index_into(int *positions, int n)
{
    struct Node * head = NULL;
    struct Node* t =head;
    int l =len();
    for (int i = 0;i<n;i++)
{
    if (positions[i] >=l || positions[i] <0)
    {
        continue;
    }
    if (head == NULL)
    {
        head = create_node(getitem(positions[i]));
        t = head;
        continue;
    }
    t->next = create_node(getitem(positions[i]));
    t = t->next;
}
return head;
}



// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position)

{   
    
    int a=len();
    if (position < 0 || position>=a)
    {
        return;
    }
    if (a==0||a==1){
        return;
    }  
    struct Node *p = PythonListHead;
    struct Node *q = PythonListHead->next;
    if(position==a-1){
        return ;}
    else if (position==0){
        p->next=q->next;
        q->next=p;
        
        PythonListHead=q;
    }
    else{
    for (int i = 0; i < position-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    struct Node *temp = q->next;
    struct Node* temp1 = temp -> next;

    q->next = temp1;
    temp->next=q;
    p->next=temp;
    
 
    
}}
// sort the Python list
// you may use the above defined swap function to
// implement bubble sort. But its upto you.
void sort()
{   // it`s a bubble sort 
    int a = len();
    struct Node *currentNode;
    struct Node *nextNode;
    for (int nodeCtr = a - 2; nodeCtr >= 0; nodeCtr--)
    {
        currentNode = PythonListHead;
        nextNode = currentNode->next;
        for (int i = 0; i <= nodeCtr; i++)
        {
            if ((currentNode->data) > (nextNode->data))
            {
                int temp  = currentNode->data;
                currentNode->data = nextNode->data;
                nextNode->data = temp;
            }
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
    }
}
// ----------------------- Driver program starts here -----------------------
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    char operation_type[20];
    int indices[100];

    while (T--)
    {
        scanf("%s", operation_type);

        if (strcmp(operation_type, "append") == 0)
        {
            int x;
            scanf("%d", &x);
            append(x);
        }

        if (strcmp(operation_type, "insert") == 0)
        {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insert(pos, x);
        }

        if (strcmp(operation_type, "pop") == 0)
        {
            pop();
        }
        
        if (strcmp(operation_type, "clear") == 0)
        {
            clear();
        }

        if (strcmp(operation_type, "count") == 0)
        {
            int x;
            scanf("%d", &x);
            int cnt = count(x);
            printf("%d\n", cnt);
        }

        if (strcmp(operation_type, "reverse") == 0)
        {
            reverse();
        }

        if (strcmp(operation_type, "len") == 0)
        {
            int length = len();
            printf("%d\n", length);
        }

        if (strcmp(operation_type, "setitem") == 0)
        {
            int pos, x;
            scanf("%d %d", &pos, &x);
            setitem(pos, x);
        }

        if (strcmp(operation_type, "getitem") == 0)
        {
            int pos;
            scanf("%d", &pos);
            int value = getitem(pos);
            printf("%d\n", value);
        }

        if (strcmp(operation_type, "print") == 0)
        {
            print_list(PythonListHead);
        }

        if (strcmp(operation_type, "erase") == 0)
        {
            int pos;
            scanf("%d", &pos);
            erase(pos);
        }

        if (strcmp(operation_type, "swap") == 0)
        {
            int pos;
            scanf("%d", &pos);
            swap(pos);
        }

        if (strcmp(operation_type, "index_into") == 0)
        {
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
                scanf("%d", &indices[i]);
            struct Node *new_head = index_into(indices, n);
            print_list(new_head);
        }

        if (strcmp(operation_type, "sort") == 0)
        {
            sort();
        }
    }
} 
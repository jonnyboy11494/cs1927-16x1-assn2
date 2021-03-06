typedef struct list * List;

typedef struct node * link;

struct node{
  Item item;
  link next;
};

struct list{
  link first;
};

//create new empty list
List newList();

//create new node
link newNode(Item path);

//insert node at the end of list
List insertEnd(List list, link new);

//insert node at front of list
List insertFront(List list, link new);

//delete first node and return first item
Item getFirstItem(List list);

//check if list is empty
int isListEmpty(List list);

//empty (but not free) list
List emptyList(List list);

//completely free list
void deleteList(List list);

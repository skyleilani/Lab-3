/*
 * Lab 3 - Linked Lists - C++ and Data Structures with Andrew Cencini (andrewcencini@bennington.edu)
 *
 * Sky Leilani (skyleilani@bennington.edu)
 *
 * 3/22/2019
 */

#include <iostream>

using namespace std;


/*
 * Struct: node - allows us to create instances of node object with which we will create a linked list
 *
 * constructor(?) params: int v - the value ;
 *                node *n - the pointer to the neighboring node
 *
 */

struct node {

    int value;
    node *link;

    node(int v, node *n){
        value = v;
        link = n;
    }

};


void traverse(node *);  // traverse through a linked list & print values & addresses of nodes
void addToEnd(node *, node* ); // traverse through a linked list and add a node to the end
void addToBeginning(node *, node * ); // replace the initial start node with newNode
int addAtIndex(node *, node*, int);
int removeByValue(node*, int);
node* removeAtStart(node*);
node* findByValue(node* , int);


/*
 * Function: traverse - Task 0: traverse through linked list from node 0 to node with NULL neighbor
 *
 * Param: start- pointer to the location of the starter node
 *
 * Returns: no return
 */
void traverse(node *start) {

    while (start != NULL) {

    cout << "node value: " << start -> value << " node address: " << start << endl;
    start = start -> link;

    }
}


/*
 * Function: addToEnd - Task 1: add a neew node to the end of an existing linked list
 *
 * Params: startingPoint - a pointer to the start node's location,
 *         newNode - a pointer to a different node that will be added to linked list
 *
 * Returns: no return
 */
void addToEnd( node *startingPoint, node *newNode ) {

    node* current = startingPoint;

    while ( current -> link != NULL ) {

        current = current -> link;

    }

    current -> link = newNode;
}


/*
 * Function: addToBeginning - Task 2 : add a new node to the beginning of an already existing linked list
 *
 * Params: startingPoint - starting node of list,
 *         newNode - new node to add to linked list
 *
 * Returns: no return
 */
void addToBeginning( node *startingPoint, node *newNode ) {

        newNode->link = startingPoint;
}


/*
 * Function: addAtIndex - Task 3 : add a new node at given (in param) index in linked list
 *
 * Params: startingPoint - pointer to  start node of linked list,
 *         newNode - pointer to newNode to add, index_val - place in list to add
 *
 * Returns: no return
 */
int addAtIndex( node *startingPoint, node *newNode, int index_val ) {

    int x = 0;

    while (x < index_val - 1 ) {

        x++;
        startingPoint = startingPoint -> link;

    }

    newNode -> link = startingPoint -> link;
    startingPoint -> link = newNode;

    return startingPoint -> value;
}


/*
 * Function: removeByValue - task 4 : remove a node by specified value
 *
 * Params: startingPoint: start node of linked list,
 *         rem_val - index of node you want to remove
 *
 * Returns: nodes_removed - number of nodes removed
 */
int removeByValue( node* startingPoint, int val ){

    int nodes_removed = 0;

    node* prev = startingPoint; // super thanks to andrew's code
    node* curr = startingPoint -> link; // ^

    while( curr != NULL ) {

        if( curr -> value == val ){

            prev -> link = curr -> link; // c->l : StartingPoint -> link -> link
            delete( prev -> link );

            nodes_removed++;
        }

        prev = curr;
        curr = curr -> link;
    }

    cout << nodes_removed << " nodes removed." << endl;
    return nodes_removed;
}


/*
 * Function: removeAtStart - removes node from the beginning and creates a new node as start node
 *
 * Params: startingPoint - start node of linked list
 *
 * Returns: startingPoint - the new starting point of the linked list or NULL if starting point is null (not a linked list
 */
node* removeAtStart( node* startingPoint ){

    if( startingPoint != NULL ){

         cout << "Deleting node " << startingPoint-> value << " at "<<  startingPoint  << endl;

         startingPoint = startingPoint -> link;

         return startingPoint;
    }

    cout << "This list is empty... " << endl;
    return NULL;

}

/*
 * Function: removeAtEnd - removes a node from the end of an existing linked list
 *
 * Params: startingPoint - start node of linked list
 *
 * Returns: no return
 */
void removeAtEnd( node* startingPoint ) {

    node* curr = startingPoint;
    node* prev = startingPoint;

    while ( curr->link != NULL ) {

        prev = curr;
        curr = curr->link;

     }

    cout << curr -> value   << " deleted" << endl;
    prev -> link = NULL;

    delete(prev->link);
}


/*
 * Function: findByValue - finds a node of specified value
 *
 * Params: startingPoint - start node of linked list,
 *         int value - value of node you wish you find
 *
 * Returns: location of node with the value specified
 */
node* findByValue(node* startingPoint, int value) {

    while( startingPoint -> link != NULL && startingPoint -> value != value ) {
        
        startingPoint = startingPoint -> link;
        
    }

    if (startingPoint -> value == value ) {

        cout << "node " << startingPoint -> value << " found at " << startingPoint << endl;
        return startingPoint;
    }

    cout << "NODE NOT FOUND IN LIST " << endl;
    return NULL;
}


int main() {

    node *start_l = new node(1, new node(2, new node(3, new node (20, new node (70, NULL)))));  // creating a linked list
    traverse(start_l);

    // create a node named addNode that will be adde to the end of the list (so NULL neighbor
    // call addToEnd ( traverse through list of start node given and add addNode to the end )
    // traverse through start_l list one more time

    cout << "\n adding a node to the end of linked list... \n" << endl;
    node *addNode = new node(4, NULL);

    addToEnd(start_l, addNode);
    traverse(start_l);

    cout << "\n adding a node to the beginning of linked list... \n" << endl;
    node *newNode = new node(0, NULL);
    addToBeginning(start_l, newNode);

    start_l = newNode;  // 100% understood this due to Andrew's answer sheet

    traverse(start_l);


    cout << "\n adding a new node to specified index... \n" << endl;
    node *add_Node = new node(8, NULL);
    addAtIndex(start_l, add_Node, 2);
    traverse(start_l);


    cout << "\n removing a node...\n" << endl;

    removeByValue(start_l, 2);
    removeByValue(start_l, 100);
    traverse(start_l);


    cout <<"\n removing from start of list.. \n" << endl;
    start_l = removeAtStart(start_l);
    traverse(start_l);

    cout <<"\n removing from end of list... \n" << endl;
    removeAtEnd(start_l);
    traverse(start_l);

    cout <<"\n finding by value... \n" << endl;
    findByValue(start_l, 2);
    findByValue(start_l, 20);
    traverse(start_l);



    return 0;
}



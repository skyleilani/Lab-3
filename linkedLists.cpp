//
// Created by Sky Leilani on 2019-03-15.
//

#include <iostream>

using namespace std;


struct node {       // naming our struct 'node'

    int value;      // declaring first item (integer-type 'value')
    node *next;     // creating link named 'next' containing the neighboring node's address

    node ( int v, node *n ) {   // I think this is setting a template for the the node constructor & it's
                            // params as some integer 'v' and some node n's location
        value = v;  // defining the item param  as the integer declared earlier, 'value'
        next = n;   // defining the link param as the location on line 11

    };
};


int main() {

    node* start = new node( 1, NULL );    // setting the very first node's value to 1 and link to NULL
    start -> next = new node( 2, NULL );  // setting the neighboring node of start's value to 2 and it's link to NULL,

    node* two = new node( 2, NULL); // so my thinking is that this makes a new node and says its name is two, it's value is 2 and its neighbor is NULL,
                                    // so it just gives a name to the node next to start...?
    two -> next = new node( 3, NULL); // and then this one says "node two's neighbor's value is 3 and it's neighbor is NULL)


    cout << "FIRST LOCATION: " << start << endl << "SECOND LOCATION: " << two -> next << endl <<"LAST LOCATION: " << start -> next  << endl;
    return 0;
}

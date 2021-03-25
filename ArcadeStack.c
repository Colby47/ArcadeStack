#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//typedefs for the structs
typedef struct Stack Stack;
typedef struct Node Node;

//Stack struct
struct Stack {
    Node * head;
};

//Node struct
struct Node{
    char name [21];
    int money;
    Node * mvp;
    Node * next;
};

//allocates for new node person, sets their next to null, and returns it
Node * createNode(){
    Node * person = calloc(1, sizeof(Node));
    person->next = NULL;
    return person;
}

//function to add a person to the head of stack
void push(Stack * arcade, Node * person){

    //assign the oldHead and newHead
    Node * oldHead = arcade->head;
    Node * newHead = person;

    //switch pointers around by making head = newHead and head->next = oldHead
    arcade->head = newHead;
    arcade->head->next = oldHead;

    return;
}

//function to remove head of stack
void pop(Stack * arcade){

    //if there is only one element in stack
    if(arcade->head->next == NULL){
        arcade->head = NULL;
    }
    else{
        Node * newHead = arcade->head->next;
        free(arcade->head);
        arcade->head = newHead;
    }

    return;
}

int main (){

    //create the stack arcade
    Stack * arcade = calloc(1, sizeof(Stack));

    //create variables to assign to people later
    int t = 4;
    int money;
    char name [21];
    Node * mvp;

    //While statement to loop for inputs and respond accordingly
    while(t != 0){

        //scan for input
        scanf("%d", &t);

        //if num entered is 0, break loop and end program
        if(t == 0){
            break;
        }

        //if num entered is 1, create a person and add to stack
        else if (t == 1){

            //in case arcade is empty
            if(arcade->head == NULL){

                scanf("%d", &money);
                scanf("%s", name);

                //create a new person
                Node * person = createNode();

                //assign data to person
                person->money = money;
                strcpy(person->name, name);
                person->mvp = person;

                //person becomes head of stack
                arcade->head = person;
            }

            //if arcade is not empty
            else{

                scanf("%d", &money);
                scanf("%s", name);

                //create a new person
                Node * person = createNode();

                //assign data to person
                person->money = money;
                strcpy(person->name, name);

                //compare money to mvp
                if(arcade->head->mvp->money > person->money){
                    person->mvp = arcade->head->mvp;
                }
                else{
                    person->mvp = person;
                }

                //push person onto the stack
                push(arcade, person);
            }

        }

        //if num entered is 2, remove a person from stack
        else if(t == 2){
            pop(arcade);
        }

        //if num entered is 3, print mvp
        else if (t == 3) {
            printf("%s\n", arcade->head->mvp);
        }
    }

    return 0;
}

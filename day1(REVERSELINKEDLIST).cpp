// today i solveed reverse linked list  
// how tow use three pointer (prev , current ,next ) to reverse linked list ;
// ALGO IS TO 1.SET  PREV AND NEXT TO NULL ,2.EACH TIME CURRENT POINTER PROCESS IS TO REVERSE DIRECTION OF NODE , 3.NEXT POINTER HELP TO STORE REMANING LINKED LIST 
//4.UPDATE PREV TO CURRENT AND CURRENT TO NEXT ;
#include <iostream>
using namespace std ; 

class Node {
    public :
    int data ;
    Node * next ;

};
Node* reverselinkedlist(Node* head){
    Node* prev = NULL;
    Node * current = head ;
     
    while (current!= NULL){
        Node* next = current->next;
        current->next =prev;
        prev= current ;
        current = next ; 
    }
 return prev;
}
int main (){

Node * head = new Node() ;
Node * second = new Node() ;
Node * third = new Node() ;
Node * fourth = new Node() ;
  
head ->data = 10 ;
head ->next = second ;
second ->data = 20 ;
second ->next = third ;
third ->data = 30 ;
third ->next = fourth;
fourth ->data = 40 ;
fourth ->next = NULL;


head = reverselinkedlist(head);

Node* temp = head;

while(temp != NULL)
{
    cout << temp->data << " ";
    temp = temp->next;
}
    return 0;
}

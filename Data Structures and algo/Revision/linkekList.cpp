#include<iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
	
	node(int a){
	   data = a;
	   next = NULL;	
	}
};

node *head = NULL;
node *tail;

void insert_beg(){
    int n;
	cout << "Enter the data for the node" << endl;
   	cin >> n;
    node *newNode = new node(n);
  
    if(head == NULL){
   	  head = newNode;
   	  tail = newNode;
    }	 
   else{
   	  newNode -> next = head;
      head = newNode;
   }
}

void insert_end(){
   	int n;
	cout << "Enter the data for the node" << endl;
   	cin >> n;
    node *newNode = new node(n);
    
    tail -> next = newNode;
    tail = tail -> next;
}

void del_beg(){
     if(head == NULL){
     	return;
	 }	
	 
	 node *q = head;
	 head = head -> next;
	 delete q;
}

void del_end(){
     if(head == NULL){
     	return;
	 }	
	 
	 node *r = head;
	 while(r -> next -> next != NULL){
	 	r = r -> next;
	 }
	 
	 r -> next = NULL;
     tail = r;
}

void print(){
    if(head == NULL){
   	  cout << "Linked List is empty" << endl;
    }
    else{
    cout << "Linked List is:" << endl; 
    node *p = head;
    while(p != NULL){
   	  cout << p -> data << " ";
   	  p = p -> next;
    }
    cout << endl; 
  }
}

int main(){

   int n;
   do{
      cout << "Enter the task to be performed" << endl;
      cin >> n;
      
      switch(n){
      	case 1:
      	   insert_beg();
		   break;
		case 2:
		   insert_end();
		   break;
		case 3:
		   del_beg();        
		   break;
		case 4:
		   del_end();   
		   break;
		case 5:
		   print();    	
	  }
   }while(n != 6);  

   return 0;	
}
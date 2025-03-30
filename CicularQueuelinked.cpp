#include<iostream>
using namespace std;
//class to create the Nodes for the circular Queue
class Node{
    public:
    Node* next;
    int data;
    Node(int val){
        next=nullptr;
        data=val;
    }
};
//class to impliment the Circular Queue throught linkedlist
class CircularQueue{
    Node *front,*rear;
    public:
    bool isEmpty();
    void EnQueue();
    int DeQueue();
    void Display();
    CircularQueue(){
        front=nullptr;
        rear=nullptr;
    }
};
//function to check if the Queue is empty or not
bool CircularQueue:: isEmpty(){
return front==nullptr;
}
//funttion to add the new Nodes to the Queue
void CircularQueue::EnQueue(){
    int value;
    cout<<"Enter the Value you want to store in the new Node "<<endl;
    cin>>value;
    Node * newnode=new Node(value);
    if(isEmpty()){
        front=newnode;
        rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
//funtion to remove the Nodes form the Queue
int CircularQueue::DeQueue(){
    int value;
    Node* head=front;
    if(isEmpty()){cout<<"The Queue is Empty can't DeQueue any element"<<endl;
    return -1;}
    else if(head->next==front){

      value=head->data;

      delete head;
      front=rear=nullptr;

    }else{

          value=head->data;
        front=front->next;
         delete head;
        rear->next=front;


       }
    return value;
}
// funtion to Display the Nodes of the Queue
void CircularQueue::Display(){
    if(isEmpty()){
        cout<<"The Queue is Empty right now "<<endl;
    return;}

    Node * head=front;
   do{
  cout<<head->data<<" ";
  head=head->next;

    } while(head!=front);
    cout<<endl;
}
//The Menu function to display the options to the user
void menu(){
    CircularQueue CQ;
    cout<<"\n#####Welcome to the  the circualar Queue implimentation with linkedlist####"<<endl;

    int choice;
    do{


    cout<<"1.To EnQueue"<<endl;
    cout<<"2.To DeQueue"<<endl;
    cout<<"3.To print the Number of nodes present in the Queue"<<endl;

    cout<<"\nEnter your choice from 1-3"<<endl;
    cin>>choice;

    switch(choice){
    case 1:
    CQ.EnQueue();
    break;
    case 2:
    CQ.DeQueue();
    break;
    case 3:
    CQ.Display();
    break;
    default:
    cout<<"YOu enterd wrong number re-Enter the choice"<<endl;


    }}while(choice>0&& choice<4);}


//main form where the program will start the execution
int main(){
    menu();

    return 0;
}

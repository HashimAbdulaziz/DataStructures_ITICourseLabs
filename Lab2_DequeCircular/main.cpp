#include <iostream>
using namespace std;

/*
Simple Queue :
  problems : deleted Elements cant Be reused
  solution : Circular Queue

Delete ===> Front
Insert ===> Rear
==================================================
Circular Queue
Delete ===> Front
Insert ===> Rear
==================================================
Priority Queue

Delete ===> Priority, Front
Insert ===>  Rear
==================================================
Double Ended Queue
=============================
Input Restricted  [One Inertion , Both Delete]
insertRear();
deleteFront();
deleteRear();


Output Restricted
insertRear();
insertFront();
deleteFront();


*/
class MinaQueue{
    private:
        int* items ;
        int rear ; //EnterIndex
        //int fornt; //OutIndex
        int capicty;
        int size;

    public:
        int fornt; //OutIndex

        MinaQueue(int capicty){
            rear=-1;
            fornt=-1;
            //size=0;
            this->capicty = capicty;
            items = new int[capicty];
        }

        ~MinaQueue(){
            delete [] items;
        }

        void insertRear(int item){
            //Check Full
            if((fornt == 0 && rear == capicty-1) || (fornt == rear+1)){
                //if(size == capicty){}
                //Resize Dynamic Array
                cout<<"Ops Qeueu is Full!"<< endl;
                return;
            }

            //Setting Rear and Front
            //First Element
            if(rear == -1 &&  fornt == -1  ){
                rear=0;
                fornt=0;
            }
            else if (rear == capicty-1){ //&& fornt != 0
                rear=0;
            }
            else{
                rear++;
            }
            //Add item
            items[rear] = item;
            //size++;
        }


        int deleteFront(){
            //Check Empty
            if(fornt == -1 ){cout<<"Empty Queue!\n"; return -1;}
            //if(size == 0 ){cout<<"Empty Queue" ; return -1;}

            int temp = items[fornt]; //Backup Item
            //Delete Item
            items[fornt] = -10; //-10 for Debug

            //Change Front and Rear
            if(fornt == rear ){ // will be empty
                fornt = -1;
                rear = -1;
            }
            else if(fornt == capicty -1){ // Circular
                fornt = 0;
            }
            else{
                fornt++;
            }

            //return Item
            //size--;
            return temp;
        }


        void display(){
            cout<<"\n========================================\n";
            //Empty
            if(fornt == -1 ){cout<<"Empty Queue\n"; return;}
            /*if(fornt <= rear){
                for (int i= fornt ; i<= rear; i++){
                    cout<<items[i]<< "\t";
                }
            }else { //fornt >= rear
                for (int i= fornt ; i< capicty; i++){
                    cout<<items[i]<< "\t";
                }
                for (int i= 0 ; i<= rear; i++){
                    cout<<items[i]<< "\t";
                cout << "Ops Queue is Full!\n";
                return;
            }
            else if(fornt == -1 && rear == -1){
                fornt = 0;
                rear = 0;
                items[fornt] = item;

            }
            else{
                fornt--;
                items[fornt] = item;
            }
        }


        void deleteRear(){

        }
};                }

            }*/
            // rear = 0  front = 1
            // fornt 3   rear = 2   3 4 0 1 2
            int i = fornt % capicty; // 3%5 ===> 3
            while(i != rear){
                cout << items[i] << "\t";
                i = (i+1) % capicty;
            }
            cout << items[rear];
            cout<<"\n========================================\n";
        }


        void insertFront(int item){
            // check if Full
            if((fornt == 0 && rear == capicty-1) || fornt-1 == rear){
                cout << "Ops Queue is Full!\n";
                return;
            }

            if(fornt == -1 && rear == -1){ // check if empty
                fornt = rear = 0;
            }
            else{
                fornt = (fornt-1 + capicty) % capicty;
            }
            items[fornt] = item;
        }


        int deleteRear(){
            if(fornt == -1 ){cout<<"Empty Queue!\n"; return -1;}

            int temp = items[rear];

            if(fornt == rear ){ // will be empty
                fornt = -1;
                rear = -1;
            }
            else{
                rear = (rear-1 + capicty) % capicty;
            }

            return temp;
        }
};


//======================================================================================

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class QueueLinkedList{
    private:
        Node* front;
        Node* rear;

    public:
        QueueLinkedList() {
            front = rear = nullptr;
        }

        ~QueueLinkedList() {
            while (!isEmpty()) {
                deleteFront();
            }
        }

        bool isEmpty() {
            return front == nullptr;
        }

        // Insert at Rear
        void insertRear(int item) {
            Node* newNode = new Node(item);

            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                newNode->prev = rear;
                rear = newNode;
            }
        }

        // Insert at Front
        void insertFront(int item) {
            Node* newNode = new Node(item);

            if (isEmpty()) {
                front = rear = newNode;
            } else {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
        }

        // Delete from Front
        int deleteFront() {
            if (isEmpty()) {
                cout << "Empty Queue!\n";
                return -1;
            }

            Node* temp = front;
            int value = temp->data;

            if (front == rear) {
                front = rear = nullptr;
            } else {
                front = front->next;
                front->prev = nullptr;
            }

            delete temp;
            return value;
        }

        // Delete from Rear
        int deleteRear() {
            if (isEmpty()) {
                cout << "Empty Queue!\n";
                return -1;
            }

            Node* temp = rear;
            int value = temp->data;

            if (front == rear) {
                front = rear = nullptr;
            } else {
                rear = rear->prev;
                rear->next = nullptr;
            }

            delete temp;
            return value;
        }

        // Display Queue
        void display() {
            if (isEmpty()) {
                cout << "Empty Queue\n";
                return;
            }

            cout << "\n========================================\n";
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << "\n========================================\n";
        }
};







int main()
{
     MinaQueue q(5);

     q.insertRear(10);
     q.insertRear(20);
     q.insertRear(30);
     q.insertRear(40);
     q.insertRear(50);
     q.insertRear(60); // Ops it's Full
     q.display(); //10 20 30 40 50
     cout<< "Delete Front: "<< q.deleteFront()<< endl; //10
     cout<< "Delete Front: "<< q.deleteFront()<< endl; //20
     q.display(); //30 40 50

     q.insertRear(70); //rear = 0
     q.insertRear(80); //rear = 1
     q.display();//30 40 50 70 80
     cout<< "Delete Front: " << q.deleteFront()<<endl; //30
     cout<< "Delete Front: " << q.deleteFront()<<endl; //40
     cout<< "Delete Front: " << q.deleteFront()<<endl; //50
     cout<< "Delete Front: " << q.deleteFront()<<endl; //70
     cout<< "Delete Front: " << q.deleteFront()<<endl; //80
     cout<< "Delete Front: " << q.deleteFront()<<endl; //Empty -1
     q.display(); //Empty

     q.insertRear(90);
     q.insertRear(100);
     q.insertRear(1000);
     q.display(); //90 100 1000

     // testing insert front
     q.insertFront(80);
     q.insertFront(70);
     q.display(); //70 80 90 100 1000

     // testing dele rear
     cout<< "Delete Rear: " << q.deleteRear()<<endl;
     cout<< "Delete Rear: " << q.deleteRear()<<endl;
     q.display(); //90 100 1000


     cout << "====================== testing QueueLinkedList ============================\n";
     //=========================================

    QueueLinkedList qL;

    qL.insertRear(10);
    qL.insertRear(20);
    qL.insertRear(30);
    qL.insertRear(40);
    qL.insertRear(50);
    qL.display();

    cout << "Delete Front: " << qL.deleteFront() << endl;
    cout << "Delete Front: " << qL.deleteFront() << endl;
    qL.display();

    qL.insertRear(60);
    qL.insertRear(70);
    qL.display();

    cout << "Delete Rear: " << qL.deleteRear() << endl;
    cout << "Delete Rear: " << qL.deleteRear() << endl;
    qL.display();

    qL.insertFront(5);
    qL.insertFront(1);
    qL.display();



    return 0;
}

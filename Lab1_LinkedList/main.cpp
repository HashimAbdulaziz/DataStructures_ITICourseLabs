#include <iostream>

using namespace std;


        //void InsertAfter(int data, int afterData);

        //void InsertBefore(int data, int beforeData);

        //int GetCount();

        //int GetDataByIndex(int index);
//5. Remove All Nodes
    //void RemoveALL(int data)


class Node{
    public:
        Node* next;
        Node* prev;
        int data;

        Node(int data){
            next = nullptr;
            prev = nullptr;
            this->data = data;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int count;

    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            count = 0;
        }

        LinkedList(int data){
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
            count = 1;
        }

        void insertLast(int data){
            Node* newNode = new Node(data);

            // check if it's first Node or not
            if(tail == nullptr){
                tail = newNode;
                head = newNode;
            }
            else{
                Node* oldNode = tail;
                tail->next = newNode;
                tail = newNode;
                tail->prev = oldNode;
            }

            count++;
        }


        void insertFirst(int data){
            Node* newNode = new Node(data);
            if(tail == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }

            count++;
        }


        //1. indsert node after given node
        void insertAfter(int data, int afterData){
            Node* current = head;
            // check if the Linked List is empty
            if(current == nullptr){
                cout << "Ops LinkedList is empty!" << endl;
                return;
            }

            while(current->data != afterData){
                current = current->next;

                if(current == nullptr){
                    cout << "Ops node with data " << afterData << " not exist!" << endl;
                    return;
                }
            }

            if(current == tail){ // if you inserting after last element
                insertLast(data);
            }
            else{
                Node* newNode = new Node(data);

                newNode->next = current->next;
                newNode->prev = current;
                current->next->prev = newNode;
                current->next = newNode;

                count++;
            }
        }


        //2. insert node before given node
        void insertBefore(int data, int beforeData){
            Node* current = head;
            // check if the Linked List is empty
            if(current == nullptr){
                cout << "Ops LinkedList is empty!" << endl;
                return;
            }

            while(current->data != beforeData){
                current = current->next;

                if(current == nullptr){
                    cout << "Ops node with data " << beforeData << " not exist!" << endl;
                    return;
                }
            }

            if(current == head){ // if you inserting before first element
                insertFirst(data);
            }
            else{
                Node* newNode = new Node(data);

                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;

                count++;
            }
        }

        //4. get data in the given
        int getDataByIndex(int index){
            Node* current = head;
            if(index > count-1 || index < 0){
                cout << "Ops index out of bounds" << ends;
                return -1;
            }

            for(int i = 0; i < index; i++, current=current->next);

            return current->data;
        }

        void removeFirst(int data, Node* current = nullptr){
            // check if the Linked List is empty
            if(current == nullptr){
                current = head;
                if(current == nullptr) return;
            }

            while(current->data != data){
                current = current->next;

                if(current == nullptr){
                    return;
                }
            }

            if(current != head)
                current->prev->next = current->next;
            else{   // moving head if removing first element
                head = current->next;
            }

            if(current != tail)
                current->next->prev = current->prev;
            else{ // moving tail if you remove last element
                tail = current->prev;
            }

            current->next = NULL;
            current->prev = NULL;
            delete current;

            count--;
        }


        void removeALL(int data){
            Node* current= head;
            while(current){
                if(current->data == data){
                    current = current->next;
                    if(current != nullptr)
                        removeFirst(data, current->prev);
                    else
                        removeFirst(data, tail);
                }
                else{
                    current = current->next;
                }
            }
        }


        void display(){
            Node* current = head;
            while(current){
                cout << "[" << current->data << "]->";
                current = current->next;
            }
            cout <<"NULL\n";
        }

        //3. get number of nodes
        int getSize(){
            return count;
        }



        ~LinkedList(){
            Node* current = head;
            while(current){
                current = current->next;

                current->prev->next = NULL;
                current->prev->prev = NULL;

                delete current;
            }
        }


};


int main()
{
    // testing insertLast
    LinkedList l1(10);
    l1.insertLast(12);
    l1.insertLast(15);
    l1.insertLast(15);

    l1.display();

    // testing insertFirst
    l1.insertFirst(50);
    l1.insertFirst(40);
    l1.insertFirst(10);
    l1.insertFirst(10);

    l1.display();

    // testing getSize
    cout << l1.getSize() << endl;

    // testing insertAfter
    l1.insertAfter(13, 12);
    l1.insertAfter(14, 13);
    l1.insertAfter(16, 100); // node not found

    l1.display();

    // testing insertBefore
    l1.insertBefore(30, 40);
    l1.insertBefore(11, 12);
    //l1.insertBefore(16, 70); // node not found

    l1.display();


    // testing removeFirst
    cout << endl << "===== testing removeFirst =====" << endl;
    l1.removeFirst(15);
    l1.removeFirst(10);
    l1.display();

    l1.removeALL(10);
    l1.display();




    return 0;
}

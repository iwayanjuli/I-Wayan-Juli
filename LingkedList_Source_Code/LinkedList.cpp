#include <iostream>
using namespace std;
class Node{
	public:
		char id;
		Node *next;
		
		Node(){
			next = NULL;
		}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
		LinkedList(){
			head = tail = NULL;
		}
		
		void insertToHead(char data){
			Node *node = new Node();
			node->id = data;
			
			if(head==NULL){
				head = node;
				tail = node;
			}else{
				Node *tmp = head;
				head = node;
				head->next= tmp;
			}
		}
		
		void insertToTail(char data){
			Node *node = new Node();
			node->id = data;
			if(head == NULL){ //jika linkedlist kosong
				head = node;
				tail = node;
				//head = tail = node;
			}else{
				tail->next = node;
				tail = node;
			}
		}
		
		void insertDataAfter(char data, char after){
			if(head == NULL){
				cout << "ERROR: LinkedList is Empty!" << endl;
			}else if(after == tail->id){
				insertToTail(data);
			}else{
				Node *tmp = head;
				while(tmp != NULL && tmp->id!=after){
					tmp = tmp->next;
				}
				
				if(tmp == NULL){
					cout << "ERROR: After data not found" << endl;
				}else{
					Node *newNode = new Node();
					newNode->id = data;
					
					newNode->next = tmp->next;
					tmp->next = newNode;
				}
			}
		}

		void deletefromHead(){
			if(head == NULL){
				cout << "LinkedList is Empty!" << endl;
				return;
			} else if (head == tail){
				delete head;
				head = tail = NULL;
			} else {
				Node *tmp = head;
				head = head->next;
				tmp->next = NULL;
				delete tmp;
			}	
		}

		void deletefromTail(){
			if (head == NULL){
				cout << "LinkedList is Empty!" << endl;
				return;
			} else if (head == tail){
				deletefromHead();
			} else {
				Node *tmp = head;
				while (tmp != NULL && tmp->next != tail){
					tmp = tmp->next;
				}
				delete tail;
				tail = tmp;
				tmp->next = NULL;
			}	
		}
		void deleteafterId(char afterId){
			if (head == NULL){
				cout << "LinkedList is Empty!" << endl;
				return;
			} else if (head == tail){
				deletefromHead();
			} else {
				Node *tmp = head;
				while(tmp != NULL && tmp->id != afterId){
					tmp = tmp->next;
			}
			if (tmp == NULL || tmp->next == NULL){
				cout <<"Node dengan after id" << afterId <<"tidak ada!" <<endl;
				return;
			}
				Node *tmp2 = tmp;
				tmp = tmp->next;
				if(tmp->next == tail){
					delete tail;
					tail = tmp2;
				} else {
					tmp2->next = tmp->next;
					tmp->next = NULL;
					delete tmp;
				}
			}
		}
			
		void printAll(){
			Node *tmp = head;
			
			while(tmp!=NULL){
				cout << tmp->id << "->";
				tmp = tmp->next;
			}
		}
};

int main(int argc, char** argv) {
	
	LinkedList *list1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->id = 'A';
	
	list1->head = node1;
	list1->tail = node1;
	
	cout << list1 << endl;
	cout << list1->head->id <<endl << endl;
	
	
	cout << list1->head << endl;
	cout << node1 << endl;
	cout << list1->tail << endl;
	
	//Insert to tail
	Node *node2 = new Node();
	node2->id = 'B';
	
	list1->tail->next = node2;
	list1->tail = node2;
	
	cout << list1->head->id << endl;
	cout << list1->tail->id << endl;
	
	//insert to head
	Node *nodex = new Node();
	nodex->id = 'X';
	
	Node *tmp = list1->head;
	list1->head = nodex;
	list1->head->next = tmp; //nodex->next = tmp;
	
	cout << list1->head->id << endl;
	cout << list1->tail->id << endl;
	
	//after creating function
	list1->insertToHead('Y');
	list1->insertToTail('C');
	
	cout << list1->head->id << endl;
	cout << list1->tail->id << endl;
	
	list1->insertDataAfter('Z', 'X');
	
	cout << endl;

	list1->deletefromHead();

	
	list1->deletefromTail();

	list1->deleteafterId('X');
	cout << endl;

	list1->printAll();
	return 0;
}

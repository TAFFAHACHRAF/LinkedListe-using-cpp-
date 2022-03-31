#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class node{
	public:
		int data;
		node *next;
		
		node(int data){
			this->data=data;
			next=NULL;
		}
};

class linkedListe{
	private:
		node *header;
		node *tail;
		int size;
	public:
		linkedListe(){
			header=NULL;
			tail=NULL;
			size=0;
		}
		int getSize(){
			return size;
		}
		void append(int data){
			node *n = new node(data);
			if(header == NULL){
				header=n;
				tail=n;
			}
			else{
				tail->next=n;
				tail=n;
			}
			size++;
		}
		void toString(){
			node *temp;
			temp=header;
			int i=0;
			while(temp->data){
				cout << "Data["<< i << "]=" << temp->data << "\n";
				i++;
				temp=temp->next;
			}
		}
};
int main(){
	linkedListe *l=new linkedListe();
	l->append(188);
	l->append(1);
	l->append(178);
	l->append(888);
	
	l->toString();
	return 0;
}

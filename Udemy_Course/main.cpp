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
		node *getHeader(){
			return header;
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
			while(temp!=NULL){
				cout << "Data["<< i << "]=" << temp->data << "\n";
				i++;
				temp=temp->next;
			}
			cout << endl;
		}
		void remove_first(){
			if(header != NULL){
				node *temp=header;
				header=header->next;
				delete(temp);
				size--;
			}
		}
		void remove_last(){
			if(header->next == NULL){
				remove_first();
			}
			else if(header != NULL){
				node *cur=header;
				node *prev;
				while(cur->next != NULL){
					prev=cur;
					cur=cur->next;
				}
				tail=prev;
				prev->next=NULL;
				delete cur;
				size--;
			}
		}
};
		bool campare_lists(linkedListe *head1,linkedListe *head2){
			node *temp1=head1->getHeader(),*temp2=head2->getHeader();
			while(temp1 && temp2){
				if(temp1->data != temp2->data){
					delete temp1;
					delete temp2;
					return false;
				}
				temp1=temp1->next;
				temp2=temp2->next;
			}
			delete temp1;
			delete temp2;
			return true;
		}
		
		linkedListe *ConcatTwoLinkeListe(linkedListe *head1,linkedListe *head2){
			if(head1->getSize()==0 && head2->getSize()==0){
				return head1;
			}
			else if(head1->getSize()>0 && head2->getSize()==0){
				return head1;
			}
			else if(head1->getSize()==0 && head2->getSize()>0){
				return head2;
			}
			else{
				node *temp1=head1->getHeader(),*temp2=head2->getHeader();
				linkedListe *NewLinkListe=new linkedListe();
	
				while(temp1){
					NewLinkListe->append(temp1->data);
					temp1=temp1->next;
				}
				while(temp2){
					NewLinkListe->append(temp2->data);
					temp2=temp2->next;
				}
				return  NewLinkListe;
			}
		}
int main(){
	linkedListe *l=new linkedListe();
	l->append(188);
	l->append(1);
	l->append(178);
	l->append(888);
	
	linkedListe *y=new linkedListe();
	y->append(188);
	y->append(1);
	
	l->remove_first();
	l->remove_last();
	
	l->toString();
	cout << campare_lists(l,l) <<endl;
	l->toString();
	y->toString();
	linkedListe *a=new linkedListe();

	
	linkedListe *o=ConcatTwoLinkeListe(l,l);
	o=ConcatTwoLinkeListe(o,o);
	o=ConcatTwoLinkeListe(o,o);
	o=ConcatTwoLinkeListe(o,o);
	o->toString();
	cout << o->getSize() <<endl;
	return 0;
}

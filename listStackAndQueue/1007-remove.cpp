#include <iostream>
using namespace std;

struct ListNode
{
  int data;
  ListNode *next;
};
class List
{
public:
  List()
  {
    head = new ListNode;
    head->next = NULL;
  }
 	void insert(int toadd, int pos);
 	int head_num() {
 		if (head->next)
 			return head->next->data;
 	}
 	void print() {
 		ListNode *p = head->next;
 		while (p) {
 			cout << p->data << " ";
 			p = p->next;
 		}
 		cout << endl;
 	}
 	void remove(int pos);
  ~List()
  {
    ListNode* curNode;
    while( head->next )
    {
      curNode = head->next;
      head->next = curNode->next;
      delete curNode;
    }       
    delete head;
  }
      ListNode *head; //head指向虚拟头结点，head-next指向第一个实际结点
};
 	void List::insert(int toadd, int pos) {
        int count = 0;
        ListNode* p = head->next;
        while (p) {
            count++;
            p = p->next;
        }
        if (pos <= 0 || pos > count + 1) return;
        if (pos == 1 && head->next == NULL) {
            head->next = new ListNode;
            head->next->data = toadd;
            head->next->next = NULL;
        } else if (pos == 1 && head->next != NULL) {
        	ListNode* t = head->next;
        	head->next = new ListNode;
        	head->next->data = toadd;
        	head->next->next = t;
      	  } else {
            ListNode* q = head->next;
            int n = 1;
            while (n != pos - 1) {
                q = q->next;
                n++;
            }
            ListNode* t = q->next;
            q->next = new ListNode;
            q->next->data = toadd;
            q->next->next = t;
       }
}
void List::remove(int pos) {
	int count = 0;
	ListNode* p = head->next;
	while (p) {
		count++;
		p = p->next;
	}
	if (pos > count) return;
	if (pos == 1 && head->next->next == NULL) {
		delete head->next;
		head->next = NULL;
	} else if (pos == 1 && head->next->next != NULL) {
		ListNode* t = head->next;
		head->next = t->next;
		delete t;
	} else {
		int n = 2;
		ListNode* q = head->next;
		while (n != pos) {
			q = q->next;
			n++;
		}
		ListNode* temp = q->next;
		q->next = temp->next;
		delete temp;
	}
}
int main() {
	List test = List();
	test.insert(2, 1);
	cout << test.head_num() << endl;
	test.insert(3, 1);
	test.insert(4, 2);
	test.print();
	test.remove(2);
	test.print();
	test.remove(1);
	test.print();
	test.insert(5, 2);
	test.print();
	return 0;
}
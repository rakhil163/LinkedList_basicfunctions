//
// Created by Akhil Raveendran on 11/2/18.
//

#include<iostream>
#include<cstdlib>
#include<stack>
#include <vector>
#include <set>
using namespace std;
class List{
public:
int x=0;
    typedef struct node {
        int data;
        node *next;
    } *nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;

public:
    List();
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList();
    void insertNode(int index,int d);
    int findLength(nodePtr h);
    nodePtr getNode(int i);
    bool search(nodePtr n,int key);
    //nodePtr getFromLast(int size,int index);
    nodePtr getFromLast(int index);
    void removeDuplicates();
  //  void reArrange(int p,int size);
  nodePtr reArrange(int part);
   nodePtr Sum(nodePtr n1,nodePtr n2);

};

List::List()
{
    head = NULL;
    curr =NULL;
    temp=NULL;
}
void List::AddNode(int addData)
{
    nodePtr n = new node;
    n->next=NULL;
    n->data = addData;

    if(head!=NULL)
    {
        curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=n;
    }
    else{
        head = n;
    }
    //cout<<curr->data;
}
void List::DeleteNode(int delData) {
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while((curr != NULL)&& (curr->data!=delData))
    {
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL)
    {
        cout<<"Not found"<<endl;
        delete delPtr;
    }
    else
    {
        delPtr = curr;
        curr= curr->next;
        temp->next =curr;
        delete delPtr;
        cout<<"Deleted!!!";
    }
}
void List::PrintList() {
    curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}
void List::insertNode(int index,int d)
{
    curr= head;
    temp = head;
    int count=1;
    nodePtr newPtr = new node;
    if(index == 0)
    {
        newPtr->data = d;
        head = newPtr;
        head->next = NULL;
        return;
    }

    while((curr!=NULL)&&(count<index))
    {
        temp = curr;
        curr=curr->next;
        count++;
    }
    if(count ==  index)
    {
        temp->next=newPtr;
        newPtr->data = d;
        newPtr->next = curr;
    }
    else if(curr==NULL)
    {
        cout<<"position out of bound";
    }
    //curr = curr->next;

}
//int List::findLength()
//{
//    curr = head;
//    int count=0;
//    while(curr!=NULL)
//    {
//        count++;
//        curr=curr->next;
//    }
//    //cout<<"count is"<<count;
//    return count;
//}
int List::findLength(nodePtr head)
{
    if(head == NULL)
        return 0;
    else
        return 1+findLength(head->next);
}
List::nodePtr List::getNode(int index)
{
    curr = head;
    int pos=1;
    while((curr!=NULL)&&(pos <  index))
    {
        curr=curr->next;
        pos=pos+1;
    }
    if(pos==index)
    {
        return curr;
    }
    else if(curr==NULL)
    {
        cout<<"index out of bounds";
    }
}
//bool List::search(int key)
//{
//    curr = head;
//    while(curr->next != NULL)
//    {
//        if(curr->data == key)
//        {
//            cout<<"found";
//            return true;
//        }
//        curr = curr->next;
//    }
//    return false;
//}
bool List::search(List::nodePtr n,int key)
{
    if(n==NULL)
    {
        return false;
    }
    else
    {
        if(n->data == key)
        {
            return true;
        } else
        {
            return search(n->next,key);
        }
    }
}
/*List::nodePtr List::getFromLast(int size,int index) {
    curr = head;
    int pos = 1;
    while ((curr != NULL) && (pos < (size+1) - index)) {
        curr = curr->next;
        pos = pos + 1;
    }
    if (pos == ((size+1) - index)) {
        return curr;
    } else if (curr == NULL) {
        cout << "index out of bounds";
    }
}*/

List::nodePtr List::getFromLast(int index)
{
    vector<nodePtr> s;
    curr = head;

    if(head->next == NULL)
        s.push_back(curr);
    while(curr->next != NULL)
    {
        //cout<<curr->data;
        s.push_back(curr);
        curr = curr->next;
    }
    s.push_back(curr);
    int count=1;
    while(count<index)
    {
      s.pop_back();
      count++;
    }

    x=s.size()-1;
    return s.at(x);
}
void List::removeDuplicates()
{
    curr = head;
    temp = head;
    set<int> s;

    while(curr!=NULL){
        if(s.find(curr->data)!=s.end())
        {
            if(curr->next!=NULL)
            {
                curr= curr->next;
                temp->next= curr;
            }
            else
            {
                curr=temp->next;
                temp->next = NULL;
            }

        }
        else
        {
            s.insert(curr->data);
            temp = curr;
            curr = curr->next;
        }
    }
}
List::nodePtr List::reArrange(int part) {
    nodePtr lesshead = NULL;
    nodePtr greathead = NULL;
    nodePtr lesstail = NULL;
    nodePtr greattail = NULL;
    curr = head;
    while (curr != NULL) {
        if (curr->data < part) {
            if (lesshead == NULL) {
                lesshead = curr;
                lesstail = lesshead;

            } else {
                lesstail->next = curr;
                lesstail = curr;
            }
        } else {

            if (greathead == NULL) {
                greathead = curr;
                greattail = greathead;
            } else {
                greattail->next = curr;
                greattail = curr;
            }


        }
        curr = curr->next;
    }

    if (lesstail != NULL) {
        lesstail->next = greathead;
        return lesstail;
    } else
        return greathead;
}














int main()
{
    List l;
    List l2;

//    l.AddNode(1);
//    l.AddNode(2);
    l.AddNode(3);
    l.AddNode(8);
    l.AddNode(4);
    l.AddNode(5);
    l2.AddNode(2);
    l2.AddNode(7);
    l2.AddNode(6);
    l2.AddNode(6);
//    l.PrintList();
//    l.DeleteNode(2);
//    l.PrintList();
    //l.insertNode(2,10);
    //l.insertNode(3,11);
    //cout<<"Last ONe"<<endl;
   //int size = l.findLength(l.getNode(1));//<<endl;
   //cout<<(l.getFromLast(1))->data;
  //  l.removeDuplicates();
  //  l.reArrange(4);
    //(l.getNode(2))->data;
    //cout<<l.search(l.getNode(1),4);
 //  l.PrintList();



}


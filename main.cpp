#include <iostream>

using namespace std;
struct listnode{
int data;
int indx;
listnode *next;
listnode *prev;
};


class List{
public:
    int length{};
    listnode *head=nullptr;
    listnode *tail{};
    int arrlength=0;
List(){
    head=tail=new listnode();
    head->data=0;
    head->indx=-1;
    head->next=nullptr;
}
List(int x){
    arrlength=x;
    head=tail=new listnode();
    head->data=0;
    head->indx=-1;
    head->next=nullptr;
}
void link(listnode *first,listnode *second){
if(first){
    first->next=second;
}
if(second){
    second->prev=first;
}
}



listnode *embed_after(listnode *prev,int id,int val){
listnode *middle=new listnode ();
middle->data=val;
middle->indx=id;
 listnode *after=prev->next;
link(prev,middle);

 if(!after){
     tail=middle;
 }
 else{
    link(middle,after);
 }
return middle;
}

listnode *make_list(int id,bool f){
    listnode *prev=head;
    while(prev->next&&prev->next->indx<id){
      prev=prev->next;
    }
    bool found=prev->next&&prev->next->indx==id;

    if(found)
    return prev->next;
    if(!f)
    return nullptr;
    return embed_after(prev,id,0);

    /*else{
        return prev;
    }*/



}

void set_value(int id,int val){
make_list(id,true)->data=val;
}

void print(){
    listnode*temp=head->next;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
}}




void get_value(int id){
    listnode *l=make_list(id,false);
    cout<<l->data;
}

};






struct linkedlist{
 List l;
linkedlist *next;
linkedlist *prev;
int c;
int r;
};







class matrix{
    linkedlist *HEAD{};
    linkedlist *TAIL{};
    int cols=0;
    int rows=0;
public:
    matrix(int c,int r){
    cols=c;
    rows=r;
    HEAD=TAIL=new linkedlist();
    HEAD->r=-2;
    }



void link(linkedlist *first,linkedlist *second){
if(first){
    first->next=second;
}
if(second){
    second->prev=first;
}
}



linkedlist *embed_after_list(linkedlist *prev,int row){
    linkedlist *middle=new linkedlist();
    middle->c=cols;
    middle->r=row;
    linkedlist *after=prev->next;
    link(prev,middle);

    if(!after){
        TAIL=middle;
    }
    else{
        link(middle,after);
    }
    return middle;
}



linkedlist *get_list(int row,bool flag){
    linkedlist *prev=HEAD;
    while(prev->next&&prev->next->r<row){
        prev=prev->next;
    }
    bool found_list=prev->next&&prev->next->r==row;
    if(found_list)
    return prev->next;
    if(!flag)
    return nullptr;
    return embed_after_list(prev,row);
}


void set_value_Matrix(int rows,int cols,int val){
    linkedlist *L=get_list(rows,true);
    L->l.set_value(cols,val);
}

void get_value_Matrix(int rows,int cols){
    linkedlist *L=get_list(rows,false);
    if(L){
        L->l.get_value(cols);
    }
}

void print_matrix_nonzero() {
		cout << "\nPrint Matrix: " << rows << " x " << cols << "\n";
		for (linkedlist* cur = HEAD->next; cur; cur = cur->next){
			cur->l.print();
			cout<<endl;
	}}

    };



int main(){
    matrix m1(5,5);
    m1.set_value_Matrix(2,1,3);
    m1.set_value_Matrix(2,2,20);
    m1.set_value_Matrix(3,2,10);
    m1.set_value_Matrix(3,3,15);
    m1.set_value_Matrix(3,6,20);
    m1.get_value_Matrix(3,6);
     m1.print_matrix_nonzero();
}

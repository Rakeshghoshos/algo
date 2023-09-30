#include<iostream>

using namespace std;

typedef struct queue{
    int cap;
    int f,r;
    int *arr;
}q;

q *root = NULL;

void create(int n){
    root = (q*)malloc(sizeof(q));
    root->f=root->r=-1;
    root->cap = n;
    root->arr = (int*)calloc(n,sizeof(int));
    cout<<"created queue"<<endl;
}
int isempty(q *p){
    if(p->r == -1){
        return 1;
    }
    return 0;
}
int isfull(q *p){
    if((p->r+1)%p->cap == p->f){
        return 1;
    }
    return 0;
}
int size(q *p){
    return((p->cap - p->f+p->r+1)%p->cap);
}
void enqueue(int x){
    if(isfull(root)){
        cout<<"queue is full"<<endl;
    }
    else{
        root->r = (root->r+1)%root->cap;
        root->arr[root->r] = x;
        if(root->f == -1){
            root->f++;
        }
    }
}
int dequeue(){
    if(isempty(root)){
        cout<<"queue is empty"<<endl;
        return -1;
    }
    else{
        int data;
        data = root->arr[root->f];
        if(root->f == 0 && root->r == 0){
            root->f=root->r=-1;
        }else{
            root->f = (root->f+1)%root->cap;
        }
        return data;
    }  
}
void transverse(q *p){
 if(size(p) == 0){
    cout<<"queue is empty"<<endl;
 }else{
    for(int i=0;i<size(p);i++){
    cout<<p->arr[i]<<" ";
 }  
 cout<<endl; 
 }
}
int main(){
    int i,n,x;
    cout<<"enter the number of elements"<<endl;
    cin>>n;
    create(n);
    
    while(1){
        cout<<"1 for insert"<<endl;
        cout<<"2 for delete"<<endl;
        cout<<"3 for view"<<endl;
        cout<<"4 for exit"<<endl;
        cin>>i;
        switch (i)
        {
        case 1:
            cout<<"enter the value"<<endl;
            cin>>x;
            enqueue(x);
            cout<<"inserted"<<endl;
            break;
        case 2:
            x = dequeue();
            cout<<"deleted"<<" "<<x<<endl;
            break;
        case 3:
            transverse(root);
            break;
        case 4:
                exit(0);
        default:
        cout<<"enter a valid input"<<endl;
            break;
        }
    }
    return 0;
}

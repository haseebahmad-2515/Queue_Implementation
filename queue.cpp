#include<iostream>
using namespace std;
class queue{

    private: 
    int *q;
    int maxsize;
    int currsize;
    int back ;
    int front;
    public:
    queue(int size){  // constructor
        maxsize=size;
        currsize=0;
        back=-1;
        front =0;
        q=new int[size];

    }

    queue(const queue&obj){ // copy constructor
        maxsize=obj.maxsize;            
        currsize=obj.currsize;
        front=obj.front;
        back=obj.back;

        q= new int[maxsize];
        for(int i=0;i<maxsize;i++){
            q[i]=obj.q[i];
        }

    }

    queue&operator=(const queue&obj ){  // assignment operator
        if(this ==&obj){    // self assignment check
            return *this;
        }

        delete []q;  // delete old one

         maxsize=obj.maxsize;
        currsize=obj.currsize;
        front=obj.front;
        back=obj.back;

        q= new int[maxsize];
        for(int i=0;i<maxsize;i++){
            q[i]=obj.q[i];
        }

    return *this;   // return *this 

    }

    ~queue(){  // destructor
        if(q!=nullptr){
            delete[]q;
            q=nullptr;
        }
    }
    bool isempty(){  // isempty func
        if(currsize==0){  // in empty   if front>back
            return true;
        }
        return false;
    }

    bool isfull(){      // is full func
        if(currsize==maxsize){ // in full back=size-1  full 
            return true;
        }
        return false;
    }


   bool enqueue(int val){   // insertion func enqueue
    if(isfull()){
        return false;
    }

    back = (back + 1) % maxsize; // circulation logic take mod with maxsize
    q[back] = val;
    currsize++;

    return true;
}

bool dequeue(int &val){   // removal  dequeue 
    if(isempty()){
        return false;
    }

    val = q[front];
    front = (front + 1) % maxsize;   // circulation logic take mod with maxsize
    currsize--; 

    return true;
}

void makeempty(){
    currsize=0;
        back=-1;
        front =0;

}

bool insertatfront(int val){
      if(isfull()){
        return false;
    }

    front = (front - 1+maxsize) % maxsize; // circulation logic take mod with maxsize
    q[front] = val;
    currsize++;

    return true;
}
    
bool removeatback(int&val){
      if(isempty()){
        return false;
    }

    val = q[back];
    back= (back - 1+maxsize) % maxsize;   // circulation logic take mod with maxsize
    currsize--; 

    return true;
}

void display(){   // display func
    if(isempty()){
      cout<<"empty "<<endl;
    }
    else{
        for(int i=0;i<currsize;i++){
            int index=(front+i)%maxsize; // to display in logical order
            cout<<q[index]<<" ";

        }
    }
}

};
int main(){
    int temp;

    queue q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.insertatfront(5);
    q1.insertatfront(1);
   q1.display();

   

  

   
   
   

}
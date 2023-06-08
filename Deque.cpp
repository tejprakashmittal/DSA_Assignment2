#include<iostream>
using namespace std;

template<class T>
class MyCircularDeque {
public:
    int *arr,front,rear,capacity,currentSize;
    MyCircularDeque(int k) {
        arr=new int[k];
        front=-10;rear=-10;
        currentSize=0;
        capacity=k;
    }

    MyCircularDeque(int n,T x){
        for(int i=0;i<n;i++){
            insertLast(x);
        }
    }
    
    bool insertFront(T value) {
        if(currentSize==capacity) return false;
        
        if(front == -10 && rear== -10){
            front=capacity/2;
            rear=front;
            arr[front]=value;
            currentSize++;
            return true;
        }
        
        front--;
        if(front==-1) front=capacity-1;
        arr[front]=value;
        currentSize++;
        return true;
    }
    
    bool insertLast(T value) {
        if(currentSize==capacity) return false;
        
        if(front == -10 && rear== -10){
            rear=capacity/2;
            front=rear;
            arr[rear]=value;
            currentSize++;
            return true;
        }
        
        rear=(rear+1)%capacity;
        arr[rear]=value;
        currentSize++;
        return true;
    }
    
    bool deleteFront() {
        if(currentSize==0) return false;
        
        if(front >=0 and rear >= 0 and front==rear){
            // if(currentSize==1){
            //     front=rear=-10;
            //     return true;
            // }
            // front=(front+1)%capactity;
            // rear--;
            // if(rear==-1) rear=capacity-1;
            // return;
            front=rear=-10;
            currentSize--;
            return true;
        }
        front=(front+1)%capacity;
        currentSize--;
        return true;
    }
    
    bool deleteLast() {
        if(currentSize==0) return false;
        
        if(front >=0 and rear >= 0 and front==rear){
            front=rear=-10;
            currentSize--;
            return true;
        }
        rear--;
        if(rear==-1) rear=capacity-1;
        currentSize--;
        return true;
    }
    
    T getFront() {
        if(currentSize==0) return -1;
        return arr[front];
    }
    
    T getRear() {
        if(currentSize==0) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(currentSize==0) return true;
        return false;
    }
    
    bool isFull() {
        if(currentSize==capacity) return true;
        return false;
    }

    int getSize(){
        return currentSize;
    }

    void resize(int n,T d){
        if(currentSize < n){
            while(currentSize < n)
            insertLast(d);
        }
        else if(currentSize > n){
            while(currentSize > n)
            deleteLast();
        }
    }

    T operator [](int n){
        return arr[front+n-1];
    }

    void clear(){
        front=-10;rear=-10;
        currentSize=0;
    }

};

int main(){
    MyCircularDeque<char>* obj = new MyCircularDeque<char>(100);
    obj->insertFront('D');
    obj->resize(5,'P');
    obj->resize(2,'\0');
    cout<<(*obj)[2]<<endl;
    cout<<obj->getSize();
    return 0;
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
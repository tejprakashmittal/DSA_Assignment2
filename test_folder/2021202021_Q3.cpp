#include<iostream>
#define SIZE 10000
using namespace std;

template<class T>
class MyCircularDeque {
public:
    int *arr,frnt,rear,capacity,currentSize;
    MyCircularDeque() {
        arr=new int[SIZE];
        frnt=-10;rear=-10;
        currentSize=0;
        capacity=SIZE;
    }

    void double_size(){
        int* newArr = new int[capacity*2];
        if(frnt <= rear)
        {
            for(int i=0;i<capacity;i++){
                newArr[i]=arr[i];
            }
        }
        else{
            for(int i=0;i<=rear;i++){
                newArr[i]=arr[i];
            }
            int temp=capacity*2-1;
            for(int i=capacity-1;i>=frnt;i--){
                newArr[temp--]=arr[i];
            }
        }
        capacity=capacity*2;
        delete[] arr;
        arr = newArr;
    }

    MyCircularDeque(int n,T x){
        for(int i=0;i<n;i++){
            push_back(x);
        }
    }
    
    bool push_front(T value) {
        if(currentSize==capacity) double_size();
        
        if(frnt == -10 && rear== -10){
            frnt=capacity/2;
            rear=frnt;
            arr[frnt]=value;
            currentSize++;
            return true;
        }
        
        frnt--;
        if(frnt==-1) frnt=capacity-1;
        arr[frnt]=value;
        currentSize++;
        return true;
    }
    
    bool push_back(T value) {
        if(currentSize==capacity) double_size();
        
        if(frnt == -10 && rear== -10){
            rear=capacity/2;
            frnt=rear;
            arr[rear]=value;
            currentSize++;
            return true;
        }
        
        rear=(rear+1)%capacity;
        arr[rear]=value;
        currentSize++;
        return true;
    }
    
    bool pop_front() {
        if(currentSize==0) return false;
        
        if(frnt >=0 and rear >= 0 and frnt==rear){
            // if(currentSize==1){
            //     front=rear=-10;
            //     return true;
            // }
            // front=(front+1)%capactity;
            // rear--;
            // if(rear==-1) rear=capacity-1;
            // return;
            frnt=rear=-10;
            currentSize--;
            return true;
        }
        frnt=(frnt+1)%capacity;
        currentSize--;
        return true;
    }
    
    bool pop_back() {
        if(currentSize==0) return false;
        
        if(frnt >=0 and rear >= 0 and frnt==rear){
            frnt=rear=-10;
            currentSize--;
            return true;
        }
        rear--;
        if(rear==-1) rear=capacity-1;
        currentSize--;
        return true;
    }
    
    T front() {
        if(currentSize==0) return -1;
        return arr[frnt];
    }
    
    T back() {
        if(currentSize==0) return -1;
        return arr[rear];
    }
    
    bool empty() {
        if(currentSize==0) return true;
        return false;
    }
    
    bool isFull() {
        if(currentSize==capacity) return true;
        return false;
    }

    int size(){
        return currentSize;
    }

    void resize(int n,T d){
        if(currentSize < n){
            while(currentSize < n)
            push_back(d);
        }
        else if(currentSize > n){
            while(currentSize > n)
            pop_back();
        }
    }

    T operator [](int n){
        return arr[frnt+n-1];
    }

    void clear(){
        frnt=-10;rear=-10;
        currentSize=0;
    }

};

int main(){
    MyCircularDeque<char>* obj = new MyCircularDeque<char>();
    obj->push_front('D');
    obj->push_back('F');
    obj->resize(10,'P');
    // obj->resize(2,'\0');
    // cout<<(*obj)[2]<<endl;
    cout<<obj->front()<<endl;
    cout<<obj->size()<<endl;
    cout<<obj->back()<<endl;
    obj->pop_front();
    cout<<obj->front()<<endl;
    cout<<obj->size()<<endl;
    cout<<(*obj)[9]<<endl;
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
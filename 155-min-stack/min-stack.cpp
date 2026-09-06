class MinStack {
public:
    int arr[30000];
    int mini[30000];
    int start=-1;
    int start2=-1;
    MinStack() {
        
    }
    
    void push(int value) {
        arr[++start] = value;
        if(start2==-1) mini[++start2] = value;
        else if(value<=mini[start2]) mini[++start2] = value; 
    }
    
    void pop() {
        if(arr[start]==mini[start2]){
            start2--;
        }
        start--;
    }
    
    int top() {
        return arr[start];
    }
    
    int getMin() {
        return mini[start2];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}
    
    // Thao tác Push: O(n)
    void push(int x) {
       int size = q.size();
       q.push(x);
       for(int i = 0; i < size; i++){
        int val_front = q.front();
        q.pop();
        q.push(val_front);
    }
        
        
            }
    
    // Thao tác Pop: O(1) - Vì phần tử mới nhất đã nằm ở đầu q1
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    // Thao tác lấy đỉnh: O(1)
    int top() {
        return q.front();
    }
    
    // Kiểm tra rỗng: O(1)
    bool empty() {
        return q.empty();
    }
};
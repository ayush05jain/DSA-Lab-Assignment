#include<iostream>
#include<vector>
#include<string>
using namespace std;
class PriorityQueue {
private:
    vector<int> heap;
    int parent(int i){ 
        return (i - 1) / 2; 
    }
    int left(int i){ 
        return 2 * i + 1; 
    }
    int right(int i){ 
        return 2 * i + 2; 
    }
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[parent(i)];
            heap[parent(i)] = temp;

            i = parent(i);
        }
    }
    void heapifyDown(int i) {
        int n = (int)heap.size();
        while (true) {
            int largest = i;
            int l = left(i);
            int r = right(i);

            if (l < n && heap[l] > heap[largest]) {
                largest = l;
            }
            if (r < n && heap[r] > heap[largest]) {
                largest = r;
            }

            if (largest != i) {
                int temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;
                i = largest;
            } else {
                break; 
            }
        }
    }

    public:
    void push(int x) {
        heap.push_back(x);         
        heapifyUp((int)heap.size() - 1);
    }
    void pop() {
        if (heap.empty()) {
            cout << "Priority queue is empty, cannot pop.\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }
    int top() {
        if (heap.empty()) {
            cout << "Priority queue is empty.\n";
            return -1;
        }
        return heap[0];
    }
    bool empty() {
        return heap.empty();
    }
    int size() {
        return (int)heap.size();
    }
    void printHeap() {
        cout << "Heap array: ";
        for (int i = 0; i < (int)heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
    PriorityQueue pq;
    int choice;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Size\n5. Print Heap\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int x;
            cout << "Enter value to insert: ";
            cin >> x;
            pq.push(x);
        } else if (choice == 2) {
            pq.pop();
        } else if (choice == 3) {
            if (!pq.empty()) {
                cout << "Top (max priority): " << pq.top() << "\n";
            } else {
                cout << "Priority queue is empty.\n";
            }
        } else if (choice == 4) {
            cout << "Size: " << pq.size() << "\n";
        } else if (choice == 5) {
            pq.printHeap();
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
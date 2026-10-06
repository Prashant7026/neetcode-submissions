class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    int getMaxHeapSize() {
        return maxHeap.size();
    }

    int getMinHeapSize() {
        return minHeap.size();
    }
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        int top = maxHeap.top();
        maxHeap.pop();
        minHeap.push(top);

        if(getMaxHeapSize() < getMinHeapSize()) {
            int top1 = minHeap.top();
            minHeap.pop();
            maxHeap.push(top1);
        }
    }
    
    double findMedian() {
        if((getMaxHeapSize() + getMinHeapSize()) % 2 == 0) {
            int maxTop = maxHeap.top();
            int minTop = minHeap.top();
            return double((maxTop + minTop)) / 2;
        } else {
            return maxHeap.top();
        }
    }
};

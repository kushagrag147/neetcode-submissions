class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (minHeap.size() == 0) {
            minHeap.push(num);
        } else {
            if (num > minHeap.top()) {
                minHeap.push(num);
                if (minHeap.size() - maxHeap.size() == 2) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            } else {
                maxHeap.push(num);
                if (maxHeap.size() - minHeap.size() == 2) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            } 
        }
    }
    
    double findMedian() {
        // cout<<"Heaps: "<<maxHeap.size()<<" "<<minHeap.size()<<"\n";
        
        if (maxHeap.size() == minHeap.size()) {
            // cout<<"Heaps top: "<<maxHeap.top()<<" "<<minHeap.top()<<"\n";
            return (double(maxHeap.top() + minHeap.top()))/2;
        } else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return minHeap.top();
        }
    }
};

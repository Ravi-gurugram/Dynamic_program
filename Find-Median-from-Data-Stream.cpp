class MedianFinder {
    std::priority_queue<int> lo; // max-heap (lower half)
    std::priority_queue<int, std::vector<int>, std::greater<int>> hi; // min-heap (upper half)

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: push to lo
        lo.push(num);

        // Step 2: balance order: max of lo should be <= min of hi
        if (!hi.empty() && lo.top() > hi.top()) {
            int x = lo.top(); lo.pop();
            hi.push(x);
        }

        // Step 3: balance sizes so that lo has either equal or one extra
        if (lo.size() > hi.size() + 1) {
            hi.push(lo.top());
            lo.pop();
        } else if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() const {
        if (lo.size() == hi.size()) {
            // when even count, average of two middle values
            return (lo.empty() ? 0.0
                               : (lo.top() + hi.top()) / 2.0);
        }
        // odd count, lo has one extra
        return static_cast<double>(lo.top());
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
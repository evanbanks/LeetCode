class SeatManager {
    priority_queue<int, vector<int>, greater<int>> q;
public:
    SeatManager(int n) {
        for (int i=1; i<=n; ++i) q.push(i);
    }
    
    int reserve() {
        int min_seat = q.top();
        q.pop();
        return min_seat;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

class MyCalendar {
private:
    vector<pair<int,int>> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) 
    {
        if(bookings.size() == 0)
            bookings.push_back({start,end});
        else
        {
            for(auto booking : bookings)
                if( (start >= booking.first && start < booking.second) || 
                    (end > booking.first && end <= booking.second) ||
                    (start<booking.first && end>booking.second) 
                   )
                    return false;
            bookings.push_back({start,end});
        }
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
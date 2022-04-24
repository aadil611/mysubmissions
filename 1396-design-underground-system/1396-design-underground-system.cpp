class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkins;
    unordered_map<string,pair<long,int>> res;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkins[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        long diff = t - checkins[id].second;
        string key = checkins[id].first + ":" + stationName;
        checkins.erase(id);
        
       
        if( res.find(key) != res.end()){
            auto &it = res[key];
            it.first += diff;
            it.second ++;
        }
        else
            res[key]={diff,1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        return (double)res[key].first / res[key].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
class UndergroundSystem {
public:
    map<int,pair<string,int>> customer;
    map<pair<string,string>,int> sum;
    map<pair<string,string>,int> total;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customer[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [a,b] = customer[id];
        sum[{a,stationName}] += (t-b);
        total[{a,stationName}]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)(sum[{startStation,endStation}]*1.0/total[{startStation,endStation}]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
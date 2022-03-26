class UndergroundSystem {
private:
    class CheckIn{
        public:
        int id;
        string station_name;
        int check_in_time;
        CheckIn(int id, string station_name, int check_in_time){
            this -> id = id;
            this -> station_name = station_name;
            this -> check_in_time = check_in_time;
        }
    };
    class RouteData{
        public:
        double total_time;
        int total_trips;
        RouteData(){
            this -> total_time = 0.0;
            this -> total_trips = 0;
        }
        void update_average(double trip_time){
            this -> total_time += trip_time;
            this -> total_trips++;
        }
        double get_average(){
            return (this -> total_time / this -> total_trips);
        }
    };
    string get_route_key(string start_station, string end_station){
        return (start_station + "->" + end_station);
    }
    unordered_map<string, RouteData*> route_data;
    unordered_map<int, CheckIn*> check_in_data;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check_in_data[id] = new CheckIn(id, stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        CheckIn* check_in = check_in_data[id];
        //every id that had ever used the program will have an entry in the check-in tables.
        //If, instead, we delete the old entries, then only ids that are currently undergoing a journey (have checked-in but not checked-out) will be in the table.
        check_in_data.erase(id);
        string route_key = get_route_key(check_in -> station_name, stationName);
        if(route_data.find(route_key) == route_data.end())
            route_data[route_key] = new RouteData();
        double trip_time = t - (check_in -> check_in_time);
        route_data[route_key] -> update_average(trip_time);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route_key = get_route_key(startStation, endStation);
        return route_data[route_key] -> get_average();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
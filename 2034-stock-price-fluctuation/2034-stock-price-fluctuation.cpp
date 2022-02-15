class StockPrice {
private:
    unordered_map<int, int> timestamp_price;
    multiset<int> prices;
    int latest_timestamp = 0;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(timestamp_price.find(timestamp) != timestamp_price.end())
            prices.erase(prices.find(timestamp_price[timestamp]));
        prices.insert(price);
        timestamp_price[timestamp] = price;
        if(timestamp > latest_timestamp)    latest_timestamp = timestamp;
    }
    
    int current() {
        return timestamp_price[latest_timestamp];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
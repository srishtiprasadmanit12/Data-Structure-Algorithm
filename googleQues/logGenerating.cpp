
class log{
    int timestamp;
    string message;

    // constructor
    Log(int t,string m){
        timestamp = t;
        message = m;
    }
};
/*
bool customComparison(int a, int b)
{
    // Custom comparison logic
    return a < b; // it sorts in ascending order
}
*/
class compare{
    publc:
        bool operator()(const Log &a,const Log &b){
            return a.timestamp > b.timestamp
        }
};

class LogStorage{
    private :
        priority_queue<Log,vector<Log>,compare>pq;
    public:
        void addLog(Log log){
            pq.push(log);
        }
    vector<string>getLastKMessages(int k){
        vector<string>result;

        //copy heap so original remains intact
        auto temp = pq;
        while(k-- && !temp.empty()){
            result.push_back(temp.top().message);
            temp.pop();
        }
        return result;
    }
};



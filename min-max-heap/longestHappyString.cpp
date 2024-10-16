class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>>pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});

        string res = "";

        while(!pq.empty()){

            //get the char with most count 
            auto [count1,char1] = pq.top();
            //pop this
            pq.pop();

            //Inside this if condition check for consecutive characters
            if(res.size()>=2 &&res.back()==char1 && res[res.size()-2]==char1){
                //if queue is empty
                if(pq.empty()) break;

                //get second most character
                auto [count2,char2] = pq.top();
                pq.pop();

                res+=char2;
                count2--;

                if(count2>0){
                    pq.push({count2,char2});
                }

                pq.push({count1,char1});

            }else{
                //res doesnt have three consecutive characters
                res+=char1;
                count1--;
                if(count1>0) pq.push({count1,char1});
            }

        }

        return res;
    }
};
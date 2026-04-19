### Log generating system 

- there is an API addLog() for adding logs 
- logs comes in arbitary order

- return messages of latest k logs sorted by timestamp in descending order (latest first)

follow up 
- optimise for : frequent addLogs
- optimse for : frequent last k messages 

constraints 
- up to 10^5 logs
- k can be small (like 10-100)


/*---------------------------------------------------------------------*/
Brute force :
I can store all logs in a vector & on each query sort by timestamp
- addLog--> O(1)
- getLastK-->O(NlogN)

this algo will be too slow

 I need quiick access top k elements repeatedly
 -->heap (priority queue)
 --.heap (max heap)

 important thought to access top K elements , i have to pop logs and will lose,data
 - hence I should not destroy original data
 
 there are 2 ways to fix this:
 1. copy heap --> extract k elements
 2. maintain another data structure (multiset)

 Will choose option 1st 

 Also c++ doesn't know how to sort/compare Log 
 - for that define a custom comparator

 Final data sturcture to use is:

 priority_queue<Log,vector<Log>,compare> 
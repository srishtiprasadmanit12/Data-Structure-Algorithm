class log{
    int timestamp;
    string message;
};

log getLog(); // api to generate the log

int main(){
    log log1 = getLog(); // log1 is a log object
}
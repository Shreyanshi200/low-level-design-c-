#include<string>
#include <iostream>
#include <mutex>
using namespace std;

// mutex Logger::mtx;
class Logger{
    static int ctr;
    static Logger* loggerInstance;
    Logger(){
            ctr++;
            cout<<"New Instance created Instances: "<<ctr<<endl;
    };
    //make copy constructor also private
    Logger(const Logger &);
    Logger operator=(const Logger &);
    public:
        static Logger* getLogger(){
            // double check locking
        // if(loggerInstance==nullptr){
        //     mtx.lock();
            if(loggerInstance==nullptr){
                loggerInstance=new Logger();
            }
            // mtx.unlock();
        // }
           
            return loggerInstance;
        };
        void Log(string msg){
            cout<<msg<<endl;
        };
};
int Logger::ctr=0;
Logger* Logger::loggerInstance = nullptr;
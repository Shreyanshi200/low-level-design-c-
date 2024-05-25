#include <bits/stdc++.h>
using namespace std;

//product

class Desktop{
    string monitor;
    string keyboard;
    string mouse;
    string speaker;
    string ram;
    string processor;
    string motherboard;

public:
    void setMonitor(string pMonitor){
        monitor = pMonitor;
    }
    void setKeyboard(string pKeyboard){
        keyboard = pKeyboard;
    }
    void setMouse(string pMouse){
        mouse= pMouse;
    }
    void setSpeaker(string pSpeaker){
        speaker = pSpeaker;
    }
    void setRam(string pRam){
        ram = pRam;
    }
    void setProcessor(string pProcessor){
        processor = pProcessor;
    }
    void setMotherboard(string pMotherboard){
        motherboard = pMotherboard;
    }
    void showSpecs(){
        cout<<"............................................."<<endl;
        cout<<"Monitor"<<monitor<<endl;
        cout<<"Keyboard"<<keyboard<<endl;
        cout<<"Mouse"<< mouse <<endl;
        cout<<"Speaker" <<speaker <<endl;
        cout<< "RAM" <<ram<<endl;
        cout<<"Processor"<<processor<<endl;
        cout<<"Mother Board"<<motherboard<<endl;
        cout<<"............................................."<<endl;
    };
};

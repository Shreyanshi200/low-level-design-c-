#include<iostream>
using namespace std;

class XMLData{
    string xmlData;
public:
    XMLData(string pXmlData){
        xmlData = pXmlData;
    }
    string getXMLData(){
        return xmlData;
    }
};

class DataAnalyticsTool{
    string jsonData;
public:
    DataAnalyticsTool(){};


    
    DataAnalyticsTool(string pJsonData){
        jsonData = pJsonData;
    }
    virtual void analyseData(){
        cout<<"Analysing data"<<jsonData<<endl;
    }
};

class Adaptor:public DataAnalyticsTool{
    XMLData* xmlData;
    public:
        Adaptor(XMLData* pXMLData){
            xmlData = pXMLData;
        }
        void analyseData()override{
            cout<<"Converting XML data "<<xmlData->getXMLData()<<" to json data "<<endl;
            DataAnalyticsTool::analyseData();
        }
};

class Client{
    public:
    void ProcessData(DataAnalyticsTool* tool){
        tool->analyseData();
    }
};

int main(){
    XMLData* xmlData = new XMLData("Sample XML data");
    DataAnalyticsTool* tool = new Adaptor(xmlData);
    Client* client = new Client;
    client->ProcessData(tool);
    return 0;
}
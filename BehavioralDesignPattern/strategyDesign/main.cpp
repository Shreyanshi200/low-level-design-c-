#include<bits/stdc++.h>
using namespace std;

//strategy interface
class SortingStrategy{
    public:
    virtual void sort(vector<int>&arr)=0;
};

//concrete strategy classes
class BubbleSort:public SortingStrategy{
    public:
    void sort(vector<int>&arr)override{
        cout<<"Implementing bubble sort"<<endl;
    }
};

class MergeSort:public SortingStrategy{
    public:
    void sort(vector<int>&arr)override{
        cout<<"Implementing Merge sort"<<endl;
    }
};

//Context
class SortContext{
    SortingStrategy* strategy;
    public:
    void setStrategy(SortingStrategy* strategy){
        this->strategy =strategy;
    }
    void executeStrategy(vector<int>&arr){
        strategy->sort(arr);
    }
};

int main(){
    vector<int> data = { 5, 2, 7, 1, 9 };
    SortContext* context  = new SortContext();
    MergeSort* ms = new MergeSort();
    BubbleSort* bs = new BubbleSort();
    context->setStrategy(ms);
    context->executeStrategy(data);
    context->setStrategy(bs);
    context->executeStrategy(data);
    return 0;
}
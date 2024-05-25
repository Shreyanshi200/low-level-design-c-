#include<iostream>
using namespace std;

class IButton{
    public:
    virtual void press()=0;
};

class Macbutton:public IButton{
    public:
    void press(){
        cout<<"Mac button pressed"<<endl;
    }
};

class Winbutton:public IButton{
    public:
    void press(){
        cout<<"Win button pressed"<<endl;
    }
};

class ITextBox{
    public:
    virtual void showText()=0;
};

class MacTextBox:public ITextBox{
    public:
    void showText(){
        cout<<"Mac TextBox showing"<<endl;
    }
};

class WinTextBox:public ITextBox{
    public:
    void showText(){
        cout<<"Win TextBox showing"<<endl;
    }
};

class IFactory{
    public:
    virtual IButton* CreateButton()=0;
    virtual ITextBox* CreateTextbox()=0;
};

class Macfactory:public IFactory{
    public:
    IButton* CreateButton(){
        return new Macbutton();
    }
    ITextBox* CreateTextbox(){
        return new MacTextBox();
    }
};
class Winfactory:public IFactory{
    public:
    IButton* CreateButton(){
        return new Winbutton();
    }
    ITextBox* CreateTextbox(){
        return new WinTextBox();
    }
};

class GUIAbstractFactory{
public:
static IFactory* CreateFactory(string osType){
    if(osType=="mac"){
        return new Macfactory();
    }else if(osType=="windows"){
        return new Winfactory();
    }
    else{
        return new Winfactory();
    }
}
};

int main(){
    cout<<"Enter your machine OS"<<endl;
    string ostype;
    cin>>ostype;
    IFactory* fact = GUIAbstractFactory::CreateFactory(ostype);

    IButton* button = fact->CreateButton();
    button->press();
    ITextBox* textbox = fact->CreateTextbox();
    textbox->showText();
    return 0;
}
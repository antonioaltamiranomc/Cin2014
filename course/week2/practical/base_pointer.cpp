#include <iostream>
#include <string>

using namespace std;

class Base {
    private:
	string name;

    protected:
	int a;

    public:
	Base(){name = "Base";}
	Base(string name){this->name = name;}
 	
        void hello(){cout<<"Hello from "<<name<<"\n";}
        // virtual hello(){cout<<"Hello from "<<name<<"\n";}
        // virtual void hello() = 0;
};

class Son : public Base {
    private:
	string name;

    protected:
	int b;

    public:
	Son(){name = "Son";}
	Son(string name){this->name = name;}
	void hello(){
            cout<<"Hello from "<<name<<"\n";
            //Base::hello();
            //cout<<"end Son---\n";
        }
};

class GrandSon : public Son{
    private:
	string name;
    
    protected:
	int c;
    
    public:
	GrandSon(){name = "GrandSon";}
	GrandSon(string name){this->name = name;}
	void hello(){cout<<"Hello from "<<name<<"\n";}
};

// Showing 
void show(Base*);

int main(){
    cout<<"Levels\n";
    Base myBase;
    Son  mySon;
    GrandSon myGrandSon;

    myBase.hello();
    mySon.hello();
    myGrandSon.hello();

    // Pointers
    cout<<"Base pointer [Son]\n";
    Base* ptr_base;
    Son*  ptr_son;

    ptr_base = &mySon;

    ptr_base->hello();
    cout<<"Base pointer [GrandSon]\n";
    ptr_base = &myGrandSon;
    ptr_base->hello();
    cout<<"Other pointer\n";
    ptr_son = &myGrandSon;
    ptr_son->hello();
    cout<<"---- Actions\n";
    //show(&myBase);
    //show(&mySon);
    //show(&myGrandSon);    

}

void show(Base* init){
     init->hello();

}


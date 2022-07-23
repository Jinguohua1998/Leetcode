#include <iostream>
#include <cstring>

using namespace std;

class MyStr{

    public:
        MyStr(const char* pData = nullptr);
        MyStr(const MyStr&);
        ~MyStr(void);

        MyStr& operator= (const MyStr&);
        //const不能忘加

        void Print();

    private:
        char* str;
};

MyStr::MyStr(const char* pData)
{
    if(pData == nullptr){
        //==不能写成=
        str = new char[1];
        str[0] = '\0';
    }else{
        str = new char[strlen(pData)+1];
        strcpy(str, pData);
    }
}

MyStr::MyStr(const MyStr& mystr){
    str = new char[strlen(mystr.str)+1];
    strcpy(str, mystr.str);
}

MyStr::~MyStr(void){
    delete[] str;
}

MyStr& MyStr::operator= (const MyStr& mystr){
    if(this == &mystr)
        return *this;
    delete[] str;
    str = new char[strlen(mystr.str)+1];
    strcpy(str, mystr.str);
    return *this;
}

void MyStr::Print(void){
    cout << str << endl;
}

int main()
{
    char* str = "33";
    
    MyStr mystr1("dddd");
    MyStr mystr2("aaaa");
    MyStr mystr3("bbbb");
    mystr1 = mystr2 = mystr3;
    mystr1.Print();
    mystr2.Print();
    mystr3.Print();
}


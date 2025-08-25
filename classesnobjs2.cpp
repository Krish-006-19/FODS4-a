#include<iostream>
#include<string>
using namespace std;

class Student{

private:
    double* balance;
    string password;
public:
    int* age;
    // unparameterized Constructor
    Student(){ cout<<"Hi, I am constructor!\n"; }
    // parameterized Constructor
    Student(string accId, string userName, int Age){
        cout<<"Hi, I am constructor!\n";
        this->accId = accId;
        this->userName = userName;
        age = new int;
        *age = Age;
    }
    // Custom Copy Constructor
    Student(Student &ref){
        // ref is a object
        /*
        let ref = {
        accId:"xyz101",
        userName:"Shivam Shinde",
        age:"10921XLo9"
        }
        *(ref.age) = val
        ref.age = address
        */
        cout<<"Copy constructor called!\n";
        this->accId = ref.accId;
        this->userName = ref.userName;
        // Shallow Copy
        // this->age = age;
        
        // Deep Copy
        age = new int;
        *age = *(ref.age);
    }
    string accId;
    string userName;

    void print(){
    cout<<accId<<endl<<userName<<endl<<*age<<endl;
    }
};

int main(){
    Student stu; // unparameterized
    Student stu1("123Hgkhu","Ram Prem Chopra",25); // parameterized
    Student stu2(stu1); // custom copy constructor

    /*  There are two types of copy
    1) shallow copy -> fails when -> Dynamic Memory Allocation
    2) Deep copy
    */

    // Problems with shallow copy
    // solution => deep copy
    stu1.print();
    *(stu2.age) = 35;
    stu1.print();
    stu2.userName = "Shalu Sharma";
    stu2.print();  
    cout<<"\n";
    return 0;
}
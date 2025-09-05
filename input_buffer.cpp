//task:
//question:
// how to let the user know that he entered wrong inputs?

//findings:
// clear input buffer before using getline.
// 

#include <iostream>
#include <limits>
using namespace std;

int main(){
    int weight;
    cout<<"enter your weight: ";
    cin>>weight;
    cout<<"weight : "<<weight<<endl;

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string full_name;
    cout<<"enter your full name: ";
    getline(cin,full_name);

    cout<<"full name: "<<full_name<<endl;
}
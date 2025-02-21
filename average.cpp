#include<iostream>

#include<cstdlib>
using namespace std;

int main(int argc, char* argv[]){
    double avg=0;
    double sum=0;
    for(int i=0;i<argc;i++){
        sum+=atof(argv[i]);
    }
    avg= sum/(argc-1);

    if(argc==1){
    cout<<"Please input numbers to find average.\n";
    }
    else{
    cout<<"---------------------------------\n";
    cout<<"Average of "<<argc-1<< " numbers = "<<avg<<endl;
    cout<<"---------------------------------\n";
    }
}

/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 
 * Purpose: 
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

//User Libraries Here


//Function Prototypes Here
void fillAry(char[],short[]);
void output(char[]);
void guessIn(char[],short[]);
void compare(char[],char[],short[],short[]);
bool Restart();
//Program Execution Begins Here

//Global values
short SIZE = 4;
int main() {
    //Declare and process variables
    bool restart;
    char master[SIZE],
            guess[SIZE];
    srand(static_cast<int>(time(0)));
    //Process/Calculations Here
    do {
    
        short tracker[10]={0},
              track2[10]={0};
        
    
        fillAry(master,tracker);
        guessIn(guess,track2);
        //output(master);
        compare(master,guess,tracker,track2);


        restart = Restart();
    } while (restart);

    //Output Located Here

    //Exit
    return 0;
}

void fillAry(char m[],short t[]){
    for(short i=0;i<SIZE;i++){
        m[i]=rand()%10+48;
        t[m[i]-48]++;
    }
    cout<<"The numbers are set!"<<endl;
    cout<<"TEST:: ";
    for(short i=0;i<SIZE;i++){
        cout<<m[i];
    }
    cout<<endl;
}
void output(char m[]){
    for(short i=0;i<SIZE;i++){
        cout<<m[i];
    }
    cout<<endl;
}
void guessIn(char g[],short t2[]){
    string guess;
    cout<<"Input your guess."<<endl;
    cin>>guess;
    for(short i=0;i<SIZE;i++){
        g[i]=guess.at(i);
        t2[g[i]-48]++;
        cout<<g[i]<<endl;
    }
}
void compare(char m[],char g[],short t[],short t2[]){
    short nc;
    for(short i=0;i<10;i++){
        if(t2[i]>=1&&t[i]>=1){
        cout<<"t2["<<i<<"]: "<<t2[i]<<"   ";
        cout<<"t["<<i<<"]: "<<t[i]<<endl;
            while(t2[i]>=1&&t[i]>=1){
                t2[i]--;t[i]--;nc++;
            }
        }
    }
    cout<<"Number correct: "<<nc<<endl;
    short num[SIZE],
          pos[SIZE],
            equal=0;
    for(short i=0;i<SIZE;i++){
              pos[i]=0,
              num[i]=0;
        if(g[i]==m[i]){
            pos[i]=1;num[i]=1;
            }
    }
        for(short i=0;i<SIZE;i++){              //equal numbers finder
            if(g[i]==g[SIZE-i]){
                equal++;
            }
        }
        
                }

bool Restart() {
    char ans;
    bool restart;
    cout << endl;
    cout << "Would you like to run this program again? y/n" << endl;
    cin>>ans;
    while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N') {
        cout << "Please enter y/n" << endl;
        cin>>ans;
    }
    if (ans == 'y' || ans == 'Y')
        restart = true;
    else
        restart = false;
    return restart;
}
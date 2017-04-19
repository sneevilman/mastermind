/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 
 * Purpose: 
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries Here


//Function Prototypes Here
void fillAry(char[],short[]);
void output(char[]);
void guessIn(char[],short[]);
bool compare(char[],char[],short[],short[]);
bool Restart();
//Program Execution Begins Here

//Global values
short SIZE = 4;
int main() {
    //Declare and process variables
    bool cont,
         restart;
    char master[SIZE],
            guess[SIZE];
    srand(static_cast<int>(time(0)));
    //Process/Calculations Here
    
    do {
        short tracker[10]={0},
              track2[10]={0},
              numG=10;
        
        fillAry(master,tracker);
        do{
        cont=true;              //initialize boolean for continuation
        guessIn(guess,track2);
        //output(master);           
        cont=compare(master,guess,tracker,track2);      
        numG--;
        cout<<"Guesses remaining: "<<numG<<endl;
        }while(cont&&numG>0);
        if(cont==false){
          cout<<"Congratulations! You are the mastermind!\n"
                "Number of guesses: "<<10-numG<<endl;
        }else{cout<<"You were outsmarted!\n"
                "Correct answer: ";
        for (short i=0;i<SIZE;i++){
            cout<<master[i];
        }
        cout<<endl;
        }
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
    //cout<<"TEST:: ";
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
    for(short i=0;i<10;i++){
        t2[i]=0;            //guess tracker re-initialization
    }
    cout<<"Input your guess."<<endl;
    for(short i=0;i<SIZE;i++){
        cin>>g[i];
        while(g[i]<48||g[i]>58){
            cout<<"Invalid Input. Try again."<<endl;
            cin>>g[i];
        }
        t2[g[i]-48]++;
//        cout<<g[i]<<endl;
    }
}
bool compare(char m[],char g[],short t[],short t2[]){
    bool cont=false;
    short nc,           //correctly guessed numbers
          pc;           //correctly guessed positions
    nc=pc=0;            //initialization

    for(short i=0;i<10;i++){
        if(t2[i]>=1&&t[i]>=1){
//        cout<<"t2["<<i<<"]: "<<t2[i]<<"   ";
//        cout<<"t["<<i<<"]: "<<t[i]<<endl;
        short c1=t[i],c2=t2[i];
            while(c1>=1&&c2>=1){
                c1--;c2--;nc++;
            }
        }
    }
    for(short i=0;i<SIZE;i++){
        if(g[i]==m[i]){
            pc++;
        }
    }
    if(pc==4&&nc==4){cont=false;}
    else {
          cont=true;
          cout<<"Numbers correct: "<<nc<<endl;
          cout<<"Positions correct: "<<pc<<endl;
    }
    return cont;
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
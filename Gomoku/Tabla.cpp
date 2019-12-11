#include "Tabla.h"
#include "global.h"
#include <iostream>
#include <windows.h>
using namespace std;

Tabla::Tabla()
{
    for(int i=0;i<13;i++){
            for(int j=0;j<13;j++)
                tabla[i][j]=0;
        }
        height=26;
        width=28;
        x=width/2;
        y=height/2;
        for(int i=0;i<width;i++) //top wall
            cout<<"#";
        cout<<endl;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                 if(i==y && j==x){
                    if(turn==true)
                        cout<<"1";
                    else
                        cout<<"2";
                 }
                 else if(j==0 || j==width-1)
                    cout<<"#";
                    else if((i+j)%2==0){
                        if(i%2==0)
                            cout<<"*";
                        else
                            cout<<"|";
                    }
                        else
                    cout<<" ";
                 }
            cout<<endl;
        }
        for(int i=0;i<width;i++) //bottom wall
            cout<<"#";
        cout<<endl;
}

void Tabla::draw(){
if(gameOver==true){
    system("cls");
    if(turn!=true)
        cout<<"Player1 won";
    else
        cout<<"Player2 won!";
    char c;
    cout<<endl<<"Type y to continue"<<endl;
    cin>>c;
}
else{
    if(move==true){
    system("cls"); //system("clear");
    for(int i=0;i<width;i++) //top wall
        cout<<"#";
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
              if(j>=2 && tabla[j/2-1][(i-1)/2]==1 && i%2==1 && j%2==0){
                    cout<<"X";
                 }
                 else if(j>=2 && tabla[j/2-1][(i-1)/2]==2 && i%2==1 && j%2==0){
                    cout<<"O";
                 }
                 else{
             if(i==y && j==x){
                if(turn==true)
                    cout<<"1";
                else
                    cout<<"2";
             }
             else if(j==0 || j==width-1)
                cout<<"#";
            else if((i+j)%2==0){
                if(i%2==0)
                    cout<<"*";
                else
                    cout<<"|";
            }
            else
                cout<<" ";
        }
        }
        cout<<endl;
    }
    for(int i=0;i<width;i++) //bottom wall
        cout<<"#";
    cout<<endl;
    move=false;
    }
}
}


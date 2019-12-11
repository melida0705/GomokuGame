#include "Game.h"
#include "global.h"
Game::Game():Table(),igrac()
{
    turn=true;
    gameOver=false;
    dir=STOP;
}
void Game::logic()
{
    switch(dir){
        case LEFT:
            Table.x-=2;
            dir=STOP;
            if(Table.x<=0)
                Table.x+=2;
            break;
        case RIGHT:
            Table.x+=2;
            dir=STOP;
            if(Table.x>=Table.width)
                Table.x-=2;
            break;
        case UP:
            Table.y-=2;
            dir=STOP;
            if(Table.y<=0)
                Table.y+=2;
            break;
        case DOWN:
            Table.y+=2;
            dir=STOP;
            if(Table.y>=Table.height)
                Table.y-=2;
            break;
        case UPIS:
            dir=STOP;
            if(Table.tabla[Table.x/2-1][(Table.y-1)/2]==0){
                if(turn==true)
                    Table.tabla[Table.x/2-1][(Table.y-1)/2]=1;
                else
                    Table.tabla[Table.x/2-1][(Table.y-1)/2]=2;
                int tr_x=Table.x/2-1;
                int tr_y=(Table.y-1)/2;
                int trazen;
                if(turn==true)
                    trazen=1;
                else
                    trazen=2;

                int count=0;
                for(int i=0;i<13;i++){
                    if(Table.tabla[i][tr_y]==trazen)
                        count++;
                    else
                        count=0;
                    if(count==5)
                    {
                        gameOver=true;  //vertikalno
                        break;
                    }
                }
                if(count!=5){
                for(int i=0;i<13;i++){
                    if(Table.tabla[tr_x][i]==trazen)
                        count++;
                    else
                        count=0;
                    if(count==5)
                    {
                        gameOver=true;  //vertikalno
                        break;
                    }
                }
                }
                if(count!=5){
                    for(int i=0;i<13;i++){
                        for(int j=0;j<13;j++){
                            if(i+j==tr_x+tr_y){
                                if(Table.tabla[i][j]==trazen)
                                    count++;
                                else
                                    count=0;
                            }
                            if(count==5){
                                gameOver=true;
                                break;
                            }
                        }

                    }
                }

                if(count!=5){
                    for(int i=0;i<13;i++){
                        for(int j=0;j<13;j++){
                            if(i-j==tr_x-tr_y){
                                if(Table.tabla[i][j]==trazen)
                                    count++;
                                else
                                    count=0;
                            }
                            if(count==5){
                                gameOver=true;
                                break;
                            }
                        }

                    }
                }
                turn=!turn;
            }
            break;
        default:dir=STOP;break;
    }
    bool state=true;
    for(int i=0;i<13;i++){
        for(int j=0;j<13;j++)
            if(Table.tabla[i][j]==0){
                state=false;
                break;
            }
        if(state==false)
            break;
    }
    if(state==true)
        gameOver=true;
}
void Game::run()
{

        while(!gameOver){
            igrac.input();
            logic();
            Table.draw();
        }

}



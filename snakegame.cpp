#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int row =50,col =70,sx,sy,fx,fy,score,gameover,flag,tc,tx[100],ty[100];
void setup()
{
    gameover=1;
    sx=row/2;
    sy=col/2;

l1:
    fx=rand()%row;
    if(fx<=1)
    {
        goto l1;
    }
l2:
    fy=rand()%col;
    if(fy<=1)
    {
        goto l2;
    }

    score =0;
    tc=0;

}

void bound()
{
    system("cls");
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            if(i==1||j==1||i==row||j==col)
            {
                cout<<"#";
            }
            else
            {
                if(i==sx&&j==sy)
                {
                    cout<<"0";
                }
                else if(fx==i&&fy==j)
                {
                    cout<<"@";
                }
                else
                {   int f=0;
                    for(int k =0;k<tc;k++)
                    {
                        if(i==tx[k]&&j==ty[k])
                        {
                            cout<<"o";
                            f=1;
                        }
                    }
                    if(!f)
                    {
                    cout<<" ";
                    f=0;
                    }
                }
            }
        }
        cout<<endl;
    }
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case '4' :
            flag =1 ;
            break;
        case '6' :
            flag =2 ;
            break;
        case '8' :
            flag =3 ;
            break;
        case '2' :
            flag =4 ;
            break;
        case 'x' :
            gameover=0 ;
            break;
        default :
            break;
        }
    }
}
void logic()
{
    int px=tx[0];
    int py=ty[0];
    int px1,py1;
    tx[0]=sx;
    ty[0]=sy;
    for(int i=1;i<tc;i++)
    {
        px1=tx[i];
        py1=ty[i];
        tx[i]=px;
        ty[i]=py;
        px=px1;
        py=py1;
    }

    switch(flag)
    {
    case 1 :
        sy-- ;
        break;
    case  2 :
        sy++;
        break;
    case 3 :
        sx-- ;
        break;
    case 4 :
        sx++;
        break;
    default :
        break;
    }
    if(row==sx||col==sy||1==sx||1==sy)
    {
        gameover=0;
    }
    for(int i =0;i<tc;i++)
    {
        if(sx==tx[i]&&sy==ty[i])
        {
            gameover=0;
        }
    }
    if(fx==sx&&fy==sy)
    {

l11:
        fx=rand()%row;
        if(fx<=1)
        {
            goto l11;
        }
l22:
        fy=rand()%col;
        if(fy<=1)
        {
            goto l22;
        }
        score+=5;
        tc++;
    }

}
int main()
{
    lll :
    setup();
    while(gameover)
    {
        bound();
        input();
        logic();
        int g=10000;
        while(g--);
        cout<<endl<<"Score = "<<score;

    }
    cout<<"\nPress 'R' for play again ...\nElse press any key..."<<endl;
   char fn=getch();
   if(fn=='R'||fn=='r')
   {
       goto lll;
   }
   cout<<"\n Powered by Team Fortune\n\nMember list: \n# Redoy\n# Yeasin\n# Noor\n# Sabbir\n# Shourov\n"<<endl;
   cout<<"\nHow to play?\n=> For Right press '6'.\n=> For Left press '4'.\n=> For Up press '8'.\n=> For Down press '2'.\n=> For Stop press 'x'.\n"<<endl;
}

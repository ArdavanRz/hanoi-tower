#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
int l,c,r,s22=25;
void gotoxy( short x, short y ){

    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}
void draw(int n1,int pix,int cordX,int cordY){

    int i,j;
    for(j=12;j<=20;j++){
        gotoxy(12,j);
        printf("%c",219);
        gotoxy(37,j);
        printf("%c",219);
        gotoxy(62,j);
        printf("%c",219);
    }
    gotoxy(cordX-n1,cordY);
    for(i=1;i<=(2*n1+1);i++){
        printf("%c",pix);
    }
}
void moveleft(int n1,char initial,char dest){
    int n,i,j;
     if(initial=='l')
        i=12;
    if(initial=='c')
        i=37;
    if(initial=='r')
        i=62;
    if(dest=='l')
        j=12;
    if(dest=='c')
        j=37;
    if(dest=='r')
        j=62;
    for(n=i;n>=j;n--){
        draw(n1,219,n,11);
        Sleep(s22);
        draw(n1,0,n,11);

    }
}
void moveright(int n1,char initial,char dest){
    int n,i,j;
     if(initial=='l')
        i=12;
    if(initial=='c')
        i=37;
    if(initial=='r')
        i=62;
    if(dest=='l')
        j=12;
    if(dest=='c')
        j=37;
    if(dest=='r')
        j=62;
    for(n=i;n<=j;n++){
        draw(n1,219,n,11);
        Sleep(s22);
        draw(n1,0,n,11);

    }
}
void moveup(int n1,char initial){
    int i,j,n;
    if(initial=='l')
    {
        n=l;
        j=12;}
    if(initial=='c'){
        n=c;
        j=37;}
    if(initial=='r'){
        n=r;
        j=62;}
    for(i=20-(n+1);i>=11;i--){
        draw(n1,219,j,i);
        Sleep(s22);
        draw(n1,0,j,i);
    }
}
void movedown(int n1,char dest){
    int i,j,n;
    if(dest=='l'){
        n=l;
        j=12;}
    if(dest=='c'){
         n=c;
        j=37;}
    if(dest=='r'){
        n=r;
        j=62;}
    for(i=11;i<=20-n;i++){
        draw(n1,219,j,i);
        Sleep(s22);
        draw(n1,0,j,i);
    }
    i=20-n;
    draw(n1,219,j,i);
}
void transfer(int n1,char initial, char dest){
    moveup(n1,initial);
    if(initial=='r'||(initial=='c'&&dest=='l')){
    moveleft(n1,initial,dest);}
    if(initial=='l'||(initial=='c'&&dest=='r')){
    moveright(n1,initial,dest);}
    movedown(n1,dest);

}
void hanoi(int n1,char initial,char dest){
    char tempo;
    if(initial=='l'&&dest=='r'){
        tempo='c';
//l--;
     //   r++;
    }
    if(initial=='l'&&dest=='c'){
        tempo='r';
     //   l--;
     //   c++;
    }
    if(initial=='c'&&dest=='l'){
        tempo='r';
     //   c--;
    //    l++;
    }
    if(initial=='c'&&dest=='r'){
        tempo='l';
     //   c--;
     //   r++;
    }
    if(initial=='r'&&dest=='c'){
        tempo='l';
    //    r--;
     //   c++;
    }
    if(initial=='r'&&dest=='l'){
        tempo='c';
     //   r--;
      //  l++;
    }
    if(n1==1){


          if(dest=='l'){
              l++;

            }
              if(dest=='c'){
              c++;



            }
              if(dest=='r'){
              r++;


            }
            if(initial=='l'){
              l--;


            }
              if(initial=='c'){
              c--;


            }
              if(initial=='r'){
              r--;


            }
    transfer(1,initial,dest);
    }
    if(n1!=1)
    {
     hanoi(n1-1,initial,tempo);


         if(dest=='l'){
              l++;


            }
              if(dest=='c'){
              c++;


            }
              if(dest=='r'){
              r++;


            }
            if(initial=='l'){
              l--;

            }
              if(initial=='c'){
              c--;


            }
              if(initial=='r'){
              r--;


            }
transfer(n1,initial,dest);
     hanoi(n1-1,tempo,dest);
    }

}


int main()
{
    system ("mode con: cols=156 lines=56");
int x,y=20,i,t;
printf("enter your desired number of disks\n");
scanf("%d",&x);
system("color e");
printf("okay let me think this through...\n");
Sleep(800);
if(x>9){
        system("color c");
  printf("\n...eeeeh...maybe a little bit less??\n");
  return 0;

}
if(x<1){
        system("color c");
  printf("\nwhat are you trying to pull??\n");
  return 0;

}
system ("color b");
printf("aha...\n");
Sleep(800);
if(x>4){
        system ("color 70");

  printf("\n that's a bit too much...so i'll speed things up\n");
  s22=1;



}
printf("i'll tell you when i'm done'\n");
l=x-1;
r=-1;
c=-1;
for(i=x;i>=1;i--){
    draw(i,219,12,y);
    y--;
}

hanoi(x,'l','r');

printf("\n\n\n\n\n\n\a");
t = pow(2,x)-1;
system ("color 02");
printf("there you go...\n\a");
printf("with your number of disks the total executed actions are %d\n",t);
printf("#licensed by make easy things hard UNI.#\n ");
system ("pause");




    return 0;
}

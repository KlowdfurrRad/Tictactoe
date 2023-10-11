#include <iostream>
using namespace std;
#define kaba { \
      if(a[3*i]=='X')x++; \
      if(a[3*i]=='O')x+=2; \
      break;}
/*char rotateclock(char a[],int times,int n){
  char a0,a1;
  for (int i=0;i<times;i++){
    char a0=a[0];
    char a1=a[1];
    a[0]=a[6];
    a[6]=a[8];
    a[8]=a[2];
    a[2]=a0;
    a[1]=a[3];
    a[3]=a[7];
    a[7]=a[5];
    a[5]=a1;
    }
  return a[n];
}*/


void draw(char a[]){
  for(int i=0;i<3;i++){
    cout<<a[3*i]<<"|"<<a[3*i+1]<<"|"<<a[3*i+2]<<"\n";   
if(i==2){cout<<"\n";break;}
    cout<<"-----\n";
  }
}      


//START of ROW ,COLUMN,DIAGONAL function : to check if one X is there , for double checker program
int r(char a[],int x){ //x is row number start from 0
  int totX=0;
  int space=0;
  for(int i=0;i<3;i++){
    if(a[3*x+i]=='X'){totX++;}else if(a[3*x+i]==' '){space++;}
  }
  if(space==2){
  return totX;
  }else{return 3-space;}
}

int c(char a[],int x){ //x is column number start from 0
  int totX=0;
  int space=0;
  for(int i=0;i<3;i++){
    if(a[x+3*i]=='X'){totX++;}else if(a[x+3*i]==' '){space++;}
  }
  if(space==2){
  return totX;
  }else{return 3-space;}
}

int d(char a[],int x){ //x=0 is falling diagonal , x=1 is upward diagonal
  int totX=0;
  int space=0;
  if(x==0){
    if(a[0]=='X'){totX++;}else if(a[0]==' '){space++;}
    if(a[4]=='X'){totX++;}else if(a[4]==' '){space++;}
    if(a[8]=='X'){totX++;}else if(a[8]==' '){space++;}
  }
  if(x==1){
    if(a[2]=='X'){totX++;}else if(a[2]==' '){space++;}
    if(a[4]=='X'){totX++;}else if(a[4]==' '){space++;}
    if(a[6]=='X'){totX++;}else if(a[6]==' '){space++;}
  }
  if(space==2){
  return totX;
  }else{return 3-space;} //only if return value is 1 the doublechecker care
}
//Ending of row column diagonal X number checker


int doublechecker(char a[]){ //redundancy if middle occupied by O
  int overcheck=0;
  for(int i=0;i<3;i++){ //columnth
    for(int j=0;j<3;j++){ //rowth
      if(r(a,j)==1 && c(a,i)==1 && a[i+3*j]!='X'){return i+3*j; overcheck=1;break;}
    }
    if(overcheck==1){break;}
  } //start row-diagonal check
  if(overcheck==0){
    if(d(a,0)==1 && r(a,0)==1 && a[0]!='X'){overcheck=1;return 0;}   
  }
  if(overcheck==0){
    if(d(a,0)==1 && r(a,1)==1 && a[4]!='X'){overcheck=1;return 4;}
  }
  if(overcheck==0){
    if(d(a,0)==1 && r(a,2)==1 && a[8]!='X'){overcheck=1;return 8;}
  }
  if(overcheck==0){
    if(d(a,1)==1 && r(a,0)==1 && a[2]!='X'){overcheck=1;return 2;}
  }
  if(overcheck==0){
    if(d(a,1)==1 && r(a,1)==1 && a[4]!='X'){overcheck=1;return 4;}
  }
  if(overcheck==0){
    if(d(a,1)==1 && r(a,2)==1 && a[6]!='X'){cout<<"PAPA"; overcheck=1;return 6;}
  }//start diagonal-column check
  if(overcheck==0){
    if(d(a,0)==1 && c(a,0)==1 && a[0]!='X'){overcheck=1;return 0;}   
  }
  if(overcheck==0){
    if(d(a,0)==1 && c(a,1)==1 && a[4]!='X'){overcheck=1;return 4;}
  }
  if(overcheck==0){
    if(d(a,0)==1 && c(a,2)==1 && a[8]!='X'){overcheck=1;return 8;}
  }
  if(overcheck==0){
    if(d(a,1)==1 && c(a,0)==1 && a[6]!='X'){overcheck=1;return 6;}
  }
  if(overcheck==0){
    if(d(a,1)==1 && c(a,1)==1 && a[4]!='X'){overcheck=1;return 4;}
  }
  if(overcheck==0){
    if(d(a,1)==1 && c(a,2)==1 && a[2]!='X'){cout<<"PAPA"; overcheck=1;return 2;}
  }
  if(overcheck==0){return 10;} //default for not placing X anywhere
}


int wincheck(char a[]){
  int x=0; //if 1 then X win , if 2 then O win
  for(int i=0;i<3;i++){
    if(a[3*i]==a[3*i+1] && a[3*i+1]==a[3*i+2] && a[3*i]!=' ') {
      if(a[3*i]=='X')x++;
      if(a[3*i]=='O'){x+=2;cout<<1;}
      break;}
    if(a[i]==a[i+3] && a[i+3]==a[i+6] && a[i]!=' ') {
      if(a[i]=='X')x++;
      if(a[i]=='O'){x+=2;cout<<2;}
      break;}
    }
  if(x==0){
      if(a[0]==a[4] && a[4]==a[8] && a[0]!=' ') {
        if(a[0]=='X')x++;
        if(a[0]=='O'){x+=2;cout<<3;}
        }else if(a[2]==a[4] && a[4]==a[6] && a[6]!=' ') {
        if(a[2]=='X')x++;
        if(a[2]=='O'){x+=2;cout<<4;}
        }
    }
    int count=0;
  if(x==0){
    for(int j=0;j<9;j++){
      if(a[j]!=' '){count++;}
    }
    if(count==9){x=3;}
  }
  return x;
  }


int checker1O(char a[]){
  int x=0;
  int PLACEFILL=10; //10 is default variable of PLACEFILL such that 
  for(int i=0;i<3;i++){  
    x=0;
    PLACEFILL=10;
    for(int j=0;j<3;j++){
      if(a[3*i+j]=='O'){x++;}
      else if(a[3*i+j]==' '){PLACEFILL=3*i+j;}
    }
    if(x==1 &&PLACEFILL!=10){cout<<""; break;} 
  }
  if(x==1){return PLACEFILL;}
  if(x!=1) { for(int k=0;k<3;k++){
            x=0;
            PLACEFILL=10;
              for(int l=0;l<3;l++){
                if(a[k+3*l]=='O'){x++;}
                else if(a[k+3*l]==' '){PLACEFILL=k+3*l;}
              }
            if(x==1 &&PLACEFILL!=10){break;}
          }
  if(x==1){return PLACEFILL;}
  }
  if(x!=1){
    if(a[0]=='O'&& a[4]==' ' && a[8]==' '){PLACEFILL=8;x=1;}
    else if(a[0]==' '&& a[4]=='O' && a[8]==' '){PLACEFILL=4;x=1;}
    else if (a[0]==' '&& a[4]==' ' && a[8]=='O'){PLACEFILL=0;x=1;}
    else if(a[2]=='O' && a[4]==' ' && a[6]==' '){PLACEFILL=6;x=1;}
    else if(a[2]==' ' && a[4]==' ' && a[6]=='O'){PLACEFILL=4;x=1;}
    else if(a[2]==' '&& a[4]==' ' && a[6]=='O'){PLACEFILL=2;x=1;} //VERY IMP: im filling specified space to make 2 in a diagonal . should make it random in future
    if(x==1){return PLACEFILL;}
  }
  if(x!=1){return 10;} //if 10 comes as output it should skip it 
}


int checker2OX(char a[],int OX){
  char check;
  if(OX==1){check='O';}else if(OX==2){check='X';} //if 1 is inputted it checks O ,else check for X.so i dont have to write two codes for checking 
  int x=0;
  int PLACEFILL=10; //10 is default variable of PLACEFILL such that 
  for(int i=0;i<3;i++){  
    x=0;
    PLACEFILL=10;
    for(int j=0;j<3;j++){
      if(a[3*i+j]==check){x++;}
      else if(a[3*i+j]==' '){PLACEFILL=3*i+j;}
    }
    if(x==2 &&PLACEFILL!=10){cout<<""; break;} 
  }
  if(x==2 &&PLACEFILL!=10){return PLACEFILL;}
  
  for(int k=0;k<3;k++){
            x=0;
            PLACEFILL=10;
              for(int l=0;l<3;l++){
                if(a[k+3*l]==check){x++;}
                else if(a[k+3*l]==' '){PLACEFILL=k+3*l;}
              }
            if(x==2 &&PLACEFILL!=10){break;}
          }
  if(x==2 &&PLACEFILL!=10){return PLACEFILL;}
  
    if(a[0]==check&& a[4]==check && a[8]==' '){PLACEFILL=8;x=2;}
    else if(a[0]==check&& a[4]==' ' && a[8]==check){PLACEFILL=4;x=2;}
    else if (a[0]==' '&& a[4]==check && a[8]==check){PLACEFILL=0;x=2;}
    else if(a[2]==check && a[4]==check && a[6]==' '){PLACEFILL=6;x=2;}
    else if(a[2]==check && a[4]==' ' && a[6]==check){PLACEFILL=4;x=2;}
    else if(a[2]==' '&& a[4]==check && a[6]==check){PLACEFILL=2;x=2;}
    if(x==2){return PLACEFILL;}
  
  if(x!=2){return 10;} //if 10 comes as output it should skip it 
}


int AI(char a[]){
  if(checker2OX(a,1)<9){return checker2OX(a,1);} //redundant to compute checker twice , please change in next version of game 
  else if(checker2OX(a,2)<9){return checker2OX(a,2);}
  else if(doublechecker(a)<9){return doublechecker(a);} //double as in checking if double lines may be possible for player
  else if(checker1O(a)<9){return checker1O(a);}
  else if(1){
    for(int i=0;i<9;i++){
      if(a[i]==' '){a[i]='O';return i; break;}
    }  
  }
}


int main(){
  char a[9];
  for(int j=0;j<9;j++) a[j]=' ';
  int y,x=0;
  while(x<9){
    if(x%2==0){
      cin>>y;
      while(a[y-1]!=' '){
        cout<<"BRo chicken boy, fill empty slot, shtawp cheating \n";                cin>>y;}//if y is not between 1-9 or place is full then intimate the player *****
      a[y-1]='X';
      draw(a); //not drawing as comp will play then draw its move along with player's move
    }
    else {
        if(x!=1 || a[4]=='X'){ //for 1st move if player keeps in middle , comp will use AI fxn to counter
          int O=AI(a);
          a[O]='O';  //please include the draw function within the outputer of 'O'     
          draw(a);
        }
        if(x==1 && a[4]!='X'){ //for 1st move if player doesnt keep in middle , computer will put in middle
          if(a[4]!='X'){a[4]='O';draw(a);}  
        }
    }
    x++;
    if(wincheck(a)==1){draw(a); cout<<"WINNer chicken dinner";break;}
    else if(wincheck(a)==2){cout<<"LOooser chicken dinner";break;}//draw fxn not req here are we draw in AI else
    else if(wincheck(a)==3){cout<<"Draw chicken chicken";}
  }
}
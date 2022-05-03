#include "melody.h"

int buz=8;

int tempo=72;

int t1=240000/tempo;
int t2=120000/tempo;
int t4=t1/4;
int t8=t1/8;
int t16=t1/16;

int t2d=t2+t4;
int t4d=t4+t8;
int t4_3=t2/3;
int t8d=t8+t16;

int n;

int mel[]={
R, R, //1 반주
C5, D5, E5, A4, C5, A4, D5, //2 Where the north wind meets the sea
D5, G5, A5, C5, G5, F5, E5, D5, E5, //3 There's a river full of memory
F5, E5, D5, A4, A4, B4, C5, //4 Sleep my darling, safe and sound
C5, C5, C5, B4, G4, G4, A4, A4, R, //5 For in this river, all is found
C5, D5, E5, A4, C5, A4, D5, //6 In her waters deep and true
D5, G5, A5, C5, G5, F5, E5, D5, E5, //7 Lie the answers and the path for you
F5, E5, D5, A4, A4, B4, C5, //8 Dive down deep in to her sound
C5, C5, C5, B4, G4, G4, A4, A4, //9 But not too far, or you'll be drowned
C4, D4, E4, R, //10 간주
G5, A5, B5, C6, B5, A5, G5, G5, F5, E5, //11 Yes, she will sing to those who here
F5, F5, E5, D5, A4, A4, C5, D5, C5, D5, E5, F5, //12 And in her song, all magic flows
G5, A5, B5, C6, B5, A5, G5, E5, D5, E5, R, //13 But can you brave what your fear?
F5, E5, D5, A4, A4, B4, C5, R, //14 Can you face what the river knows?
Ef5, Ff5, F5, Bf4, Df5, Bf4, Ef5, //15 Where's the north wind meets the sea
Ef5, Gf5, Bf5, Df5, Af5, Gf5, F5, Ef5, F5, //16 There's a mother full of memory
Gf5, F5, Ef5, Bf4, Bf4, C5, Df5, //17 Come my darling, homeward bound
Df5, Df5, Df5, C5, Af4, Af4, Bf4, Bf4, R, //18 When all is lost, then all is found
R, R, F3, Bf3, C4, Df4, F4 //19 반주
};

int dur[]={
t1, t2d, //1
t8d, t16, t8, t8+t2, t8, t8+t8, t8+t2, //2
t8d, t16, t8, t8+t2, t8d, t16, t16, t16, t8+t2, //3
t8d, t16, t8, t8, t8, t8+t8, t4d+t8d, //4
t16, t8, t8, t16, t8d, t8, t8+t8, t8+t2d, t2d, //5
t8d, t16, t8, t8+t2, t8, t8+t8, t8+t2, //6
t8d, t16, t4, t2, t8, t8+t8, t16, t16, t2, //7
t8d, t16, t8, t8, t8, t8+t8, t8+t4+t8d, //8
t16, t8, t8, t16, t8d, t8, t8+t8, t8+t2, //9
t8d, t16, t2, t4, //10
t4, t4d, t8, t8d, t16, t8, t8+t8, t8+t16, t16, t8+t8d, //11
t16, t8, t8, t2+t8, t8, t8, t8, t4+t16, t16, t16, t16, t4d, //12
t8, t4d, t8, t8d, t16, t8, t8+t8, t16, t16, t4, t4, //13
t8, t8, t2+t8d, t16, t8, t8+t8, t8+t2d, t2d, //14
t8d, t16, t4, t2, t8, t8+t8, t8+t2, //15
t8d, t16, t8, t8+t2, t8, t8+t8, t16, t16, t2, //16
t8d, t16, t8, t8, t8, t8+t8, t4d+t8d, //17
t16, t8, t8, t8d*3, t16, t8, t8+t8, t8+t2, t4, //18
t1, t1, t16, t16, t16, t16, t2d
};

void setup() {
  pinMode(buz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(n=0; n<sizeof(dur)/sizeof(int); n++) {
    if(mel[n]!=0) {
      tone(buz, mel[n], dur[n]);
      delay(dur[n]);
    }
    else {
      noTone(buz);
      delay(dur[n]);
    }
  }
  noTone(buz);
}

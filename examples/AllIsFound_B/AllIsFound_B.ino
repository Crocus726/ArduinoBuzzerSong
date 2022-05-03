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
int t16_6=t4/6;

int n;

int mel[]={
A2, E3, B3, C4, E3, A2, E3, C4, D4, E3, //1-2
A2, E3, B3, E3, C4, E3, E4, E3, D2, A2, Fs3, A2, A3, A2, D4, A2, //3-4
F2, C3, A3, C3, C4, F4, A4, C4, C2, G2, E3, G3, C4, G4, A4, G4, //5-6
F4, A2, F3, G3, F2, C3, F3, G3, A3, C4, F4, G4, A4, E4, B3, //7-8
A2, A3, G3, E4, E3, A3, G3, E4, A2, A3, G3, E4, E3, A3, G3, E4, //9
A2, A3, G3, E4, E3, A3, G3, E4, A2, //10
A2, E3, B3, E3, C4, E3, A3, E3, A2, E3, B3, E3, C4, E3, A3, E3, //11
D2, A2, E3, A2, Fs3, A2, D3, A2, D2, A2, E3, A2, F3, A2, A3, A2, //12
F2, C3, G3, C3, A3, C3, F3, C3, F2, C3, G3, C3, A3, C3, C4, C3, //13
C2, G2, C3, G2, D3, G2, E3, G2, C2, G2, E3, G2, F3, G2, G3, G2, //14
D2, A2, D3, E3, F3, A3, D3, E3, F2, C3, F3, G3, A3, C4, F4, G4, //15
A4, G4, D4, //16
A2, A3, G3, E4, E3, A3, G3, E4, A2, A3, G3, E4, E3, A3, G3, E4, //17
A2, A3, G3, E4, E3, A3, G3, E4, A2, //18
F2, C3, F3, G3, A3, G3, F3, C3, F2, C3, F3, C4, A3, G3, F3, C3, //19
C2, G2, C3, D3, E3, D3, C3, G2, C2, G2, C3, D3, G3, D3, C3, G2, //20
D2, A2, D3, E3, F3, E3, D3, A2, D2, A2, D3, E3, F3, E3, D3, A2, //21
Bf1, F2, Bf2, C3, D3, C3, Bf2, F2, Bf1, F2, Bf2, C3, F3, D3, C3, Bf2, //22 ???
F2, C3, F3, G3, C4, G3, F3, C3, F2, C3, F3, G3, C4, G3, F3, C3, //23
E2, B2, E3, F3, G3, B3, E4, G4, B4, A2, Gs2, G2, Fs2, F2, E2, //24
D4, A4, Gs4, A4, F4, A4, Gs4, A4, D4, A4, Gs4, A4, D4, B3, //25
C4, Af4, G4, Af4, C4, F4, E4, F4, C5, Af4, G4, Af4, C4, F4, E4, F4, //26
C6, Af5, G5, Af5, C5, F5, E5, F5, C6, Af5, G5, Af5, D5, F5, Bf5, Ef5, //27
F6, C6, Df6, Bf5, F6, Ef6, F6, F5, Df6, C6, Df6, F5, F6, Ef6, F6, F5, //28
Ef6, D6, Ef6, G5, Bf6, A6, Bf6, Bf5, Ef6, D6, Ef6, G5, Bf6, A6, Bf6, Bf5, //29
Gf6, F6, Gf6, Bf5, Ef7, Df7, Ef7, Ef6, Gf6, F6, Gf6, Bf5, Ef7, Df7, Ef7, Ef6, //30
F6, Ef6, F6, Af5, Af6, G6, Af6, Af5, F6, Ef6, F6, Af5, F5, Df5, Af4, F4, //31
Gf3, Gf2, Df3, Gf3, Af3, Bf3, Df4, Gf4, Af4, //32
Bf4, Af3, Af3, //33
R, //34
Bf2, F3, C4, Df4, F3, //35
Bf2, F3, Df4, Ef4, F3, //36
Bf1 //37
};

int dur[]={
t8, t8, t16, t16, t8+t2, t8, t8, t16, t16, t8+t2, //1-2
t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, //3-4
t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8, t8d, t16, //5-6
t8, t8, t8, t8, t16, t16, t16, t16, t16, t16, t16, t16, t4, t4, t2, //7-8
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //9
t16, t16, t16, t16, t16, t16, t16, t16, t2, //10
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //11
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //12
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //13
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //14
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //15
t4, t4, t2, //16
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //17
t16, t16, t16, t16, t16, t16, t16, t16, t2, //18
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //19
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //20
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //21
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //22
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //23
t16, t16, t16, t16, t16, t16, t16, t16, t4, t16_6, t16_6, t16_6, t16_6, t16_6, t16_6, //24
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //25
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //26
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //27
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //28
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //29
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //30
t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, t16, //31
t2, t16, t16, t16, t16, t16, t16, t16, t16, //32
t4, t4, t2, //33
t1, //34
t8, t8, t16, t16, t8+t2, //35
t8, t8, t16, t16, t8+t2, //36
t1 //37
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

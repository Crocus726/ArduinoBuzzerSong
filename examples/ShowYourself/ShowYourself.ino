#include "melody.h"

int buz=8;

int tempo=100;

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
Fs3, Gs3, Es3, Fs3, Gs3, B3, //1 반주
Fs4, Fs4, Fs4, Fs4, Fs4, Gs4, Gs4, Fs4, R, Fs4, Fs4, Gs4, Fs4, B4, As4, Gs4, Fs4, //2 Every inch of me is trembling, but not from the cold
Fs4, Fs4, Fs4, Gs4, Gs4, Fs4, R, Fs4, Fs4, Fs4, Gs4, Fs4, B4, As4, As4, Gs4, Fs4, //3 Something is familiar, like a dream I can reach but not quite hold
Fs4, Cs5, Cs5, As4, As4, R, Gs4, Gs4, Gs4, As4, B4, As4, As4, Fs4, Gs4, As4, Gs4, //4 I can sense you there. Like a friend I've always known
Fs4, Cs5, Cs5, Fs4, Fs4, R, Gs4, As4, B4, As4, Gs4, Fs4, Cs5, B4, As4, Gs4, //5 I'm arriving, and it feels like I am home
Cs5, Fs5, Es5, Cs5, Cs5, Ds5, Es5, Gs4, R, Es5, Es5, Fs5, Ds5, Cs5, Ds5, //6 I have always been a fortress, cold secrets deep inside
A4, Cs5, Ds5, E5, E5, R, A4, E5, Fs5, Fs5, Gs5, Gs5, //7 You have secrest too, but you don't have to hide
Gs5, Fs5, Fs5, R, Fs5, Fs5, Ds5, Cs5, Cs5, Es5, //8 Show yourself, I'm dying to meet you
Gs5, Fs5, Fs5, R, Fs5, Ds5, Cs5, E4, R, //9 Show yourself, it's you're turn
As4, Gs4, As4, Cs5, As4, Cs5, Ds5, Cs5, As4, Fs4, Gs4, As4, Cs5, Fs5, Es5, Gs5, //10 Are you the one I've been looking for all of my life?
B5, As5, As5, Gs5, Fs5, R, Fs5, Es5, Es5, Fs5, E5, //11 Show yourself, I'm ready to learn
R, Fs5, F5, G5, Ds5, R, G5, A5, G5, Fs5, C5, R, //12 Ah-ah, ah-ah (Ah-ah ah-ah-ah)
G4, G4, G4, G4, A4, D5, B4, D5, D5, D5, C5, B4, D5, B4, E5, //13 I've never felt so certain, all my life I've been torn
D5, D5, D5, D5, E5, E5, D5, D5, D5, D5, D5, D5, C5, B4, D5, G5, G5, //14 But I'm here for a reason, could it be the reason I was born?
G5, G5, A5, Fs5, D5, E5, Fs5, A4, Fs5, Fs5, Fs5, G5, E5, D5, E5, R, //15 I have always been so different, normal rules did not apply
G4, C5, D5, D5, R, E5, E5, F5, F5, R, D5, F5, G5, G5, A5, A5, //16 Is this the day? Are you the way? I finally find out why
C6, B5, B5, G5, G5, E5, D5, D5, A5, E5, Fs5, G5, G5, D6, R, G5, A5, B5, A5, //17 Show yourself, I'm no longer trembling Here I am I've come so far
E5, D5, E5, G5, E5, G5, A5, G5, E5, G5, A5, B5, D6, C6, B5, A5, //18 You are the answer I waited for all of my life
C6, C6, B5, B5, A5, G5, G5, G5, G5, A5, G5, B5, //19 Oh, show yourself, let me see who you are
A5, G5, Fs5, D5, A5, G5, Fs5, D5, A5, G5, Fs5, E5, E5, Fs5, G5, G5, B5, G5, //20 Come to me now, open your door, don't make me wait, one moment more, oh
A5, G5, Fs5, G5, Fs5, A5, G5, Fs5, G5, Fs5, E5, D5, A5, G5, Fs5, E5, E5, Fs5, G5, G5, A5, B5, R, //21 Come to me now, open your door, don't make me wait, one moment more
Fs5, Gs5, As5, Ds5, Fs5, Ds5, Gs5, Ds6, D6, Ds6, B5, //22 Where the north wind meets the sea (Ah-ah ah-ah)
Gs5, Cs6, Ds6, Fs5, Fs6, F6, Fs6, Ds6, Cs6, B5, As5, Gs5, As5, F5, Fs5, Cs5, B4, Cs5, //23 There's a river (Ah-ah ah-ah) Full of memory (Full of memory)
B5, As5, Gs5, Ds5, Ds5, F5, Fs5, As5, B5, Cs6, R, //24 Sleep my darling, safe and sound (I am found)
Cs6, C6, C6, R, Gs5, Gs5, F5, Ds5, Ds5, As5, Cs6, C6, C6, R, C6, C6, Cs6, C6, C6, As5, //25 Show yourself, step into your power Grow yourself into something new
C6, As5, Gs5, Gs5, As5, C6, C6, As5, Gs5, Gs5, As5, C6, C6, Cs6, C6, As5, //26 You are the one you've been waiting for (All of my life)
Cs6, Cs6, C6, C6, As6, Gs6, //27 Oh, show yourself
Gs5, G5, Gs5, G5, F4, G4, F4, Gs4, As5, Gs5, As5, G5, Gs4, As4, Gs4, C5, //28 Ah-ah ah-ah (Ah-ah ah-ah) Ah-ah ah-ah (Ah-ah ah-ah)
Ds6, D6, Ds6, C6, R //29 Ah-ah ah-ah
};

int dur[]={
t2d, t4, t1, t2d, t4, t2d, //1
t8, t8, t8, t8, t8, t8, t8, t4d, t4, t8, t4_3, t4_3, t4_3, t2d+t8, t16, t16, t1, //2
t8, t8, t8, t8, t8, t8+t4, t4, t8, t8, t4_3, t4_3, t4_3, t4, t8, t4, t4, t8+t2d, //3
t8, t8, t8, t8, t2d, t4+t8, t16, t16, t4_3, t4_3, t4_3, t4, t2+t16, t16, t16, t16, t2d, //4
t8, t8, t4, t8, t2+t8+t4, t8, t16, t16, t8, t8, t8, t8+t4, t4+t4d, t16, t16, t2d, //5
t8, t8, t4, t8, t8+t4, t8, t8+t8, t4, t4d, t4, t8, t4, t4, t4, t8+t1, //6
t8, t4, t4, t4, t8+t2d, t8, t8, t8, t4, t4, t4d, t1, //7
t8, t8, t2d, t4, t8, t8+t8, t8, t8, t8+t8, t4d+t2, //8
t8, t8, t2d, t4d, t8+t8, t8, t4, t2, t2, //9
t8, t8, t8, t8+t8, t8, t8, t8+t8, t8, t4, t4_3, t4_3, t4_3+t4, t2, t4, t2, t2, //10
t8, t8, t2, t8, t8+t4, t8, t8, t4_3, t4_3, t4_3, t1, //11
t4, t8, t8+t4, t8, t8+t1, t4, t4, t4d, t16, t16, t2d, t8, //12
t8, t16, t16, t4, t8, t8, t4d+t4, t8, t8, t4_3, t4_3, t4_3, t2d, t8, t8+t2d+t8, //13
t8, t8, t8, t8, t16, t16+t8, t4d+t4d, t8, t4_3, t4_3, t4_3, t4, t8, t4, t4, t8, t2d, //14
t8, t8, t4, t8, t8+t4, t8, t8+t8, t4d+t4, t8, t8, t4, t8, t8+t8, t4, t8+t2d, t8, //15
t8, t4, t8, t8+t4, t8, t8, t4, t8, t8+t4, t8, t8, t4, t8, t8+t8, t4, t8+t1, //16
t8, t8, t2d+t4, t8, t8+t8, t8, t8, t8+t8, t8+t2d, t4d, t4d, t4+t8, t8, t8, t8, t4, t4+t8, t8, t2d, //17
t8, t8, t8, t8+t8, t8, t8, t8+t8, t8, t4, t4_3, t4_3, t4_3+t4, t4+t4d, t16, t16, t2, //18
t2, t8, t8, t2, t8, t8+t4, t8, t8, t4_3, t4_3, t4_3+t4, t2d+t1, //19
t4d, t4d, t4, t1, t4d, t4d, t4, t1, t4d, t4d, t4, t1, t4d, t4d, t4, t2d, t8, t8, //20
t4d, t4d, t4, t8, t8+t2d, t4d, t4d, t4, t8, t8+t8, t16, t16+t2, t4d, t4d, t4, t1, t4d, t4d, t4, t4d, t4d, t4+t1+t1, t1+t2, //21
t4, t4, t4, (t4d+t4)*2, t8d*2, t8, t2-t8, t8, t8d*2, t8, t2, //22
t4d, t8, t4, t8, t8, t4d, t8, t2, t4d, t8, t8, t8, t4, t4d, t8, t8, t8, t4, //23
t4d, t8, t4, t4, t4, t4+t8, t4d+t4, t8, t8+t8, t4d+t2, t2, //24
t4, t4, t2, t4, t8, t8+t8, t8, t8, t8+t8, t8+t2d, t4, t4, t2, t4, t8, t8, t4, t4, t8, t8+t2d, //25
t8, t8, t8, t8+t8, t8, t8, t8+t8, t8, t4, t4_3, t4_3, t4_3+t4, t4+t4d, t16, t16, t2, //26
t2, t4, t8, t8+t4, t8, t8+t1+t4, //27
t8, t8+t4, t8, t8+t4, t8, t8+t4, t8, t8+4, t8, t8+t4, t8, t8+t4, t8, t8+4, t8, t8+t2d, //28
t4, t2, t2, t1+t1, t1+t1 //29
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

#include<iostream>
#include <stdio.h>
using namespace std;

class Mixto{
public:
 float r[10];

void iniciar(int n){
  int j;
  for(int i=0;i<n;i++){
  cout<<"dame el valor de R"<<i+1<<endl;
  cin>>j;
  r[i]=j;
  }
}

void serie(int n){
  float aux=0;
  int k;
  char b;
  float equivalencia=0;
  char a;
  do{
    do{
     cout<<"dime cuales r estan en serie"<<endl;
     cin>>k;
     for(int i=0;i<n;i++){
      if(r[i]==k){
       aux=(1/r[i]);
       r[i]=0;
       r[i]=aux;
       cout<<"Valor de r["<<i<<"]: "<<r[i]<<endl;
       }
     }
     cout<<"Vas a meter mas resistencias s/n"<<endl;
     cin>>b;
    }while(b!='n');
    cout<<"Vas seguir metiendo mas resistencias en serie s/n"<<endl;
    cin>>a;
  }while(a!='n');
  for(int i=0;i<n;i++){
    equivalencia+=1/r[i];
  }
  cout<<"el valor de la equivalencia es:"<<equivalencia<<endl;
  }
};

int main(){
   Mixto a;
int n;
cout<<"cuantas r vas a meter"<<endl;
cin>>n;
a.iniciar(n);
a.serie(n);
}

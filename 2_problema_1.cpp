////////////////////////
//Librerias
/////////////////////////
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string.h>
using namespace std;
/////////////////////////
//Definiciones
/////////////////////////
#define tam_max 10
/////////////////////////
//Clases
/////////////////////////
class Circuito{
public:
    float equivalencia;
    string s[tam_max]{"resistencia","inductancias"};
    string u[tam_max]{"ohm", "mH", "uf"};
    float resultado(){
      return equivalencia;
    }
};
class Serie:public Circuito{
public:
  float suma_res_ind(float r1,float r2, float r3,float r4, float r5){
    return (r1+r2+r3+r4+r5);
  }
  float suma_cap(float r1,float r2, float r3,float r4, float r5){
    return (1/(r1+r2+r3+r4+r5));
  }
  void todo_serie(){
    for(int i=0;i<2;i++){
      cout<<"Circuito de "<<s[i]<<" en serie"<<endl;
      equivalencia=suma_res_ind(1,1,1,1,1);
      cout<<"El valor de la equivalencia en serie de "<<s[i]<<" es: "<<resultado()<<u[i]<<endl<<endl;
    }
    cout<<"Circuito de Capacitores en serie"<<endl;
    equivalencia=suma_cap(1,1,1,1,1);
    cout<<"El valor de la equivalencia en serie de capacitores es: "<<resultado()<<u[2]<<endl<<endl;
  }
};
class Paralelo:public Circuito{
  public:
  float suma_res_ind(float r1,float r2, float r3,float r4, float r5){
    return (1/(r1+r2+r3+r4+r5));
  }
  float suma_cap(float r1,float r2, float r3,float r4, float r5){
    return (r1+r2+r3+r4+r5);
  }
  void todo_paralelo(){
    for(int i=0;i<2;i++){
      cout<<"Circuito de "<<s[i]<<" en paralelo"<<endl;
      equivalencia=suma_res_ind(1,1,1,1,1);
      cout<<"El valor de la equivalencia en paralelo de "<<s[i]<<" es: "<<resultado()<<u[i]<<endl<<endl;
    }
    cout<<"Circuito de Capacitores en paralelo"<<endl;
    equivalencia=suma_cap(1,1,1,1,1);
    cout<<"El valor de la equivalencia en paralelo de capacitores es: "<<resultado()<<u[2]<<endl<<endl;
  }
};
class Mixto:public Circuito{
  public:
  float r[tam_max];

void iniciar(int n){
    for(int i=0;i<n;i++)
      r[i]=1;
}
void imprime(int n){
  char c[tam_max]={'R','L','C'};
  for(int j=0;j<3;j++){
    for(int i=0;  i<n ; i++){
      cout<<c[j]<<i+1<<"="<<r[i]<<u[j]<<" ";
    }
    cout<<endl<<endl;
  }
}

void mix_res_ind(int l){
  float aux_ser=0;
  float aux_para=0;
  int i,n;
  char a;
    do{
    cout<<"Dime que vas a hacer paralelo o serie, s/p"<<endl;
    cin>>a;
    if(a=='p'){
      cout<<"Dime cuantas "<<s[l]<<" estan en paralelo"<<endl;
      cin>>n;
      for(int j=0;j<n;j++){
        cout<<"Dime que "<<s[l]<<endl;
        cin>>i;
        aux_para+=1/r[i-1];
      }
      aux_para=1/aux_para;
      cout<<"Valor de paralelo: "<<aux_para<<u[l]<<endl;
    }
    else{
      cout<<"Dime cuantas "<<s[l]<<" estan en serie"<<endl;
      cin>>n;
      for(int j=0;j<n;j++){
        cout<<"Dime que "<<s[l]<<endl;
        cin>>i;
        aux_ser+=r[i-1];
      }
      cout<<"Valor de serie: "<<aux_ser<<u[l]<<endl;
    }
    cout<<"Vas a hacer algo mas s/n"<<endl;
    cin>>a;
    }while(a!='n');
    equivalencia=aux_ser+aux_para;
    cout<<"El valor de la equivalencia en mixto es: "<<resultado()<<u[l]<<endl<<endl;
  }
  void mix_cap(){
    float aux_ser=0;
    float aux_para=0;
    int i,n;
    char a;
      do{
      cout<<"Dime que vas a hacer paralelo o serie, s/p"<<endl;
      cin>>a;
      if(a=='p'){
        cout<<"Dime cuantas capacitores estan en paralelo"<<endl;
        cin>>n;
        for(int j=0;j<n;j++){
          cout<<"Dime que capacitor"<<endl;
          cin>>i;
          aux_para+=r[i-1];
        }
        cout<<"Valor de paralelo: "<<aux_para<<u[2]<<endl;
      }
      else{
        cout<<"Dime cuantas capacitores estan en serie"<<endl;
        cin>>n;
        for(int j=0;j<n;j++){
          cout<<"Dime que capacitor"<<endl;
          cin>>i;
          aux_ser+=1/r[i-1];
        }
        aux_ser=1/aux_ser;
        cout<<"Valor de serie: "<<aux_ser<<u[2]<<endl;
      }
      cout<<"Vas a hacer algo mas s/n"<<endl;
      cin>>a;
      }while(a!='n');
      equivalencia=aux_ser+aux_para;
      cout<<"El valor de la equivalencia en mixto es: "<<resultado()<<u[2]<<endl<<endl;
    }
  void todo_mix(){
    for(int i=0;i<2;i++){
      cout<<"Circuito de "<<s[i]<<" mixto"<<endl;
      mix_res_ind(i);
    }
    cout<<"Circuito de Capacitores mixto"<<endl;
    mix_cap();
  }
};
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  Circuito a;
  Serie b;
  Paralelo c;
  Mixto d;
  int n;
  cout<<"Dime cuantos valores de las Resistencias, Inductancias y Capacitores"<<endl;
  cin>>n;
  d.iniciar(n);
  d.imprime(n);
  b.todo_serie();
  c.todo_paralelo();
  d.todo_mix();
}

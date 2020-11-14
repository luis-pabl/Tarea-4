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
    float resultado(){
      return equivalencia;
    }
};
class Serie:public Circuito{
public:
  float suma_resis(float r1,float r2, float r3,float r4, float r5){
    return 1/(r1+r2+r3+r4+r5);
  }
};
class Paralelo:public Circuito{
  public:
  float suma_resis(float r1,float r2, float r3,float r4, float r5){
    return 1/(1/(r1+r2+r3+r4+r5));
  }
};
class Mixto:public Circuito{
  public:
  float r[tam_max];
  void iniciar_resist(int n){
    cout<<"Dame los valores de las Resistencias"<<endl;
    for(int i=0;i<n;i++){
      cout<<"Dame la Resistencia "<<i+1<<": "<<endl;
      cin>>r[i];
    }
  }
  void imprime_matriz(int n){
    for(int i=0;  i<n ; i++){
      printf("%.1f ",r[i]);
    }
    cout<<endl;
  }

  void pri_serie(int n){
    char a;
    float aux=0;
    int i;
    do{
      cout<<"Dime cuales son las resistencia en Serie de la rama:"<<endl;
      char b='s';
      aux=0;
      for(;b!='n';){
        cout<<"Dime la resistencia"<<endl;
        cin>>i;
        aux+=r[i-1];
        cout<<"valor de r["<<i-1<<"]: "<<r[i-1]<<endl;
        cout<<"Valor de aux: "<<aux<<endl;
        r[i-1]=0;
        cout<<"valor de r["<<i-1<<"]: "<<r[i-1]<<endl;
        cout<<"vas a seguir metiendo valores:"<<endl;
        cin>>b;
        if(b=='n')
        r[i-1]=aux;
      }
      cout<<"Hay mas Resistencias en Serie? s/n"<<endl;
      cin>>a;
    }while(a!='n');
    for(int i=0;i<n;i++){
      if(r[i]!=0){
        r[i]=(1/r[i]);
        cout<<"valor de r["<<i<<"]: "<<r[i]<<endl;
      }
    }
    equivalencia=0;
    for(int i=0;i<n;i++){
    equivalencia+=(r[i]);
    }
    equivalencia=1/equivalencia;
  }
  void pri_paralelo(int n){
    char a;
    float aux=0;
    int i;
    do{
      cout<<"Dime cuales son las resistencia en paralelo de la rama:"<<endl;
      char b='s';
      aux=0;
      for(;b!='n';){
        cout<<"Dime la Resistencia"<<endl;
        cin>>i;
        aux+=1/r[i-1];
        cout<<"valor de r["<<i-1<<"]: "<<r[i-1]<<endl;
        cout<<"Valor de aux: "<<aux<<endl;
        r[i-1]=0;
        cout<<"valor de r["<<i-1<<"]: "<<r[i-1]<<endl;
        cout<<"vas a seguir metiendo valores:"<<endl;
        cin>>b;
        if(b=='n')
        r[i-1]=1/aux;
      }
      cout<<"Hay mas Resistencias en Paralelo? s/n"<<endl;
      cin>>a;
    }while(a!='n');
    equivalencia=0;
    for(int i=0;i<n;i++){
    equivalencia+=(r[i]);
    }
  }
  void suma_resis(int n){
    char b;
    char a;
    do{
      cout<<"Dime si tu Circuito tiene mas Resistencias en Paraleolo o en Serie, s/p"<<endl;
      cin>>b;
      if(b=='s')
      pri_serie(n);
      else
      pri_paralelo(n);
      cout<<"Necesitas usar alguno de los otra vez s/n"<<endl;
      cin>>a;
    }while(a!='n');
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
  a.equivalencia=b.suma_resis(1,1,1,1,1);
  cout<<"El valor de la equivalencia en serie es: "<<a.resultado()<<endl;
  a.equivalencia=c.suma_resis(1,1,1,1,1);
  cout<<"El valor de la equivalencia en paralelo es: "<<a.resultado()<<endl;
  int n;
  cout<<"Cuantas Resistencia hay en el circuito"<<endl;
  cin>>n;
  d.iniciar_resist(n);
  d.imprime_matriz(n);
  d.suma_resis(n);
  cout<<"El valor de la equivalencia en mixto es: "<<d.resultado()<<endl;
}

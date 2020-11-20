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
class Transformador{
public:
  float vp1=23;
  float vp2=85;
  float vs1=0.44;
  float vs2=23;
};
class Poste:public Transformador{
  float lp;
  float ls;
public:
  void co_pri2(float kVA){
    lp=kVA/(sqrt(3)*1000*vp1);
  }
  void co_sec2(float kVA){
    ls=kVA/(sqrt(3)*1000*vs1);
  }
  float co_pri(float kVA){
      co_pri2(kVA);
      return get_prin();
  }
  float co_sec(float kVA){
      co_sec2(kVA);
      return get_sec();
  }
  float get_prin(){
      return lp;
  }
  float get_sec(){
      return ls;
  }
};
class Pedestal:public Transformador{
  float lp;
  float ls;
public:
  void co_pri2(float kVA){
    lp=kVA/(sqrt(3)*1000*vp1);
  }
  void co_sec2(float kVA){
    ls=kVA/(sqrt(3)*1000*vs1);
  }
  float co_pri(float kVA){
      co_pri2(kVA);
      return get_prin();
  }
  float co_sec(float kVA){
      co_sec2(kVA);
      return get_sec();
  }
  float get_prin(){
      return lp;
  }
  float get_sec(){
      return ls;
  }
};
class Potencia:public Transformador{
  float lp;
  float ls;
public:
  void co_pri2(float kVA){
    lp=kVA/(sqrt(3)*1000*vp2);
  }
  //auto completador de codigo, generedor de seters y geters atom
  void co_sec2(float kVA){
    ls=kVA/(sqrt(3)*1000*vs2);
  }
  float co_pri(float kVA){
      co_pri2(kVA);
      return get_prin();
  }
  float get_prin(){
      return lp;
  }
  float get_sec(){
      return ls;
  }
  float co_sec(float kVA){
      co_sec2(kVA);
      return get_sec();
  }
};
void todo(Poste b,Pedestal c, Potencia d);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  Transformador a;
  Poste b;
  Pedestal c;
  Potencia d;
  todo(b,c,d);
}
void todo(Poste b,Pedestal c, Potencia d){
  char n;
  int f;
  char s;
  do{
  cout<<"Dime el tipo de Transformador al que le quieres calcular"<<endl;
  cout<<"su corriente principal y secundaria"<<endl;
  cout<<"Para Pedestal/p, Poste/t, Potencia/a"<<endl;
  cin>>n;
  if(n=='p'||n=='t'){
    cout<<"Dime cuantos kVA tiene"<<endl;
    cin>>f;
    if(f>=15&&f<=500){
      cout<<"Categoria 1"<<endl;
      cout<<"Corriente principal: "<<b.co_pri(f)<<endl;
      cout<<"Corriente secundaria: "<<b.co_sec(f)<<endl;
    }
    else if(f>=501&&f<=5000){
      if(n=='p'){
        cout<<"Categoria 2"<<endl;
        cout<<"Corriente principal: "<<b.co_pri(f)<<endl;
        cout<<"Corriente secuandaria: "<<b.co_sec(f)<<endl;
      }
      else{
        cout<<"Categoria 2"<<endl;
        cout<<"Corriente principal: "<<c.co_pri(f)<<endl;
        cout<<"Corriente secuandaria: "<<c.co_sec(f)<<endl;
      }
    }
    else if(f>=5001&&f<=30000){
      cout<<"Categoria 3"<<endl;
      cout<<"Corriente principal: "<<c.co_pri(f)<<endl;
      cout<<"Corriente secuandaria: "<<c.co_sec(f)<<endl;
    }
  }
  else{
    cout<<"Dime cuantos kVA tiene"<<endl;
    cin>>f;
    if(f>=5001&&f<=30000){
      cout<<"Categoria 3"<<endl;
      cout<<"Corriente principal: "<<d.co_pri(f)<<endl;
      cout<<"Corriente secuandaria: "<<d.co_sec(f)<<endl;
    }
    else{
      cout<<"Categoria 4"<<endl;
      cout<<"Corriente principal: "<<d.co_pri(f)<<endl;
      cout<<"Corriente secuandaria: "<<d.co_sec(f)<<endl;
    }
  }
cout<<"Quieres hacer el calculo de nuevo s/n"<<endl;
cin>>s;
}while(s!='n');
}

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
public:
  float co_pri(float kVA){
    float lp=0;
    lp=kVA/(sqrt(3)*1000*vp1);
    return lp;
  }
  float co_sec(float kVA){
    float lp=0;
    lp=kVA/(sqrt(3)*1000*vs1);
    return lp;
  }
};
class Pedestal:public Transformador{
public:
  float co_pri(float kVA){
    float lp=0;
    lp=kVA/(sqrt(3)*1000*vp1);
    return lp;
  }
  float co_sec(float kVA){
    float lp=0;
    lp=kVA/(sqrt(3)*1000*vs1);
    return lp;
  }
};
class Potencia:public Transformador{
public:
  float co_pri(float kVA){
    float lp=0;
    lp=kVA/(sqrt(3)*1000*vp2);
    return lp;
  }
  float co_sec(float kVA){
    float lp=0;
    lp=kVA/(sqrt(3)*1000*vs2);
    return lp;
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

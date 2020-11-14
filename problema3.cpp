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
class Conversion{
public:
  float m_pi=3.28;
  float m_pul=39.37;
  float m_li=0.7376;
  float li_pi=0.083333;
  float li_pul=2.036;
  float li_m=0.01152;
  float pi_m=0.3048;
  float pi_pul=12;
  float pi_li=0.083333;
  float pul_pi=0.0833333;
  float pul_m=0.0254;
  float pul_li=2.036;

};
class Metros:Conversion{
public:
  float metros_pies(float m){
    float pies;
    pies=m*m_pi;
    return pies;
  }
  float metros_pul(float m){
    float pul;
    pul=m*m_pul;
    return pul;
  }
  float metros_libras(float m){
    float libra;
    libra=m*m_li;
    return libra;
  }
};
class Pulgadas:Conversion{
public:
  float pul_met(int pul){
    float m;
    m=pul*pul_m;
    return m;
  }
  float pul_pie(int pul){
    float pie;
    pie=pul*pul_pi;
    return pie;
  }
  float pul_libras(int pul){
    float li;
    li=pul*pul_li;
    return li;
  }
};
class Pies:Conversion{
public:
  float pie_met(float pi){
    float m;
    m=pi*pi_m;
    return m;
  }
  float pie_pul(float pi){
    float pul;
    pul=pi*pi_pul;
    return pul;
  }
  float pie_libra(float pi){
    float li;
    li=pi*pi_li;
    return li;
  }
};
class Libras:Conversion{
public:
  float libra_met(float lib){
    float m;
    m=lib*li_m;
    return m;
  }
  float libra_pie(float lib){
    float pie;
    pie=lib*li_pi;
    return pie;
  }
  float libra_pul(float lib){
    float pul;
    pul=lib*li_pul;
    return pul;
  }
};
void todo(Metros b,Pulgadas c,Pies d,Libras e);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  Conversion a;
  Metros b;
  Pulgadas c;
  Pies d;
  Libras e;
  todo(b,c,d,e);

}
void todo(Metros b,Pulgadas c,Pies d,Libras e){
  char a;
  float m,lib,pi,pul;
  char h;
  do{
    cout<<"Dime que quieres convertir"<<endl;
    cout<<"Metros/m, Pies/t, Pulgadas/p, Libras/l"<<endl;
    cin>>a;
    if(a=='m'){
      cout<<"Dime cuantos metros hay:"<<endl;
      cin>>m;
      cout<<"Pies: "<<b.metros_pies(m)<<"ft"<<endl;
      cout<<"Pulgadas: "<<b.metros_pul(m)<<"in"<<endl;
      cout<<"Libras: "<<b.metros_libras(m)<<"lb"<<endl;
    }
    else if(a=='t'){
      cout<<"Dime cuantos pies hay:"<<endl;
      cin>>pi;
      cout<<"Metros: "<<d.pie_met(pi)<<"m"<<endl;
      cout<<"Pulgadas: "<<d.pie_pul(pi)<<"in"<<endl;
      cout<<"Libras: "<<d.pie_libra(pi)<<"lb"<<endl;
    }
    else if(a=='p'){
      cout<<"Dime cuantos pulgadas hay:"<<endl;
      cin>>pul;
      cout<<"Metros: "<<c.pul_met(pul)<<"m"<<endl;
      cout<<"Pies: "<<c.pul_pie(pul)<<"ft"<<endl;
      cout<<"Libras: "<<c.pul_libras(pul)<<"lb"<<endl;
    }
    else {
      cout<<"Dime cuantos libras hay:"<<endl;
      cin>>lib;
      cout<<"Metros: "<<e.libra_met(lib)<<"m"<<endl;
      cout<<"Pulgadas: "<<e.libra_pul(lib)<<"in"<<endl;
      cout<<"Pies: "<<e.libra_pie(lib)<<"ft"<<endl;
    }
    cout<<"Quieres hacer otras conversion s/n"<<endl;
    cin>>h;
  }while(h!='n');
}

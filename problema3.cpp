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
  const float m_pi=3.28;
  const float m_pul=39.37;
  const float m_li=0.7376;
  const float li_pi=0.083333;
  const float li_pul=2.036;
  const float li_m=0.01152;
  const float pi_m=0.3048;
  const float pi_pul=12;
  const float pi_li=0.083333;
  const float pul_pi=0.0833333;
  const float pul_m=0.0254;
  const float pul_li=2.036;
};
class Metros:Conversion{
  float pul;
  float libra;
  float pies;
public:
  void metros_pies(float m){
    pies=m*m_pi;
  }
  void metros_pul(float m){
    pul=m*m_pul;
  }
  void metros_libras(float m){
    libra=m*m_li;
  }
  float met_pie(float m){
    metros_pies(m);
    return ret_met_pie();
  }
  float met_pul(float m){
    metros_pul(m);
    return ret_met_pul();
  }
  float met_lib(float m){
    metros_libras(m);
    return ret_met_lib();
  }
  float ret_met_pul(){
    return pul;
  }
  float ret_met_lib(){
    return libra;
  }
  float ret_met_pie(){
    return pies;
  }
};
class Pulgadas:Conversion{
  float m;
  float pie;
  float li;
public:
  void pul_met(int pul){
    m=pul*pul_m;
  }
  void pul_pie(int pul){
    pie=pul*pul_pi;
  }
  void pul_libras(int pul){
    li=pul*pul_li;
  }
  float pulg_met(float m){
    pul_met(m);
    return ret_pul_met();
  }
  float pulg_pie(float m){
    pul_pie(m);
    return ret_pul_pie();
  }
  float pulg_lib(float m){
    pul_libras(m);
    return ret_pul_lib();
  }
  float ret_pul_lib(){
    return li;
  }
  float ret_pul_met(){
    return m;
  }
  float ret_pul_pie(){
    return pie;
  }
};
class Pies:Conversion{
  float m;
  float pul;
  float li;
  public:
  void pie_met(float pi){
    m=pi*pi_m;
  }
  void pie_pul(float pi){
    pul=pi*pi_pul;
  }
  void pie_libra(float pi){
    li=pi*pi_li;
  }
  float pies_met(float m){
    pie_met(m);
    return ret_pie_met();
  }
  float pies_pul(float m){
    pie_pul(m);
    return ret_pie_pul();
  }
  float pies_lib(float m){
    pie_libra(m);
    return ret_pie_lib();
  }
  float ret_pie_lib(){
    return li;
  }
  float ret_pie_met(){
    return m;
  }
  float ret_pie_pul(){
    return pul;
  }
};
class Libras:Conversion{
  float pul;
  float m;
  float pie;
  public:
  void libra_met(float lib){
    m=lib*li_m;
  }
  void libra_pie(float lib){
    pie=lib*li_pi;
  }
  void libra_pul(float lib){
    pul=lib*li_pul;
  }
  float lib_met(float m){
    libra_met(m);
    return ret_lib_met();
  }
  float lib_pul(float m){
    libra_pul(m);
    return ret_lib_pul();
  }
  float lib_pie(float m){
    libra_pie(m);
    return ret_lib_pie();
  }
  float ret_lib_pul(){
    return pul;
  }
  float ret_lib_met(){
    return m;
  }
  float ret_lib_pie(){
    return pie;
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
      cout<<"Pies: "<<b.met_pie(m)<<"ft"<<endl;
      cout<<"Pulgadas: "<<b.met_pul(m)<<"in"<<endl;
      cout<<"Libras: "<<b.met_lib(m)<<"lb"<<endl;
    }
    else if(a=='t'){
      cout<<"Dime cuantos pies hay:"<<endl;
      cin>>pi;
      cout<<"Metros: "<<d.pies_met(pi)<<"m"<<endl;
      cout<<"Pulgadas: "<<d.pies_pul(pi)<<"in"<<endl;
      cout<<"Libras: "<<d.pies_lib(pi)<<"lb"<<endl;
    }
    else if(a=='p'){
      cout<<"Dime cuantos pulgadas hay:"<<endl;
      cin>>pul;
      cout<<"Metros: "<<c.pulg_met(pul)<<"m"<<endl;
      cout<<"Pies: "<<c.pulg_pie(pul)<<"ft"<<endl;
      cout<<"Libras: "<<c.pulg_lib(pul)<<"lb"<<endl;
    }
    else {
      cout<<"Dime cuantos libras hay:"<<endl;
      cin>>lib;
      cout<<"Metros: "<<e.lib_met(lib)<<"m"<<endl;
      cout<<"Pulgadas: "<<e.lib_pul(lib)<<"in"<<endl;
      cout<<"Pies: "<<e.lib_pie(lib)<<"ft"<<endl;
    }
    cout<<"Quieres hacer otras conversion s/n"<<endl;
    cin>>h;
  }while(h!='n');
}

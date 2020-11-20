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
class Dimensiones{
public:
  float lado=3;
  float lado2=2;
  float radio=2;
  float altura=5;
  float pi=3.141592654;
  float area;
  float perimetro;
  float res_area(){
    return area;
  }
  float res_peri(){
    return perimetro;
  }
  float valor_s(){
    float s=0;
    s=(lado+lado+lado)/2;
    return s;
  }
  void todo_parametros(){
    cout<<"Valor de el lado del cuadrado: "<<lado<<endl;
    cout<<"Valor de el lado del rectangulo: "<<lado<<endl;
    cout<<"Valor de el otro lado del rectangulo: "<<lado2<<endl;
    cout<<"Valor del radio del circulo: "<<radio<<endl;
    cout<<"Valor de pi: "<<pi<<endl<<endl;
  }
};
class Area:public Dimensiones{
  float rec;
  float cuad;
  float tria;
  float circ;
public:
  void rectangulo(){
    rec=lado*lado2;
  }
void cuadrado(){
    cuad=lado*lado;
  }
void triangulo(){
    float s=valor_s();
    tria=sqrt(s*(s-lado)*(s-lado)*(s-lado));
  }
void circulo(){
    circ=pi*radio*radio;
  }
  float rectan(){
    rectangulo();
    return ret_rectangulo();
  }
  float cuadra(){
    cuadrado();
    return ret_cuadrado();
  }
  float triang(){
    triangulo();
    return ret_triangulo();
  }
  float circu(){
    circulo();
    return ret_circulo();
  }
  float ret_rectangulo(){
    return rec;
  }
  float ret_cuadrado(){
    return cuad;
  }
  float ret_triangulo(){
    return tria;
  }
  float ret_circulo(){
    return circ;
  }
  void todo_area(){
    cout<<"Areas: "<<endl;
    area=rectan();
    cout<<"Rectangulo: "<<res_area()<<"m^2"<<endl;
    area=cuadra();
    cout<<"Cuadrado: "<<res_area()<<"m^2"<<endl;
    area=triang();
    cout<<"Triangulo: "<<res_area()<<"m^2"<<endl;
    area=circu();
    cout<<"Circulo: "<<res_area()<<"m^2"<<endl<<endl;
  }
};
class Perimetro:public Dimensiones{
  float rec;
  float cuad;
  float tria;
  float circ;
public:
  void rectangulo(){
    rec=lado*2+lado2*2;
  }
  void cuadrado(){
    cuad=lado*4;
  }
  void triangulo(){
    tria=lado*3;
  }
  void circulo(){
    circ=pi*radio*2;
  }
  float rectan(){
    rectangulo();
    return ret_rectangulo();
  }
  float cuadra(){
    cuadrado();
    return ret_cuadrado();
  }
  float triang(){
    triangulo();
    return ret_triangulo();
  }
  float circu(){
    circulo();
    return ret_circulo();
  }
  float ret_rectangulo(){
    return rec;
  }
  float ret_cuadrado(){
    return cuad;
  }
  float ret_triangulo(){
    return tria;
  }
  float ret_circulo(){
    return circ;
  }
  void todo_peri(){
    cout<<"Perimetros: "<<endl;
    perimetro=rectan();
    cout<<"Rectangulo: "<<res_peri()<<"m"<<endl;
    perimetro=cuadra();
    cout<<"Cuadrado: "<<res_peri()<<"m"<<endl;
    perimetro=triang();
    cout<<"Triangulo: "<<res_peri()<<"m"<<endl;
    perimetro=circu();
    cout<<"Circulo: "<<res_peri()<<"m"<<endl<<endl;
  }
};

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  Dimensiones a;
  Area b;
  Perimetro c;
  a.todo_parametros();
  b.todo_area();
  c.todo_peri();
}

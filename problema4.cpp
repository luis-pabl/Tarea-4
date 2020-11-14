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
public:
  float rectangulo(){
    float f=lado*lado2;
    return f;
  }
  float cuadrado(){
    float f=lado*lado;
    return f;
  }
  float triangulo(){
    float s=valor_s();
    float f=sqrt(s*(s-lado)*(s-lado)*(s-lado));
    return f;
  }
  float circulo(){
    float f=pi*radio*radio;
    return f;
  }
  void todo_area(){
    cout<<"Areas: "<<endl;
    area=rectangulo();
    cout<<"Rectangulo: "<<res_area()<<"m^2"<<endl;
    area=cuadrado();
    cout<<"Cuadrado: "<<res_area()<<"m^2"<<endl;
    area=triangulo();
    cout<<"Triangulo: "<<res_area()<<"m^2"<<endl;
    area=circulo();
    cout<<"Circulo: "<<res_area()<<"m^2"<<endl<<endl;
  }
};
class Perimetro:public Dimensiones{
public:
  float rectangulo(){
    float f=lado*2+lado2*2;
    return f;
  }
  float cuadrado(){
    float f=lado*4;
    return f;
  }
  float triangulo(){
    float f=lado*3;
    return f;
  }
  float circulo(){
    float f=pi*radio*2;
    return f;
  }
  void todo_peri(){
    cout<<"Perimetros: "<<endl;
    perimetro=rectangulo();
    cout<<"Rectangulo: "<<res_peri()<<"m"<<endl;
    perimetro=cuadrado();
    cout<<"Cuadrado: "<<res_peri()<<"m"<<endl;
    perimetro=triangulo();
    cout<<"Triangulo: "<<res_peri()<<"m"<<endl;
    perimetro=circulo();
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

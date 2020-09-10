#include <iostream>
#include<sstream>
#include <string.h>
#include <cctype>
#include <cstring>

#define INICIO 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define S7 7
#define ERROR 8
using namespace std;

int main()
{
    int estado = INICIO;
    string numeroString;

    cout<<"Enter a value ";
    cin>>numeroString;

    char *cadenaconver = strdup(numeroString.c_str());
    ///Conversion del valor introducido a un valor en CHAR
    cout<<"-------------------------------------"<<endl;
      for(int i=0;i<numeroString.length();i++) ///Recorrido de la cadena introducida
        {
            switch(estado)
            {
                case INICIO:///SOLO DIGITOS
                {
                    if(cadenaconver[i+1]=='\0')
                            cout<<"Cadena No Permitida"<<endl;
                    if (isdigit(cadenaconver[i]))///El primer estado Solo admite Digitos
                    {
                        estado = S1;
                        ///cout<<"Primer Estado: "<<cadenaconver[i]<<endl;
                    }
                    else
                    {
                        ///Si no es un caracter valido va al estado de ERROR
                        estado = ERROR;
                        cout<<"Cadena No permitida"<<endl;
                    }
                    break;
                }
                case S1:
                {
                    if(cadenaconver[i+1]=='\0')
                            cout<<"Cadena No Permitida"<<endl;
                    ///El Segundo estado Admite digitos '.' y 'E'
                    if(cadenaconver[i]=='.')
                    {
                        estado = S2;
                        ///cout<<"Segundo Estado: "<<cadenaconver[i]<<endl;
                    }
                    else if(cadenaconver[i]=='E'){
                        estado = S4;
                        ///cout<<"Segundo Estado: "<<cadenaconver[i]<<endl;
                    }
                    else if(isdigit(cadenaconver[i])){
                        estado = S1;
                        ///cout<<"Segundo Estado: "<<cadenaconver[i]<<endl;
                    }
                    else
                    {
                        estado = ERROR;
                        cout<<"Cadena No permitida"<<endl;
                    }
                    break;
                }
                case S2:
                {
                    ///EL Tercero Solo Admite Digitos
                    if(isdigit(cadenaconver[i]))
                    {

                        estado = S3;
                        if(cadenaconver[i+1]=='\0')
                            cout<<"Cadena Permitida"<<endl;
                    }
                    else
                    {
                        estado = ERROR;
                        cout<<"Cadena No permitida"<<endl;
                    }
                    break;
                }
                case S3:
                {
                    ///EL Cuarto se repite cuando es un digito, y cuando es E va al siguiente
                    if(isdigit(cadenaconver[i]))
                    {
                        estado = S3;
                         if(cadenaconver[i+1]=='\0')
                            cout<<"Cadena Permitida"<<endl;

                    }
                    else if(cadenaconver[i]=='E'){
                        estado = S4;
                        ///cout<<"Cuarto Estado: "<<cadenaconver[i]<<endl;
                    }
                    else
                    {
                        estado = ERROR;
                        cout<<"Cadena No permitida"<<endl;
                    }

                    break;
                }
                case S4:
                {

                    ///EL Quinto Admite '+' y '-' y cuando es un digito va al proximo
                    if(cadenaconver[i]=='+'||cadenaconver[i]=='-')
                    {
                        estado = S5;
                        ///cout<<"Quinto Estado: "<<cadenaconver[i]<<endl;

                    }
                    else if (isdigit(cadenaconver[i]))
                    {
                        estado = S6;
                         if(cadenaconver[i+1]=='\0')
                            cout<<"Cadena Permitida"<<endl;
                    }
                    else
                    {
                        estado = ERROR;
                        cout<<"Cadena No permitida"<<endl;
                    }
                    break;
                }
                case S5:
                {
                    ///EL Quinto Admite '+' y '-' y cuando es un digito va al proximo
                    if(isdigit(cadenaconver[i]))
                    {
                        estado = S6;
                         if(cadenaconver[i+1]=='\0')
                            cout<<"Cadena Permitida"<<endl;
                    }
                    else
                    {
                        estado = ERROR;
                        cout<<"Cadena No permitida"<<endl;
                    }
                    break;
                }
                case S6:
                {
                    cout<<"Cadena Permitida"<<endl;
                    ///EL Quinto Admite '+' y '-' y cuando es un digito va al proximo
                    if(isdigit(cadenaconver[i]))
                    {
                        cout<<"Cadena Permitida"<<endl;
                        ///cout<<"Septimo Estado: "<<cadenaconver[i]<<endl;
                    }
                    else
                    {
                        estado = ERROR;
                        cout<<"Cadena No permitida"<<endl;
                    }
                    break;
                }
                case ERROR:
                    {
                          cout<<"Cadena No permitida"<<endl;
                           i = numeroString.length()+100;
                    }
                    break;
            }
        }
    return 0;
}

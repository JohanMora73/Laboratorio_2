#include "lab2.h"

int main()
{
    int num, menu, cont, div, cantidades[]={50000,20000,10000,5000,2000,1000,500,200,100,50}, len, n=0, opc,k, Matriz14[5][5],total,combinacion;
    long long int max, amg2, suma=0, lista[50];
    char aleatorio, Lista[20], cadena1[20], *cadena, *asientos[15][20];
    bool resp;
    string str = "0123456789";
    int Matriz[6][8]={{0,3,4,0,0,0,6,8},
                       {5,13,6,0,0,0,2,3},
                       {2,6,2,7,3,0,10,0},
                       {0,0,4,15,4,1,6,0},
                       {0,0,7,12,6,9,10,4},
                       {5,0,6,10,6,4,8,0},
                       };
    while(true){
        cout<<"Digite el ejercicio a ejecutar: "<<endl;cin>>menu;
        switch(menu){
            case 1:
                cout<<"ingrese el valor: "<<endl;cin>>num;
                for(int i=0;i<10;i++){
                    div=num/cantidades[i];
                    cout<<cantidades[i]<<": "<<div<<endl;
                    num%=cantidades[i];
                }
                cout<<"Faltante: "<<num<<endl;
            break;

            case 2:
                for(int i=0;i<100;i+=1){
                    aleatorio=rand()% 26+65;
                    Lista[i]=aleatorio;
                    cout<<aleatorio<<" "<<i<<endl;
                }
                for(char i=65;i<=90;i++){
                    cont=0;
                    for(int j=0;j<200;j++){
                        if(i==Lista[j]){
                            cont+=1;
                        }
                    }
                    num+=cont;
                    cout<<i<<": "<<cont<<endl;
                }
            break;

            case 3:
                cout<<"ingrese una cadena de caracteres: "<<endl;cin>>cadena1;
                cout<<"ingrese otra cadena de caracteres: "<<endl;cin>>Lista;
                resp=CompararCadenas(cadena1,Lista);
                if (resp==true) cout<<"son iguales"<<endl;
                else cout<<"son diferentes"<<endl;
            break;

            case 4:
                cout<<"ingrese la longitu del arreglo: "<<endl;
                cin>>len;
                cadena=new char[len+1];
                cadena[len]='\0';
                fflush(stdin);           //Para limpiar el nufer serial
                cout<<"Ingrese el numero a convertir: "<<endl;
                gets(cadena);
                cout<<cadena<<endl;
                num = ConvCadANum(cadena);
                delete [] cadena;
                num/=10;
                cout<<num<<endl;
            break;

            case 5:
                cout << "digite un numero" << endl;cin>>num;
                len=0;
                n=num;
                while(n>0){
                    n/=10;
                    len+=1;            //Se calcula la cantidad de digitos del numero ingresado
                }
                //cout<<"longitud= "<<len<<endl;
                Char_Int(num,len);

            break;

            case 6:
                cout<<"Ingrese la longitud de la cadena: "<<endl;
                cin>>len;
                cadena=new char[len+1];
                cadena[len]='\0';
                fflush(stdin);
                cout<<"Ingrese la cadena a convertir: "<<endl;
                gets(cadena);
                cadena[len]='\0';
                cout<<"Original: "<<cadena ;

                while(cadena[n]!='\0'){
                    if(cadena[n]>=97 && cadena[n]<=122){
                        cadena[n]=cadena[n]-32;
                    }
                    n+=1;
                }
                cout<<". Mayuscula: "<<cadena<<endl;
                delete [] cadena;
            break;

            case 7:
                cout<<"ingrese la longitud de la cadena: "<<endl;
                cin>>len;
                cadena= new char[len+1];
                cadena[len]='\0';
                fflush(stdin);
                cout<<"ingrese la cadena: "<<endl;
                gets(cadena);
                eliminar_repetidos(cadena,len);

                delete [] cadena;
            break;

            case 8:
                cout<<"digite la longitud de la cadena: "<<endl;cin>>len;
                cadena=new char[len+1];
                cadena[len]='\0';
                fflush(stdin);
                cout<<"ingrese la cadena de caracteres: "<<endl;
                gets(cadena);
                cout<<"Original: "<<cadena<<endl;
                Separar_charYnum(cadena,len);
                delete [] cadena;
            break;

            case 9:
                cout<<"digite la longitud de la cadena: "<<endl;cin>>len;
                cout<<"digite la cantidad de digitos de sus numeros: "<<endl;cin>>num;
                cadena=new char[len+1];
                cadena[len]='\0';
                fflush(stdin);
                cout<<"ingrese la cadena de caracteres NUMERICOS: "<<endl;
                gets(cadena);
                cout<<"Original: "<<cadena<<endl;
                Separar_nums(cadena,len,num);

                delete [] cadena;
            break;

            case 10:
                do{
                cout<<"Digite el numero a convertir (debe ser menor o igual a 3999): "<<endl;
                cin>>num;
                }while(num>3999);

                ConvertirRomano(num);
                cout<<"Que corresponde a: "<<num<<endl;
            break;

            case 11:
                do{
                cout<<"Menu: "<<endl<<"para reservar un asiento ingrese 1"<<endl<<"Para cacelar una reserva ingrese 2"<<"Para salir ingrese 3"<<endl;
                cin>>opc;
                switch(opc){
                    case 1:
                        Cine(asientos, opc);
                    break;

                    case 2:
                        Cine(asientos, opc);
                    break;
                }

                }while(opc!=3);
            break;

            case 12:
                k=0;
                cout<<"digite la dimension de la matriz: "<<endl;cin>>n;
                char  *cadena, *cad;
                cad=new char[n*n+1];
                cadena=new char[2*n*n];
                cadena[2*n*n]='\0';
                fflush(stdin);
                cout<<"Ingrese los "<<n*n<<" valores de la matriz separados con (,): "<<endl;
                gets(cadena);
                for(int i=0;cadena[i]!='\0';i++){
                    if(cadena[i]==','){
                        cad[k]=num;
                        num=0;
                        k+=1;
                    }
                    else{
                        num=num*10+(cadena[i]-48);
                    }
                }
                CuadroMagico(cad,n);
                delete [] cadena;
                delete [] cad;
            break;

            case 13:
                MostrarMatriz(Matriz);
                num=ContarEstrellas(Matriz);
                cout<<"Hay: "<<num<<" estrellas"<<endl;
            break;

            case 14:
                k=1;
                cout<<"Matriz sin rotar: "<<endl<<endl;
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        Matriz14[i][j]=k;
                        if(k<10){
                        cout<<"| "<<Matriz14[i][j];
                        }
                        else{
                            cout<<"|"<<Matriz14[i][j];
                        }
                        k+=1;
                    }
                    cout<<"|"<<endl;
                    cout<<"+--+--+--+--+--+"<<endl;
                }
                cout<<endl;
                RotarMatriz(Matriz14);
            break;

            case 15:
                //x,y,ancho,alto
                int rectangulo1[4],rectangulo2[4],rectangulo3[4],*dir;
                    cout<<"ingrese la cordenada de la ezquina superior x & y respectivamente(Para el rectangulo 1): "<<endl;
                    cin>>rectangulo1[0]>>rectangulo1[1];

                    cout<<"ingrese el ancho y alto del rectangulo respectivamente(Para el rectangulo 1): "<<endl;
                    cin>>rectangulo1[2]>>rectangulo1[3];

                    cout<<"ingrese la cordenada de la ezquina superior x & y respectivamente(Para el rectangulo 2): "<<endl;
                    cin>>rectangulo2[0]>>rectangulo2[1];

                    cout<<"ingrese el ancho y alto del rectangulo respectivamente(Para el rectangulo 2): "<<endl;
                    cin>>rectangulo2[2]>>rectangulo2[3];

                    dir=IntersecRectang(rectangulo1,rectangulo2,rectangulo3);

                    cout<<"para el rectangulo C se obtuvieron los siguientes datos: "<<endl<<"x0: "<<*dir<<" y0: "<<*(dir+1)<<" ancho: "<<*(dir+2)<<" Alto: "<<*(dir+3)<<endl;

            break;

            case 16:
                cout<<"Escriba la magnitud del lado de un cuadrado:";
                cin>>num;
                total=num+num; // casos posibles
                combinacion=Factorial(total)/(Factorial(total-num)*Factorial(num));// formula de combinacion
                cout<<"Para una malla de "<<num<<'x'<<num<< " puntos hay "<<combinacion<<" caminos"<<endl;
            break;

            case 17:
                cont=0;
                len=0;
                resp=false;
                cout<<"ingrese el numero limite: "<<endl;cin>>max;

                for(long long int i=219;i<max;i++){
                    amg2=SumadeDivisores(i);
                    if(SumadeDivisores(amg2)==i && i!=amg2){
                        len+=1;
                    }
                }
                len=len/2+1;

                cout<<len<<endl;

                for(long long int i=219;i<max;i++){
                    amg2=SumadeDivisores(i);
                    if(SumadeDivisores(amg2)==i && i!=amg2){
                        for(int k=0;k<=cont;k++){
                            if(lista[k]==amg2){
                                resp=true;break;
                            }
                            else{
                                resp=false;
                                lista[cont]=i;
                            }

                        }
                        if (resp==false){
                            cout<<i<<" "<<amg2<<endl;
                            suma=suma+i+amg2;
                            cont+=1;
                        }
                    }
                }
                cout<<"El resultado de la suma es: "<<suma<<endl;
            break;

            case 18:
                cout<<"este programa recibe el enecimo termino de una permutacion y lo imprime "<<endl;

                    long int n ;
                    cout<<"ingrese enesimo termino: "<<endl;
                    cin>>n;
                    enesima_permutacion(str, n);
                break;

            default:
                cout<<"Esa opcion no esta disponible: "<<endl;
            break;
        }
    }

    return 0;
}

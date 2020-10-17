#include "lab2.h"

bool CompararCadenas(char Lista1[],char Lista2[]){
    int len1,len2;
    bool resp=false;
    len1=strlen(Lista1);
    len2=strlen(Lista2);
    if(len1==len2){
        for(int i=0;i<len1;i++){
            if(Lista1[i] != Lista2[i]){
                resp=false;
                break;
            }
            else resp=true;
        }
    }
    return resp;
}

int ConvCadANum(char listanum[]){
    int num=0, i=0;
    while(listanum[i]!='\0'){
        cout<<listanum[i]<<endl;
        listanum[i]=listanum[i]-48;
        num=(num+listanum[i])*10;
        cout<<num<<endl;
        i+=1;    }
  return num;
}

void Char_Int(int num, int lon){
    char cadena[lon-1];
    int n;
    cadena[lon]='\0';
    //cout<<"numero "<<num<<" longitud "<<lon<<endl;

    for(int i=lon;i>=0;i--){
        n=num%10;
        num/=10;
        cadena[i-1]= char(n+48);
    }
    cout<<"El numero convertido en caracter es: "<<cadena<<endl;
}

void eliminar_repetidos(char *cad, int lon){
    int k=0;
    char *no_rep =new char[lon+1];
    cout<<"Original: "<<cad<<". Sin repeticiones: ";
    no_rep[0]='\0';
    for(int i =0;cad[i]!='\0';i++){
        for(k=0;cad[i]!=no_rep[k] && no_rep[k]!='\0';k++);
            if(no_rep[k]=='\0'){
                no_rep[k]=cad[i];
                no_rep[k+1]='\0';
                cout<<cad[i];
            }
    }
    cout<<endl;
    delete [] no_rep;
}

void Separar_charYnum(char *cad, int len){
    char *SoloNum = new char[len+1];
    char *SoloChar = new char[len+1];
    int k=0;
    int j=0;
    SoloNum[0]='\0';
    SoloChar[0]='\0';
    for(int i=0;cad[i]!='\0';i++){
        if(cad[i]>=48 && cad[i]<=57){
            SoloNum[k]=cad[i];
            SoloNum[k+1]='\0';
            k+=1;
        }
        else{
            SoloChar[j]=cad[i];
            SoloChar[j+1]='\0';
            j+=1;
        }
    }
    cout<<"Texto: "<<SoloChar<<". Numero: "<<SoloNum<<endl;
    delete [] SoloChar;
    delete [] SoloNum;

}

void Separar_nums(char *cad, int len, int n){
    int num=0, suma=0, k, dec=1, lon, i;
    if(len%n!=0){
        lon=(len/n+1)*n;
        char *newcad=new char[lon+1];
        newcad[lon]='\0';
        //cout<<lon<<endl;
        for(i=0;i<(lon-len);i++){
            newcad[i]='0';
        }
        for(int j=0;cad[j]!='\0' ;j++){
            newcad[i]=char(cad[j]);
            i+=1;
        }
        cad=newcad;
        len=lon;
    }
    else{
        char *newcad=new char[len+1];
        newcad=cad;
    }

    for (int i=len-1;i>=0;i--){
        k=cad[i]-48;
        num=num+dec*k;
        dec*=10;
        if(i+1<len && i%n==0){
            //cout<<num<<endl;
            suma+=num;
            dec=1;
            num=0;
        }
    }
    cout<<"Suma: "<<suma<<endl;
}

void ConvertirRomano(int n){
    cout<<"El numero ingresado fue: ";
    char R1, R2, R3;
    int unidad, decena, centena, millar, caso;
    unidad = n % 10; n /= 10; // unidad = 6, n=257
    decena = n % 10; n /= 10; // decena = 7, n=25
    centena = n % 10; n /= 10; //centena = 5, n=2
    millar =n;
    for(int i=0;i<4;i++){
        if(i==3) {R1='I';R2='V';R3='X';caso=unidad;}
        else if(i==2){R1='X';R2='L';R3='C';caso=decena;}
        else if(i==1){R1='C';R2='D';R3='M';caso=centena;}
        else if(i==0){R1='M';R2=' ';R3=' ';caso=millar;}
        switch(caso){
            case 1: cout<<R1; break;
            case 2: cout<<R1<<R1; break;
            case 3: cout<<R1<<R1<<R1; break;
            case 4: cout<<R1<<R2; break;
            case 5: cout<<R2; break;
            case 6: cout<<R2<<R1; break;
            case 7: cout<<R2<<R1<<R1; break;
            case 8: cout<<R2<<R1<<R1<<R1; break;
            case 9: cout<<R1<<R3; break;
        }
    }
    cout<<endl;
}

void Cine(char *asientos[15][20], int op){
    int col;
    char fil;
    for(int i=0;i<15;i++){
        for(int k=0;k<20;k++){
            if(asientos[i][k] != "+"){
            asientos[i][k]="-";
            }
            cout<<"|"<<asientos[i][k];
        }
        cout<<"|"<<char(i+65)<<endl;
    }
    if (op==1){
        do{
            cout<<"ingrese la posicion del asiento que desea reservar, tenga en cuenta que esta debe estar libre: ";
            cin>>fil>>col;
            if(asientos[fil-65][col-1] == "+") cout<<"estimado usuario esa ocion no esta disponible"<<endl;
        }while(asientos[fil-65][col-1] == "+");
        asientos[fil-65][col-1] = "+";
        cout<<"Reserva exitosa"<<endl;

    }
    else{
        do{
        cout<<"ingrese la posicion de la reserva que desea cancelar: ";
        cin>>fil>>col;
        if(asientos[fil-65][col-1] != "+") cout<<"Estimado usuario esa ocion no esta reservada"<<endl;
    }
    while(asientos[fil-65][col-1] != "+");
    asientos[fil-65][col-1] = "-";
    cout<<" Cancelacion de reserva exitosa"<<endl;
    }
}

void CuadroMagico(char *cad, int n){
    int k=0, suma=0, comparar;
    bool resp=false;
    char *matriz [n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++,k+=1){
            matriz[i][j]=&cad[k];
            cout<<"|"<<int(*matriz[i][j]);
        }
        cout<<"|"<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            suma+=int(*matriz[i][j]);
        }
        if(i==0){comparar=suma;}
        if(suma==comparar){resp=true;}
        else{resp=false;break;}
        cout<<"La suma es: "<<suma<<endl;
        suma=0;
    }
    if(resp==true){
        k=0;
        suma=0;
        cout<<"paso el primer filtro"<<endl;
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
               suma+=int(*matriz[i][k]);
            }
            if(j==0){comparar=suma;}
            if(suma==comparar){resp=true;}
            else{resp=false;cout<<"F"<<endl;break;}
            k+=1;
            suma=0;
        }
        if(resp==true){
            suma=0;
            for(int i=0;i<n;i++){
                suma+=int(*matriz[i][i]);
            }
             if(suma==comparar){
                 resp=true;
                 suma=0;
                 for(int i=0, j=n-1;i<n;i++,j--){
                     suma+=int(*matriz[i][j]);
                 }
                 if(suma==comparar){
                     resp=true;
                     cout<<"Es un cuadrado magico"<<endl;
                 }
                 else{resp=false;cout<<"No es cuadrado magico"<<endl;}
             }
             else{resp=false;cout<<"No es cuadrado magico"<<endl;}
        }
        else cout<<"No es cuadrado magico"<<endl;
    }
    else cout<<"No es cuadrado magico"<<endl;
}

void MostrarMatriz(int matriz[6][8]){
    cout<<"+--+--+--+--+--+--+--+--+"<<endl;
    for (int i=0;i<6;i++){
        for(int j=0;j<8;j++){
            if(matriz[i][j]<10){
                cout<<"| "<<matriz[i][j];
            }
            else{
                 cout<<"|"<<matriz[i][j];
            }
        }
        cout<<"|"<<endl;
        cout<<"+--+--+--+--+--+--+--+--+"<<endl;
    }
}

int ContarEstrellas(int matriz[6][8]){
    float suma=0;
    int cont=0;
    for(int i=1;i<5;i++){
        for(int j=1; j<7; j++){
            suma=float(matriz[i][j]+matriz[i][j-1]+matriz[i][j+1]+matriz[i-1][j]+matriz[i+1][j])/5;
            if(suma>6){
                cont+=1;
                cout<<"en la posicion "<<i<<" "<<j<<" en torno a "<<matriz[i][j]<<" hay una estrella, La suma es: "<<suma<<endl;
            }
        }
    }
    return cont;
}

void RotarMatriz(int matriz[5][5]){
    //cout<<"Hola mundo"<<endl;
    cout<<"Matriz rotada 90 grados: "<<endl<<endl;
    for(int i=0;i<5;i++){
        for(int j=4;j>=0;j--){
            if(matriz[j][i]<10){
            cout<<"| "<<matriz[j][i];
            }
            else{
                cout<<"|"<<matriz[j][i];
            }
        }
        cout<<"|"<<endl;
        cout<<"+--+--+--+--+--+"<<endl;
    }
    cout<<endl;
    cout<<"Matriz rotada 180 grados: "<<endl<<endl;
    for(int i=4;i>=0;i--){
        for(int j=4;j>=0;j--){
            if(matriz[i][j]<10){
                cout<<"| "<<matriz[i][j];
            }
            else{
                cout<<"|"<<matriz[i][j];
            }
        }
        cout<<"|"<<endl;
        cout<<"+--+--+--+--+--+"<<endl;
    }
    cout<<endl;
    cout<<"Matriz rotada 270 grados: "<<endl<<endl;
    for(int i=4;i>=0;i--){
        for(int j=0;j<5;j++){
            if(matriz[j][i]<10){
                cout<<"| "<<matriz[j][i];
            }
            else{
                cout<<"|"<<matriz[j][i];
            }
        }
        cout<<"|"<<endl;
        cout<<"+--+--+--+--+--+"<<endl;
    }
    cout<<endl<<"adios mundo"<<matriz[3][4]<<endl;
}

int* IntersecRectang(int rectangulo1[4],int rectangulo2[4],int rectangulo3[4]){
    int *ref;
    bool resp=true;
    if(rectangulo2[0]>=rectangulo1[0] && rectangulo2[1]>=rectangulo1[1]){
        //casos 2 y 5
        if(rectangulo2[0]+rectangulo2[2]<=rectangulo1[0]+rectangulo1[2] && rectangulo2[1]+rectangulo2[3]<=rectangulo1[1]+rectangulo1[3]){
            for(int i=0;i<4;i++){
                rectangulo3[i]=rectangulo2[i];
            }
        }
        //casos 1 3 4
        else{
            rectangulo3[0]=rectangulo2[0];
            rectangulo3[1]=rectangulo2[1];
            //ancho
            if(rectangulo2[0]==rectangulo1[0] && rectangulo1[2]==rectangulo2[2]){rectangulo3[2]=rectangulo2[2];}
            else {rectangulo3[2]=rectangulo1[0]+rectangulo1[2]-rectangulo2[0];}
            //alto
            if(rectangulo2[1]==rectangulo1[1] && rectangulo1[3]==rectangulo2[3]){rectangulo3[3]=rectangulo2[3];}
            else if(rectangulo2[3]<=rectangulo1[3]-(rectangulo2[1]-rectangulo1[1])){rectangulo3[3]=rectangulo2[3];}
            else {rectangulo3[3]=rectangulo1[1]+rectangulo1[3]-rectangulo2[1];}
        }
    }
    else if(rectangulo1[0]>=rectangulo2[0] && rectangulo1[1]>=rectangulo2[1]){
        if(rectangulo1[0]+rectangulo1[2]<=rectangulo2[0]+rectangulo2[2] && rectangulo1[1]+rectangulo1[3]<=rectangulo2[1]+rectangulo2[3]){
            for(int i=0;i<4;i++){
                rectangulo3[i]=rectangulo1[i];
            }
            cout<<"esta dentro o es igual"<<endl;
        }
        else{
            rectangulo3[0]=rectangulo1[0];
            rectangulo3[1]=rectangulo1[1];
            //ancho
            if(rectangulo1[0]==rectangulo2[0] && rectangulo2[2]==rectangulo1[2]){rectangulo3[2]=rectangulo1[2];}
            else {rectangulo3[2]=rectangulo2[0]+rectangulo2[2]-rectangulo1[0];}
            //alto
            if(rectangulo1[1]==rectangulo2[1] && rectangulo2[3]==rectangulo1[3]){rectangulo3[3]=rectangulo1[3];}
            else if(rectangulo1[3]<=rectangulo2[3]-(rectangulo1[1]-rectangulo2[1])){rectangulo3[3]=rectangulo1[3];}
            else {rectangulo3[3]=rectangulo2[1]+rectangulo2[3]-rectangulo1[1];}
        }
    }
    else{
        if(rectangulo2[0]+rectangulo2[2]>rectangulo1[0] && rectangulo2[1]>rectangulo1[1]){
            rectangulo3[0]=rectangulo1[0];
            rectangulo3[1]=rectangulo2[1];
            rectangulo3[2]=rectangulo2[0]+rectangulo2[2]-rectangulo1[0];
            if(rectangulo2[3]<=rectangulo1[3]-(rectangulo2[1]-rectangulo1[1])){rectangulo3[3]=rectangulo2[3];}
            else{rectangulo3[3]=rectangulo1[1]+rectangulo1[3]-rectangulo2[1];}
        }
        else if(rectangulo1[0]+rectangulo1[2]>rectangulo2[0] && rectangulo1[1]>rectangulo2[1]){
            rectangulo3[0]=rectangulo2[0];
            rectangulo3[1]=rectangulo1[1];
            rectangulo3[2]=rectangulo1[0]+rectangulo1[2]-rectangulo2[0];
            if(rectangulo1[3]<=rectangulo2[3]-(rectangulo1[1]-rectangulo2[1])){rectangulo3[3]=rectangulo1[3];}
            else{rectangulo3[3]=rectangulo2[1]+rectangulo2[3]-rectangulo1[1];}
        }
        else {cout<<"no se intersectan"<<endl;resp=false;}

    }
    if(resp!=false){
        cout<<"x: "<<rectangulo3[0]<<" y: "<<rectangulo3[1]<<" Ancho: "<<rectangulo3[2]<<" Alto: "<<rectangulo3[3]<<endl;}
    ref=&rectangulo3[0];
    return ref;
}
int Factorial(int num)
{
    int fact=1,count=1;
    if(num==0)return 1;
    else{
        while(count<=num){
            fact=fact*count;
            count++;
        }
    }
    return fact;
}

long long int SumadeDivisores(int amg1){
    int suma=0;
    for (int i=1;i<(amg1/2)+1;i++){
        if(amg1%i==0){
            suma+=i;
        }
    }
    return suma;
}

void enesima_permutacion(string str, long int n)
{
    sort(str.begin(), str.end());
    long int i = 1;
    do {
        if (i == n){
            break;
        }
        i++;
    } while (next_permutation(str.begin(), str.end()));
    cout << str<<endl;
}

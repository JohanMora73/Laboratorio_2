#ifndef LAB2_H
#define LAB2_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int ConvCadANum(char[]);
bool CompararCadenas(char[],char[]);
void Char_Int(int, int);
void eliminar_repetidos(char *cad, int lon);//Ejemplo del profesor
void Separar_charYnum(char *cad, int len);
void Separar_nums(char *cad, int len, int n);
void ConvertirRomano(int);
void Cine(char *asientos[15][20], int);
void CuadroMagico(char *cad, int dim);
void MostrarMatriz(int matriz[6][8]);
int ContarEstrellas(int matriz[6][8]);
void RotarMatriz(int matriz[5][5]);
void IntersecRectang(int rectangulo1[4],int rectangulo2[4]);
int* IntersecRectang(int rectangulo1[4],int rectangulo2[4],int rectangulo3[4]);
int Factorial(int);// calcula el factorial de un numero
long long int SumadeDivisores(int);
void enesima_permutacion(string str, long int n);


#endif // LAB2_H

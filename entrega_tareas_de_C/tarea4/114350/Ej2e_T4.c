#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
        copia();
        printf("%s\n", linea_max); 
        }
return 0;
}
 
/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
        linea[i] = c;
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i;
}
 
/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i, j;
    extern char linea[], linea_max[];
    i=0;
    j=strlen(linea)-1;  //strlen te dice el lenght del string, se le resta uno para que no lea el vacio
    while(linea[i] != '\0'){       // Lógica parecida al ejercicio 1 de esta tarea4
        linea_max[i] = linea[j];   // copiar en el arreglo "linea_max" pero con j disminuyendo y pegando al revés
        i++;
        j--;    
    }
}
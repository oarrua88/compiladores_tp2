/*-- Librerias --*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*-- valores por defecto --*/
#define TAMBUFF 	5
#define TAMLEX 		50
#define TAMHASH 	101
#define _TRUE       0
#define _FALSE      1

/*-- definiciones del analizador lexico --*/
typedef enum {TRUE, FALSE} Error;
typedef struct entrada{
	//definir los campos de 1 entrada de la tabla de simbolos
	int compLex;
	char lexema[TAMLEX];	//es lo que apare en elcodigo 
	struct entrada *tipoDato; // null puede representar variable no declarada, otra entrada la tabla de simbolos , no sera usado, por solo analizaremos lexicamente
	// aqui irian mas atributos para funciones y procedimientos...
	
} entrada;

typedef struct {
	int compLex;
	entrada *pe; //tabla de simbolos
} token;

// TIPO DE DATO PARA CONJUNTO PRIMERO Y SIGUIENTE
typedef struct {
	entrada * elem;
	int cantElem; //tabla de simbolos
} conjunto;

/*-- Variables globales --*/
int consumir;			/* 1 indica al analizador lexico que debe devolver
						el sgte componente lexico, 0 debe devolver el actual */

char cad[5*TAMLEX];		// string utilizado para cargar mensajes de error
token t;				// token global para recibir componentes del Analizador Lexico
token t_anterior;		// indica el token anterior

// variables para el analizador lexico
FILE *archivo;			
char buff[2*TAMBUFF];	// Buffer para lectura de archivo fuente
char id[TAMLEX];		// Utilizado por el analizador lexico
int delantero=-1;		// Utilizado por el analizador lexico
int fin=0;				// Utilizado por el analizador lexico
int numLinea=1;			// Numero de Linea
Error HayError= FALSE;

/*-- Prototipos --*/
void sigLex();		

#include "tabsim.h"
#include "anlex.h"
#include "ansintac.h"

/*---------------------------------- Funcion principal ---------------------------------*/

int main(int argc,char* args[])
{
    
	int complex=0;             //iniciar el analizador lexico
	initTabla();
	initTablaSimbolos();

         if(argc > 1)
	     {
    		 if (!(archivo=fopen(args[1],"rt")))
    		 {
    			printf("\tNo se ha encontrado el Archivo..");
    			exit(1);
    		 }
         
             parse();
            
             if(HayError==FALSE){
                 printf("\n Analisis Exitoso. No se encontraron errores.\n");                                  
             }
        
             fclose(archivo);
             system("pause");
       	     return 0;
         }
         else
         {
    		 printf("Debe pasar como parametro el path del archivo fuente.");
    		 exit(1);
	     }    
}

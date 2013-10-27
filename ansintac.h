// no terminales
#define _LISTA_SENTENCIAS     100  
#define _SENTENCIA            101  
#define _ASIGNACION           102  
#define _EXPRESION            103  
#define _EXPRESION_SIMPLE     104  
#define _EXPRESION_LOGICA     105
#define _TERM                 106  
#define _FACTOR               107  
#define _CONDICIONAL          108
#define _DECLARACION          109
#define _ESCRIBIR             110
#define _ESCRIBIR_CON_SALTO   111
#define _REPETIR              112

// incluir
#include "manerror.h"

/*-- procedimientos del parsing --*/
void parse();
void comparar(int);
void esarray();

//*-- una función para cada no terminal --*//
void lista_sentencias();
void sentencia();
void asignacion();
void declaracion();
void condicional();
void expresion_logica();
void expresion();
void expresion_simple();
void term();
void factor();
void escribir();
void escribir_con_salto();
void repetir();

//funciones implementadas
void comparar(int tokenEsperado){
    if (t.compLex==tokenEsperado){
        sigLex();   
    }
    else{
        error(" no se esperaba el token ");
    }
}

/* parsing */
 void parse(){
      sigLex();        
      lista_sentencias();
 } 

/*lista de sentencias*/
void lista_sentencias(){ 
    // RECORRER LA FUENTE HASTA SINCRONIZAR
    check_input(primeros(_LISTA_SENTENCIAS), siguientes(_LISTA_SENTENCIAS));
    
    if(t.compLex!=EOF){
                       
      sentencia();
      while ((t.compLex!=EOF) && 
            (t.compLex!=END) && 
            (t.compLex!=PR_ELSE))
      {        
          comparar(';');
          if((t.compLex!=EOF) && 
             (t.compLex!=END) && 
             (t.compLex!=PR_ELSE)){
                 sentencia();                   
          } 
      } 
    
      // EL ÚLTIMO TOKEN DEBE SER ;
      if (t_anterior.compLex != ';'){ 
        error_sintactico("Se esperaba ;");
      }
    }                              
}

/*eleccion de sentencias */
void sentencia(){
     // RECORRER LA FUENTE HASTA SINCRONIZAR
    check_input(primeros(_SENTENCIA), siguientes(_SENTENCIA));
    switch(t.compLex){    
    case ID : asignacion();break;    
    case PR_IF: condicional();break;
    case PR_FOR: repetir();break;
    case VAR: declaracion();break;
    case ST_WRITE: escribir();break;
    case ST_WRITELN: escribir_con_salto();break;
    case EOF: break;
    
    default: error(" no se esperaba ");
      sigLex();    
      break;
    }     
}

/* sentencia de asignacion */
void asignacion(){
    // RECORRER LA FUENTE HASTA SINCRONIZAR
    check_input(primeros(_ASIGNACION), siguientes(_ASIGNACION));
    if(t.compLex==ID){
        comparar(ID);
        esarray();//si la variable es array
        // SI NO SE ENCUENTRA EL SIMBOLO EMITIR MENSAJE DE FALTA =
        if (t.compLex!=OPASIGNA){
           error_sintactico("se esperaba =");
           sigLex();       
        } else {
          // SI ES EL OPERADOR = PASAR AL SIGUIENTE TOKEN
          sigLex();
        }                                
        expresion();        
    }    
}

/* expresion */
void expresion(){
    // RECORRER LA FUENTE HASTA SINCRONIZAR
    check_input(primeros(_EXPRESION), siguientes(_EXPRESION));
    if(t.compLex==ID || t.compLex=='(' || t.compLex==NUM){                   
       expresion_simple();
       if (t.compLex==OPREL){
         comparar(t.compLex);
         expresion_simple();       
       }
    }   
}

/* expresion simple */
void expresion_simple(){
    // RECORRER LA FUENTE HASTA SINCRONIZAR
    check_input(primeros(_EXPRESION_SIMPLE), siguientes(_EXPRESION_SIMPLE));
    if(t.compLex==ID || t.compLex=='(' || t.compLex==NUM){                 
       term();
       //OPSUMA = +| -
       while(t.compLex==OPSUMA){
          comparar(OPSUMA);
          term();          
       } 
    }
}

/* termino */
void term(){
    check_input(primeros(_TERM), siguientes(_TERM));
    if(t.compLex==ID || t.compLex=='(' || t.compLex==NUM){                 
      factor();
      //OPMULT=*| /
      while(t.compLex==OPMULT){
        comparar(t.compLex);
        factor();                  
      }
    }
}

/* factor */
void factor(){
     check_input(primeros(_FACTOR), siguientes(_FACTOR));
     switch(t.compLex){
        case NUM:
             comparar(NUM);
             break;
        case ID:
             comparar(ID);
             esarray();//nuevalinea
             break;
        case '(':
             comparar('(');
             expresion();     
             comparar(')'); 
             break;
        default :
           error(" no se esperaba ");   
           sigLex();   
           break;                                        
      }     
 }

/* expresion condicional */
void condicional(){
    // RECORRER LA FUENTE HASTA SINCRONIZAR
    check_input(primeros(_CONDICIONAL), siguientes(_CONDICIONAL));
    switch(t.compLex){
        case PR_IF:
           comparar(PR_IF);
           expresion_logica();
           if (t.compLex!=THEN){
              error_sintactico("se esperaba THEN");
              sigLex();       
           } else {
             // SI ES EL OPERADOR PASAR AL SIGUIENTE TOKEN
             sigLex();
             lista_sentencias();
           }       
                                    
           if(t.compLex==PR_ELSE){
              comparar(PR_ELSE);
              lista_sentencias();           
           }
           
           if (t.compLex!=END){
              error_sintactico("se esperaba END");      
           } else {
             // SI ES EL OPERADOR PASAR AL SIGUIENTE TOKEN
             sigLex();
           }  
           
           if (t.compLex!=PR_IF){
                error_sintactico("se esperaba IF");
           } else {
                // SI ES EL OPERADOR PASAR AL SIGUIENTE TOKEN
                sigLex();
           } 
             
           if (t.compLex != ';'){ 
               error_sintactico("Se esperaba ;");
           } 
                      
           break;
        case PR_ELSE:   
           comparar(PR_ELSE);       
           lista_sentencias();
           
          if (t.compLex!=END){
              error_sintactico("se esperaba END");      
           } else {
             // SI ES EL OPERADOR PASAR AL SIGUIENTE TOKEN
             sigLex();
           }  
           
           if (t.compLex!=PR_IF){
                error_sintactico("se esperaba IF");
           } 
             
           if (t.compLex != ';'){ 
               error_sintactico("Se esperaba ;");
           } 

           break;
      default :
           error(" no se esperaba ");   
           sigLex();   
           break;                                        
      }  
}

/* expresion logica */
void expresion_logica(){
     // RECORRER LA FUENTE HASTA SINCRONIZAR
     check_input(primeros(_EXPRESION_LOGICA), siguientes(_EXPRESION_LOGICA));
     if(t.compLex==ID || t.compLex=='(' || t.compLex==NUM){
         expresion();
         if(t.compLex==OPERLOGIC){
           comparar(OPERLOGIC);
           expresion();        
         }
     }                                            
}

/* sentencia de declaración */
void declaracion(){
     // RECORRER LA FUENTE HASTA SINCRONIZAR
     check_input(primeros(_DECLARACION), siguientes(_DECLARACION));
     if(t.compLex==VAR){
        comparar(VAR);
        comparar(ID);
        esarray();         
        while(t.compLex==','){
           comparar(',');
           comparar(ID);
           esarray();                        
        }
     }
}

void esarray(){
    if (t.compLex=='['){
       comparar('[');
       expresion_simple(); 
       if (t.compLex!=']'){
           error_sintactico("se esperaba ]");
       } else {
           // SI ES EL TOKEN PASAR AL SIGUIENTE
           sigLex();
       }       
    }    
}

void escribir(){
     // RECORRER LA FUENTE HASTA SINCRONIZAR
     check_input(primeros(_ESCRIBIR), siguientes(_ESCRIBIR));
     if(t.compLex==ST_WRITE){
         comparar(ST_WRITE);
         if (t.compLex!='('){
           error_sintactico("se esperaba (");   
         } else {
           // SI ES EL TOKEN PASAR AL SIGUIENTE
           sigLex();
         }
         
         if(t.compLex==LITERAL){
            comparar(LITERAL);                                           
         }else{
            factor();
         }
         
         if (t.compLex!=')'){
           error_sintactico("se esperaba )");   
         } else {
           // SI ES EL TOKEN PASAR AL SIGUIENTE
           sigLex();
         }
     }
}

void escribir_con_salto(){
     // RECORRER LA FUENTE HASTA SINCRONIZAR
     check_input(primeros(_ESCRIBIR_CON_SALTO), siguientes(_ESCRIBIR_CON_SALTO));
     if(t.compLex==ST_WRITELN){
         comparar(ST_WRITELN);
         if (t.compLex!='('){
           error_sintactico("se esperaba (");   
         } else {
           // SI ES EL TOKEN PASAR AL SIGUIENTE
           sigLex();
         }
         
         if(t.compLex==LITERAL){
            comparar(LITERAL);                                           
         }else{
            factor();
         }
         
         if (t.compLex!=')'){
           error_sintactico("se esperaba )");   
         } else {
           // SI ES EL TOKEN PASAR AL SIGUIENTE
           sigLex();
         }
     }
}

/* repetir */
void repetir(){
    check_input(primeros(_REPETIR), siguientes(_REPETIR));
    if(t.compLex==PR_FOR){ 
         comparar(PR_FOR);
         asignacion();
         if (t.compLex!=TO){
             error_sintactico("se esperaba TO");
             sigLex();       
         } else {
             // SI ES EL OPERADOR PASAR AL SIGUIENTE TOKEN
             sigLex();
             factor();     
         }  

         if (t.compLex!=STEP){
             error_sintactico("se esperaba STEP");
             sigLex();       
         } else {
             // SI ES EL OPERADOR PASAR AL SIGUIENTE TOKEN
             sigLex();
             factor();
         }  
         
         if (t.compLex!=PR_DO){
             error_sintactico("se esperaba DO");     
         } else {
             // SI ES EL OPERADOR PASAR AL SIGUIENTE TOKEN
             sigLex();
         }  
         
         if(t.compLex!=END){
           lista_sentencias();
         }
         
         if (t.compLex!=END){
            error_sintactico("se esperaba END");
         } else {
             // SI ES EL OPERADOR PASAR AL SIGUIENTE TOKEN
             sigLex();
         }       
         
         if (t.compLex!=PR_FOR){
            error_sintactico("se esperaba FOR");
         } else {
             // SI ES EL OPERADOR PASAR AL SIGUIENTE TOKEN
             sigLex();
         }       
    }
}
 




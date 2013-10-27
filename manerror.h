
/* conjuntos primeros */  
conjunto primeros(int noTerminal)
{
  conjunto _primero;
  if (noTerminal == _LISTA_SENTENCIAS){
     _primero.cantElem = 7;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = VAR;
     sprintf(_primero.elem[0].lexema,"VAR");
     _primero.elem[1].compLex = PR_IF;
     sprintf(_primero.elem[1].lexema,"if");
     _primero.elem[2].compLex = PR_FOR;
     sprintf(_primero.elem[2].lexema,"for");
     _primero.elem[3].compLex = ST_WRITE;
     sprintf(_primero.elem[3].lexema,"write");
     _primero.elem[4].compLex = ST_WRITELN;
     sprintf(_primero.elem[4].lexema,"writeln");
     _primero.elem[5].compLex = ID;
     sprintf(_primero.elem[5].lexema,"identificador");
     _primero.elem[6].compLex = PR_DO;
     sprintf(_primero.elem[6].lexema,"do");
  } else if (noTerminal == _SENTENCIA){
     _primero.cantElem = 7;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = ID;
     sprintf(_primero.elem[0].lexema,"identificador");
     _primero.elem[1].compLex = PR_IF;
     sprintf(_primero.elem[1].lexema,"if");
     _primero.elem[2].compLex = PR_FOR;
     sprintf(_primero.elem[2].lexema,"for");
     _primero.elem[3].compLex = ST_WRITE;
     sprintf(_primero.elem[3].lexema,"write");
     _primero.elem[4].compLex = ST_WRITELN;
     sprintf(_primero.elem[4].lexema,"writeln");
     _primero.elem[5].compLex = VAR;
     sprintf(_primero.elem[5].lexema,"var");
     _primero.elem[6].compLex = PR_DO;
     sprintf(_primero.elem[6].lexema,"do");
    } else if (noTerminal == _ASIGNACION){
     _primero.cantElem = 1;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = ID;
     sprintf(_primero.elem[0].lexema,"identificador");
    } else if (noTerminal == _EXPRESION){
     _primero.cantElem = 3;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = ID;
     sprintf(_primero.elem[0].lexema,"identificador");
     _primero.elem[1].compLex = NUM;
     sprintf(_primero.elem[1].lexema,"numero");
     _primero.elem[2].compLex = '(';
     sprintf(_primero.elem[2].lexema,"(");
    } else if (noTerminal == _EXPRESION_SIMPLE){
     _primero.cantElem = 3;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = ID;
     sprintf(_primero.elem[0].lexema,"identificador");
     _primero.elem[1].compLex = NUM;
     sprintf(_primero.elem[1].lexema,"numero");
     _primero.elem[2].compLex = '(';
     sprintf(_primero.elem[2].lexema,"(");
    } else if (noTerminal == _EXPRESION_LOGICA){
     _primero.cantElem = 3;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = ID;
     sprintf(_primero.elem[0].lexema,"identificador");
     _primero.elem[1].compLex = NUM;
     sprintf(_primero.elem[1].lexema,"numero");
     _primero.elem[2].compLex = '(';
     sprintf(_primero.elem[2].lexema,"(");
    } else if (noTerminal == _TERM){
     _primero.cantElem = 3;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = ID;
     sprintf(_primero.elem[0].lexema,"identificador");
     _primero.elem[1].compLex = NUM;
     sprintf(_primero.elem[1].lexema,"numero");
     _primero.elem[2].compLex = '(';
     sprintf(_primero.elem[2].lexema,"(");
    } else if (noTerminal == _FACTOR){
     _primero.cantElem = 3;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = ID;
     sprintf(_primero.elem[0].lexema,"identificador");
     _primero.elem[1].compLex = NUM;
     sprintf(_primero.elem[1].lexema,"numero");
     _primero.elem[2].compLex = '(';
     sprintf(_primero.elem[2].lexema,"(");
    } else if (noTerminal == _CONDICIONAL){
     _primero.cantElem =1;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = PR_IF;
     sprintf(_primero.elem[0].lexema,"if");
    } else if (noTerminal == _DECLARACION){
     _primero.cantElem =1;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = VAR;
     sprintf(_primero.elem[0].lexema,"var");
   } else if (noTerminal == _ESCRIBIR){
     _primero.cantElem =1;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = ST_WRITE;
     sprintf(_primero.elem[0].lexema,"write(");
   } else if (noTerminal == _ESCRIBIR_CON_SALTO){
     _primero.cantElem =1;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = ST_WRITELN;
     sprintf(_primero.elem[0].lexema,"writeln(");
   } else if (noTerminal == _REPETIR){
     _primero.cantElem =1;
     _primero.elem=(entrada *) malloc(_primero.cantElem*sizeof(entrada));
     // ELEMENTOS
     _primero.elem[0].compLex = PR_FOR;
     sprintf(_primero.elem[0].lexema,"for");
   }                 
                             
   return _primero;
}

conjunto siguientes(int noTerminal)
{
  conjunto _siguiente;
  if (noTerminal == _LISTA_SENTENCIAS){
     _siguiente.cantElem = 8;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // ELEMENTOS
     _siguiente.elem[0].compLex = VAR;
     sprintf(_siguiente.elem[0].lexema,"VAR");
     _siguiente.elem[1].compLex = PR_IF;
     sprintf(_siguiente.elem[1].lexema,"if");
     _siguiente.elem[2].compLex = PR_FOR;
     sprintf(_siguiente.elem[2].lexema,"for");
     _siguiente.elem[3].compLex = ST_WRITE;
     sprintf(_siguiente.elem[3].lexema,"write");
     _siguiente.elem[4].compLex = ST_WRITE;
     sprintf(_siguiente.elem[4].lexema,"writeln");
     _siguiente.elem[5].compLex = ID;
     sprintf(_siguiente.elem[5].lexema,"identificador");                 
     _siguiente.elem[6].compLex =EOF;
     sprintf(_siguiente.elem[6].lexema,"EOF");   
     _siguiente.elem[7].compLex =PR_DO;
     sprintf(_siguiente.elem[7].lexema,"do");                 
  } else if (noTerminal == _SENTENCIA){
     _siguiente.cantElem = 2;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // )
     _siguiente.elem[0].compLex = EOF;
     sprintf(_siguiente.elem[0].lexema,"EOF");
     // ;
     _siguiente.elem[1].compLex = ';';
     sprintf(_siguiente.elem[1].lexema,";");
  } else if(noTerminal == _ASIGNACION){
     _siguiente.cantElem = 2;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // TO
     _siguiente.elem[0].compLex = TO;
     // ;
     _siguiente.elem[1].compLex = ';';
     sprintf(_siguiente.elem[1].lexema,";");
  } else if (noTerminal == _EXPRESION){        
     _siguiente.cantElem = 5;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // )
     _siguiente.elem[0].compLex = ')';
     sprintf(_siguiente.elem[0].lexema,")");
     // AND | OR
     _siguiente.elem[1].compLex = OPREL;
     sprintf(_siguiente.elem[1].lexema,"operador relacional");
     // + | -
     _siguiente.elem[2].compLex = OPSUMA;
     sprintf(_siguiente.elem[2].lexema,"operador aritmetico");
     // * | /
     _siguiente.elem[3].compLex = OPMULT;
     sprintf(_siguiente.elem[3].lexema,"operador multiplicativo");
     // ;
     _siguiente.elem[4].compLex = ';';
     sprintf(_siguiente.elem[4].lexema,";");
    } else if (noTerminal == _EXPRESION_SIMPLE){        
     _siguiente.cantElem = 5;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // )
     _siguiente.elem[0].compLex = ')';
     sprintf(_siguiente.elem[0].lexema,")");
     // AND | OR
     _siguiente.elem[1].compLex = OPREL;
     sprintf(_siguiente.elem[1].lexema,"operador relacional");
     // + | -
     _siguiente.elem[2].compLex = OPSUMA;
     sprintf(_siguiente.elem[2].lexema,"operador aritmetico");
     // * | /
     _siguiente.elem[3].compLex = OPMULT;
     sprintf(_siguiente.elem[3].lexema,"operador multiplicativo");
     // ;
     _siguiente.elem[4].compLex = ';';
     sprintf(_siguiente.elem[4].lexema,";");
    } else if (noTerminal == _EXPRESION_LOGICA){        
     _siguiente.cantElem = 5;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // )
     _siguiente.elem[0].compLex = ')';
     sprintf(_siguiente.elem[0].lexema,")");
     // AND | OR
     _siguiente.elem[1].compLex = OPREL;
     sprintf(_siguiente.elem[1].lexema,"operador relacional");
     // + | -
     _siguiente.elem[2].compLex = OPSUMA;
     sprintf(_siguiente.elem[2].lexema,"operador aritmetico");
     // * | /
     _siguiente.elem[3].compLex = OPMULT;
     sprintf(_siguiente.elem[3].lexema,"operador multiplicativo");
     // ;
     _siguiente.elem[4].compLex = ';';
     sprintf(_siguiente.elem[4].lexema,";");
   } else if (noTerminal == _TERM){        
     _siguiente.cantElem = 5;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // )
     _siguiente.elem[0].compLex = ')';
     sprintf(_siguiente.elem[0].lexema,")");
     // AND | OR
     _siguiente.elem[1].compLex = OPREL;
     sprintf(_siguiente.elem[1].lexema,"operador relacional");
     // + | -
     _siguiente.elem[2].compLex = OPSUMA;
     sprintf(_siguiente.elem[2].lexema,"operador aritmetico");
     // * | /
     _siguiente.elem[3].compLex = OPMULT;
     sprintf(_siguiente.elem[3].lexema,"operador multiplicativo");
     // ;
     _siguiente.elem[4].compLex = ';';
     sprintf(_siguiente.elem[4].lexema,";");
   } else if (noTerminal == _FACTOR){        
     _siguiente.cantElem = 5;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // )
     _siguiente.elem[0].compLex = ')';
     sprintf(_siguiente.elem[0].lexema,")");
     // AND | OR
     _siguiente.elem[1].compLex = OPREL;
     sprintf(_siguiente.elem[1].lexema,"operador relacional");
     // + | -
     _siguiente.elem[2].compLex = OPSUMA;
     sprintf(_siguiente.elem[2].lexema,"operador aritmetico");
     // * | /
     _siguiente.elem[3].compLex = OPMULT;
     sprintf(_siguiente.elem[3].lexema,"operador multiplicativo");
     // ;
     _siguiente.elem[4].compLex = ';';
     sprintf(_siguiente.elem[4].lexema,";");
   } else if (noTerminal == _CONDICIONAL){        
     _siguiente.cantElem = 3;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // ELSE
     _siguiente.elem[0].compLex = PR_ELSE;
     sprintf(_siguiente.elem[0].lexema,"else");
     // END
     _siguiente.elem[1].compLex = END;
     sprintf(_siguiente.elem[1].lexema,"end");
     // ;
     _siguiente.elem[2].compLex = ';';
     sprintf(_siguiente.elem[2].lexema,";");
   } else if (noTerminal == _ESCRIBIR){        
     _siguiente.cantElem = 2;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // )
     _siguiente.elem[0].compLex = ')';
     sprintf(_siguiente.elem[0].lexema,")");
     // ;
     _siguiente.elem[1].compLex = ';';
     sprintf(_siguiente.elem[1].lexema,";");
   } else if (noTerminal == _ESCRIBIR_CON_SALTO){        
     _siguiente.cantElem = 2;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // )
     _siguiente.elem[0].compLex = ')';
     sprintf(_siguiente.elem[0].lexema,")");
     // ;
     _siguiente.elem[1].compLex = ';';
     sprintf(_siguiente.elem[1].lexema,";");
  } else if (noTerminal == _REPETIR){        
     _siguiente.cantElem = 2;
     _siguiente.elem=(entrada *) malloc(_siguiente.cantElem*sizeof(entrada));
     // )
     _siguiente.elem[0].compLex = END;
     sprintf(_siguiente.elem[0].lexema,"END");
     // ;
     _siguiente.elem[1].compLex = ';';
     sprintf(_siguiente.elem[1].lexema,";");
  }

  return _siguiente;
}

int buscar_token_sincronizador(conjunto siguiente){
    // BUSCAR SI EL TOKEN ACTUAL ESTA EN EL CONJUNTO PRIMERO
    int i=0;
    int _esta = _FALSE;
    
   	while(i < siguiente.cantElem && _esta == _FALSE){
        if(t.compLex == siguiente.elem[i].compLex)
        {
           _esta = _TRUE;
        }
        i++;                
    }
    return _esta;
}

void sincronizar(conjunto _siguiente){
   // RECORRER HASTA ENCONTRAR TOKEN SINCRONIZADOR
   while((buscar_token_sincronizador(_siguiente) == _FALSE) &&
        (t.compLex!=EOF)){
      sigLex(); 
   }	    
}

void check_input(conjunto primero, conjunto siguiente){
    // BUSCAR SI EL TOKEN ACTUAL ESTA EN EL CONJUNTO PRIMERO
    int i=0;
    int _esta = _FALSE;
    
   	while(i < primero.cantElem && _esta == _FALSE){
        if(t.compLex == primero.elem[i].compLex)
        {
           _esta = _TRUE;
        }
        i++;                
    }	
    
    // EMITIR UN ERROR SI EL TOKEN NO SE ENCUENTRA EN EL CONJUNTO PRIMERO
    if(_esta == _FALSE){
       printf("Lin %d: %s==>'%s'\n",numLinea,"se esperaba el token: ", primero.elem[0].lexema);
       HayError=TRUE;
       // SINCRONIZAR
       sincronizar(siguiente);        
    }
}

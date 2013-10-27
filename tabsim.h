
//Codigos
#define VAR			256  //var 

/*if then else */
#define PR_IF		257 // if  
#define THEN		258 //then 
#define PR_ELSE		259 //else 

/*for to step do */ 
#define PR_FOR		260 //for 
#define TO			261 //to 
#define STEP		262 //st   
#define PR_DO		263 //do   

/*end , que sera usado asi 'end if' o 'end for'*/
#define END			264 //end 

/*do write */
#define ST_WRITE    265 //WRITE  
#define ST_WRITELN  266 //WRITE  

/*token de conjuntos de caracteres*/
#define NUM			267 //numero
#define ID			268 //identificador
#define LITERAL		269 //literal "as"

/*operador de asignacion*/
#define OPASIGNA	270

/*tokens simples operadores */
#define OPREL		270 //<=, >=, ==
#define OPSUMA		271 //+,- 
#define OPMULT		272 //* /
#define OPERLOGIC   273 // or and



/*----- HASH -----*/
entrada *tabla;				//declarar la tabla de simbolos
int tamTabla=TAMHASH;		//utilizado para cuando se debe hacer rehash
int elems=0;				//utilizado para cuando se debe hacer rehash

int h(char* k, int m)
{
	unsigned h=0,g;
	int i;
	for (i=0;i<strlen(k);i++)
	{
		h=(h << 4) + k[i];
		if (g=h&0xf0000000){
			h=h^(g>>24);
			h=h^g;
		}
	}
	return h%m;
}
void insertar(entrada e);

void initTabla()
{	
	int i=0;
	
	tabla=(entrada*)malloc(tamTabla*sizeof(entrada));
	for(i=0;i<tamTabla;i++)
	{
		tabla[i].compLex=-1;
	}
}

int esprimo(int n)
{
	int i;
	for(i=3;i*i<=n;i+=2)
		if (n%i==0)
			return 0;
	return 1;
}

int siguiente_primo(int n)
{
	if (n%2==0)
		n++;
	for (;!esprimo(n);n+=2);

	return n;
}

//en caso de que la tabla llegue al limite, duplicar el tamaño
void rehash()
{
	entrada *vieja;
	int i;
	vieja=tabla;
	tamTabla=siguiente_primo(2*tamTabla);
	initTabla();
	for (i=0;i<tamTabla/2;i++)
	{
		if(vieja[i].compLex!=-1)
			insertar(vieja[i]);
	}		
	free(vieja);
}

//insertar una entrada en la tabla
void insertar(entrada e)
{
	int pos;
	if (++elems>=tamTabla/2)
		rehash();
	pos=h(e.lexema,tamTabla);
	while (tabla[pos].compLex!=-1)
	{
		pos++;
		if (pos==tamTabla)
			pos=0;
	}
	tabla[pos]=e;

}
//busca una clave en la tabla, si no existe devuelve NULL, posicion en caso contrario
entrada* buscar(char *clave)
{
	int pos;
	entrada *e;
	pos=h(clave,tamTabla);
	while(tabla[pos].compLex!=-1 && stricmp(tabla[pos].lexema,clave)!=0 )
	{
		pos++;
		if (pos==tamTabla)
			pos=0;
	}
	return &tabla[pos];
}

void insertTablaSimbolos(char *s, int n)
{
	entrada e;
	sprintf(e.lexema,s);
	e.compLex=n;
	insertar(e);
}

void initTablaSimbolos()
{
	int i;
	entrada pr,*e;
	char *vector[]={
	"var",
    "if", 
    "then", 
    "else",
	"for", 
    "to", 
    "step", 
    "do",
    "end",
    "write",	
    "writeln",
  	};
  	//rango de 0 a 9 , para tomar solo las palabras reservadas
 	for (i=0;i<10;i++)
	{
		insertTablaSimbolos(vector[i],i+256);
//			printf("\n %s ->%d",vector[i],i+256);
	}
	//notese que el numero correpondiente a los parentesis y corchetes
	//es su mismo numero de ascii, aprovechando que son caracteres unitarios
    insertTablaSimbolos(",",',');
	insertTablaSimbolos(".",'.');
	insertTablaSimbolos(";",';');
	insertTablaSimbolos("(",'(');
	insertTablaSimbolos(")",')');
	insertTablaSimbolos("[",'[');
	insertTablaSimbolos("]",']');
	insertTablaSimbolos("<",OPREL);
	insertTablaSimbolos("<=",OPREL);
	insertTablaSimbolos("<>",OPREL);
	insertTablaSimbolos("==",OPREL);
	insertTablaSimbolos(">",OPREL);
	insertTablaSimbolos(">=",OPREL);
	insertTablaSimbolos("=",OPASIGNA);
	insertTablaSimbolos("+",OPSUMA);
	insertTablaSimbolos("-",OPSUMA);
	insertTablaSimbolos("or",OPSUMA);
	insertTablaSimbolos("*",OPMULT);
	insertTablaSimbolos("/",OPMULT);
	insertTablaSimbolos("and",OPERLOGIC);
	insertTablaSimbolos("AND",OPERLOGIC);
	insertTablaSimbolos("or",OPERLOGIC);
	insertTablaSimbolos("OR",OPERLOGIC);
 	insertTablaSimbolos("write",ST_WRITELN);
	insertTablaSimbolos("WRITE",ST_WRITE);
 	insertTablaSimbolos("writeln",ST_WRITELN);
 	insertTablaSimbolos("WRITELN",ST_WRITELN);
 	insertTablaSimbolos("IF",PR_IF);
    insertTablaSimbolos("VAR",VAR);
    insertTablaSimbolos("THEN",THEN);
    insertTablaSimbolos("END",END);
    insertTablaSimbolos("ELSE",PR_ELSE);
    insertTablaSimbolos("FOR",PR_FOR);
   	insertTablaSimbolos("TO",TO);
   	insertTablaSimbolos("STEP",STEP);
   	insertTablaSimbolos("DO",PR_DO);
}

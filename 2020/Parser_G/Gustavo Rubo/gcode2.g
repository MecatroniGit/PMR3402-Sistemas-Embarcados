grammar gcode2;


prg
 	:	statement+ fimprograma
	;
	
fimprograma 
	:	numerolinha mfim
	;
		
statement 
	:	numerolinha codfunc coordx coordy fimdelinha
	|	numerolinha mfunc fimdelinha
	|   fimdelinha
	;

numerolinha 
	:	'N' INT INT INT?
	;

mfim
 	:	'M30'
	;
	
mfunc 
	:	'M02'
	|	'M01'
	;
	
codfunc
	:	'G01'
	|	'G00'
	;

coord
	:   INT INT? INT?
	;
	
coordx
	:	'X'coord
	;

coordy
	:	'Y'coord
	;
		

fimdelinha 	:	'\r'? '\n'  ;

			
INT :	'0'..'9'
    ;
	
ID  :   [a-z]+  ;
WS : [ \t]+ -> skip ;
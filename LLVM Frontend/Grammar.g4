grammar Grammar;

program: funDecl+ EOF;

funDecl: 'let' ID '(' ID* ')' '->' (NUM | VOID) '=' '{' line+ '}';
line: (expr | assign | create | returnExpr) ';' | forExpr | ifExpr | whileExpr;
forExpr: 'for' ('[' ID ',' expr ',' expr ']')+ '{' line+ '}';
ifExpr: 'if' '[' expr ']' '{' line+ '}';
whileExpr: 'while' '[' expr ']' '{' line+ '}';
expr: 	ID funParams |
		ID ('['expr (',' expr)* ']')? | 
		TERN_OP '(' expr ',' expr ',' expr ')'| 
		BIN_OP '(' expr ',' expr ')'|
		INT;
funParams: '(' (expr (',' expr)*)? ')';
assign: ID ('['expr (',' expr)* ']')? '=' expr;
create: varDecl | arrDecl;
varDecl: NUM ID '=' expr;
arrDecl: 'arr' '['INT (',' INT)* ']' ID;
returnExpr: 'return' expr?;

NUM: 'num';
VOID: 'void';
TERN_OP: '?';
BIN_OP: '==' | '!=' | '||' | '|' | '%' | '*' | '+' | '&&' | '&' | '/';
ID: [a-zA-Z_][a-zA-Z_0-9]*;
INT: '-'?('0'|([1-9][0-9]*));
WS: [ \t\r\n]+ -> skip;
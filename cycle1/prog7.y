% token DIGIT LETTER NL UND
%%
stmt : variable NL {
printf ("\ nValid id\n\n") ; exit (0) ;}
;
variable : LETTER alphanumeric
;
alphanumeric : LETTER alphanumeric
| DIGIT alphanumeric
| UND alphanumeric
| LETTER
| DIGIT
| UND
;
%%
int yyerror ( char * msg )
{
printf ("\ nINVALID \n") ;
exit (0) ;
}
void main ()
{
printf (" Enter id : ") ;
yyparse () ;
}

#include "tc.h"

int countch(char *f, char *t, char c){
	int k=1;   /* start on line 1 */
	while( f++ <= t) if(*f==c) ++k;
	return k;
}
/*	Prints end of program message, "done" if no error, else code and 
 *	line with error and carot under.
 */
void whatHappened() {
	if(error==KILL) errToWords();
	else if(error){
		char *fc, *lc;
		int firstSignif=0, blanks, lineno;
		if(*errat==0x0a||*errat==0x0d)--errat;
		if(errat<apr){
			lineno = countch(pr,errat,0x0a);
			if(!lineno)lineno = countch(pr,errat,0x0d);
			printf("\nlib ");
		}
		else {
			lineno = countch(apr,errat,0x0a);
			if(!lineno)lineno = countch(apr,errat,0x0d);
			printf("\napp ");
		}
		printf("line %d (cursor pr[%d])", lineno,errat-pr); errToWords();
		fc=fchar(errat);
		while((*(fc+firstSignif))==' ' ||(*(fc+firstSignif))=='\t' )
			 ++firstSignif;
		lc=lchar(errat);
/*		fc=fc-1;
*/
		pft(fc,lc);
		printf("\n");
		pft(fc,fc+firstSignif-1);        /* leading whitespace */
		blanks=errat-fc-firstSignif-1;   /* blanks to carot */
		while(--blanks >= 0) printf(" ");
		printf("^\n");
	}
	else {
		printf("\ndone\n");
	}
}

void showLine(char *line) {
		char *fc, *lc;
		fc=fchar(line);
		lc=lchar(line);
		pft(fc,lc);
}

void errToWords(){
	char *x;
	switch(error){
		case 2: x="CURSERR, cursor out of range"; break;
		case 3: x="SYMERR, decl needed"; break;
		case 1: x="STATERR"; break;
		case 5: x="RPARERR, ) missing"; break;
		case 6: x="RANGERR, subscript out of range"; break;
		case 7: x="CLASERR"; break;
		case 8: x="TYPEERR"; break;
		case 9: x="SYNXERR"; break;
		case 14: x="LVALERR, not assignable"; break;
		case 15: x="POPERR, nothing to pop"; break;
		case 16: x="PUSHERR, overlowed stack area"; break;
		case 17: x="TMFUERR, overflowed function table"; break;
		case 18: x="TMVRERR, overflowed variable table"; break;
		case 19: x="TMVLERR, overflowed available space for values"; break;
		case 20: x="LINKERR"; break;
		case 21: x="ARGSERR, args don't match"; break;
		case 22: x="LBRCERR, [ required"; break;
		case 23: x="RBRCERR, ] required somewhere"; break;
		case 24: x="MCERR, no such MC"; break;
		case 26: x="SYMERRA, decl needed"; break;
		case 27: x="EQERR, illegal assign"; break;
		case 28: x="PTRERR"; break;
		case 99: x="KILL, stopped by user"; break;
	}
	printf("%s\n",x);
}

/************ simple prints ******************/
void ps(char* s) {printf("%s",s);}
void pl(char* s) {printf("\n%s",s);}
int  pn(int n)   {printf("%d", n);return n;}
void pc(char c)  {printf("%c", c);}

void logo() {
	printf(
"***  TINY-C VERSION 1.0,  COPYRIGHT 1977, T A GIBSON  ***\n"
		);
	printf(
"        This C version copyright 2017, T A Gibson\n"
		);
}

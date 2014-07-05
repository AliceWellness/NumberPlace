#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>			/* Standard In/Out */
#include <memory.h>			/* memset—p */
#include <stdlib.h>			/* system("pause")—p */

/* ”Õ–ÊƒTƒCƒY */
#define SIZE 9

/* ¬Œ÷/¸”s’è‹` */
enum BOOL
{
	FALSE = 0,	/* ¸”s */
	TRUE = 1	/* ¬Œ÷ */
};

/* ”Õ–Êƒf[ƒ^\‘¢ */
struct nplace
{
	short num[SIZE][SIZE];	/* ”Õ–Ê‚Ì”š */
	short flg[SIZE][SIZE];	/* ƒtƒ‰ƒO‚Æ‚© */
};

<<<<<<< HEAD
/* ç›¤é¢å‡ºåŠ›é–¢æ•° */
=======
/* ”Õ–Êo—ÍŠÖ” */
>>>>>>> Add "struct" + "enum"
void printnpl(const struct nplace *pnpl)
{
	int i, j;						/* ƒ‹[ƒv—p */
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			printf("%d", pnpl->num[i][j]);
		}
		printf("\n");				/* ‰üs */
	}
	system("pause;");
	return;
}

<<<<<<< HEAD
/* ç›¤é¢å…¥åŠ›é–¢æ•°(å¤±æ•—=FALSE, æˆåŠŸ=TRUE) */
BOOL putnum(struct nplace *pnpl, int x, int y, int n)
=======
/* ”Õ–Ê“ü—ÍŠÖ”(¸”s=FALSE, ¬Œ÷=TRUE) */
enum BOOL putnum(struct nplace *pnpl, int x, int y, int n)
>>>>>>> Add "struct" + "enum"
{
	int i, j;
	for(i = 0; i < SIZE; i++){			/* ‰¡•ûŒüŠm”F */
		if(pnpl->num[i][y] == n){		/* ‚à‚µˆê’v‚·‚éƒ}ƒX‚ª‚ ‚é‚È‚ç */
			pnpl->flg[x][y] |= 1 << n;	/* “ü‚ç‚È‚¢ */
			return FALSE;
		}
	}
	for(i = 0; i < SIZE; i++){			/* c•ûŒüŠm”F */
		if(pnpl->num[x][i] == n){		/* ‚à‚µˆê’v‚·‚éƒ}ƒX‚ª‚ ‚é‚È‚ç */
			pnpl->flg[x][y] |= 1 << n;	/* “ü‚ç‚È‚¢ */
			return FALSE;
		}
	}
<<<<<<< HEAD
	for(i = (x/3)*3; i <= ((x/3)*3)+2; i++){ 	/* å…¥åŠ›ãƒã‚¹ãŒå«ã¾ã‚Œã‚‹ä¸‰ãƒã‚¹ã‚’ç¢ºèªã™ã‚‹ */
=======
	for(i = (x/3)*3; i <= ((x/3)*3)+2; i++){ 	/* “ü—Íƒ}ƒX‚ªŠÜ‚Ü‚ê‚éOƒ}ƒX‚ğŠm”F‚·‚é */
>>>>>>> Add "struct" + "enum"
		for(j = (y/3)*3; j <= ((y/3)*3)+2; j++){
			if(pnpl->num[i][j] == n){			/* ‚à‚µˆê’v‚·‚éƒ}ƒX‚ª‚ ‚é‚È‚ç */
				pnpl->flg[x][y] |= 1 << n;		/* “ü‚ç‚È‚¢ */
				return FALSE;
			}
		}
	}
	pnpl->num[x][y] = n;				/* ‘ã“ü */
	return TRUE;
}

<<<<<<< HEAD
/* å…¨ãƒã‚¹ãŒåŸ‹ã¾ã£ã¦ã‚‹ã‹ç¢ºèªã™ã‚‹é–¢æ•° */
BOOL allchecked(struct nplace *pnpl)
=======
/* ‘Sƒ}ƒX‚ª–„‚Ü‚Á‚Ä‚é‚©Šm”F‚·‚éŠÖ” */
enum BOOL allchecked(struct nplace *pnpl)
>>>>>>> Add "struct" + "enum"
{
	int i, j;
	/* ‘Sƒ}ƒX‚ª–„‚Ü‚Á‚Ä‚é‚©Šm”F */
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			/* –„‚Ü‚Á‚Ä‚È‚¢ƒ}ƒX‚ª‚ ‚é‚È‚ç */
			if(pnpl->num[i][j] == 0){
				/* –„‚Ü‚Á‚Ä‚È‚¢ */
				return FALSE;
			}
		}
	}
	/* –„‚Ü‚Á‚Ä‚¢‚é */
	return TRUE;
}

<<<<<<< HEAD
/* ãƒŠãƒ³ãƒãƒ¼ãƒ—ãƒ¬ãƒ¼ã‚¹ã‚’è§£ãé–¢æ•° */
=======
/* ƒiƒ“ƒo[ƒvƒŒ[ƒX‚ğ‰ğ‚­ŠÖ” */
>>>>>>> Add "struct" + "enum"
void solve(struct nplace *pnpl, int x, int y)
{
	int i;
	/* ‘S•”–„‚Ü‚Á‚Ä‚é‚©‚Ç‚¤‚©Šm”F‚·‚é */
	if(allchecked(pnpl) == TRUE){
		/* –„‚Ü‚Á‚Ä‚½‚çŒ‹‰Êo—Í */
		printnpl(pnpl);
<<<<<<< HEAD
		/* çµ‚äº† */
=======
		/* I—¹ */
>>>>>>> Add "struct" + "enum"
		return;
	}
	/* Œ©‚Â‚©‚é‚Ü‚Åƒ‹[ƒv‚³‚¹‚é */
	while(pnpl->num[x][y] != 0){
		x = (x + 1)%SIZE;	/* x‚ğˆê‚Â‰¡‚É‚¸‚ç‚· */
		if(x == 0){			/* ˆêü‚µ‚½‚ç */
			y = (y+1)%SIZE;	/* y‚ğˆê‚Âc‚É‚¸‚ç‚· */
		}
	}
	/* ‚»‚Ì’l‚Ì”š‚ª“ü‚é‚©‚Ç‚¤‚©ƒ`ƒFƒbƒN */
	for(i = 1; i <= 9; i++){
		/* ‚à‚µ“ü‚é‚æ‚¤‚È‚ç */
		if((pnpl->flg[x][y] & (1 << i)) == 0){
<<<<<<< HEAD
			/* ä»®å®šç”¨ã‚’ä½œæˆ */
			nplace tmpnpl = *pnpl;
			/* ä»£å…¥ */
=======
			/* ‰¼’è—p‚ğì¬ */
			struct nplace tmpnpl = *pnpl;
			/* ‘ã“ü */
>>>>>>> Add "struct" + "enum"
			if(putnum(&tmpnpl, x, y, i)){
				/* Ä‹A */
				solve(&tmpnpl, x, y);
			}
		}
	}
	return;
}

<<<<<<< HEAD
/* ãƒ•ã‚¡ã‚¤ãƒ«ã‚’é–‹ã„ã¦è§£æã™ã‚‹ */
void readFile(char path[], nplace* lpnp)
=======
/* ƒtƒ@ƒCƒ‹‚ğŠJ‚¢‚Ä‰ğÍ‚·‚é */
void readFile(char path[], struct nplace* lpnp)
>>>>>>> Add "struct" + "enum"
{
	int i, j;
	/* ƒtƒ@ƒCƒ‹ƒnƒ“ƒhƒ‹ */
	FILE* fp;
	/* “Ç‚İ‚Ş•¶š—ñ */
	char readStr[64] = { '\0' };
	/* ŠJ‚­ */
	fp = fopen(path, "r");
	/* ‰ğÍ */
	for(i = 0; i < SIZE; i++){
		/* “Ç‚İ‚Ş */
		fgets(readStr, 64, fp);
		/* •ª‰ğ */
		for(j = 0; j < SIZE; j++){
<<<<<<< HEAD
			/* ä»£å…¥ */
=======
			/* ‘ã“ü */
>>>>>>> Add "struct" + "enum"
			lpnp->num[i][j] = readStr[j] - '0';
		}
	}
	/* •Â‚¶‚é */
	fclose(fp);
}

/* ƒƒCƒ“ŠÖ” */
int main(void)
{
	/* ”Õ–Êƒf[ƒ^Šm•Û */
	struct nplace npdata;
	/* 0‚Å‰Šú‰» */
	memset(&npdata, 0, sizeof(struct nplace));
	/* ƒtƒ@ƒCƒ‹‚©‚çƒf[ƒ^Šm•Û */
	readFile("NumPlace.txt", &npdata);
	/* ‰ğ‚­ */
	solve(&npdata, 0, 0);
	return 0;
}

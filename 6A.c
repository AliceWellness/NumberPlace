#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>			/* Standard In/Out */
#include <memory.h>			/* memsetp */
#include <stdlib.h>			/* system("pause")p */

/* ÕÊTCY */
#define SIZE 9

/* ¬÷/¸sè` */
enum BOOL
{
	FALSE = 0,	/* ¸s */
	TRUE = 1	/* ¬÷ */
};

/* ÕÊf[^\¢ */
struct nplace
{
	short num[SIZE][SIZE];	/* ÕÊÌ */
	short flg[SIZE][SIZE];	/* tOÆ© */
};

<<<<<<< HEAD
/* ç¤é¢åºåé¢æ° */
=======
/* ÕÊoÍÖ */
>>>>>>> Add "struct" + "enum"
void printnpl(const struct nplace *pnpl)
{
	int i, j;						/* [vp */
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			printf("%d", pnpl->num[i][j]);
		}
		printf("\n");				/* üs */
	}
	system("pause;");
	return;
}

<<<<<<< HEAD
/* ç¤é¢å¥åé¢æ°(å¤±æ=FALSE, æå=TRUE) */
BOOL putnum(struct nplace *pnpl, int x, int y, int n)
=======
/* ÕÊüÍÖ(¸s=FALSE, ¬÷=TRUE) */
enum BOOL putnum(struct nplace *pnpl, int x, int y, int n)
>>>>>>> Add "struct" + "enum"
{
	int i, j;
	for(i = 0; i < SIZE; i++){			/* ¡ûümF */
		if(pnpl->num[i][y] == n){		/* àµêv·é}Xª éÈç */
			pnpl->flg[x][y] |= 1 << n;	/* üçÈ¢ */
			return FALSE;
		}
	}
	for(i = 0; i < SIZE; i++){			/* cûümF */
		if(pnpl->num[x][i] == n){		/* àµêv·é}Xª éÈç */
			pnpl->flg[x][y] |= 1 << n;	/* üçÈ¢ */
			return FALSE;
		}
	}
<<<<<<< HEAD
	for(i = (x/3)*3; i <= ((x/3)*3)+2; i++){ 	/* å¥åãã¹ãå«ã¾ããä¸ãã¹ãç¢ºèªãã */
=======
	for(i = (x/3)*3; i <= ((x/3)*3)+2; i++){ 	/* üÍ}XªÜÜêéO}XðmF·é */
>>>>>>> Add "struct" + "enum"
		for(j = (y/3)*3; j <= ((y/3)*3)+2; j++){
			if(pnpl->num[i][j] == n){			/* àµêv·é}Xª éÈç */
				pnpl->flg[x][y] |= 1 << n;		/* üçÈ¢ */
				return FALSE;
			}
		}
	}
	pnpl->num[x][y] = n;				/* ãü */
	return TRUE;
}

<<<<<<< HEAD
/* å¨ãã¹ãåã¾ã£ã¦ããç¢ºèªããé¢æ° */
BOOL allchecked(struct nplace *pnpl)
=======
/* S}XªÜÁÄé©mF·éÖ */
enum BOOL allchecked(struct nplace *pnpl)
>>>>>>> Add "struct" + "enum"
{
	int i, j;
	/* S}XªÜÁÄé©mF */
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			/* ÜÁÄÈ¢}Xª éÈç */
			if(pnpl->num[i][j] == 0){
				/* ÜÁÄÈ¢ */
				return FALSE;
			}
		}
	}
	/* ÜÁÄ¢é */
	return TRUE;
}

<<<<<<< HEAD
/* ãã³ãã¼ãã¬ã¼ã¹ãè§£ãé¢æ° */
=======
/* io[v[Xðð­Ö */
>>>>>>> Add "struct" + "enum"
void solve(struct nplace *pnpl, int x, int y)
{
	int i;
	/* SÜÁÄé©Ç¤©mF·é */
	if(allchecked(pnpl) == TRUE){
		/* ÜÁÄ½çÊoÍ */
		printnpl(pnpl);
<<<<<<< HEAD
		/* çµäº */
=======
		/* I¹ */
>>>>>>> Add "struct" + "enum"
		return;
	}
	/* ©Â©éÜÅ[v³¹é */
	while(pnpl->num[x][y] != 0){
		x = (x + 1)%SIZE;	/* xðêÂ¡É¸ç· */
		if(x == 0){			/* êüµ½ç */
			y = (y+1)%SIZE;	/* yðêÂcÉ¸ç· */
		}
	}
	/* »ÌlÌªüé©Ç¤©`FbN */
	for(i = 1; i <= 9; i++){
		/* àµüéæ¤Èç */
		if((pnpl->flg[x][y] & (1 << i)) == 0){
<<<<<<< HEAD
			/* ä»®å®ç¨ãä½æ */
			nplace tmpnpl = *pnpl;
			/* ä»£å¥ */
=======
			/* ¼èpðì¬ */
			struct nplace tmpnpl = *pnpl;
			/* ãü */
>>>>>>> Add "struct" + "enum"
			if(putnum(&tmpnpl, x, y, i)){
				/* ÄA */
				solve(&tmpnpl, x, y);
			}
		}
	}
	return;
}

<<<<<<< HEAD
/* ãã¡ã¤ã«ãéãã¦è§£æãã */
void readFile(char path[], nplace* lpnp)
=======
/* t@CðJ¢ÄðÍ·é */
void readFile(char path[], struct nplace* lpnp)
>>>>>>> Add "struct" + "enum"
{
	int i, j;
	/* t@Cnh */
	FILE* fp;
	/* ÇÝÞ¶ñ */
	char readStr[64] = { '\0' };
	/* J­ */
	fp = fopen(path, "r");
	/* ðÍ */
	for(i = 0; i < SIZE; i++){
		/* ÇÝÞ */
		fgets(readStr, 64, fp);
		/* ªð */
		for(j = 0; j < SIZE; j++){
<<<<<<< HEAD
			/* ä»£å¥ */
=======
			/* ãü */
>>>>>>> Add "struct" + "enum"
			lpnp->num[i][j] = readStr[j] - '0';
		}
	}
	/* Â¶é */
	fclose(fp);
}

/* CÖ */
int main(void)
{
	/* ÕÊf[^mÛ */
	struct nplace npdata;
	/* 0Åú» */
	memset(&npdata, 0, sizeof(struct nplace));
	/* t@C©çf[^mÛ */
	readFile("NumPlace.txt", &npdata);
	/* ð­ */
	solve(&npdata, 0, 0);
	return 0;
}

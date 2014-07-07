#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>			/* Standard In/Out */
#include <memory.h>			/* memset用 */
#include <stdlib.h>			/* system("pause")用 */

/* 盤面サイズ */
#define SIZE 9

/* 成功/失敗定義 */
enum BOOL
{
	FALSE = 0,	/* 失敗 */
	TRUE = 1	/* 成功 */
};

/* 盤面データ構造 */
struct nplace
{
	short num[SIZE][SIZE];	/* 盤面の数字 */
	short flg[SIZE][SIZE];	/* フラグとか */
};

void printnpl(const struct nplace *pnpl)
{
	int i, j;						/* ループ用 */
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			printf("%d", pnpl->num[i][j]);
		}
		printf("\n");				/* 改行 */
	}
	system("pause;");
	return;
}

/* 盤面入力関数(失敗=FALSE, 成功=TRUE) */
enum BOOL putnum(struct nplace *pnpl, int x, int y, int n)
{
	int i, j;
	for(i = 0; i < SIZE; i++){			/* 横方向確認 */
		if(pnpl->num[i][y] == n){		/* もし一致するマスがあるなら */
			pnpl->flg[x][y] |= 1 << n;	/* 入らない */
			return FALSE;
		}
	}
	for(i = 0; i < SIZE; i++){			/* 縦方向確認 */
		if(pnpl->num[x][i] == n){		/* もし一致するマスがあるなら */
			pnpl->flg[x][y] |= 1 << n;	/* 入らない */
			return FALSE;
		}
	}
	for(i = (x/3)*3; i <= ((x/3)*3)+2; i++){ 	/* 入力マスが含まれる三マスを確認する */
		for(j = (y/3)*3; j <= ((y/3)*3)+2; j++){
			if(pnpl->num[i][j] == n){			/* もし一致するマスがあるなら */
				pnpl->flg[x][y] |= 1 << n;		/* 入らない */
				return FALSE;
			}
		}
	}
	pnpl->num[x][y] = n;				/* 代入 */
	return TRUE;
}

/* 全マスが埋まってるか確認する関数 */
enum BOOL allchecked(struct nplace *pnpl)
{
	int i, j;
	/* 全マスが埋まってるか確認 */
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			/* 埋まってないマスがあるなら */
			if(pnpl->num[i][j] == 0){
				/* 埋まってない */
				return FALSE;
			}
		}
	}
	/* 埋まっている */
	return TRUE;
}

/* ナンバープレースを解く関数 */
void solve(struct nplace *pnpl, int x, int y)
{
	int i;
	/* 全部埋まってるかどうか確認する */
	if(allchecked(pnpl) == TRUE){
		/* 埋まってたら結果出力 */
		printnpl(pnpl);
		/* 終了 */
		return;
	}
	/* 見つかるまでループさせる */
	while(pnpl->num[x][y] != 0){
		x = (x + 1)%SIZE;	/* xを一つ横にずらす */
		if(x == 0){			/* 一周したら */
			y = (y+1)%SIZE;	/* yを一つ縦にずらす */
		}
	}
	/* その値の数字が入るかどうかチェック */
	for(i = 1; i <= 9; i++){
		/* もし入るようなら */
		if((pnpl->flg[x][y] & (1 << i)) == 0){
			/* 仮定用を作成 */
			struct nplace tmpnpl = *pnpl;
			/* 代入 */
			if(putnum(&tmpnpl, x, y, i)){
				/* 再帰 */
				solve(&tmpnpl, x, y);
			}
		}
	}
	return;
}

/* ファイルを開いて解析する */
void readFile(char path[], struct nplace* lpnp)
{
	int i, j;
	/* ファイルハンドル */
	FILE* fp;
	/* 読み込む文字列 */
	char readStr[64] = { '\0' };
	/* 開く */
	fp = fopen(path, "r");
	/* 解析 */
	for(i = 0; i < SIZE; i++){
		/* 読み込む */
		fgets(readStr, 64, fp);
		/* 分解 */
		for(j = 0; j < SIZE; j++){
			/* 代入 */
			lpnp->num[i][j] = readStr[j] - '0';
		}
	}
	/* 閉じる */
	fclose(fp);
}

/* メイン関数 */
int main(void)
{
	/* 盤面データ確保 */
	struct nplace npdata;
	/* 0で初期化 */
	memset(&npdata, 0, sizeof(struct nplace));
	/* ファイルからデータ確保 */
	readFile("NumPlace.txt", &npdata);
	/* 解く */
	solve(&npdata, 0, 0);
	return 0;
}

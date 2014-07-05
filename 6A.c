#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>			/* Standard In/Out */
#include <memory.h>			/* memset�p */
#include <stdlib.h>			/* system("pause")�p */

/* �ՖʃT�C�Y */
#define SIZE 9

/* ����/���s��` */
enum BOOL
{
	FALSE = 0,	/* ���s */
	TRUE = 1	/* ���� */
};

/* �Ֆʃf�[�^�\�� */
struct nplace
{
	short num[SIZE][SIZE];	/* �Ֆʂ̐��� */
	short flg[SIZE][SIZE];	/* �t���O�Ƃ� */
};

<<<<<<< HEAD
/* 盤面出力関数 */
=======
/* �Ֆʏo�͊֐� */
>>>>>>> Add "struct" + "enum"
void printnpl(const struct nplace *pnpl)
{
	int i, j;						/* ���[�v�p */
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			printf("%d", pnpl->num[i][j]);
		}
		printf("\n");				/* ���s */
	}
	system("pause;");
	return;
}

<<<<<<< HEAD
/* 盤面入力関数(失敗=FALSE, 成功=TRUE) */
BOOL putnum(struct nplace *pnpl, int x, int y, int n)
=======
/* �Ֆʓ��͊֐�(���s=FALSE, ����=TRUE) */
enum BOOL putnum(struct nplace *pnpl, int x, int y, int n)
>>>>>>> Add "struct" + "enum"
{
	int i, j;
	for(i = 0; i < SIZE; i++){			/* �������m�F */
		if(pnpl->num[i][y] == n){		/* ������v����}�X������Ȃ� */
			pnpl->flg[x][y] |= 1 << n;	/* ����Ȃ� */
			return FALSE;
		}
	}
	for(i = 0; i < SIZE; i++){			/* �c�����m�F */
		if(pnpl->num[x][i] == n){		/* ������v����}�X������Ȃ� */
			pnpl->flg[x][y] |= 1 << n;	/* ����Ȃ� */
			return FALSE;
		}
	}
<<<<<<< HEAD
	for(i = (x/3)*3; i <= ((x/3)*3)+2; i++){ 	/* 入力マスが含まれる三マスを確認する */
=======
	for(i = (x/3)*3; i <= ((x/3)*3)+2; i++){ 	/* ���̓}�X���܂܂��O�}�X���m�F���� */
>>>>>>> Add "struct" + "enum"
		for(j = (y/3)*3; j <= ((y/3)*3)+2; j++){
			if(pnpl->num[i][j] == n){			/* ������v����}�X������Ȃ� */
				pnpl->flg[x][y] |= 1 << n;		/* ����Ȃ� */
				return FALSE;
			}
		}
	}
	pnpl->num[x][y] = n;				/* ��� */
	return TRUE;
}

<<<<<<< HEAD
/* 全マスが埋まってるか確認する関数 */
BOOL allchecked(struct nplace *pnpl)
=======
/* �S�}�X�����܂��Ă邩�m�F����֐� */
enum BOOL allchecked(struct nplace *pnpl)
>>>>>>> Add "struct" + "enum"
{
	int i, j;
	/* �S�}�X�����܂��Ă邩�m�F */
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			/* ���܂��ĂȂ��}�X������Ȃ� */
			if(pnpl->num[i][j] == 0){
				/* ���܂��ĂȂ� */
				return FALSE;
			}
		}
	}
	/* ���܂��Ă��� */
	return TRUE;
}

<<<<<<< HEAD
/* ナンバープレースを解く関数 */
=======
/* �i���o�[�v���[�X�������֐� */
>>>>>>> Add "struct" + "enum"
void solve(struct nplace *pnpl, int x, int y)
{
	int i;
	/* �S�����܂��Ă邩�ǂ����m�F���� */
	if(allchecked(pnpl) == TRUE){
		/* ���܂��Ă��猋�ʏo�� */
		printnpl(pnpl);
<<<<<<< HEAD
		/* 終了 */
=======
		/* �I�� */
>>>>>>> Add "struct" + "enum"
		return;
	}
	/* ������܂Ń��[�v������ */
	while(pnpl->num[x][y] != 0){
		x = (x + 1)%SIZE;	/* x������ɂ��炷 */
		if(x == 0){			/* ��������� */
			y = (y+1)%SIZE;	/* y����c�ɂ��炷 */
		}
	}
	/* ���̒l�̐��������邩�ǂ����`�F�b�N */
	for(i = 1; i <= 9; i++){
		/* ��������悤�Ȃ� */
		if((pnpl->flg[x][y] & (1 << i)) == 0){
<<<<<<< HEAD
			/* 仮定用を作成 */
			nplace tmpnpl = *pnpl;
			/* 代入 */
=======
			/* ����p���쐬 */
			struct nplace tmpnpl = *pnpl;
			/* ��� */
>>>>>>> Add "struct" + "enum"
			if(putnum(&tmpnpl, x, y, i)){
				/* �ċA */
				solve(&tmpnpl, x, y);
			}
		}
	}
	return;
}

<<<<<<< HEAD
/* ファイルを開いて解析する */
void readFile(char path[], nplace* lpnp)
=======
/* �t�@�C�����J���ĉ�͂��� */
void readFile(char path[], struct nplace* lpnp)
>>>>>>> Add "struct" + "enum"
{
	int i, j;
	/* �t�@�C���n���h�� */
	FILE* fp;
	/* �ǂݍ��ޕ����� */
	char readStr[64] = { '\0' };
	/* �J�� */
	fp = fopen(path, "r");
	/* ��� */
	for(i = 0; i < SIZE; i++){
		/* �ǂݍ��� */
		fgets(readStr, 64, fp);
		/* ���� */
		for(j = 0; j < SIZE; j++){
<<<<<<< HEAD
			/* 代入 */
=======
			/* ��� */
>>>>>>> Add "struct" + "enum"
			lpnp->num[i][j] = readStr[j] - '0';
		}
	}
	/* ���� */
	fclose(fp);
}

/* ���C���֐� */
int main(void)
{
	/* �Ֆʃf�[�^�m�� */
	struct nplace npdata;
	/* 0�ŏ����� */
	memset(&npdata, 0, sizeof(struct nplace));
	/* �t�@�C������f�[�^�m�� */
	readFile("NumPlace.txt", &npdata);
	/* ���� */
	solve(&npdata, 0, 0);
	return 0;
}

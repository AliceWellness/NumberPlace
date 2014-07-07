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

/* �Ֆʓ��͊֐�(���s=FALSE, ����=TRUE) */
enum BOOL putnum(struct nplace *pnpl, int x, int y, int n)
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
	for(i = (x/3)*3; i <= ((x/3)*3)+2; i++){ 	/* ���̓}�X���܂܂��O�}�X���m�F���� */
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

/* �S�}�X�����܂��Ă邩�m�F����֐� */
enum BOOL allchecked(struct nplace *pnpl)
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

/* �i���o�[�v���[�X�������֐� */
void solve(struct nplace *pnpl, int x, int y)
{
	int i;
	/* �S�����܂��Ă邩�ǂ����m�F���� */
	if(allchecked(pnpl) == TRUE){
		/* ���܂��Ă��猋�ʏo�� */
		printnpl(pnpl);
		/* �I�� */
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
			/* ����p���쐬 */
			struct nplace tmpnpl = *pnpl;
			/* ��� */
			if(putnum(&tmpnpl, x, y, i)){
				/* �ċA */
				solve(&tmpnpl, x, y);
			}
		}
	}
	return;
}

/* �t�@�C�����J���ĉ�͂��� */
void readFile(char path[], struct nplace* lpnp)
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
			/* ��� */
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

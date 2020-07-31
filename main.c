
/********************************************************************************************
	*  Copyright(c) tcpipstack
	*	File Name				:	RSA.c
	*	Abstract Description	:	RSA�[�ѱK�t��k��²��t��
	*	Create Date				:	2010/08/17
	*	Author					:	tcpipstack
	*-------------------------Revision History--------------------------------------------------
	*	No	Version		Date		Revised By			Item			Description
	*	 1		1.0		10/08/17
	*
	********************************************************************************************/
//https://github.com/longluo/RSA/blob/master/main.c
	#include <stdio.h>
	#include <math.h>

	/* RSA�t��k���[�K�褽�G�����_�ON�ME�A�ѱK��ϥ�N�MD�ѱK */
	#define P	5	/* P�MQ���������ơA�b��ڹB�Τ��q�`���ܤj���� */
	#define	Q	7

	#define N	(P*Q)	/* add the (), or will cause the mistake */
	#define Z	((P - 1)*(Q - 1))

	#define E	5		/* �[�K����E�AE�����MZ�u���@�Ӥ����� */
	#define D	5		/* (E * D - 1)��������QZ�㰣 */
	/* �ѩ�long int�L�k��ܹL�j���Ʀr�A�ҥHD��5 */


	int main(void)
	{
		int i;
		int TrsMsg[4] = {12, 15, 22, 5};
		long en[4], de[4];
		int SecCode[4], DeMsg[4];

		printf("�U���O�@��RSA�[�ѱK�t��k��²��t��:\n");
		printf("\t Copyright(C) Long.Luo.\n\n");
		printf("����\t�[�K\t   �[�K��K��\n");

		for (i=0; i<4; i++)
		{
			/* s = m(E) mod N */
			en[i] = (int)pow(TrsMsg[i], E);
			SecCode[i] = en[i] % N;

			printf("%d\t%d\t\t%d\n", TrsMsg[i], en[i], SecCode[i]);
		}

		printf("\n��l����\t�K��\t�[�K\t\t�ѱK����\n");
		for (i=0; i<4; i++)
		{
			/* d = s(D) mod N */
			de[i] = pow(SecCode[i], D);
			DeMsg[i] = de[i] % N;

			printf("%d\t\t%d\t%d\t\t%d\n", TrsMsg[i], SecCode[i], de[i], DeMsg[i]);
		}

		getchar();

	  return 0;
	}



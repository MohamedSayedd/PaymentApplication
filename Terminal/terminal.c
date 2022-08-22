#include <stdio.h>

#include "STD_TYPES.h"
#include "terminal.h"

int main (void)
{
	
	ST_terminalData_t termData;
	ST_cardData_t CardData;
	 getCardExpiryDate(&CardData);
printf("ExpirationDate:%s\n",CardData.cardExpirationDate);
	 getTransactionDate(&termData);
printf("transaction Date:%s\n",termData.transactionDate);
if(isCardExpired(&CardData,&termData)==0)
{
	printf("\nOk");
}
else
{
	printf("\nNOk");
}

}

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
		u8 Local_u8tCounter=0;
	
	printf("enter transaction data in format DD/MM/YY\n");
	scanf("%s",&termData->transactionDate);
	while(termData->transactionDate[Local_u8tCounter]!='\0')
	{
		Local_u8tCounter++;
	}
	if((Local_u8tCounter<10) || (termData->transactionDate[2]!='/') || (termData->transactionDate[5]!='/'))
	{
		return WRONG_DATE ;
	}
	else
	{
		return TERMINAL_OK ;
	}
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
	if((cardData->cardExpirationDate[4]>=termData->transactionDate[9]))
	{
		if((cardData->cardExpirationDate[0]>=termData->transactionDate[3])  && (cardData->cardExpirationDate[1]>termData->transactionDate[4]))
		{
		return TERMINAL_OK ;
		}
		else
		{
			return EXPIRED_CARD ;
		}
	}

	else
	{
		return EXPIRED_CARD ;
	}
}



EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
	printf("transaction amount\n");
	scanf("%s",&termData->transAmount);
	if(termData->transAmount<=0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}

}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
	if(termData->transAmount > termData->maxTransAmount)
	{
		return EXCEED_MAX_AMOUNT ;
	}
	else
	{
		return TERMINAL_OK;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
	
	if(termData->maxTransAmount<=0)
	{
		return INVALID_MAX_AMOUNT ;
	}
	else
	{
		return TERMINAL_OK;
	}
}







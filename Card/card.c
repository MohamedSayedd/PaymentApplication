#include <stdio.h>

#include "STD_TYPES.h"
#include "card.h"




EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
	u8 Local_u8tCounter=0;
	
	
	printf("enter your name\n");
	scanf("%s",&cardData->cardHolderName);
while(cardData->cardHolderName[Local_u8tCounter]!='\0')
	{
		Local_u8tCounter++;
	}
	if((Local_u8tCounter>24) || (Local_u8tCounter<20))
	{
		return WRONG_NAME;
	}
	else
	{
		return CARD_OK;
	}
}


EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
	u8 Local_u8tCounter=0;
	
	
	printf("card expiry date in format MM/YY\n");
	scanf("%s",&cardData->cardExpirationDate);
	while(cardData->cardExpirationDate[Local_u8tCounter]!='\0')
	{
		Local_u8tCounter++;
	}
	
	if((Local_u8tCounter<5) || (Local_u8tCounter>5) || (cardData->cardExpirationDate[2]!='/'))
	{
		return WRONG_EXP_DATE;
	}
	else
	{
		return CARD_OK;
	}
	
}
EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
		u8 Local_u8tCounter=0;
	
	
	printf("enter card's Primary Account Number\n");
	scanf("%s",&cardData->primaryAccountNumber);
	while(cardData->primaryAccountNumber[Local_u8tCounter]!='\0')
	{
		Local_u8tCounter++;
	}
	
	if((Local_u8tCounter<16) || (Local_u8tCounter>19) )
	{
		return WRONG_PAN;
	}
	else
	{
		return CARD_OK;
	}
}










#include <stdio.h>

#include "STD_TYPES.h"
#include "card.h"
#include "terminal.h"
#include "Server.h"
#include "app.h"
int main(void)
{
	
	
	
	
	
}

void appStart(void)
{
	//setMaxAmount
	ST_terminalData_t termData;
	termData.maxTransAmount=5000;
	setMaxAmount(&termData)
	//1-card
	
	//get CardHolderName
	u8 local_u8ErrorCheck;
	ST_cardData_t CardData;
	getCardHolderName(&CardData);
	printf("your Name:%s",CardData.cardHolderName);
	
	//Get card expiration Date
	getCardExpiryDate(&CardData);
	printf("ExpirationDate:%s",CardData.cardExpirationDate);
	
	//Get card PAN
	getCardPAN(&CardData);
	printf("CardPan:%s",CardData.primaryAccountNumber);
	
	
	//2-terminal
	
	getTransactionDate(&termData);
	isCardExpired(&CardData,&termData);
	if((isCardExpired(&CardData,&termData))==EXPIRED_CARD )
	{
		printf("Expired Card");
		
	}
	else if((isCardExpired(&CardData,&termData))==TERMINAL_OK)
	{
		getTransactionAmount(&termData);
	}
	
	if((isBelowMaxAmount(&termData))==TERMINAL_OK)
	{
		//
	}
	else
	{
		printf("Amount Exceeding Limit");
	}
	

	
	
	
	
	
	
	
	
}
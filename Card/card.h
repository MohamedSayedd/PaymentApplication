#ifndef CARD_H_
#define CARD_H_

typedef struct ST_cardData_t
{
u8	cardHolderName[25];
u8 	primaryAccountNumber[20];
u8	cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);






#endif
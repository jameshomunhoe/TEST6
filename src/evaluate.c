#include "Stack.h"
#include "Token.h"
#include "evaluate.h"
#include "Error.h"
#include "String.h"
#include "CException.h"
#include <stdio.h>


int evaluate(char *expression, Stack *operatorStack, Stack *dataStack){

	Tokenizer *tokenizer;
	Token *token;
	NumberToken *number;
	OperatorToken *operator;
	
	tokenizer = tokenizerNew(expression);
	
	while(1){
	number = (NumberToken *)nextToken(tokenizer);
	if(number == NULL) 
	Throw(ERR_NOT_DATA);
	else if(number->type != NUMBER_TOKEN)
	Throw(ERR_NOT_DATA);
	else
	push(dataStack,number);
	
	

	operator = (OperatorToken *)nextToken(tokenizer);	
	if(operator == NULL)
	break;
	else if(operator->type != OPERATOR_TOKEN)
	Throw(ERR_NOT_OPERATOR);
	else
	tryEvaluateOperatorsOnStackThenPush(operatorStack,dataStack,operator);
	}
	evaluateAllOperatorsOnStack(operatorStack,dataStack);


}

void tryEvaluateOperatorsOnStackThenPush(Stack *operatorStack, 
										 Stack *dataStack,
										 OperatorToken *operator){

	int interrupt = 0;
	OperatorToken *toCheck;
	
	
	while (interrupt!=1){
		
		toCheck	= pop(operatorStack);
		if(toCheck == NULL){
			push(operatorStack,operator);
			interrupt = 1;
		}
		else if(operator->precedence > toCheck->precedence){
			push(operatorStack,toCheck);
			push(operatorStack,operator);
			interrupt = 1;
		}
		else{
			evaluateOperator(dataStack,toCheck);
			interrupt = 0;
		}
	}	
}
										 
										 
void evaluateAllOperatorsOnStack(Stack *operatorStack, Stack *dataStack){
	
	OperatorToken *token;
	
	do{
	token = pop(operatorStack);
		if(token == NULL)
			printf("bye");
		else
			evaluateOperator(dataStack,token);
	}while( token != NULL);


}

void evaluateOperator(Stack *dataStack, OperatorToken *operator){
	
	NumberToken *result;
	NumberToken *right = pop(dataStack);
	NumberToken *left = pop(dataStack);
	
	if(strcmp("*",operator->name)==0){
	result = createNumberToken(right->value * left->value);
	}
	else if(strcmp("/",operator->name)==0){
	result = createNumberToken(right->value / left->value);
	}
	else if(strcmp("%",operator->name)==0){
	result = createNumberToken(right->value % left->value);
	}
	else if(strcmp("+",operator->name)==0){
	result = createNumberToken(right->value + left->value);
	}
	else if(strcmp("-",operator->name)==0){
	result = createNumberToken(right->value - left->value);
	}
	else if(strcmp("^",operator->name)==0){
	result = createNumberToken(right->value ^ left->value);
	}
	else if(strcmp("&",operator->name)==0){
	result = createNumberToken(right->value & left->value);
	}
	else if(strcmp("|",operator->name)==0){
	result = createNumberToken(right->value | left->value);
	}
	else
		Throw(ERR_NOT_OPERATOR);
	
	push(dataStack,result);
}
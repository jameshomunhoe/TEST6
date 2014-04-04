#include "Stack.h"
#include "Token.h"
#include "evaluate.h"
#include "Error.h"
#include "String.h"
#include "CException.h"
#include <stdio.h>


int evaluate(char *expression){}

void tryEvaluateOperatorsOnStackThenPush(Stack *operatorstack, 
										 Stack *dataStack,
										 OperatorToken *operator){

										 
										 
										 
}
										 
										 
void evaluateAllOperatorsOnStack(Stack *operatorStack, Stack *dataStack){

	OperatorToken *token = pop(operatorStack);
	if( token != NULL)
		evaluateOperator(dataStack,token);
	else
		printf("Bye");

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
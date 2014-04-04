#ifndef evaluate_H
#define evaluate_H

int evaluate(char *expression, Stack *operatorStack, Stack *dataStack);

void tryEvaluateOperatorsOnStackThenPush(Stack *operatorstack, 
										 Stack *dataStack,
										 OperatorToken *operator);
										 
void evaluateAllOperatorsOnStack(Stack *operatorStack, Stack *dataStack);
void evaluateOperator(Stack *dataStack, OperatorToken *operator);										 
#endif // evaluate_H

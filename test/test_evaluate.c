#include "unity.h"
#include "mock_Stack.h"
#include "mock_Token.h"
#include "evaluate.h"
#include "Error.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

void test_evaluateOperator_should_multiple_2_numbers(void)
{
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="*", .precedence = 100};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =6};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp1);
	pop_ExpectAndReturn(&dataStack, &temp2);
	createNumberToken_ExpectAndReturn(6, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_divide_2_numbers(void)
{
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="/", .precedence = 100};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =1};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp1);
	pop_ExpectAndReturn(&dataStack, &temp2);
	createNumberToken_ExpectAndReturn(1, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_modulo_2_numbers(void)
{
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="%", .precedence = 100};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =5};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =1};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp1);
	pop_ExpectAndReturn(&dataStack, &temp2);
	createNumberToken_ExpectAndReturn(1, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_add_2_numbers(void)
{
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="+", .precedence = 70};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =5};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp1);
	pop_ExpectAndReturn(&dataStack, &temp2);
	createNumberToken_ExpectAndReturn(5, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_subtract_2_numbers(void)
{
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="-", .precedence = 70};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =1};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp1);
	pop_ExpectAndReturn(&dataStack, &temp2);
	createNumberToken_ExpectAndReturn(1, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_XOR_2_numbers(void)
{
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="^", .precedence = 50};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =1};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp1);
	pop_ExpectAndReturn(&dataStack, &temp2);
	createNumberToken_ExpectAndReturn(1, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_AND_2_numbers(void)
{
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="&", .precedence = 20};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =2};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp1);
	pop_ExpectAndReturn(&dataStack, &temp2);
	createNumberToken_ExpectAndReturn(2, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_OR_2_numbers(void)
{
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="|", .precedence = 10};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =15};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =15};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp1);
	pop_ExpectAndReturn(&dataStack, &temp2);
	createNumberToken_ExpectAndReturn(15, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_throw_error_not_operator(void)
{
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="?", .precedence = 10};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =15};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =15};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp1);
	pop_ExpectAndReturn(&dataStack, &temp2);
	//createNumberToken_ExpectAndReturn(15, &answer);
	//push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_tryEvaluateOperatorOnStackThenPush_2_operator(){

	Stack dataStack;
	Stack operatorStack;
	OperatorToken mul = {.type = OPERATOR_TOKEN, .name ="*", .precedence = 100};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name="+", .precedence = 70}; 
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken temp3 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value =6};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value =8};

	pop_ExpectAndReturn(&operatorStack,&mul);
	pop_ExpectAndReturn(&dataStack,&temp1);
	pop_ExpectAndReturn(&dataStack,&temp2);
	createNumberToken_ExpectAndReturn(6,&answer1);
	push_Expect(&dataStack, &answer1);
	
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
	
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&answer1);
	pop_ExpectAndReturn(&dataStack,&temp3);
	createNumberToken_ExpectAndReturn(8,&answer2);
	push_Expect(&dataStack, &answer2);
		
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
}

void test_tryEvaluateOperatorOnStackThenPush_3_operator(){

	Stack dataStack;
	Stack operatorStack;
	OperatorToken mul = {.type = OPERATOR_TOKEN, .name ="*", .precedence = 100};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name="+", .precedence = 70}; 
	OperatorToken xor = {.type = OPERATOR_TOKEN, .name="^", .precedence = 50}; 
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp3 = {.type = NUMBER_TOKEN, .value =4};
	NumberToken temp4 = {.type = NUMBER_TOKEN, .value =15};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value =6};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value =10};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value =5};

	pop_ExpectAndReturn(&operatorStack,&mul);
	pop_ExpectAndReturn(&dataStack,&temp1);
	pop_ExpectAndReturn(&dataStack,&temp2);
	createNumberToken_ExpectAndReturn(6,&answer1);
	push_Expect(&dataStack, &answer1);
	
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
	
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&answer1);
	pop_ExpectAndReturn(&dataStack,&temp3);
	createNumberToken_ExpectAndReturn(10,&answer2);
	push_Expect(&dataStack, &answer2);
		
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
	
	pop_ExpectAndReturn(&operatorStack,&xor);
	pop_ExpectAndReturn(&dataStack,&answer2);
	pop_ExpectAndReturn(&dataStack,&temp4);
	createNumberToken_ExpectAndReturn(5,&answer3);
	push_Expect(&dataStack, &answer3);
		
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
}

void test_tryEvaluateOperatorOnStackThenPush_stop_at_null(){

	Stack dataStack;
	Stack operatorStack;
	OperatorToken mul = {.type = OPERATOR_TOKEN, .name ="*", .precedence = 100};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name="+", .precedence = 70}; 
	OperatorToken xor = {.type = OPERATOR_TOKEN, .name=" ", .precedence = 50}; 
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp3 = {.type = NUMBER_TOKEN, .value =4};
	NumberToken temp4 = {.type = NUMBER_TOKEN, .value =15};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value =6};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value =10};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value =5};

	pop_ExpectAndReturn(&operatorStack,&mul);
	pop_ExpectAndReturn(&dataStack,&temp1);
	pop_ExpectAndReturn(&dataStack,&temp2);
	createNumberToken_ExpectAndReturn(6,&answer1);
	push_Expect(&dataStack, &answer1);
	
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
	
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&answer1);
	pop_ExpectAndReturn(&dataStack,&temp3);
	createNumberToken_ExpectAndReturn(10,&answer2);
	push_Expect(&dataStack, &answer2);
		
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	//pop_ExpectAndReturn(&dataStack,&answer2);
	//pop_ExpectAndReturn(&dataStack,&temp4);
	//createNumberToken_ExpectAndReturn(5,&answer3);
	//push_Expect(&dataStack, &answer3);
		
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
}
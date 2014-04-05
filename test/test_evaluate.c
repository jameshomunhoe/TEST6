#include "unity.h"
#include "mock_Stack.h"
#include "mock_Token.h"
#include "evaluate.h"
#include "Error.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

void test_evaluateOperator_should_multiple_2_numbers(void){
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

void test_evaluateOperator_should_divide_2_numbers(void){
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="/", .precedence = 100};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =1};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp2);
	pop_ExpectAndReturn(&dataStack, &temp1);
	createNumberToken_ExpectAndReturn(1, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_modulo_2_numbers(void){
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="%", .precedence = 100};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =5};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =1};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp2);
	pop_ExpectAndReturn(&dataStack, &temp1);
	createNumberToken_ExpectAndReturn(1, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_add_2_numbers(void){
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

void test_evaluateOperator_should_subtract_2_numbers(void){
	Stack dataStack;
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name ="-", .precedence = 70};
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =1};
	
	int e;
	
	pop_ExpectAndReturn(&dataStack, &temp2);
	pop_ExpectAndReturn(&dataStack, &temp1);
	createNumberToken_ExpectAndReturn(1, &answer);
	push_Expect(&dataStack, &answer);
	
	Try{
	evaluateOperator(&dataStack,&plus);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);}
}

void test_evaluateOperator_should_XOR_2_numbers(void){
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

void test_evaluateOperator_should_AND_2_numbers(void){
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

void test_evaluateOperator_should_OR_2_numbers(void){
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

void test_evaluateOperator_should_throw_error_not_operator(void){
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

void test_evaluateAllOperatorsOnStack_2_operator(){

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
	
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&answer1);
	pop_ExpectAndReturn(&dataStack,&temp3);
	createNumberToken_ExpectAndReturn(8,&answer2);
	push_Expect(&dataStack, &answer2);
		
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
}

void test_evaluateAllOperatorsOnStack_3_operator(){

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
	
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&answer1);
	pop_ExpectAndReturn(&dataStack,&temp3);
	createNumberToken_ExpectAndReturn(10,&answer2);
	push_Expect(&dataStack, &answer2);
	
	pop_ExpectAndReturn(&operatorStack,&xor);
	pop_ExpectAndReturn(&dataStack,&answer2);
	pop_ExpectAndReturn(&dataStack,&temp4);
	createNumberToken_ExpectAndReturn(5,&answer3);
	push_Expect(&dataStack, &answer3);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
		
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
}

void test_evaluateAllOperatorsOnStack_stop_at_null(){

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
	
	pop_ExpectAndReturn(&operatorStack,&plus);
	pop_ExpectAndReturn(&dataStack,&answer1);
	pop_ExpectAndReturn(&dataStack,&temp3);
	createNumberToken_ExpectAndReturn(10,&answer2);
	push_Expect(&dataStack, &answer2);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	//pop_ExpectAndReturn(&dataStack,&answer2);
	//pop_ExpectAndReturn(&dataStack,&temp4);
	//createNumberToken_ExpectAndReturn(5,&answer3);
	//push_Expect(&dataStack, &answer3);
		
	evaluateAllOperatorsOnStack(&operatorStack,&dataStack);
}

void test_tryEvaluateOperatorsOnStackThenPush_should_add_to_opratorStack(){

	Stack dataStack;
	Stack operatorStack;
	OperatorToken mul = {.type = OPERATOR_TOKEN, .name ="*", .precedence = 100};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name="+", .precedence = 70}; 

	pop_ExpectAndReturn(&operatorStack,&plus);
	push_Expect(&operatorStack,&plus);
	push_Expect(&operatorStack,&mul);		
		
	tryEvaluateOperatorsOnStackThenPush(&operatorStack,&dataStack,&mul);
}

void test_tryEvaluateOperatorsOnStackThenPush_should_execute_once(){

	Stack dataStack;
	Stack operatorStack;
	OperatorToken mul = {.type = OPERATOR_TOKEN, .name ="*", .precedence = 100};
	OperatorToken plus = {.type = OPERATOR_TOKEN, .name="+", .precedence = 70}; 
	NumberToken temp1 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken temp2 = {.type = NUMBER_TOKEN, .value =3};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value =6};

	pop_ExpectAndReturn(&operatorStack,&mul);
	pop_ExpectAndReturn(&dataStack,&temp1);	
	pop_ExpectAndReturn(&dataStack,&temp2);
	createNumberToken_ExpectAndReturn(6, &answer1);
	push_Expect(&dataStack,&answer1);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&plus);
		
	tryEvaluateOperatorsOnStackThenPush(&operatorStack,&dataStack,&plus);
}

void test_evaluate_1_plus_2(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 1};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 2};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =3};
	
	
	tokenizerNew_ExpectAndReturn("1+2",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	push_Expect(&dataStack,&number2);
	
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	pop_ExpectAndReturn(&operatorStack,&operator1);
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(3, &answer);
	push_Expect(&dataStack, &answer);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	Try{
	evaluate("1+2",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);
	}
}

void test_evaluate_4_multiply_3(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "*", .precedence =100};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 4};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 3};
	NumberToken answer = {.type = NUMBER_TOKEN, .value =12};
	
	
	tokenizerNew_ExpectAndReturn("4*3",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	push_Expect(&dataStack,&number2);
	
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	pop_ExpectAndReturn(&operatorStack,&operator1);
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(12, &answer);
	push_Expect(&dataStack, &answer);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	Try{
	evaluate("4*3",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);
	}
}

void test_evaluate_3_plus_4_plus_5_subtract_6(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence =70};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "-", .precedence =70};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 4};
	NumberToken number3={.type = NUMBER_TOKEN, .value = 5};
	NumberToken number4={.type = NUMBER_TOKEN, .value = 6};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value =7};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value =12};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value =6};
	
	
	tokenizerNew_ExpectAndReturn("3+4+5-6",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	push_Expect(&dataStack,&number2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	pop_ExpectAndReturn(&operatorStack,&operator1);
	pop_ExpectAndReturn(&dataStack,&number2);
	pop_ExpectAndReturn(&dataStack,&number1);
	createNumberToken_ExpectAndReturn(7, &answer1);
	push_Expect(&dataStack, &answer1);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number3);
	push_Expect(&dataStack,&number3);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack,&operator1);
	pop_ExpectAndReturn(&dataStack,&number3);
	pop_ExpectAndReturn(&dataStack,&answer1);
	createNumberToken_ExpectAndReturn(12, &answer2);
	push_Expect(&dataStack, &answer2);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number4);
	push_Expect(&dataStack,&number4);
	
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	pop_ExpectAndReturn(&operatorStack,&operator2);
	pop_ExpectAndReturn(&dataStack,&number4);
	pop_ExpectAndReturn(&dataStack,&answer2);
	createNumberToken_ExpectAndReturn(6,&answer3);
	push_Expect(&dataStack,&answer3);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	Try{
	evaluate("3+4+5-6",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);
	}
}

void test_evaluate_111_divide_12_plus_13_multiply_14(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "/", .precedence =100};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "+", .precedence =70};
	OperatorToken operator3 = {.type = OPERATOR_TOKEN, .name = "&", .precedence =20};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 111};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 12};
	NumberToken number3={.type = NUMBER_TOKEN, .value = 13};
	NumberToken number4={.type = NUMBER_TOKEN, .value = 14};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value =9};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value =22};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value =6};
	
	
	tokenizerNew_ExpectAndReturn("111/12+13*14",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	push_Expect(&dataStack,&number2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack,&operator1);
	pop_ExpectAndReturn(&dataStack,&number2);
	pop_ExpectAndReturn(&dataStack,&number1);
	createNumberToken_ExpectAndReturn(9, &answer1);
	push_Expect(&dataStack, &answer1);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number3);
	push_Expect(&dataStack,&number3);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator3);
	pop_ExpectAndReturn(&operatorStack,&operator2);
	pop_ExpectAndReturn(&dataStack,&number3);
	pop_ExpectAndReturn(&dataStack,&answer1);
	createNumberToken_ExpectAndReturn(22, &answer2);
	push_Expect(&dataStack, &answer2);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator3);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number4);
	push_Expect(&dataStack,&number4);
	
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	pop_ExpectAndReturn(&operatorStack,&operator3);
	pop_ExpectAndReturn(&dataStack,&number4);
	pop_ExpectAndReturn(&dataStack,&answer2);
	createNumberToken_ExpectAndReturn(6,&answer3);
	push_Expect(&dataStack,&answer3);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	Try{
	evaluate("111/12+13*14",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);
	}
}

void test_evaluate_211_AND_22_XOR_23_PLUS_24(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "&", .precedence =20};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "^", .precedence =50};
	OperatorToken operator3 = {.type = OPERATOR_TOKEN, .name = "+", .precedence =70};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 211};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 22};
	NumberToken number3={.type = NUMBER_TOKEN, .value = 23};
	NumberToken number4={.type = NUMBER_TOKEN, .value = 24};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value =47};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value =57};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value =17};
	
	
	tokenizerNew_ExpectAndReturn("211&22^23+24",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	push_Expect(&dataStack,&number2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack,&operator1);
	push_Expect(&operatorStack,&operator1);
	push_Expect(&operatorStack,&operator2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number3);
	push_Expect(&dataStack,&number3);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator3);
	pop_ExpectAndReturn(&operatorStack,&operator2);
	push_Expect(&operatorStack,&operator2);
	push_Expect(&operatorStack,&operator3);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number4);
	push_Expect(&dataStack,&number4);
	
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	pop_ExpectAndReturn(&operatorStack,&operator3);
	pop_ExpectAndReturn(&dataStack,&number4);
	pop_ExpectAndReturn(&dataStack,&number3);
	createNumberToken_ExpectAndReturn(47,&answer1);
	push_Expect(&dataStack,&answer1);
	
	pop_ExpectAndReturn(&operatorStack,&operator2);
	pop_ExpectAndReturn(&dataStack,&answer1);
	pop_ExpectAndReturn(&dataStack,&number2);
	createNumberToken_ExpectAndReturn(57,&answer2);
	push_Expect(&dataStack,&answer2);
	
	pop_ExpectAndReturn(&operatorStack,&operator1);
	pop_ExpectAndReturn(&dataStack,&answer2);
	pop_ExpectAndReturn(&dataStack,&number1);
	createNumberToken_ExpectAndReturn(17,&answer2);
	push_Expect(&dataStack,&answer2);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	Try{
	evaluate("211&22^23+24",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);
	}
}

void test_evaluate_266_OR_27_XOR_28_PLUS_29_AND_30(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "|", .precedence =10};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "^", .precedence =50};
	OperatorToken operator3 = {.type = OPERATOR_TOKEN, .name = "+", .precedence =70};
	OperatorToken operator4 = {.type = OPERATOR_TOKEN, .name = "&", .precedence =20};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 266};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 27};
	NumberToken number3={.type = NUMBER_TOKEN, .value = 28};
	NumberToken number4={.type = NUMBER_TOKEN, .value = 29};
	NumberToken number5={.type = NUMBER_TOKEN, .value = 30};
	NumberToken answer1 = {.type = NUMBER_TOKEN, .value =57};
	NumberToken answer2 = {.type = NUMBER_TOKEN, .value =34};
	NumberToken answer3 = {.type = NUMBER_TOKEN, .value =2};
	NumberToken answer4 = {.type = NUMBER_TOKEN, .value =266};
	
	
	tokenizerNew_ExpectAndReturn("266|27^28+29&30",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	push_Expect(&dataStack,&number2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack,&operator1);
	push_Expect(&operatorStack,&operator1);
	push_Expect(&operatorStack,&operator2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number3);
	push_Expect(&dataStack,&number3);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator3);
	pop_ExpectAndReturn(&operatorStack,&operator2);
	push_Expect(&operatorStack,&operator2);
	push_Expect(&operatorStack,&operator3);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number4);
	push_Expect(&dataStack,&number4);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator4);
	pop_ExpectAndReturn(&operatorStack,&operator3);
	pop_ExpectAndReturn(&dataStack,&number4);
	pop_ExpectAndReturn(&dataStack,&number3);
	createNumberToken_ExpectAndReturn(57,&answer1);
	push_Expect(&dataStack,&answer1);
	
	pop_ExpectAndReturn(&operatorStack,&operator2);
	pop_ExpectAndReturn(&dataStack,&answer1);
	pop_ExpectAndReturn(&dataStack,&number2);
	createNumberToken_ExpectAndReturn(34,&answer2);
	push_Expect(&dataStack,&answer2);
	
	pop_ExpectAndReturn(&operatorStack,&operator1);
	push_Expect(&operatorStack,&operator1);
	push_Expect(&operatorStack,&operator4);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number5);
	push_Expect(&dataStack,&number5);
	nextToken_ExpectAndReturn(&tokenizer,NULL);
	
	pop_ExpectAndReturn(&operatorStack,&operator4);
	pop_ExpectAndReturn(&dataStack,&number5);
	pop_ExpectAndReturn(&dataStack,&answer2);
	createNumberToken_ExpectAndReturn(2,&answer3);
	push_Expect(&dataStack,&answer3);
	
	pop_ExpectAndReturn(&operatorStack,&operator1);
	pop_ExpectAndReturn(&dataStack,&answer3);
	pop_ExpectAndReturn(&dataStack,&number1);
	createNumberToken_ExpectAndReturn(266,&answer4);
	push_Expect(&dataStack,&answer4);
	
	pop_ExpectAndReturn(&operatorStack,NULL);
	
	Try{
	evaluate("266|27^28+29&30",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);
	}
}

void test_evaluate_PLUS(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 1};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 2};
	
	tokenizerNew_ExpectAndReturn("+",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	
	Try{
	evaluate("+",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_DATA,e);
	}
}

void test_evaluate_38_space_39(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 38};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 39};
	
	tokenizerNew_ExpectAndReturn("38 39",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	
	Try{
	evaluate("38 39",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_OPERATOR,e);
	}

}

void test_evaluate_40_plus_multiply(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 40};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 39};
	
	tokenizerNew_ExpectAndReturn("40+*",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator2);
	
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	
	Try{
	evaluate("40+*",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_DATA,e);
	}
}

void test_evaluate_42_XOR_2_subtract(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "-", .precedence = 70};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 42};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 2};
	
	tokenizerNew_ExpectAndReturn("42^2-",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator1);
	pop_ExpectAndReturn(&operatorStack,NULL);
	push_Expect(&operatorStack,&operator1);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	push_Expect(&dataStack,&number2);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&operator2);
	pop_ExpectAndReturn(&operatorStack,&operator1);
	push_Expect(&operatorStack,&operator1);
	push_Expect(&operatorStack,&operator2);
	
	nextToken_ExpectAndReturn(&tokenizer,NULL);	
	
	Try{
	evaluate("42^2-",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_DATA,e);
	}
}

void test_evaluate_43_HASH_44(){

	Tokenizer tokenizer;
	Stack dataStack;
	Stack operatorStack;
	int e;
	OperatorToken operator1 = {.type = UNKNOWN_TOKEN, .name = "#", .precedence = 100};
	NumberToken number1={.type = NUMBER_TOKEN, .value = 43};
	NumberToken number2={.type = NUMBER_TOKEN, .value = 44};
	
	tokenizerNew_ExpectAndReturn("43#44",&tokenizer);
	
	nextToken_ExpectAndReturn(&tokenizer,(Token *)&number1);
	push_Expect(&dataStack,&number1);
	
	nextToken_ExpectAndThrow(&tokenizer,ERR_NOT_DATA);

	
	Try{
	evaluate("43#44",&operatorStack,&dataStack);}
	Catch(e){
	TEST_ASSERT_EQUAL(ERR_NOT_DATA,e);
	}
}
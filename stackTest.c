#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr_assert.h"


void test_creatStack_cretes_a_stack_and_sets_its_top_to_NULL(){
	Stack stack = createStack();
	assertEqual(*(int*)stack.top,0);
}

void test_createStack_creates_an_empty_stack (){
	Stack stack;
	stack = createStack();
	assertEqual(stack.list->count, 0);
	assertEqual(*(int*)stack.top , 0);
	free(stack.list);
}

void test_to_push_int_data_in_a_stack(){
	Stack s1 = createStack();
	int data = 2;
	assertEqual(push(&s1,&data),1);
	assertEqual(*(int*)s1.list->tail->data,2);
}

void test_to_push_float_data_in_a_stack(){
	Stack s1 = createStack();
	float data = 2.3;
	assertEqual(push(&s1,&data),1);
	assertEqual(*(float*)s1.list->tail->data,(float)2.3);
}

void test_to_push_char_data_in_a_stack(){
	Stack s1 = createStack();
	char data = 'a';
	assertEqual(push(&s1,&data),1);
	assertEqual(*(char*)s1.list->tail->data,'a');
}

void test_to_push_string_data_in_a_stack(){
	Stack s1 = createStack();
	char* data= "string";
	assertEqual(push(&s1,&data),1);
	assertEqual(strcmp(*((char**)s1.list->tail->data),"string"), 0);
}

void test_to_push_more_than_two_int_data_in_a_stack(){
	Stack s1 = createStack();
	int data = 2,data2=3;
	assertEqual(push(&s1,&data),1);
	assertEqual(push(&s1,&data2),2);
	assertEqual(*((int*)s1.list->tail->data),3);
	assertEqual(*(int*)(*s1.top)->data,data2);
}


void test_pop_retuns_topmost_element_from_stack(){
	int data1=1,data2 =4,count;
	int * poped;
	Stack s = createStack();
	count = push(&s,&data1);
	count = push(&s,&data2);
	poped =pop(&s);
	assertEqual(*(int*)poped, data2);
}
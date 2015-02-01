#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "expr_assert.h"

void test_to_create_linked_list(){
	LinkedList l1 = createList();
	assert(l1.head==NULL);
	assert(l1.tail==NULL);
	assertEqual(l1.count,0);
}

void test_to_create_a_node(){
	int data = 2;
	Node *n1 = create_node((void*)data);
	assertEqual((int)n1->data,2);
	assert(n1->next==NULL);
	free(n1);
} 

void test_to_add_one_node_in_linked_list_with_int_data(){
	int data = 2;
	Node *n1 = create_node((void*)data);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	assert(l1.head != NULL);
	assertEqual((int)l1.head,(int)n1);
	assertEqual((int)l1.count,1);
	free(n1);
}


void test_to_add_one_node_in_linked_list_with_char_data(){
	char c = 'a';
	Node *n1 = create_node((void*)c);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	assert(l1.head != NULL);
	assertEqual((int)l1.head,(int)n1);
	assertEqual((int)l1.count,1);
	assertEqual((char)l1.head->data,'a');
	free(n1);
}

void test_to_add_more_than_one_node_in_linked_list(){
	int d1=1,d2=2;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	assertEqual((int)l1.head,(int)n1);
	assertEqual((int)l1.tail,(int)n2);
	free(n1);
	free(n2);
}
void test_get_first_element_gives_the_first_element_of_the_list(){
	int d1=1,d2=2;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	assertEqual((int)get_first_element(l1),(int)n1);
	assertEqual((int)l1.count,2);
	free(n1);
	free(n2);
}

void test_get_last_element_gives_the_last_element_of_the_list(){
	int d1=3,d2=5;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	assertEqual((int)get_last_element(l1),(int)n2);
	assertEqual((int)l1.count,2);
	free(n1);
	free(n2);
}


void add1(void* num){
	*((int*)num)+=1;
}

void test_traverse_goes_through_each_element_of_the_list_with_int_data(){
	int d1=3,d2=4;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	traverse(l1,add1);
	assert((int)l1.head->data==4);
	free(n1);
	free(n2);
}

void changeToUpper(void* ch){
	char* chh = (char*)(ch);
	*chh = toupper(*chh);
}

void test_traverse_goes_through_each_element_of_the_list_with_char_data(){
	char c1='a',c2='b';
	Node *n1 = create_node((void*)c1);
	Node *n2 = create_node((void*)c2);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	traverse(l1,changeToUpper);
	assertEqual((char)l1.head->data,'A');
	assertEqual((char)l1.tail->data,'B');
	free(n1);
	free(n2);
}


void test_getElementAt_gives_element_of_given_index_from_list(){
	int d1=3,d2=4,d3=5;
	int index = 1;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	Node *n3 = create_node((void*)d3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	assertEqual(*((int *)getElementAt(l1,index)), 4);
	free(n1);
	free(n2);
	free(n3);
}

void test_getElementAt_gives_NULL_when_index_is_greater_than_count(){
	int d1=3,d2=4,d3=5;
	int index = 4;
	void *result;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	Node *n3 = create_node((void*)d3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	assertEqual((int)getElementAt(l1,index), 0);
	free(n1);
	free(n2);
	free(n3);
}

void test_getElementAt_gives_NULL_when_index_is_equal_to_count(){
	int d1=3,d2=4,d3=5;
	int index = 3;
	void *result;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	Node *n3 = create_node((void*)d3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	assertEqual((int)getElementAt(l1,index), 0);
	free(n1);
	free(n2);
	free(n3);
}

void test_getElementAt_gives_element_of_given_index_from_list_for_char_data(){
	char c1='a',c2='b',c3='c';
	int index = 1;
	Node *n1 = create_node((void*)c1);
	Node *n2 = create_node((void*)c2);
	Node *n3 = create_node((void*)c3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	assertEqual(*((char *)getElementAt(l1,index)), 'b');
	free(n1);
	free(n2);
	free(n3);
}

void test_getElementAt_gives_element_of_given_index_from_list_for_string_data(){
	char s1[]="pooja";
	char s2[]="banty";
	char s3[]="gurav";
	int index = 1;
	Node *n1 = create_node((void*)s1);
	Node *n2 = create_node((void*)s2);
	Node *n3 = create_node((void*)s3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	assertEqual(strcmp(*((char **)getElementAt(l1,index)),"banty"),0);
	free(n1);
	free(n2);
	free(n3);
}

void test_indexOf_gives_index_of_given_element_of_list(){
	int d1=3,d2=4,d3=5;
	void *result;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	Node *n3 = create_node((void*)d3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	assertEqual(indexOf(l1,&l1.head->next->data),1);
	free(n1);
	free(n2);
	free(n3);
}

void test_indexOf_gives_index_of_given_element_of_list_for_char_data(){
	char c1='a',c2='b',c3='c';
	Node *n1 = create_node((void*)c1);
	Node *n2 = create_node((void*)c2);
	Node *n3 = create_node((void*)c3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	assertEqual(indexOf(l1,&l1.head->next->data),1);
	free(n1);
	free(n2);
	free(n3);
}

void test_indexOf_gives_index_of_given_element_of_list_for_string_data(){
	char s1[]="pooja";
	char s2[]="banty";
	char s3[]="gurav";
	Node *n1 = create_node((void*)s1);
	Node *n2 = create_node((void*)s2);
	Node *n3 = create_node((void*)s3);
	LinkedList l1=createList();                                                                                                                                                        
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	assertEqual(indexOf(l1,&l1.head->next->data),1);
	free(n1);
	free(n2);
	free(n3);
}

void test_deletElementAt_delets_given_index_element_from_list(){
	int d1=3,d2=4,d3=5;
	void *result;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	Node *n3 = create_node((void*)d3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	deleteElementAt(&l1,1);
	assertEqual(indexOf(l1,&d3),1); 	
	free(n1);
	free(n2);
	free(n3);
}

void test_deletElementAt_delets_given_index_element_from_list_for_four_nodes(){
	int d1=3,d2=4,d3=5,d4=6;
	void *result;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	Node *n3 = create_node((void*)d3);
	Node *n4 = create_node((void*)d4);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	add_to_list(&l1,n4);
	deleteElementAt(&l1,2);
	assertEqual(indexOf(l1,&d4),2);
	free(n1);
	free(n2);
	free(n3);
}

void test_deletElementAt_delets_tail_from_list(){
	int d1=3,d2=4,d3=5;
	void *result;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	Node *n3 = create_node((void*)d3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	deleteElementAt(&l1,2); 
	assertEqual(indexOf(l1,&d3),-1);
	free(n1);
	free(n2);
	free(n3);
}

void test_deletElementAt_delets_head_from_list(){
	int d1=3,d2=4,d3=5;
	void *result;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	Node *n3 = create_node((void*)d3);
	LinkedList l1=createList();
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);
	deleteElementAt(&l1,0); 
	assertEqual(indexOf(l1,&d3),1);
	free(n1);
	free(n2);
	free(n3);
}

void test_asArray_puts_elements_datas_of_list_in_an_array(){
	int d1=5,d2=6,d3=7;
	int *array[3];
	LinkedList l1 = createList();
	Node* n1=create_node((void *)&d1);
	Node* n2=create_node((void *)&d2);
	Node* n3=create_node((void *)&d3);
	add_to_list(&l1, n1);
	add_to_list(&l1, n2);
	add_to_list(&l1, n3);
	assertEqual(asArray(l1, (void **)array), 3);
	assertEqual(*(array[0]), d1);
	assertEqual(*(array[1]), d2);
	assertEqual(*(array[2]), d3);
	free(n1);
	free(n2);
	free(n3);
}

void test_asArray_puts_all_ull_node_datas_in_an_array(){
	int d1=5,d2=6,d3=7;
	int *array[3];
	LinkedList l1 = createList();
	assertEqual(asArray(l1, (void **)array),0);
}

int findEvenData(void* num){
	return (int)((int*)num)%2==0;
}
 
void test_filter_will_filter_elements_from_the_list_which_has_int_daya(){
	int d1=3,d2=4,d3=5;
	void *result;
	Node *n1 = create_node((void*)d1);
	Node *n2 = create_node((void*)d2);
	Node *n3 = create_node((void*)d3);
	LinkedList l1=createList(),l2;
	add_to_list(&l1,n1);
	add_to_list(&l1,n2);
	add_to_list(&l1,n3);	
	l2 = *filter(l1,findEvenData);
	assertEqual(l2.count,1);
}
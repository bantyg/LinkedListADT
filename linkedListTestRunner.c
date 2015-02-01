#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_to_create_linked_list,test_to_create_a_node,test_to_add_one_node_in_linked_list_with_int_data,test_to_add_one_node_in_linked_list_with_char_data,test_to_add_more_than_one_node_in_linked_list,test_get_first_element_gives_the_first_element_of_the_list,test_get_last_element_gives_the_last_element_of_the_list,test_traverse_goes_through_each_element_of_the_list_with_int_data,test_traverse_goes_through_each_element_of_the_list_with_char_data,test_getElementAt_gives_element_of_given_index_from_list,test_getElementAt_gives_NULL_when_index_is_greater_than_count,test_getElementAt_gives_NULL_when_index_is_equal_to_count,test_getElementAt_gives_element_of_given_index_from_list_for_char_data,test_getElementAt_gives_element_of_given_index_from_list_for_string_data,test_indexOf_gives_index_of_given_element_of_list,test_indexOf_gives_index_of_given_element_of_list_for_char_data,test_indexOf_gives_index_of_given_element_of_list_for_string_data,test_deletElementAt_delets_given_index_element_from_list,test_deletElementAt_delets_given_index_element_from_list_for_four_nodes,test_deletElementAt_delets_tail_from_list,test_deletElementAt_delets_head_from_list,test_asArray_puts_elements_datas_of_list_in_an_array,test_asArray_puts_all_ull_node_datas_in_an_array;
Test test[] = {"test_to_create_linked_list",test_to_create_linked_list,"test_to_create_a_node",test_to_create_a_node,"test_to_add_one_node_in_linked_list_with_int_data",test_to_add_one_node_in_linked_list_with_int_data,"test_to_add_one_node_in_linked_list_with_char_data",test_to_add_one_node_in_linked_list_with_char_data,"test_to_add_more_than_one_node_in_linked_list",test_to_add_more_than_one_node_in_linked_list,"test_get_first_element_gives_the_first_element_of_the_list",test_get_first_element_gives_the_first_element_of_the_list,"test_get_last_element_gives_the_last_element_of_the_list",test_get_last_element_gives_the_last_element_of_the_list,"test_traverse_goes_through_each_element_of_the_list_with_int_data",test_traverse_goes_through_each_element_of_the_list_with_int_data,"test_traverse_goes_through_each_element_of_the_list_with_char_data",test_traverse_goes_through_each_element_of_the_list_with_char_data,"test_getElementAt_gives_element_of_given_index_from_list",test_getElementAt_gives_element_of_given_index_from_list,"test_getElementAt_gives_NULL_when_index_is_greater_than_count",test_getElementAt_gives_NULL_when_index_is_greater_than_count,"test_getElementAt_gives_NULL_when_index_is_equal_to_count",test_getElementAt_gives_NULL_when_index_is_equal_to_count,"test_getElementAt_gives_element_of_given_index_from_list_for_char_data",test_getElementAt_gives_element_of_given_index_from_list_for_char_data,"test_getElementAt_gives_element_of_given_index_from_list_for_string_data",test_getElementAt_gives_element_of_given_index_from_list_for_string_data,"test_indexOf_gives_index_of_given_element_of_list",test_indexOf_gives_index_of_given_element_of_list,"test_indexOf_gives_index_of_given_element_of_list_for_char_data",test_indexOf_gives_index_of_given_element_of_list_for_char_data,"test_indexOf_gives_index_of_given_element_of_list_for_string_data",test_indexOf_gives_index_of_given_element_of_list_for_string_data,"test_deletElementAt_delets_given_index_element_from_list",test_deletElementAt_delets_given_index_element_from_list,"test_deletElementAt_delets_given_index_element_from_list_for_four_nodes",test_deletElementAt_delets_given_index_element_from_list_for_four_nodes,"test_deletElementAt_delets_tail_from_list",test_deletElementAt_delets_tail_from_list,"test_deletElementAt_delets_head_from_list",test_deletElementAt_delets_head_from_list,"test_asArray_puts_elements_datas_of_list_in_an_array",test_asArray_puts_elements_datas_of_list_in_an_array,"test_asArray_puts_all_ull_node_datas_in_an_array",test_asArray_puts_all_ull_node_datas_in_an_array};
char testFileName[] = {"linkedListTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}
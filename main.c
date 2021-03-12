////#include "dlink_list.h"
//
//int main(void)
//{
//	//dLink_List* list = create_list();
//	//int value1 = 1;
//	//push_front(&value1);
//	//int value2 = 2;
//	//push_front(&value2);
//	//int value3 = 3;
//	//push_front(&value3);
//	//int value4 = 1020;
//	//push_front(&value4);
//	////empty();
//	////erase(3);
//	////pop_front();
//	////pop_front();
//	////pop_back();
//	////int value_1 = *(int*)get_pos(0);
//	////int value_2 = *(int*)get_pos(1);
//	////int value_3 = *(int*)get_pos(2);
//	////int value_4 = *(int*)get_pos(3);
//
//	//int value_1 = *(int*)back();
//	//int value_2 = *(int*)front();
//
//
//	//clear();
//
//	//empty();
//
//	return 0;
//}

#include "slink_list.h"

int main(void)
{
	slink_list* list = create_list();
	int value1 = 1;
	push_back(&value1);
	int value2 = 3;
	push_back(&value2);
	int value3 = 3;
	push_back(&value3);


	clear();
	return 0;
}
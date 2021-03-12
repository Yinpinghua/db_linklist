#include "slink_list.h"

static slink_list* list = NULL;

//创建节点
static slink_node* create_node(void* pval)
{
	slink_node* cur_node = NULL;
	cur_node = (slink_node*)malloc(sizeof(slink_node));
	if (cur_node == NULL) {
		printf("create node error!\n");
		return NULL;
	}

	//节点数据域值为pval
	cur_node->data = pval;
	cur_node->next = NULL;

	return cur_node;
}

slink_list* create_list(void)
{
	list = (slink_list*)malloc(sizeof(slink_list));
	slink_node* new_node = NULL;
	new_node = create_node(NULL);

	if (new_node == NULL) {
		return NULL;
	}

	list->header = new_node;
	//设置节点个数为0
	list->count = 0;

	return list;
}

int push_back(void* pval)
{
	if (list == NULL) {
		printf("failed! list is empty!\n");
		return -1;
	}

	slink_node* cur_node = NULL;

	cur_node = create_node(pval);
	if (cur_node == NULL) {
		return -1;
	}

	cur_node->next = list->header;
	list->header = cur_node;
	list->count++;

	return 0;
}

extern int clear(void)
{
	if (list == NULL) {
		printf("failed! list is empty!\n");
		return -1;
	}

	if (list->header == NULL){
		printf("failed! list is NULL!\n");
		return -1;
	}

	slink_node* cur_node = list->header->next;
	while (cur_node!= NULL){
		slink_node* temp_node = cur_node;
		cur_node = cur_node->next;
		free(temp_node);
		temp_node = NULL;
	}

	list->count = 0;
	list->header = NULL;
	free(list);
	list = NULL;
	return 0;
}

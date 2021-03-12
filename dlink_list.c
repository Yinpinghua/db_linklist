#include "dlink_list.h"

static dLink_List* list = NULL;

/******************************************************************************
 *   局 部 函 数 声 明
 ******************************************************************************/
static dlink_node* create_node(void* pval);		//创建节点
static dlink_node* pos_find(unsigned int index);//获取index位置节点
static dlink_node* get_head_node(void);
static dlink_node* get_tail_node(void);

/******************************************************************************
 *
 * 函 数 名 : create_node
 *
 * 函数功能 : 新建节点。成功，返回节点指针；否则返回FULL。
 *
 * 参    数 : void * pval   - 节点数据域的值
 *
 * 返 回 值 : dlink_node - 节点指针
 *
 * 备    注 :
 *
 ******************************************************************************/
dlink_node* create_node(void* pval)
{
	dlink_node* cur_node = NULL;
	cur_node = (dlink_node*)malloc(sizeof(dlink_node));

	if (cur_node==NULL){
		printf("create node error!\n");
		return NULL;
	}

	//默认pNode的前一节点和后一节点都指向它自身
	cur_node->prev = cur_node->next = cur_node;
	//节点数据域值为pval
	cur_node->data = pval;

	return cur_node;
}

/******************************************************************************
 *
 * 函 数 名 : pos_find
 *
 * 函数功能 : 获取第index位置的节点，返回该节点指针
 *
 * 参    数 : List list   - 链表
 *            int index   - 第index个位置节点
 *
 * 返 回 值 : dlink_node - 第index位置节点指针
 *
 * 备    注 :
 *
 ******************************************************************************/
dlink_node* pos_find(unsigned int index)
{
	if (list ==NULL){
		printf("failed! list is empty!\n");
		return NULL;
	}

	unsigned int i = 0;
	unsigned int j = 0;
	dlink_node* cur_node = NULL;

	if ((index < 0) || (index >=list->count)){
		printf("failed! index out of bound!\n");
		return NULL;
	}

	//正向查找
	if (index <= (list->count / 2)){
		cur_node = list->head->next;
		while ((i++ < index)){
			cur_node = cur_node->next;
		}
	}else{
		//反向查找
		cur_node = list->head->prev;
		while ((j++) < (list->count - index - 1)){
			cur_node = cur_node->prev;
		}
	}

	return cur_node;
}

/******************************************************************************
 *
 * 函 数 名 : get_head_node
 *
 * 函数功能 : 获取链表头节点
 *
 * 参    数 : List list   - 双向链表
 *
 * 返 回 值 : dlink_node
 *
 * 备    注 :
 *
 ******************************************************************************/
dlink_node* get_head_node(void)
{
	return pos_find(0);
}

/******************************************************************************
 *
 * 函 数 名 : get_tail_node
 *
 * 函数功能 : 获取链表尾节点
 *
 * 参    数 : List list   - 双向链表
 *
 * 返 回 值 : dlink_node
 *
 * 备    注 :
 *
 ******************************************************************************/
dlink_node* get_tail_node(void)
{
	return pos_find(list->count - 1);
}

/******************************************************************************
 *
 * 函 数 名 : create_list
 *
 * 函数功能 : 新建双向链表。成功，则返回链表，否则为空
 *
 * 参    数 : 无
 *
 * 返 回 值 :dLink_List
 *
 * 备    注 :
 *
 ******************************************************************************/
dLink_List* create_list(void)
{
	list = (dLink_List*)malloc(sizeof(dLink_List));
	dlink_node* new_node = NULL;
	new_node = create_node(NULL);

	if (new_node == NULL){
		return NULL;
	}

	list->head = new_node;
	//设置节点个数为0
	list->count = 0;

	return list;
}

/******************************************************************************
 *
 * 函 数 名 : empty
 *
 * 函数功能 : 链表为空则返回1，不为空返回0
 *
 * 参    数 : List list   - 双向链表
 *
 * 返 回 值 : int - 是否为空
 *
 * 备    注 :
 *
 ******************************************************************************/
int empty(void)
{
	if (list == NULL){
		return 1;
	}

	return (list->count == 0);
}

/******************************************************************************
 *
 * 函 数 名 : size
 *
 * 函数功能 : 返回链表当前节点数
 *
 * 参    数 : List list   - 双向链表
 *
 * 返 回 值 : int - 链表节点数
 *
 * 备    注 :
 *
 ******************************************************************************/
int size(void)
{
	if (list == NULL) {
		return 0;
	}

	return list->count;
}

/******************************************************************************
 *
 * 函 数 名 : search
 *
 * 函数功能 : 获取双向链表中第index位置的元素。成功则返回节点值；否则返回-1
 *
 * 参    数 : List list   - 双向链表
 *            int index   - 获取节点的位置
 *
 * 返 回 值 : void*
 *
 * 备    注 :
 *
 ******************************************************************************/
void* search(int index)
{
	dlink_node* node_index = pos_find(index);
	if (node_index == NULL){
		printf("failed!\n");
		return NULL;
	}

	return node_index->data;
}

void* front(void)
{
	return search(0);
}

void* back(void)
{
	return search(list->count - 1);
}

/******************************************************************************
 *
 * 函 数 名 : pos_insert
 *
 * 函数功能 : 将pval插入到index位置。成功返回0，否则返回-1
 *
 * 参    数 : List list     - 双向链表
 *            int index     - 插入位置
 *            void * pval   - 插入值
 *
 * 返 回 值 : int - 是否成功
 *
 * 备    注 :
 *
 ******************************************************************************/
int pos_insert(int index, void* pval)
{
	if (list == NULL){
		printf("failed! list is empty!\n");
		return -1;
	}

	dlink_node* node_index;
	dlink_node* cur_node;

	//插入表头
	if (index == 0){
		return push_front(pval);
	}

	//获取要插入位置对应的节点
	node_index = pos_find(index);
	if (node_index==NULL){
		return -1;
	}

	//创建节点
	cur_node = create_node(pval);
	if (cur_node == NULL){
		return -1;
	}

	cur_node->next = node_index;
	cur_node->prev = node_index->prev;
	node_index->prev->next = cur_node;
	node_index->prev = cur_node;
	//节点数+1
	list->count++;

	return 0;
}

/******************************************************************************
 *
 * 函 数 名 : push_front
 *
 * 函数功能 : 在双向链表表头插入pval，成功返回0
 *
 * 参    数 : List list     - 双向链表
 *            void * pval   - 插入值
 *
 * 返 回 值 : int - 返回是否成功
 *
 * 备    注 :
 *
 ******************************************************************************/
int push_front(void* pval)
{
	if (list == NULL) {
		printf("failed! list is empty!\n");
		return -1;
	}

	dlink_node* cur_node = create_node(pval);
	if (cur_node ==NULL){
		return -1;
	}

	cur_node->prev = list->head;
	cur_node->next = list->head->next;
	list->head->next->prev = cur_node;
	list->head->next = cur_node;

	//节点数+1
	list->count++;

	return 0;
}

/******************************************************************************
 *
 * 函 数 名 : push_back
 *
 * 函数功能 : 插入pval到双向链表表尾，成功返回0
 *
 * 参    数 : List list     - 双向链表
 *            void * pval   - 插入值
 *
 * 返 回 值 : int - 返回是否插入成功
 *
 * 备    注 :
 *
 ******************************************************************************/
int push_back(void* pval)
{
	if (list == NULL) {
		printf("failed! list is empty!\n");
		return -1;
	}

	dlink_node* cur_node =NULL;

	cur_node = create_node(pval);
	if (cur_node ==NULL){
		return -1;
	}

	cur_node->next = list->head;
	cur_node->prev = list->head->prev;
	list->head->prev->next = cur_node;
	list->head->prev = cur_node;

	list->count++;

	return 0;
}

/******************************************************************************
 *
 * 函 数 名 : erase
 *
 * 函数功能 : 删除双向链表中index位置节点，成功返回0
 *
 * 参    数 : List list   - 双向链表
 *            int index   - 删除节点的位置
 *
 * 返 回 值 : int - 是否删除成功
 *
 * 备    注 :
 *
 ******************************************************************************/
int erase(int index)
{
	if (list == NULL) {
		printf("failed! list is empty!\n");
		return -1;
	}

	dlink_node* cur_node =NULL;

	cur_node = pos_find(index);
	if (cur_node ==NULL){
		return -1;
	}

	cur_node->prev->next = cur_node->next;
	cur_node->next->prev = cur_node->prev;
	free(cur_node);

	list->count--;

	return 0;
}

/******************************************************************************
 *
 * 函 数 名 : head_delete
 *
 * 函数功能 : 删除表头节点,成功返回0
 *
 * 参    数 : List list   - 双向链表
 *
 * 返 回 值 : int - 是否删除成功
 *
 * 备    注 :
 *
 ******************************************************************************/
int pop_front(void)
{
	return erase(0);
}

/******************************************************************************
 *
 * 函 数 名 : pop_back
 *
 * 函数功能 : 删除表尾节点，成功返回0
 *
 * 参    数 : List list   - 双向链表
 *
 * 返 回 值 : int - 是否删除成功
 *
 * 备    注 :
 *
 ******************************************************************************/
int pop_back(void)
{
	return erase(list->count - 1);
}

/******************************************************************************
 *
 * 函 数 名 : clear
 *
 * 函数功能 : 销毁双向链表，成功返回0
 *
 * 参    数 : List list   - 双向链表
 *
 * 返 回 值 : int - 是否销毁成功
 *
 * 备    注 :
 *
 ******************************************************************************/
int clear(void)
{
	if (list == NULL) {
		printf("failed! list is empty!\n");
		return -1;
	}

	dlink_node* cur_node =NULL;
	dlink_node* temp_node = NULL;

	if (list->head==NULL){
		printf("failed! list is NULL!\n");
		return -1;
	}

	cur_node = list->head->next;
	while (cur_node != list->head){
		temp_node = cur_node;
		cur_node = cur_node->next;
		free(temp_node);
		temp_node = NULL;
	}

	free(list);
	list->head = NULL;
	list->count = 0;
	list = NULL;

	return 0;
}
#include "dlink_list.h"

static dLink_List* list = NULL;

/******************************************************************************
 *   �� �� �� �� �� ��
 ******************************************************************************/
static dlink_node* create_node(void* pval);		//�����ڵ�
static dlink_node* pos_find(unsigned int index);//��ȡindexλ�ýڵ�
static dlink_node* get_head_node(void);
static dlink_node* get_tail_node(void);

/******************************************************************************
 *
 * �� �� �� : create_node
 *
 * �������� : �½��ڵ㡣�ɹ������ؽڵ�ָ�룻���򷵻�FULL��
 *
 * ��    �� : void * pval   - �ڵ��������ֵ
 *
 * �� �� ֵ : dlink_node - �ڵ�ָ��
 *
 * ��    ע :
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

	//Ĭ��pNode��ǰһ�ڵ�ͺ�һ�ڵ㶼ָ��������
	cur_node->prev = cur_node->next = cur_node;
	//�ڵ�������ֵΪpval
	cur_node->data = pval;

	return cur_node;
}

/******************************************************************************
 *
 * �� �� �� : pos_find
 *
 * �������� : ��ȡ��indexλ�õĽڵ㣬���ظýڵ�ָ��
 *
 * ��    �� : List list   - ����
 *            int index   - ��index��λ�ýڵ�
 *
 * �� �� ֵ : dlink_node - ��indexλ�ýڵ�ָ��
 *
 * ��    ע :
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

	//�������
	if (index <= (list->count / 2)){
		cur_node = list->head->next;
		while ((i++ < index)){
			cur_node = cur_node->next;
		}
	}else{
		//�������
		cur_node = list->head->prev;
		while ((j++) < (list->count - index - 1)){
			cur_node = cur_node->prev;
		}
	}

	return cur_node;
}

/******************************************************************************
 *
 * �� �� �� : get_head_node
 *
 * �������� : ��ȡ����ͷ�ڵ�
 *
 * ��    �� : List list   - ˫������
 *
 * �� �� ֵ : dlink_node
 *
 * ��    ע :
 *
 ******************************************************************************/
dlink_node* get_head_node(void)
{
	return pos_find(0);
}

/******************************************************************************
 *
 * �� �� �� : get_tail_node
 *
 * �������� : ��ȡ����β�ڵ�
 *
 * ��    �� : List list   - ˫������
 *
 * �� �� ֵ : dlink_node
 *
 * ��    ע :
 *
 ******************************************************************************/
dlink_node* get_tail_node(void)
{
	return pos_find(list->count - 1);
}

/******************************************************************************
 *
 * �� �� �� : create_list
 *
 * �������� : �½�˫�������ɹ����򷵻���������Ϊ��
 *
 * ��    �� : ��
 *
 * �� �� ֵ :dLink_List
 *
 * ��    ע :
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
	//���ýڵ����Ϊ0
	list->count = 0;

	return list;
}

/******************************************************************************
 *
 * �� �� �� : empty
 *
 * �������� : ����Ϊ���򷵻�1����Ϊ�շ���0
 *
 * ��    �� : List list   - ˫������
 *
 * �� �� ֵ : int - �Ƿ�Ϊ��
 *
 * ��    ע :
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
 * �� �� �� : size
 *
 * �������� : ��������ǰ�ڵ���
 *
 * ��    �� : List list   - ˫������
 *
 * �� �� ֵ : int - ����ڵ���
 *
 * ��    ע :
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
 * �� �� �� : search
 *
 * �������� : ��ȡ˫�������е�indexλ�õ�Ԫ�ء��ɹ��򷵻ؽڵ�ֵ�����򷵻�-1
 *
 * ��    �� : List list   - ˫������
 *            int index   - ��ȡ�ڵ��λ��
 *
 * �� �� ֵ : void*
 *
 * ��    ע :
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
 * �� �� �� : pos_insert
 *
 * �������� : ��pval���뵽indexλ�á��ɹ�����0�����򷵻�-1
 *
 * ��    �� : List list     - ˫������
 *            int index     - ����λ��
 *            void * pval   - ����ֵ
 *
 * �� �� ֵ : int - �Ƿ�ɹ�
 *
 * ��    ע :
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

	//�����ͷ
	if (index == 0){
		return push_front(pval);
	}

	//��ȡҪ����λ�ö�Ӧ�Ľڵ�
	node_index = pos_find(index);
	if (node_index==NULL){
		return -1;
	}

	//�����ڵ�
	cur_node = create_node(pval);
	if (cur_node == NULL){
		return -1;
	}

	cur_node->next = node_index;
	cur_node->prev = node_index->prev;
	node_index->prev->next = cur_node;
	node_index->prev = cur_node;
	//�ڵ���+1
	list->count++;

	return 0;
}

/******************************************************************************
 *
 * �� �� �� : push_front
 *
 * �������� : ��˫�������ͷ����pval���ɹ�����0
 *
 * ��    �� : List list     - ˫������
 *            void * pval   - ����ֵ
 *
 * �� �� ֵ : int - �����Ƿ�ɹ�
 *
 * ��    ע :
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

	//�ڵ���+1
	list->count++;

	return 0;
}

/******************************************************************************
 *
 * �� �� �� : push_back
 *
 * �������� : ����pval��˫�������β���ɹ�����0
 *
 * ��    �� : List list     - ˫������
 *            void * pval   - ����ֵ
 *
 * �� �� ֵ : int - �����Ƿ����ɹ�
 *
 * ��    ע :
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
 * �� �� �� : erase
 *
 * �������� : ɾ��˫��������indexλ�ýڵ㣬�ɹ�����0
 *
 * ��    �� : List list   - ˫������
 *            int index   - ɾ���ڵ��λ��
 *
 * �� �� ֵ : int - �Ƿ�ɾ���ɹ�
 *
 * ��    ע :
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
 * �� �� �� : head_delete
 *
 * �������� : ɾ����ͷ�ڵ�,�ɹ�����0
 *
 * ��    �� : List list   - ˫������
 *
 * �� �� ֵ : int - �Ƿ�ɾ���ɹ�
 *
 * ��    ע :
 *
 ******************************************************************************/
int pop_front(void)
{
	return erase(0);
}

/******************************************************************************
 *
 * �� �� �� : pop_back
 *
 * �������� : ɾ����β�ڵ㣬�ɹ�����0
 *
 * ��    �� : List list   - ˫������
 *
 * �� �� ֵ : int - �Ƿ�ɾ���ɹ�
 *
 * ��    ע :
 *
 ******************************************************************************/
int pop_back(void)
{
	return erase(list->count - 1);
}

/******************************************************************************
 *
 * �� �� �� : clear
 *
 * �������� : ����˫�������ɹ�����0
 *
 * ��    �� : List list   - ˫������
 *
 * �� �� ֵ : int - �Ƿ����ٳɹ�
 *
 * ��    ע :
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
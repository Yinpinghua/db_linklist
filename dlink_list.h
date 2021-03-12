#ifndef dlink_list_h__
#define dlink_list_h__

#include <stdio.h>
#include <stdlib.h>

typedef struct dlink_node		//˫������ڵ�����
{
	struct dlink_node* prev;
	struct dlink_node* next;
	void* data;
}dlink_node;

typedef struct dLink_List
{
	dlink_node* head;			//��¼����ͷ
	unsigned int count;			//��¼����Ԫ�ظ���
}dLink_List;

extern dLink_List* create_list(void);				//����˫�������ɹ���������ָ�룬���򷵻�NULL
extern int empty(void);			//�����Ƿ�Ϊ�ա�Ϊ�շ���1�����򷵻�0
extern int size(void);			//����˫�������С
extern int clear(void);			//���������ɹ�����0�����򷵻�-1
extern void* search(int index);//��ȡ�����е�indexλ��Ԫ�ء��ɹ����ؽڵ�ָ�룬���򷵻�NULL,��0��ʼ,���Ϊsize-1
extern void* front(void);		//��ȡ�����һ��Ԫ�ء��ɹ����ؽڵ�ָ�룬���򷵻�NULL
extern void* back(void);		//��ȡ�������һ��Ԫ�ء��ɹ����ؽڵ�ָ�룬���򷵻�NULL
extern int pos_insert(int index, void* pval);//��val���뵽indexλ�á��ɹ�����0�����򷵻�-1
extern int push_front(void* pval);//���뵽��ͷ���ɹ�����0�����򷵻�-1
extern int push_back(void* pval);//���뵽��β���ɹ�����0�����򷵻�-1
extern int erase(int index);//ɾ�������е�indexλ�ýڵ㡣�ɹ�����0�����򷵻�-1,��0��ʼ,���Ϊsize-1
extern int pop_front(void);	//ͷɾ��
extern int pop_back(void);	//βɾ��

#endif // dlink_list_h__

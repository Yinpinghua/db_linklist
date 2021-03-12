#ifndef slink_list_h__
#define slink_list_h__

#include <stdio.h>
#include <stdlib.h>

typedef struct slink_node		//��������ڵ�����
{
	struct slink_node* next;
	void* data;
}slink_node;


typedef struct slink_list
{
	struct slink_node* header;
	int count;
}slink_list;

//������������
extern slink_list* create_list(void);
extern int push_back(void* pval);//���뵽��β���ɹ�����0�����򷵻�-1
extern int clear(void);
#endif // slink_list_h__

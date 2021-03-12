#ifndef slink_list_h__
#define slink_list_h__

#include <stdio.h>
#include <stdlib.h>

typedef struct slink_node		//单向链表节点类型
{
	struct slink_node* next;
	void* data;
}slink_node;


typedef struct slink_list
{
	struct slink_node* header;
	int count;
}slink_list;

//创建单向链表
extern slink_list* create_list(void);
extern int push_back(void* pval);//插入到表尾。成功返回0，否则返回-1
extern int clear(void);
#endif // slink_list_h__

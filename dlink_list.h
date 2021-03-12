#ifndef dlink_list_h__
#define dlink_list_h__

#include <stdio.h>
#include <stdlib.h>

typedef struct dlink_node		//双向链表节点类型
{
	struct dlink_node* prev;
	struct dlink_node* next;
	void* data;
}dlink_node;

typedef struct dLink_List
{
	dlink_node* head;			//记录链表头
	unsigned int count;			//记录链表元素个数
}dLink_List;

extern dLink_List* create_list(void);				//创建双向链表。成功返回链表指针，否则返回NULL
extern int empty(void);			//链表是否为空。为空返回1，否则返回0
extern int size(void);			//返回双向链表大小
extern int clear(void);			//销毁链表，成功返回0，否则返回-1
extern void* search(int index);//获取链表中第index位置元素。成功返回节点指针，否则返回NULL,从0开始,最大为size-1
extern void* front(void);		//获取链表第一个元素。成功返回节点指针，否则返回NULL
extern void* back(void);		//获取链表最后一个元素。成功返回节点指针，否则返回NULL
extern int pos_insert(int index, void* pval);//将val插入到index位置。成功返回0，否则返回-1
extern int push_front(void* pval);//插入到表头。成功返回0，否则返回-1
extern int push_back(void* pval);//插入到表尾。成功返回0，否则返回-1
extern int erase(int index);//删除链表中第index位置节点。成功返回0，否则返回-1,从0开始,最大为size-1
extern int pop_front(void);	//头删除
extern int pop_back(void);	//尾删除

#endif // dlink_list_h__

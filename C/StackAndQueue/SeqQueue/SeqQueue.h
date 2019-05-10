#ifndef SEQQUEUE_H
#define SEQQUEUE_H

typedef int DataType;

struct Queue
{
	int MAX;	//循环队列的最大容量
	int f;		//队头
	int r;		//队尾
	DataType *elem;	//队列元素起始位置
};
typedef struct Queue *SeqQueue;

/****************************************************************/
/* SeqQueue SetNullQueue_seq(int m)								*/
/* 功能:创建空的循环队列										*/
/* 输入参数:无													*/						
/* 返回值:空的循环队列											*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
SeqQueue SetNullQueue_seq(int m);

/****************************************************************/
/* int IsNullQueue_seq(SeqQueue squeue)							*/
/* 功能:判断一个循环队列是否为空								*/
/* 输入参数:squeue--循环队列指针								*/
/* 返回值:空队列返回1,否则返回0									*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_seq(SeqQueue squeue);

/****************************************************************/
/* void EnQueue_seq(SeqQueue squeue, DataType x)				*/
/* 功能:进队													*/
/* 输入参数:squeue--循环队列指针	x--进队元素					*/
/* 返回值:无													*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_seq(SeqQueue squeue, DataType x);

/****************************************************************/
/* void DeQueue_seq(SeqQueue squeue)							*/
/* 功能:出队													*/
/* 输入参数:squeue--循环队列指针								*/
/* 返回值:无													*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_seq(SeqQueue squeue);

/****************************************************************/
/* DataType FrontQueue_seq(SeqQueue squeue)						*/
/* 功能:求队头元素的值											*/
/* 输入参数:squeue--循环队列指针								*/
/* 返回值:无													*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
DataType FrontQueue_seq(SeqQueue squeue);

#endif	// SEQQUEUE_H

#ifndef MYSTACKBASIC_H
#define MYSTACKBASIC_H
/************************************************************************/
/* 栈类:                                                                */
/*     MyStack(int size);   //分配内存初始化栈空间,设定栈容量,栈顶      */
/*     ~MyStack();          //回收栈空间内存                            */
/*     bool stackEmpty();   //判定栈是否为空,为空返回true,非空返回false */
/*     bool stackFull();    //判定栈是否为满,为满返回true,不满返回false */
/*     void clearStack();   //清空栈                                    */
/*     int stackLength();   //统计已有元素的个数                        */
/*     void push(char elem);	//元素入栈,栈顶上升                     */
/*     char pop(char &elem);    //元素出栈,栈顶下降                     */
/*     void stackTraverse();    //遍历栈中所有元素                      */
/*                                                                      */
/* 目的:掌握栈的实现原理和运行机制               创建日期:2019-03-10    */
/************************************************************************/

class MyStack
{
public:
	MyStack(int size);		//分配内存初始化栈空间,设定栈容量,栈顶      
	~MyStack();				//回收栈空间内存                            
	bool stackEmpty();		//判定栈是否为空,为空返回true,非空返回false 
	bool stackFull();		//判定栈是否为满,为满返回true,不满返回false 
	void clearStack();		//清空栈                                    
	int stackLength();		//统计已有元素的个数                        
	void push(char elem);	//元素入栈,栈顶上升  
	//bool push(char elem);
	char pop(char &elem);   //元素出栈,栈顶下降 
	//char pop();
	//bool pop(char &elem);
	void stackTraverse();   //遍历栈中所有元素
	//void stackTraverse(bool isFromButtom)
private:
	char *m_pBuffer;		//栈空间指针,指针指向栈空间
	int m_iSize;			//栈容量
	int m_iTop;				//栈顶,栈中元素个数
	//栈底不用写,因为栈底永远都是0,不可能变化
};

#endif
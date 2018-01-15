#pragma once
template<class T>
//通用栈接口
class Stock
{
public:
	virtual bool push(T t)=0;
	virtual bool pop(T& t)=0;
	virtual int get_height()=0;
	virtual bool is_empty()=0;
	virtual bool get_top(T& t)=0;
	virtual void clear() = 0;
};
template<class T>
class Queue
{
	virtual bool enQueue(T t) = 0;
	virtual bool deQueue(T& t) = 0;
	virtual bool is_empty() = 0;
	virtual bool is_full() = 0;
	virtual void clear() = 0;
};
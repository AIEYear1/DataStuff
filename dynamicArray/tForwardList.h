#pragma once

template <typename T>
class tForwardList
{
	struct node
	{
		T data;
		node *next;
	};

	node *head;

public:
	tForwardList();
	tForwardList(const tForwardList &other);
	~tForwardList();

	void push_front(const T &val);
	void pop_front();

	T &front();
	const T &front() const;

	void remove(const T &val);
	void clear();

	bool empty() const;

	tForwardList &operator=(const tForwardList &rhs);

	/*class iterator
	{
		tForwardList *list;
		node cur;

	public:
		iterator();
		iterator(node *startNode);

		bool operator ==(iterator rhs);
		bool operator !=(iterator rhs);

		T &operator++();
		T operator++(int);
	};*/

	//iterator begin();
	//iterator end();
};

//template <typename T>
//tForwardList<T>::iterator::iterator()
//{
//	vector = nullptr;
//	cur = nullptr;
//}
//template <typename T>
//tForwardList<T>::iterator::iterator(node *startNode)
//{
//	vector = startNode;
//}
//
//template <typename T>
//bool tForwardList<T>::iterator::operator ==(iterator rhs)
//{
//	return (vector == rhs.vector) && (cur == rhs.cur);
//}
//template <typename T>
//bool tForwardList<T>::iterator::operator !=(iterator rhs)
//{
//	return (vector != rhs.vector) || (cur != rhs.cur);
//}
//
//template <typename T>
//T &tForwardList<T>::iterator::operator++()
//{
//	return &vector[++cur];
//}
//template <typename T>
//T tForwardList<T>::iterator::operator++(int)
//{
//	return &vector[cur++];
//}
//
//
//template <typename T>
//typename tForwardList<T>::iterator tForwardList<T>::begin()
//{
//	return iterator(this, 0);
//}
//template <typename T>
//typename tForwardList<T>::iterator tForwardList<T>::end()
//{
//	return iterator(this, arrSize);
//}

template <typename T>
tForwardList<T>::tForwardList()
{
	head = nullptr;
}

template <typename T>
tForwardList<T>::~tForwardList()
{
	while (head != nullptr)
	{
		pop_front();
	}
}
template <typename T>
tForwardList<T>::tForwardList(const tForwardList &other)
{
	head = new node{ other.head->data, nullptr };

	node *tmpBaseNode = other.head->next;
	node *tmpCopyNode = head;

	while (tmpBaseNode != nullptr)
	{
		(*tmpCopyNode).next = new node{ tmpBaseNode->data, nullptr };

		tmpBaseNode = tmpBaseNode->next;
		tmpCopyNode = tmpCopyNode->next;
	}
}
template <typename T>
tForwardList<T> &tForwardList<T>::operator=(const tForwardList &rhs)
{
	head = new node{ rhs.head->data, nullptr };

	node *tmpBaseNode = rhs.head->next;
	node *tmpCopyNode = head;

	while (tmpBaseNode != nullptr)
	{
		(*tmpCopyNode).next = new node{ tmpBaseNode->data, nullptr };

		tmpBaseNode = tmpBaseNode->next;
		tmpCopyNode = tmpCopyNode->next;
	}

	return *this;
}

template <typename T>
void tForwardList<T>::push_front(const T &val)
{
	node *oldHead = head;
	head = new node{ val, oldHead };
}
template <typename T>
void tForwardList<T>::pop_front()
{
	node *newHead = head->next;
	delete head;
	head = newHead;
}

template <typename T>
T &tForwardList<T>::front()
{
	return head->data;
}
template <typename T>
const T &tForwardList<T>::front() const
{
	return head->data;
}

template <typename T>
void tForwardList<T>::remove(const T &val)
{
	node **tmpNode = &head;

	while ((*tmpNode)->next->data != val)
	{
		tmpNode = &((*tmpNode)->next);
	}

	node *tmpNode2 = (*tmpNode)->next->next;
	delete (*tmpNode)->next;
	(*tmpNode)->next = tmpNode2;
}
template <typename T>
void tForwardList<T>::clear()
{
	node *tmpNode = head;

	while (tmpNode != nullptr)
	{
		node *subNode = tmpNode->next;
		delete tmpNode;
		tmpNode = subNode;
	}

	head = nullptr;
}

template <typename T>
bool tForwardList<T>::empty() const
{
	return head == nullptr;
}

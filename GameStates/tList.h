#pragma once

template <typename T>
class tList
{
	struct node
	{
		T data;
		node *next;
		node *prev;
	};

	node *head;
	node *tail;

public:
	tList();
	tList(const tList &other);
	~tList();

	void push_front(const T &val);
	void pop_front();
	void push_back(const T &val);
	void pop_back();

	T &front();
	const T &front() const;

	void remove(const T &val);
	void clear();

	bool empty() const;

	tList &operator=(const tList &rhs);

	class iterator
	{
		tList *list;
		node *cur;

	public:
		iterator();
		iterator(tList *List, node *startNode);

		bool operator ==(iterator rhs);
		bool operator !=(iterator rhs);

		T &operator++();
		T operator++(int);
	};

	iterator begin();
	iterator end();
};

template <typename T>
tList<T>::iterator::iterator()
{
	list = nullptr;
	cur = nullptr;
}
template <typename T>
tList<T>::iterator::iterator(tList *List, node *startNode)
{
	list = List;
	cur = startNode;
}

template <typename T>
bool tList<T>::iterator::operator ==(iterator rhs)
{
	return (list == rhs.list) && (cur == rhs.cur);
}
template <typename T>
bool tList<T>::iterator::operator !=(iterator rhs)
{
	return (list != rhs.list) || (cur != rhs.cur);
}

template <typename T>
T &tList<T>::iterator::operator++()
{
	cur = cur->next;
	return &(cur->data);
}
template <typename T>
T tList<T>::iterator::operator++(int)
{
	cur = cur->next;
	return cur->prev->data;
}


template <typename T>
typename tList<T>::iterator tList<T>::begin()
{
	return iterator(this, head);
}
template <typename T>
typename tList<T>::iterator tList<T>::end()
{
	return iterator(this, tail->next);
}

template <typename T>
tList<T>::tList()
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
tList<T>::~tList()
{
	while (head != nullptr)
	{
		pop_front();
	}
}
template <typename T>
tList<T>::tList(const tList &other)
{
	head = new node{ other.head->data, nullptr, nullptr };

	node *tmpBaseNode = other.head->next;
	node *tmpCopyNode = head;
	node *tmpPrevNode = nullptr;

	while (tmpBaseNode != nullptr)
	{
		(*tmpCopyNode).next = new node{ tmpBaseNode->data, nullptr, nullptr };
		tmpCopyNode->prev = tmpPrevNode;

		tmpPrevNode = tmpCopyNode;
		tmpCopyNode = tmpCopyNode->next;

		tmpBaseNode = tmpBaseNode->next;
	}

	tail = tmpCopyNode;
}
template <typename T>
tList<T> &tList<T>::operator=(const tList &rhs)
{
	head = new node{ rhs.head->data, nullptr, nullptr };

	node *tmpBaseNode = rhs.head->next;
	node *tmpCopyNode = head;
	node *tmpPrevNode = nullptr;

	while (tmpBaseNode != nullptr)
	{
		(*tmpCopyNode).next = new node{ tmpBaseNode->data, nullptr, nullptr };
		tmpCopyNode->prev = tmpPrevNode;

		tmpPrevNode = tmpCopyNode;
		tmpCopyNode = tmpCopyNode->next;

		tmpBaseNode = tmpBaseNode->next;
	}

	tail = tmpCopyNode;

	return *this;
}

template <typename T>
void tList<T>::push_front(const T &val)
{
	node *oldHead = head;
	head = new node{ val, oldHead, nullptr };
	if (oldHead != nullptr)
	{
		oldHead->prev = head;
	}

	if (tail == nullptr)
	{
		node *tmpNode = head;
		while (tmpNode->next != nullptr)
		{
			tmpNode = tmpNode->next;
		}

		tail = tmpNode;
	}
}
template <typename T>
void tList<T>::pop_front()
{
	node *newHead = head->next;
	delete head;
	head = newHead;
	head->prev = nullptr;
}
template <typename T>
void tList<T>::push_back(const T &val)
{
	node *oldTail = tail;
	tail = new node{ val, nullptr, tail };
	oldTail->next = tail;
}
template <typename T>
void tList<T>::pop_back()
{
	node *newTail = tail->prev;
	delete tail;
	tail = newTail;
	tail->next = nullptr;
}

template <typename T>
T &tList<T>::front()
{
	return head->data;
}
template <typename T>
const T &tList<T>::front() const
{
	return head->data;
}

template <typename T>
void tList<T>::remove(const T &val)
{
	node **tmpNode = &head;

	while ((*tmpNode)->next->data != val)
	{
		tmpNode = &((*tmpNode)->next);
	}

	node *tmpNode2 = (*tmpNode)->next->next;
	delete (*tmpNode)->next;
	(*tmpNode)->next = tmpNode2;
	tmpNode2->prev = (*tmpNode);
}
template <typename T>
void tList<T>::clear()
{
	node *tmpNode = head;

	while (tmpNode != nullptr)
	{
		node *subNode = tmpNode->next;
		delete tmpNode;
		tmpNode = subNode;
	}

	head = nullptr;
	tail = nullptr;
}

template <typename T>
bool tList<T>::empty() const
{
	return head == nullptr;
}



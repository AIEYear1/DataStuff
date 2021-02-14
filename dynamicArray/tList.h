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
	T &back();
	const T &back() const;

	void remove(const T &val);
	void clear();
	void resize(size_t newSize);

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

		T &operator*() const;

		iterator &operator++();
		iterator operator++(int);

		iterator &operator--();
		iterator operator--(int);
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
T &tList<T>::iterator::operator*() const
{
	return cur->data;
}

template <typename T>
typename tList<T>::iterator &tList<T>::iterator::operator++()
{
	cur = cur->next;
	return *this;
}
template <typename T>
typename tList<T>::iterator tList<T>::iterator::operator++(int)
{
	iterator tmpIterator = *this;
	cur = cur->next;
	return tmpIterator;
}

template <typename T>
typename tList<T>::iterator &tList<T>::iterator::operator--()
{
	cur = cur->prev;
	return *this;
}
template <typename T>
typename tList<T>::iterator tList<T>::iterator::operator--(int)
{
	iterator tmpIterator = *this;
	cur = cur->prev;
	return tmpIterator;
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
	if (other.empty())
	{
		head = nullptr;
		tail = nullptr;
		return;
	}

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

	tmpCopyNode->prev = tmpPrevNode;
	tail = tmpCopyNode;
}
template <typename T>
tList<T> &tList<T>::operator=(const tList &rhs)
{
	while (head != nullptr)
	{
		pop_front();
	}

	if (rhs.empty())
		return *this;

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

	tmpCopyNode->prev = tmpPrevNode;
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

	if (head != nullptr)
	{
		head->prev = nullptr;
	}
	else
	{
		tail = nullptr;
	}
}
template <typename T>
void tList<T>::push_back(const T &val)
{
	node *oldTail = tail;
	tail = new node{ val, nullptr, tail };

	if (oldTail != nullptr)
	{
		oldTail->next = tail;
	}

	if (head == nullptr)
	{
		node *tmpNode = tail;
		while (tmpNode->prev != nullptr)
		{
			tmpNode = tmpNode->prev;
		}

		head = tmpNode;
	}
}
template <typename T>
void tList<T>::pop_back()
{
	node *newTail = tail->prev;
	delete tail;
	tail = newTail;

	if (tail != nullptr)
	{
		tail->next = nullptr;
	}
	else
	{
		head = nullptr;
	}
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
T &tList<T>::back()
{
	return tail->data;
}
template <typename T>
const T &tList<T>::back() const
{
	return tail->data;
}

template <typename T>
void tList<T>::remove(const T &val)
{
	if (empty())
		return;

	if (head->data == val)
	{
		pop_front();
	}

	if (empty())
		return;

	node **tmpNode = &head;

	//while ((*tmpNode)->next->data != val)
	//{
	//	tmpNode = &((*tmpNode)->next);
	//}

	//node *tmpNode2 = (*tmpNode)->next->next;
	//delete (*tmpNode)->next;
	//(*tmpNode)->next = tmpNode2;
	//tmpNode2->prev = (*tmpNode);

	while ((*tmpNode) != tail && (*tmpNode)->next != tail)
	{
		if ((*tmpNode)->next->data == val)
		{
			node *tmpNode2 = (*tmpNode)->next->next;
			delete (*tmpNode)->next;
			(*tmpNode)->next = tmpNode2;
			tmpNode2->prev = (*tmpNode);
			tmpNode = &head;
		}

		tmpNode = &((*tmpNode)->next);
	}

	if (empty())
		return;

	if (tail->data == val)
	{
		pop_back();
	}
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
void tList<T>::resize(size_t newSize)
{
	node *tmpNode = head;
	int size = 0;

	while (tmpNode != nullptr)
	{
		++size;
		tmpNode = tmpNode->next;
	}

	if (size < newSize)
	{
		for (int x = size; x < newSize; ++x)
		{
			push_back(T());
		}
	}
	else if (size > newSize)
	{
		for (int x = size; x > newSize; --x)
		{
			pop_back();
		}
	}
}

template <typename T>
bool tList<T>::empty() const
{
	return head == nullptr;
}



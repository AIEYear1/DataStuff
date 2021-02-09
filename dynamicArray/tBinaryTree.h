#pragma once
#include <vector>

template <typename T>
class tBinaryTree
{
public:
	struct node
	{
		T data;
		int numOfItems;

		node *left;
		node *right;

		bool hasLeft() const;
		bool hasRight() const;

		void insert(const T &value);
		bool find(const T &value, node *&found);

		void destroy();

		node();
		node(T newDat);
	};

	tBinaryTree();

	tBinaryTree(const tBinaryTree &other);
	tBinaryTree &operator=(const tBinaryTree &other);
	~tBinaryTree();

	void insert(const T &value);
	void remove(node *target);
	bool search(const T &value, node *&found);

private:
	std::vector<node *> vertices;

	node *root;
};

template <typename T>
tBinaryTree<T>::node::node()
{
	data = T();
	numOfItems = 0;

	left = nullptr;
	right = nullptr;
}
template <typename T>
tBinaryTree<T>::node::node(T newDat)
{
	data = newDat;
	numOfItems = 1;
	left = nullptr;
	right = nullptr;
}

template <typename T>
bool tBinaryTree<T>::node::hasLeft() const
{
	return left != nullptr;
}
template <typename T>
bool tBinaryTree<T>::node::hasRight() const
{
	return right != nullptr;
}

template <typename T>
void tBinaryTree<T>::node::insert(const T &value)
{
	if (value == data)
	{
		numOfItems++;
		return;
	}

	if (value < data)
	{
		if (!hasLeft())
		{
			left = new node(value);
			return;
		}

		left->insert(value);
		return;
	}

	if (value > data)
	{
		if (!hasRight())
		{
			right = new node(value);
			return;
		}

		right->insert(value);
		return;
	}
}
template <typename T>
bool tBinaryTree<T>::node::find(const T &value, node *&found)
{
	if (value == data)
	{
		found = this;
		return true;
	}

	if (value < data)
	{
		if (!hasLeft())
		{
			found = nullptr;
			return false;
		}

		return left->find(value, found);
	}

	if (value > data)
	{
		if (!hasRight())
		{
			found = nullptr;
			return false;
		}

		return right->find(value, found);
	}

	found = nullptr;
	return false;
}

template <typename T>
void tBinaryTree<T>::node::destroy()
{
	if (hasLeft())
	{
		left->destroy();
	}
	if (hasRight())
	{
		right->destroy();
	}

	delete this;
}


template <typename T>
tBinaryTree<T>::tBinaryTree()
{
	root = nullptr;
}


template <typename T>
tBinaryTree<T>::tBinaryTree(const tBinaryTree &other)
{
	root = nullptr;

	std::vector<node> toCopy;
	std::vector<node *> toCheckNext;

	toCheckNext.push_back(other.root);

	for (int x = 0; x < toCheckNext.size(); ++x)
	{
		toCopy.push_back(*toCheckNext[x]);

		if (toCheckNext[x]->hasLeft())
		{
			toCheckNext.push_back(toCheckNext[x]->left);
		}
		if (toCheckNext[x]->hasRight())
		{
			toCheckNext.push_back(toCheckNext[x]->right);
		}
	}

	for (int x = 0; x < toCopy.size(); ++x)
	{
		for (int y = 0; y < toCopy[x].numOfItems; ++y)
		{
			insert(toCopy[x].data);
		}
	}
}
template <typename T>
tBinaryTree<T> &tBinaryTree<T>::operator=(const tBinaryTree &other)
{
	if (root != nullptr)
	{
		root->destroy();
	}

	std::vector<node> toCopy;
	std::vector<node *> toCheckNext;

	toCheckNext.push_back(other.root);

	for (int x = 0; x < toCheckNext.size(); ++x)
	{
		toCopy.push_back(*toCheckNext[x]);

		if (toCheckNext[x]->hasLeft())
		{
			toCheckNext.push_back(toCheckNext[x]->left);
		}
		if (toCheckNext[x]->hasRight())
		{
			toCheckNext.push_back(toCheckNext[x]->right);
		}
	}

	for (int x = 0; x < toCopy.size(); ++x)
	{
		for (int y = 0; y < toCopy[x].numOfItems; ++y)
		{
			insert(toCopy[x].data);
		}
	}

	return *this;
}
template <typename T>
tBinaryTree<T>::~tBinaryTree()
{
	if (root != nullptr)
	{
		root->destroy();
	}
}

template <typename T>
void tBinaryTree<T>::insert(const T &value)
{
	if (root == nullptr)
	{
		root = new node(value);
		return;
	}

	root->insert(value);
}
template <typename T>
void tBinaryTree<T>::remove(node *target)
{
	if (root == nullptr)
		return;

	node *prevNode = nullptr;
	node *tmpNode = nullptr;
	if (target == root)
	{
		if (root->hasRight())
		{
			prevNode = root;
			tmpNode = root->right;
			while (tmpNode->hasLeft())
			{
				prevNode = tmpNode;
				tmpNode = tmpNode->left;
			}

			if (tmpNode->hasRight())
			{
				prevNode->left = tmpNode->right;
			}

			tmpNode->left = root->left;
			tmpNode->right = root->right;
		}
		else if (root->hasLeft())
		{
			prevNode = root;
			tmpNode = root->left;
			while (tmpNode->hasRight())
			{
				prevNode = tmpNode;
				tmpNode = tmpNode->right;
			}

			if (tmpNode->hasLeft())
			{
				prevNode->right = tmpNode->left;
			}

			tmpNode->left = root->left;
			tmpNode->right = root->right;
		}

		delete root;

		root = tmpNode;
		return;
	}

	if (target->hasRight())
	{
		prevNode = target;
		tmpNode = target->right;
		while (tmpNode->hasLeft())
		{
			prevNode = tmpNode;
			tmpNode = tmpNode->left;
		}

		if (tmpNode->hasRight())
		{
			prevNode->left = tmpNode->right;
		}

		tmpNode->left = target->left;
		tmpNode->right = target->right;
	}
	else if (target->hasLeft())
	{
		prevNode = target;
		tmpNode = target->left;
		while (tmpNode->hasRight())
		{
			prevNode = tmpNode;
			tmpNode = tmpNode->right;
		}

		if (tmpNode->hasLeft())
		{
			prevNode->right = tmpNode->left;
		}

		tmpNode->left = target->left;
		tmpNode->right = target->right;
	}

	T tmpData = target->data;

	node *cycleNode = root;
	bool cycling = true;

	while (cycling)
	{
		cycling = false;

		if (tmpData < cycleNode->data && cycleNode->left != target)
		{
			cycling = true;
			cycleNode = cycleNode->left;
			continue;
		}
		if (tmpData > cycleNode->data && cycleNode->right != target)
		{
			cycling = true;
			cycleNode = cycleNode->right;
			continue;
		}
	}

	if (tmpNode->data < cycleNode->data)
	{
		cycleNode->left = tmpNode;
	}
	else if (tmpNode->data > cycleNode->data)
	{
		cycleNode->right = tmpNode;
	}

	delete target;
}

template <typename T>
bool tBinaryTree<T>::search(const T &value, node *&found)
{
	if (root == nullptr)
	{
		return false;
	}

	return root->find(value, found);
}

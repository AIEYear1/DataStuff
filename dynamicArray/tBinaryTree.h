#pragma once
#include <vector>

template <typename T>
class tBinaryTree
{
	struct node
	{
		T data;
		int numOfItems;

		node *left;
		node *right;

		bool hasLeft() const;
		bool hasRight() const;

		node();
	};

	tBinaryTree();

	tBinaryTree(const tBinaryTree &other);
	tBinaryTree &operator=(const tBinaryTree &other);
	~tBinaryTree();

	void insert(const T &value);
	bool search(const T &value, node &found);

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
tBinaryTree<T>::tBinaryTree()
{
	root = nullptr;
}


template <typename T>
tBinaryTree<T>::tBinaryTree(const tBinaryTree &other)
{

}
template <typename T>
tBinaryTree<T> &tBinaryTree<T>::operator=(const tBinaryTree &other)
{


	return *this;
}
template <typename T>
tBinaryTree<T>::~tBinaryTree()
{

}

template <typename T>
void tBinaryTree<T>::insert(const T &value)
{
	node *tmpNode = root;

	while (tmpNode != nulltpr)
	{
		if (value < tmpNode->data)
		{
			if (tmpNode->hasLeft())
			{
				tmpNode = tmpNode->left;
				continue;
			}

			tmpNode->left = node{ value, 1, nullptr, nullptr };
			return;
		}
		if (value > tmpNode->data)
		{
			if (tmpNode->hasRight())
			{
				tmpNode = tmpNode->right;
				continue;
			}

			tmpNode->right = node{ value, 1, nullptr, nullptr };
			return;
		}
		
		tmpNode->numOfItems++;
		return;
	}

	*tmpNode = node{ value, 1, nullptr, nullptr };
}

template <typename T>
bool tBinaryTree<T>::search(const T &value, node &found)
{
	node *tmpNode = root;
}
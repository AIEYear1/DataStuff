#pragma once
#include <vector>

template <typename T>
class tGraph
{
public:
	struct vertex
	{
		std::vector<vertex *> adjacentVertices;

		T data;

		vertex();

		vertex &preorder(const T &value);
	};

	tGraph();

	tGraph(const tGraph &other);
	tGraph &operator=(const tGraph &other);
	~tGraph();


	vertex &makeNode();
	vertex &find(const T &value);
	void remove(const vertex &vert);

	bool depthFirstSearch(const T &value, vertex &found);

private:
	std::vector<vertex *> vertices;
};

template <typename T>
tGraph<T>::vertex::vertex()
{
	data = T();
}

template <typename T>
typename tGraph<T>::vertex &tGraph<T>::vertex::preorder(const T &value)
{
	if (value == data)
	{
		return *this;
	}

	vertex *tmpVert = nullptr;

	for (int x = 0; x < adjacentVertices.size(); ++x)
	{
		tmpVert = adjacentVertices[x]->preorder(value);
	}

	return *tmpVert;
}

template <typename T>
tGraph<T>::tGraph() {}

template <typename T>
tGraph<T>::tGraph(const tGraph &other)
{
	vertices = std::vector<vertex *>();

	for (int x = 0; x < other.vertices.size(); x++)
	{
		vertex tmpVert = (*other.vertices[x]);
		vertices.push_back(&tmpVert);
	}
}
template <typename T>
tGraph<T> &tGraph<T>::operator=(const tGraph &other)
{
	vertices = std::vector<vertex *>();

	for (int x = 0; x < other.vertices.size(); x++)
	{
		vertex tmpVert = (*other.vertices[x]);
		vertices.push_back(&tmpVert);
	}

	return *this;
}
template <typename T>
tGraph<T>::~tGraph()
{
	while (!vertices.empty())
	{
		delete vertices.front();
	}
}

template <typename T>
typename tGraph<T>::vertex &tGraph<T>::makeNode()
{
	vertices.push_back(new vertex);
	return vertices.back();
}

template <typename T>
typename tGraph<T>::vertex &tGraph<T>::find(const T &value)
{
	for (int x = 0; x < vertices.size(); ++x)
	{
		if (value == vertices[x]->data)
		{
			return vertices[x];
		}
	}
}

template <typename T>
void tGraph<T>::remove(const vertex &vert)
{
	for (int x = 0; x < vertices.size(); ++x)
	{
		std::vector<vertex *> tmpVector = std::vector<vertex *>();

		for (int y = 0; y < vertices[x]->adjacentVertices.size(); ++y)
		{
			if (vert != vertices[x]->adjacentVertices[y])
			{
				tmpVector.push_back(vertices[x]->adjacentVertices[y]);
			}
		}

		vertices[x]->adjacentVertices = tmpVector;
	}

	delete vert;
}

template <typename T>
bool tGraph<T>::depthFirstSearch(const T &value, vertex &found)
{
	vertex *tmpVert = vertices[0]->preorder(value);

	found = *tmpVert;

	return tmpVert != nullptr;
}
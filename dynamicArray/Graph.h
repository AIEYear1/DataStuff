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
	};

	tGraph();

	tGraph(const tGraph &other);
	tGraph &operator=(const tGraph &other);
	~tGraph();


	vertex &makeNode();
	vertex &find(const T &value);
	void remove(const vertex &vert);

private:
	std::vector<vertex *> vertices;
};

template <typename T>
tGraph<T>::vertex::vertex()
{
	data = T();
}

template <typename T>
tGraph<T>::tGraph() {}

template <typename T>
tGraph<T>::tGraph(const tGraph &other)
{

}
template <typename T>
tGraph<T> &tGraph<T>::operator=(const tGraph &other)
{

}
template <typename T>
tGraph<T>::~tGraph()
{

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
}
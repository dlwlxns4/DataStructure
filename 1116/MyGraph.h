#include <iostream>
#include <array>
#include <vector>
#include <utility>

using namespace std;

enum class EGraphType
{
	Matrix,
	List
};

template <EGraphType type, size_t N>
class MyGraph;

template <size_t N>
class MyGraph<EGraphType::Matrix, N>
{
public:
	// 두 정점이 인접한지 확인한다.
	bool        IsAdjacent(int start, int end)
	{
		if (_edges[start][end] != 0)
			return true;

		return false;
	}

	// 차수를 구한다.
	int         GetDegree(int node)
	{
		int in = GetInDegree(node);
		int out = GetOutDegree(node);

		return in + out;
	}

	// 진입 차수를 구한다.
	int         GetInDegree(int node)
	{
		int count = 0;
		for (int i = 0; i < _edges.size(); ++i)
		{
			if (_edges[i][node])
			{
				++count;
			}
		}
		return count;
	}

	// 진출 차수를 구한다.
	int         GetOutDegree(int node)
	{
		int count = 0;

		for (int i = 0; i < _edges.size(); ++i)
		{
			if (_edges[node][i])
			{
				++count;
			}
		}
		return count;
	}


	// 간선을 추가한다.
	void        AddEdge(int start, int end, int weight = 1)
	{
		_edges[start][end] = weight;
	}

	// 간선을 제거한다.
	void        DeleteEdge(int start, int end)
	{
		_edges[start][end] = 0;
	}

	// 출력한다.
	// 예시..
	// [ 0 1 0 0 0 ]
	// [ 0 0 1 0 0 ]
	// [ 0 0 0 0 1 ]
	// [ 0 1 0 0 0 ]
	// [ 0 0 0 0 0 ]
	void        Print()
	{
		for (size_t i = 0; i < _edges.size(); ++i)
		{
			cout << "[ ";
			for (size_t j = 0; j < _edges.size(); ++j)
			{
				cout << _edges[i][j] << ' ';
			}
			cout << "] " << endl;
		}
	}

private:
	array<array<int, N>, N>     _edges = { 0 };
};



template <size_t N>
class MyGraph<EGraphType::List, N>
{
public:
	// 두 정점이 인접한지 확인한다.
	bool        IsAdjacent(int start, int end)
	{
		for (const auto& edge : _edges[start])
		{
			if (edge.first == end)
				return true;
		}
		return false;
	}

	// 차수를 구한다.
	int         GetDegree(int node)
	{
		int in = GetInDegree(node);
		int out = GetOutDegree(node);

		return in + out;
	}

	// 진입 차수를 구한다.
	int         GetInDegree(int node)
	{
		int count = 0;
		for (size_t i = 0; i < _edges.size(); ++i)
		{
			if (i == node)
				continue;

			for (const auto& edge : _edges[i])
			{
				if (edge.first == node) 
				{
					++count;
				}
			}
		}
		return count;
	}

	// 진출 차수를 구한다.
	int         GetOutDegree(int node)
	{
		int count = _edges[node].size();
		
		return count;
	}

	// 간선을 추가한다.
	void        AddEdge(int start, int end, int weight = 1)
	{
		_edges[start].push_back(pair<int, int>(end, weight));
	}

	// 간선을 제거한다.
	void        DeleteEdge(int start, int end)
	{
		for (auto iter = _edges[start].begin(); iter != _edges[start].end(); ++iter)
		{
			if (iter->first == end)
			{
				_edges[start].erase(iter);

				break;
			}
		}
	}

	// 출력한다.
	// 예시..
	// [ 1 ] : [ (3,1) (4,3) ]
	// [ 2 ] :
	// [ 3 ] :
	// [ 4 ] :
	// [ 5 ] : [ (2, 4) (3, 5) ]
	void        Print()
	{

		for (size_t r = 0; r < _edges.size(); ++r)
		{
			cout << "[ " << r << " ] : ";
			for (const auto& iter : _edges[r])
			{
				cout << "(" << iter.first << "," << iter.second << ") ";
			}
			cout << endl;
		}
	}

private:
	array<vector<std::pair<int, int>>, N>       _edges;
};

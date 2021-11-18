//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//#define INF 987654321
//
//using namespace std;
//
//int N, M;
////
////int graph[7][7] = {
////    {   0,   7, INF, INF,   3,  10, INF },
////    {   7,   0,   4,  10,   2,   6, INF },
////    { INF,   4,   0,   2, INF, INF, INF },
////    { INF,  10,   2,   0,  11,   9,   4 },
////    {   3,   2, INF,  11,   0, INF,   5 },
////    {  10,   6, INF,   9, INF,   0, INF },
////    { INF, INF, INF,   4,   5, INF,   0 }
////};
//
//vector<vector<int>> GetShortestPath(const vector<vector<pair<int,int>>>& graph)
//{
//    // distance 인접 행렬 만들기
//    // distance[i][j]는 i 정점에서 j 정점까지의 최단 경로다.
//    vector<vector<int>> dist(N, vector<int>(N,INF));
//    
//    for (int i = 0; i < N; ++i)
//    {
//        dist[i][i] = 0;
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (pair<int,int> iter : graph[i])
//        {
//            dist[i][iter.first] = min(iter.second, dist[i][iter.first]);
//        }
//    }
//
//
//    // 모든 정점의 최단 경로를 구할 때까지 반복한다.
//    for (int via = 0; via < N; ++via) // 경유 정점
//    {
//        for (int from = 0; from < N; ++from) // 시작 정점
//        {
//            for (int to = 0; to < N; ++to) // 도착 정점
//            {
//                dist[from][to] = min(dist[from][to], dist[from][via] + dist[via][to]);
//            }
//        }
//    }
//
//    for(int i=0; i<N; ++i)
//    {
//        for (int j = 0; j < N; ++j)
//        {
//            if (dist[i][j] == INF)
//                dist[i][j] = 0;
//        }
//    }
//    return dist;
//}
//
//int main()
//{
//    cin >> N;
//    cin >> M;
//
//    vector<vector<pair<int, int>>> map(N);
//
//	for (int i = 0; i < M; ++i)
//	{
//		int start = 0, end = 0, weight = 0;
//		cin >> start;
//		cin >> end;
//		cin >> weight;
//
//		map[start - 1].push_back({ end - 1, weight });
//	}
//
//
//    auto dist = GetShortestPath(map);
//
//    for (const auto& d : dist)
//    {
//        for (const auto& elem : d)
//        {
//            cout << elem << ' ';
//        }
//        cout << endl;
//    }
//}

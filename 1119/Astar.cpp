#include <iostream>
#include <queue>
#include <vector>

#define START_X 2
#define START_Y 4
#define END_X   7
#define END_Y   4

#define INF 1e9

using namespace std;

int map[10][10] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 2, 0, 0, 3, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

struct Pos
{
    int X;
    int Y;

    bool operator<(const Pos& other) const { return (X < other.X) && (Y < other.Y); }
    bool operator==(const Pos& other) const { return X == other.X && Y == other.Y; }
    bool operator!=(const Pos& other) const { return !(*this == other); }
};

void PrintMap()
{
    for (int r = 0; r < 10; ++r)
    {
        for (int c = 0; c < 10; ++c)
        {
            if (map[r][c] == 0)
                cout << " ";
            else if (map[r][c] == 1)
                cout << "S";
            else if (map[r][c] == 2)
                cout << "B";
            else if (map[r][c] == 3)
                cout << "E";
            else if (map[r][c] == 4)
                cout << "P";
        }
        cout << endl;
    }
}

int h(Pos a, Pos b)
{
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

void astar(Pos start, Pos end)
{
    vector<vector<int>> f;
    for (int i = 0; i < 10; ++i)
        f.emplace_back(10, INF);
    f[start.Y][start.X] = 0;

    Pos path[10][10];
    path[start.Y][start.X] = start;

    priority_queue<pair<int, Pos>> pq;
    pq.emplace(0, start);

    int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dg[] = { 10, 14, 10, 14, 10, 14, 10, 14 };

    while (false == pq.empty())
    {
        int w = -pq.top().first;
        Pos pos = pq.top().second;
        pq.pop();

        if (f[pos.Y][pos.X] < w)
        {
            continue;
        }

        if (pos == end)
        {
            break;
        }

        for (int i = 0; i < 8; ++i)
        {
            int ny = dy[i] + pos.Y;
            int nx = dx[i] + pos.X;

            if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10)
            {
                continue;
            }

            if (!(map[ny][nx] == 0 || map[ny][nx] == 3))
            {
                continue;
            }

            //f(x) : g(x) + h(x) = 가중치
            //g(x) : 해당 정점으로 이동하는데 비용
            //h(x) : 휴리스틱


            int nf = dg[i] + h({ nx, ny }, end);

            if (f[ny][nx] > nf)
            {
                f[ny][nx] = nf;

                path[ny][nx] = pos;

                pq.emplace(-f[ny][nx], Pos{ nx, ny });
            }
        }
    }

    Pos curr = end;
    while (curr != start)
    {
        map[curr.Y][curr.X] = 4;

        curr = path[curr.Y][curr.X];
    }
}

int main()
{
    PrintMap();

    puts("");

    astar({ START_X, START_Y }, { END_X, END_Y });

    PrintMap();

}


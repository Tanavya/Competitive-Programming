#include <iostream>
#include <vector>
#include <bitset>
#include <stdio.h>

using namespace std;
bitset<107> color;
vector<int>* graph;
vector<int> solutionSoFar, solution;
int n, m;

void find_coloring()
{
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            bitset <107> copy = color;
            found = true;
            color[i] = 1;
            solutionSoFar.push_back(i);

            for (vector<int>::iterator ni = graph[i].begin(); ni != graph[i].end(); ni++)
            {
                color[*ni] = 1;
            }
            find_coloring();
            color = copy;
            solutionSoFar.pop_back();
        }
    }
    if (!found)
    {
        if (solutionSoFar.size() > solution.size())
        {
            solution = solutionSoFar;
        }
    }
}

int main()
{
    int number_of_graphs;
    cin >> number_of_graphs;
    for (int g = 0; g < number_of_graphs; g++)
    {
        cin >> n >> m;
        
        graph = new vector<int>[n];
        for (int e = 0; e < m; e++)
        {
            int node1;
            int node2;
            cin >> node1;
            cin >> node2;
            graph[node1 - 1].push_back(node2 - 1);
            graph[node2 - 1].push_back(node1 - 1);
        }
        color.reset();
        solutionSoFar.clear();
        solution.clear();
        find_coloring();

        int size = solution.size();
        printf("%d\n", size);
        for (int i = 0; i < size; i++) {
            if (i) printf(" ");
            printf("%d", solution[i]+1);
        }
        printf("\n");
    }

    return 0;
}

#include <bits/stdc++.h>
/***************************************************************************

    Class for graph node is as follows:

    class graphNode
    {
        public:
            int data;
        vector<graphNode *> neighbours;
        graphNode()
        {
            data = 0;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val)
        {
            data = val;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val, vector<graphNode *> neighbours)
        {
            data = val;
            this->neighbours = neighbours;
        }
    };

******************************************************************************/

graphNode *cloneGraph(graphNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    unordered_map<graphNode *, graphNode *> mp;
    graphNode *first = new graphNode(node->data, {});

    mp[node] = first;

    queue<graphNode *> q;
    q.push(node);

    while (!q.empty())
    {

        graphNode *curr = q.front();
        q.pop();

        for (auto adj : curr->neighbours)
        {
            if (mp.find(adj) == mp.end())
            {
                mp[adj] = new graphNode(adj->data, {});
                q.push(adj);
            }
            mp[curr]->neighbours.push_back(mp[adj]);
        }
    }
    return mp[node];
}
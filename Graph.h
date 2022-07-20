#pragma once

#include <string>
#include <sstream>
#include <limits.h> /* For INT_MAX */
#include <utility>  /* For std::pair, std::make_pair */
#include <vector>
#include <stack>
#include <unordered_map>
#include <assert.h>
#include <queue>
#include <iostream>
#include <assert.h>
#include <functional> /* For std::greater */

namespace util
{
    /**
     * @param v The given vector
     * @return string representation of vector
     */
    template <class T>
    extern std::string to_string(const std::vector<T> &v)
    {
        std::stringstream ss;

        ss << "< ";

        for (size_t i = 0; i < v.size(); i++)
        {
            ss << '<' << v[i] << '>' << " ";
        }

        ss << ">";

        return ss.str();
    }
}

template <class K>
class Edge
{
public:
    Edge(const K &src, const K &dest, float distance = 0.0f) : source(src), destination(dest), distance(distance)
    {
    }

    ~Edge()
    {
    }

    Edge(const Edge<K> &other)
    {
        source = other.source;
        destination = other.destination;
        distance = other.distance;
    }

    bool operator<(const Edge<K> &other) const
    {
        return distance < other.distance;
    }

    bool operator=(const Edge<K> &other) const
    {
        return source == other.source && destination == other.destination && distance == other.distance;
    }

    bool operator!=(const Edge<K> &other) const
    {
        return !(*this == other);
    }

    K source;
    K destination;
    float distance;
};

template <class K, class V>
class Vertex
{
public:
    Vertex(const K &key, const V &value);

    Vertex(const Vertex<K, V> &other);

    ~Vertex();

    /**
     * @return The number of outgoing edges from this vertex
     */
    unsigned degree() const;

    /**
     * @param other a vertex
     * @return checks if this vertex is adjacent to the other vertex, i.e. the edge (this, other) exists
     */
    bool is_adj(Vertex<K, V> *other);

    /**
     * Finds an edge that contains other vertex as endpoint.
     * @param other the vertex
     * @return the edge containing the vertices or nullptr if none found.
     */
    Edge<K> *find_adj(Vertex<K, V> *other);

    /**
     * @returns List of vertex keys adjacent to this vertex.
     */
    std::vector<K> get_adj() const;

    K key;
    V value;

    Vertex<K, V> *parent;
    float distance;
    bool visited;
    float rank;

    std::list<Edge<K> *> adj;   // Edges that start from this vertex and end at another vertex.
    std::list<Edge<K> *> adjIn; // Edges that start at another vertex and end at this vertex.
};

/**
 * This class represents the graph of our model.
 */
template <class K, class V>
class Graph
{
public:
    Graph();
    ~Graph();
    Graph(const Graph &g);
    Graph<K, V> &operator=(const Graph &g);

    std::unordered_map<K, Vertex<K, V> *> vertices;
    std::vector<Edge<K> *> edges;

    bool has_vertex(const K &key) const;
    void create_edge(const K &src, const K &dest, float distance = 0.0f);
    void create_vertex(const K &key, const V &value = V());
    float path_length(std::vector<K> &path);

    bool empty() const { return vertices.empty(); }

    /**
     * Follows the backward path from each vertex to its parent vertex
     * till reaches end. Then reverses this path to get the actual path.
     * @param src start vertex key
     * @param dest end vertex key
     * @return path from src to dest vertex
     */
    std::vector<K> path(const K &src, const K &dest);

    /**
     * Does a Breadth first search traversal on graph to find the shortest path
     * from start to end vertex with least connecting flight.
     * To do this let all edges cost be 1.
     * @param src start vertex
     * @param dest end vertex
     */
    void bfs(const K &src, const K &dest);

    /**
     * Runs Dijkstra's algorithm on this graph
     * to find the shortest path from src to dest vertex.
     * @param src start vertex
     * @param dest end vertex
     */
    void dijkstra(const K &src, const K &dest);

    /**
     * Builds a transpose graph by flipping the direction of all the edges.
     * @returns transposed graph
     */
    Graph<K, V> *transpose() const;

    void print() const;

private:
    void _destroy();
    void _copy(const Graph<K, V> &g);
};

template <class K, class V>
Vertex<K, V>::Vertex(const K &key, const V &value) : key(key), value(value)
{
    parent = nullptr;
    distance = 0;
    visited = false;
    rank = 0;
    adj = std::list<Edge<K> *>();
}

template <class K, class V>
Vertex<K, V>::~Vertex()
{
    // Nothing
}

template <class K, class V>
Vertex<K, V>::Vertex(const Vertex<K, V> &other)
{
    // Warning: The copy constructor for vertex does not copy the parent pointer or the adj list.
    key = other.key;
    value = other.value;
    parent = nullptr;
    distance = other.distance;
    visited = other.visited;
    adj = std::list<Edge<K> *>();
}

template <class K, class V>
unsigned Vertex<K, V>::degree() const
{
    return adj.size();
}

template <class K, class V>
bool Vertex<K, V>::is_adj(Vertex<K, V> *other)
{
    if (other == nullptr)
    {
        return false;
    }

    for (auto edgeItr = adj.begin(); edgeItr != adj.end(); edgeItr++)
    {
        Edge<K> *edge = *edgeItr;

        if (edge->destination == other->key)
        {
            return true;
        }
    }

    return false;
}

template <class K, class V>
Edge<K> *Vertex<K, V>::find_adj(Vertex<K, V> *other)
{
    if (other == nullptr)
    {
        return nullptr;
    }

    for (auto edgeItr = adj.begin(); edgeItr != adj.end(); edgeItr++)
    {
        Edge<K> *edge = *edgeItr;

        if (edge->destination == other->key)
        {
            return edge;
        }
    }

    return nullptr;
}

template <class K, class V>
std::vector<K> Vertex<K, V>::get_adj() const
{
    std::vector<K> v;

    for (auto edgeItr = adj.begin(); edgeItr != adj.end(); edgeItr++)
    {
        Edge<K> *edge = *edgeItr;
        v.push_back(edge->destination);
    }

    return v;
}

template <class K, class V>
Graph<K, V>::Graph()
{
    // Do Nothing
}

template <class K, class V>
Graph<K, V>::~Graph()
{
    _destroy();
}

template <class K, class V>
Graph<K, V>::Graph(const Graph &g)
{
    _copy(g);
}

template <class K, class V>
Graph<K, V> &Graph<K, V>::operator=(const Graph &g)
{
    if (this != &g)
    {
        _destroy();
        _copy(g);
    }

    return *this;
}

template <class K, class V>
bool Graph<K, V>::has_vertex(const K &key) const
{
    return vertices.find(key) != vertices.end();
}

template <class K, class V>
void Graph<K, V>::create_edge(const K &src, const K &dest, float distance)
{
    if (has_vertex(src) && has_vertex(dest))
    {
        Vertex<K, V> *u = vertices[src];
        Edge<K> *e = new Edge<K>(src, dest, distance);
        u->adj.push_back(e);

        edges.push_back(e);
    }
}

template <class K, class V>
void Graph<K, V>::create_vertex(const K &key, const V &value)
{
    Vertex<K, V> *u = new Vertex<K, V>(key, value);
    vertices[key] = u;
}

template <class K, class V>
void Graph<K, V>::bfs(const K &src, const K &dest)
{
    if (!has_vertex(src) || !has_vertex(dest))
    {
        return;
    }

    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        Vertex<K, V> *u = it->second;
        u->distance = INT_MAX;
        u->parent = nullptr;
        u->visited = false;
    }

    std::queue<Vertex<K, V> *> q;

    vertices[src]->distance = 0.0;
    q.push(vertices[src]);

    while (!q.empty() && !vertices[dest]->visited)
    {
        Vertex<K, V> *u = q.front();
        q.pop();

        for (auto edgeItr = u->adj.begin(); edgeItr != u->adj.end(); edgeItr++)
        {
            Edge<K> *edge = *edgeItr;
            Vertex<K, V> *v = vertices[edge->destination];

            if (!v->visited)
            {
                v->visited = true;

                if (v->distance > u->distance + 1)
                {
                    v->distance = u->distance + 1;
                    v->parent = u;
                }

                q.push(v);
            }
        }

        u->visited = true;
    }
}

template <class K, class V>
void Graph<K, V>::dijkstra(const K &src, const K &dest)
{
    if (!has_vertex(src) || !has_vertex(dest))
    {
        return;
    }

    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        Vertex<K, V> *u = it->second;
        u->distance = INT_MAX;
        u->parent = nullptr;
        u->visited = false;
    }

    typedef std::pair<float, Vertex<K, V> *> vpair;

    std::priority_queue<vpair, std::vector<vpair>, std::greater<vpair> > q;

    vertices[src]->distance = 0.0;
    q.push(std::make_pair(0.0, vertices[src]));

    while (!q.empty() && !vertices[dest]->visited)
    {
        vpair current = q.top();
        q.pop();

        Vertex<K, V> *u = current.second;

        /* We might get duplicate vertices in the queue. */
        if (u->visited)
        {
            continue;
        }

        for (auto edgeItr = u->adj.begin(); edgeItr != u->adj.end(); edgeItr++)
        {
            Edge<K> *edge = *edgeItr;
            Vertex<K, V> *v = vertices[edge->destination];

            assert(vertices[edge->source] == u);

            /* We check if found shorter path than before from u to v */
            if (!v->visited)
            {
                if (v->distance > u->distance + edge->distance)
                {
                    v->distance = u->distance + edge->distance;
                    v->parent = u;
                }

                q.push(std::make_pair(v->distance, v));
            }
        }

        u->visited = true;
    }
}

template <class K, class V>
std::vector<K> Graph<K, V>::path(const K &src, const K &dest)
{
    if (!has_vertex(src) || !has_vertex(dest))
    {
        std::cout << __FILE__ << ":" << __LINE__ << ":"
                  << "Failed to find path from <" << src << "> to <" << dest << ">" << std::endl;
        return std::vector<K>();
    }

    std::vector<K> forward_path;
    std::stack<K> backward_path;

    Vertex<K, V> *current = vertices[dest];

    while (current != nullptr)
    {
        backward_path.push(current->key);
        current = current->parent;
    }

    while (!backward_path.empty())
    {
        forward_path.push_back(backward_path.top());
        backward_path.pop();
    }

    return forward_path;
}

template <class K, class V>
float Graph<K, V>::path_length(std::vector<K> &path)
{
    float length = 0.0;

    if (path.empty())
    {
        return length;
    }

    for (size_t i = 0; i < path.size() - 1; i++)
    {
        Vertex<K, V> *u = vertices[path[i]];
        Vertex<K, V> *v = vertices[path[i + 1]];

        if (!u || !v)
        {
            continue;
        }

        Edge<K> *e = u->find_adj(v);

        if (e != nullptr)
        {
            length += e->distance;
        }
    }

    return length;
}

template <class K, class V>
void Graph<K, V>::_destroy()
{
    /* Delete edges */
    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        delete (*it);
        *it = nullptr;
    }

    /* Delete vertices */
    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        delete it->second;
        it->second = nullptr;
    }
}

template <class K, class V>
void Graph<K, V>::_copy(const Graph<K, V> &g)
{
    for (auto it = g.vertices.begin(); it != g.vertices.end(); it++)
    {
        create_vertex(it->first, it->second->value);
    }

    for (auto it = g.edges.begin(); it != g.edges.end(); it++)
    {
        create_edge((*it)->source, (*it)->destination);
    }
}

/**
 * Builds a transpose graph by flipping the direction of all the edges.
 * @returns transposed graph
 */
template <class K, class V>
Graph<K, V> *Graph<K, V>::transpose() const
{
    Graph<K, V> *g = new Graph<K, V>();

    /* Copy all vertices from this graph to new graph */
    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        g->create_vertex(it->first, it->second->value);
    }

    /* For every edge (u,v) in this graph, create edge (v,u) in new graph */
    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        g->create_edge((*it)->destination, (*it)->source);
    }

    return g;
}

template <class K, class V>
void Graph<K, V>::print() const
{
    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        std::cout << it->first << ": " << util::to_string<K>(it->second->get_adj()) << std::endl;
    }
}
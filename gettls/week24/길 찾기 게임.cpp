#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Node {
public:
    int x, y, index;
    Node* left;
    Node* right;
    Node(int x, int y, int index, Node* left, Node* right) {
        this->x = x; this->y = y; this->index = index;
        this->left; this->right = right;
    }
};

bool compare(Node n1, Node n2) {
    return n1.y > n2.y;
}

Node* makeTree(vector<Node> v) {
    if (v.size() == 0) return NULL;
    vector<Node> left, right;
    sort(v.begin(), v.end(), compare);

    for (auto i : v) {
        if (v[0].x < i.x) right.push_back(i);
        else if (v[0].x > i.x) left.push_back(i);
    }

    Node* n = new Node(v[0].x, v[0].y, v[0].index, NULL, NULL);
    n->left = makeTree(left);
    n->right = makeTree(right);

    return n;
}

vector<int> pre, post;
void preorder(Node* n) {
    if (n) {
        pre.push_back(n->index);
        preorder(n->left);
        preorder(n->right);
    }
}
void postorder(Node* n) {
    if (n) {
        postorder(n->left);
        postorder(n->right);
        post.push_back(n->index);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> v;
    for (int i = 0; i < nodeinfo.size(); i++) {
        Node n(nodeinfo[i][0], nodeinfo[i][1], i + 1, NULL, NULL);
        v.push_back(n);
    }
    Node* result = makeTree(v);

    preorder(result); answer.push_back(pre);
    postorder(result); answer.push_back(post);

    return answer;
}
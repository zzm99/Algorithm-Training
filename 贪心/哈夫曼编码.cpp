#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
 
using namespace std;
 
class Node {
  public:
    char c; //表示字符
    int frequency; //表示该字符出现的次数或频率
    Node *left;
    Node *right;
 
    Node(char _c, int f, Node *l = NULL, Node *r = NULL)
      :c(_c), frequency(f), left(l), right(r) { }
 
    bool operator<(const Node &node) const { //重载<运算法以至于在加入优先队列的时候决定如何处理结点位置
      return frequency > node.frequency;
    }
};
 
void initNode(priority_queue<Node> &q, int nodeNum) {
  char c;
  int frequency;
  for (int i = 0; i < nodeNum; i++) {
    cout << "输入字符和结点出现的次数: ";
    cin >> c >> frequency;
    Node node(c, frequency);
    q.push(node);
  }
}
 
void showNode(priority_queue<Node> q) {
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    cout << node.c << ", " << node.frequency << endl;
  }
}
 
//构造哈夫曼树
void huffmanTree(priority_queue<Node> &q) {
  while (q.size() != 1) {
    Node *left = new Node(q.top()); q.pop();
    Node *right = new Node(q.top()); q.pop();
 
    Node node('R', left->frequency + right->frequency, left, right);
    q.push(node);
  }
}
 
 
// 打印哈夫曼编码
void huffmanCode(Node *root, string &prefix, map<char, string> &result) {
  string m_prefix = prefix;
 
  if (root->left == NULL)
    return;
 
  //处理左子树
  prefix += "0";
  //如果是叶子结点则输出,否则递归打印左子树
  if (root->left->left == NULL)
    result[root->left->c] = prefix;
    //cout << root->left->c << ": " << prefix << endl;
  else
    huffmanCode(root->left, prefix, result);
 
  //还原原来的路径,回溯
  prefix = m_prefix;
 
  //处理右子树
  prefix += "1";
  //如果是叶子结点，则输出, 否则递归打印右子树
  if (root->right->right == NULL)
    result[root->right->c] = prefix;
    //cout << root->right->c << ": " << prefix << endl;
  else
    huffmanCode(root->right, prefix, result);
 
}
 
void testResult(map<char, string> result) {
  //迭代map容器
  map<char, string>::const_iterator it = result.begin();
  while (it != result.end()) {
    cout << it->first << ": " << it->second << endl;
    ++it;
  }
}
int main() {
  priority_queue<Node> q;
  int nodeNum;
 
  //初始化字符信息
  cout << "请输入结点个数: ";
  cin >> nodeNum;
  initNode(q, nodeNum);
  //showNode(q);
 
  //构造哈夫曼树
  huffmanTree(q);
 
  //构造哈夫曼编码
  Node root = q.top();
  string prefix = "";
  map<char, string> result;
  huffmanCode(&root, prefix, result);
 
  //检验结果是否正确
  testResult(result);
  return 0;
}
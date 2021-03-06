/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:store_bitree.cc
 * Author:
 * Mail:
 * Created Time:星期一  4/ 2 18:26:46 2018
 ***************************************************/
#include <iostream>
#include <fstream>
#include "../include/base.h"

using namespace std;

const long MAX_NODE_NUM = 1000;

class NodeInfo {
public:
  int val;
  int left_pos;
  int right_pos;
};

class Solution {
public:
  void storeBitree(TreeNode* root, const string& filename = "./bitree.dat") {
    if (nullptr == root) {
      return;
    }
    vector<NodeInfo> nodes;
    nodes.reserve(MAX_NODE_NUM);
    map<TreeNode*, int> pos_map;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* ptr = q.front();
      q.pop();
      if (pos_map.find(ptr) == pos_map.end()) {
	NodeInfo n;
	nodes.push_back(n);
	pos_map.insert(pair<TreeNode*, int>(ptr, nodes.size() - 1));
      }
      NodeInfo &n = nodes[pos_map[ptr]];
      n.val = ptr->val;
      if (nullptr != ptr->left) {
	q.push(ptr->left);
	n.left_pos = nodes.size();
	pos_map.insert(pair<TreeNode*, int>(ptr->left, n.left_pos));
	nodes.resize(pos_map.size());
      } else {
	n.left_pos = 0;
      }
      if (nullptr != ptr->right) {
	q.push(ptr->right);
	if (n.left_pos != 0) {
	  n.right_pos = n.left_pos + 1;
	} else {
	  n.right_pos = nodes.size();
	}
	pos_map.insert(pair<TreeNode*, int>(ptr->right, n.right_pos));
	nodes.resize(pos_map.size());
      } else {
	n.right_pos = 0;
      }
    }
    ofstream fp(filename);
    for (int i = 0; i < nodes.size(); i++) {
      fp << nodes[i].val << "\t" << nodes[i].left_pos << "\t" << nodes[i].right_pos << endl;
      //cout << nodes[i].val << "\t" << nodes[i].left_pos << "\t" << nodes[i].right_pos << endl;
    }
    fp.close();
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(5);
  root->left = new TreeNode(6);
  root->left->left = new TreeNode(7);
  Solution sl;
  sl.storeBitree(root);
  return 0;
}

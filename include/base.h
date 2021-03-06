/***************************************************
 Xingwei_He All Rights Reserved.
 * File Name:base.h
 * Author:
 * Mail:
 * Created Time:星期一 12/ 4 11:08:01 2017
 ***************************************************/
#ifndef _BASE_H
#define _BASE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Definition of TreeNode:
class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


// Definition of Interval:
class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

// 1D vector debug
template<class T>
void debug1DVector(std::vector<T> vec, int width) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << std::setw(width) << vec[i];
  }
  std::cout << std::endl;
}

// 2D vector debug
template<class T>
void debug2DVector(std::vector<std::vector<T> > vec, int width) {
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[i].size(); j++) {
      std::cout << std::setw(width) << vec[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

#endif


/***************************************************
 * Xingwei_He All Rights Reserved.
 * File Name:bonus.cc
 * Author:
 * Mail:
 * Created Time:2018年03月14日 星期三 23时38分45秒
 ***************************************************/
#include <iostream>

#include "../include/base.h"

using namespace std;

/**
 * 题目：公司进行了一次黑客马拉松大赛，全公司一共分为了N个组，每组一个房间排成一排开始比赛，比赛结束后没有公布成绩，但是每个组能够看到自己相邻的两个组里比自己成绩低的组的成绩，比赛结束之后要发奖金，以1w为单位，每个组都至少会发1w的奖金，另外，如果一个组发现自己的奖金没有高于比自己成绩低的组发的奖金，就会不满意，作为比赛的组织方，根据成绩计算出至少需要发多少奖金才能让所有的组满意。 
 *
 * 输入描述：
 *   每组数据先输入N，然后N行输入N个正整数，每个数表示每个组的比赛成绩。
 *
 * 输出描述：
 *   输出至少需要多少w的奖金
 *
 * 示例
 * 输入
 * 10,20,32,12,32,45,11,21,31,41,33
 * 
 * 输出
 * 20
 */

class Solution {
public:
  int getMinBonus(vector<int> scores) {
    if (scores.size() <= 0) {
      return 0;
    }
    int n = scores.size();
    vector<int> bonus(n, 1);
    for (int i = 0; i < n; i++) {
      if (scores[i] < scores[i + 1]) {
	bonus[i + 1] = bonus[i] + 1;
      } else if (scores[i] == scores[i + 1]) {
	bonus[i + 1] = bonus[i];
      } else {
	//bonus[i + 1] = 1;
	for (int j = i + 1; j >= 0; j--) {
	  if (scores[j - 1] > scores[j] && bonus[j - 1] <= bonus[j]) {
	    bonus[j - 1] += 1;
	  }
	}
      }
    }
    debug1DVector<int>(scores,4);
    debug1DVector<int>(bonus,4);
    int res = 0;
    for (int i = 0; i < bonus.size(); i++) {
      res += bonus[i];
    }
    return res;
  }
};

int main() {
  int arr[] = {10,20,32,12,32,45,11,21,31,41,33};
  vector<int> scores(arr, arr + sizeof(arr)/sizeof(int));
  Solution sl;
  int res = sl.getMinBonus(scores);
  cout << res << endl;
  return 0;
}

#include<iostream>
using namespace std;
int main() {
	int k;
	cin >> k;
	int tol_coin = 0;
	int tol_day = 0;
	//起初总经过的天数为0，金币总量也为0
	for (int coin_cnt = 1;tol_day < k;coin_cnt++) {
		//第一天收益为1，只要天数小于k，收益就不断增加
		for (int day_cnt = 0;day_cnt < coin_cnt;day_cnt++) {
			//对经过了多少天进行计数，只要当天的计数小于收益的数目，天数就增加
			tol_coin += coin_cnt;
			//天数每增加一天，金币总量就增加单日的收益
			tol_day++;
			//增加完后令天数增加
			if (tol_day == k) {
				cout << tol_coin << endl;
				//当总天数达到k时，输出金币总数，然后用break退出循环
				break;
			}
		}
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<Windows.h>
using namespace std;

ostream& operator<<(ostream& out, vector<double> _) {	//输出种群构成
	for (auto __ : _) {
		out << __ << " ";
	}
	return out;
}

class solution
{
public:
	solution(int _, int __, int ___, double ____, double (*Pt)(vector<double>), double low, double up)
		:vecVar(_), vecPop(__), maxEv(___), vecMu(____), pt(Pt), lower_bound(low), upper_bound(up) {
		srand(time(NULL));
		vec.resize(_);
		best_score = DBL_MAX;
		for (auto& it : vec)it.first.resize(__);
		FillVec();
	};

	void FillVec() {	//种群初始化
		for (auto& _ : vec) {
			for (auto& __ : _.first) {
				__ = lower_bound + (upper_bound - lower_bound) * (rand() / double(RAND_MAX));
			}
			_.second = pt(_.first);
		}
	}

	void evaluate() {	//种群迭代进化算法实现
		for (int ev = 0; ev < maxEv; ev++) {
			select();
			cross();
			mutated();
			for (auto& _ : vec) {
				_.second = pt(_.first);
				if (abs(_.second) < best_score)best_score = abs(_.second), best_vec = _.first;
			}
			sort(vec.begin(), vec.end(), [](auto &x, auto &y) {return x.second < y.second; });
			cout << "迭代次数：" << ev << "  最小值：" << vec[0].second << endl;
			if (ev == maxEv - 1) {
				//cout << "最后一次迭代情况为：" << vec[0].first << endl;
				cout << "迭代过程中最优值绝对值为：" << best_score << "  最优解为：" << best_vec << endl;
			}
			//Sleep(1000);
		}
	}

	void select() {	//选择算法实现
		auto NewVec = vec;
		for (int i = 0; i < NewVec.size(); i++) {
			random_shuffle(vec.begin(), vec.end());
			if (vec[0].second < vec[1].second)NewVec[i] = vec[0];
			else NewVec[i] = vec[1];
		}
		sort(vec.begin(), vec.end(), [](auto& x, auto& y) {return x.second < y.second; });
		for (int i = 0; i < vecVar*3 / 10; i++)NewVec[i] = vec[i];	//前30%精英保留
		vec = NewVec;
	}

	void cross() {	//交叉算法实现
		for (int i = 0; i < vec.size(); i += 2) {
			int t = rand() % (vec[i].first.size() - 1) + 1;
			random_shuffle(vec[i].first.begin(), vec[i].first.end());
			random_shuffle(vec[i + 1].first.begin(), vec[i + 1].first.end());    //打乱排序，其实只需打乱一个
			//for (; t < vec[i].first.size(); t++)swap(vec[i].first[t], vec[i + 1].first[t]);	//链交叉
			swap(vec[i].first[t], vec[i + 1].first[t]);		//单点交叉
		}
	}

	void mutated() {	//变异算法实现
		double step = (upper_bound - lower_bound) * 0.1;
		for (auto& _ : vec) {
			for (auto& __ : _.first) {
				if (rand() / (double)RAND_MAX < vecMu) {
					__ += (rand() / double(RAND_MAX) * 2 - 1); // 在 [-1, 1] 范围内随机变异
					//__ += (rand() / double(RAND_MAX) - 0.5) * step;	// 在 [-0.05, 0.05]*len(up-low) 范围内随机变异
					__ = max(lower_bound, min(upper_bound, __)); // 限制在范围内
				}
			}
		}
	}


	//~solution() {};

private:
	vector<pair<vector<double>, double>> vec;
		//       单个向量构成  、适应度
	int vecVar, vecPop, maxEv;
		//种群大小、种群规模、最大迭代次数
	double vecMu;
		//突变率
	double (*pt)(vector<double>);
		//适应度函数
	double upper_bound, lower_bound;
		//取值上界、取值下界
	double best_score;
	vector<double> best_vec;

};


int main() {
	solution sol1(100, 50, 2000, 0.1, [](vector<double> T) {
		//		种群大小、种群规模、迭代次数、突变率、适应度函数
		return accumulate(T.begin(), T.end(), (double)0, [](auto i, auto j) {return i + abs(j * j + j); });
		}, -30.0, 30.0);
		//		取值下界、取值上界

	//solution sol1(100, 50, 2000, 0.1, [](vector<double> T) {
	//	return accumulate(T.begin(), T.end(), (double)0, [](auto i, auto j) {return i + j * j + j; });
	//	}, -30.0, 30.0);

	sol1.evaluate();


	return 0;
}
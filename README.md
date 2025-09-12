# 个人编程项目集

这个仓库放置了我个人编写的一些算法程序和编程项目，多数为对力扣中的算法题的解答。

## Leetcode 题目集

### 项目介绍
完成的leetcode算法题部分，包括hard题目、周赛题，命名方式为 题目编号_难度.cpp  
编程语言使用c++  需要c++17标准及以上

#### 1579 hard  
复杂度分析
```
时间复杂度：O(N⋅log(n))     空间复杂度：O(N)
```
#### 2503 hard  
复杂度分析
```
时间复杂度：O(mnlogmn+klogk)     空间复杂度：O(mn+k)
```
#### 1994 hard  
复杂度分析
```
时间复杂度：O(n+C×2^π(C))     空间复杂度：O(N)
```
#### 2787 medium  
复杂度分析
```
时间复杂度：O(n^(3/2))     空间复杂度：O(n)
```
#### 3621 hard  
复杂度分析
```
时间复杂度：O(logn*logk)     空间复杂度：O(1)
```
#### 2801 hard  
复杂度分析
```
时间复杂度：O((n1+n2)*D)     空间复杂度：O(1)
```
#### 329 hard  
复杂度分析
```
时间复杂度：O(mn)     空间复杂度：O(mn)
```
#### 1402 hard  
复杂度分析
```
时间复杂度：O(nlogn)     空间复杂度：O(1)
```
#### 879 hard  
复杂度分析
```
时间复杂度：O(len×n×minProfit)     空间复杂度：O(n×minProfit)
```
#### 3677 hard  
复杂度分析
```
时间复杂度：O(logn)     空间复杂度：O(logn)
```
#### 2276 hard  
复杂度分析
```
时间复杂度：add() O(logn) count() O(1)     空间复杂度：O(n)
```
#### 3485 hard  
复杂度分析
```
时间复杂度：O(L) O(L)  L为字符串长度之和    空间复杂度：O(n)
```

## Heredity - 遗传算法函数优化

### 项目介绍
基于遗传算法（GA）的函数优化求解器，采用现代C++编写。

### 主要特性
- 多参数调优
- 自适应变异
- 精英保留策略

### 使用示例
#### heredity_class_sol.cpp
```
int main() {
	solution sol1(100, 50, 2000, 0.1, [](vector<double> T) {
		//		种群大小、种群规模、迭代次数、突变率、适应度函数
		return accumulate(T.begin(), T.end(), (double)0, [](auto i, auto j) {return i + abs(j * j + j); });
		}, -30.0, 30.0);
		//		取值下界、取值上界
	sol1.evaluate();
	return 0;
}
```
#### 
heredity.cpp
```
int main() {
    // 参数设置
    int pop_size = 100;       // 种群大小
    int dim = 50;             // 向量维度
    double lower_bound = -30; // 变量下界
    double upper_bound = 30;  // 变量上界
    int max_generations = 100;
    double crossover_rate = 0.8;
    double mutation_rate = 0.1;

    // 执行遗传改进算法
    auto [best_solution, best_fitness] = genetic_algorithm(pop_size, dim, lower_bound, upper_bound, max_generations, crossover_rate, mutation_rate);

    // 输出最优解和最优适应度
    std::cout << "Best Solution: ";
    for (double x : best_solution) {
        std::cout << x << " ";
    }
    std::cout << "\nBest Fitness: " << best_fitness << std::endl;

    return 0;
}
```
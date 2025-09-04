#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

// 目标函数 f(t) = sum |t_i^2 + t_i|
double objective_function(const std::vector<double>& t) {
    double sum = 0.0;
    for (double ti : t) {
        sum += std::abs(ti * ti + ti);
    }
    return sum;
}

// 初始化种群
std::vector<std::vector<double>> initialize_population(int pop_size, int dim, double lower_bound, double upper_bound) {
    std::vector<std::vector<double>> population(pop_size, std::vector<double>(dim));
    for (int i = 0; i < pop_size; ++i) {
        for (int j = 0; j < dim; ++j) {
            population[i][j] = lower_bound + (upper_bound - lower_bound) * (rand() / double(RAND_MAX));
        }
    }
    return population;
}

// 计算适应度（目标函数值）
std::vector<double> calculate_fitness(const std::vector<std::vector<double>>& population) {
    std::vector<double> fitness(population.size());
    for (size_t i = 0; i < population.size(); ++i) {
        fitness[i] = objective_function(population[i]);
    }
    return fitness;
}

// 选择操作（轮盘赌选择）
std::vector<std::vector<double>> selection(const std::vector<std::vector<double>>& population, const std::vector<double>& fitness) {
    double total_fitness = 0.0;
    for (double f : fitness) {
        total_fitness += 1.0 / (1.0 + f); // 适应度越小，越有可能被选中
    }

    std::vector<std::vector<double>> selected_population;
    for (size_t i = 0; i < population.size(); ++i) {
        double rand_value = rand() / double(RAND_MAX) * total_fitness;
        double cumulative_sum = 0.0;
        for (size_t j = 0; j < population.size(); ++j) {
            cumulative_sum += 1.0 / (1.0 + fitness[j]);
            if (cumulative_sum >= rand_value) {
                selected_population.push_back(population[j]);
                break;
            }
        }
    }
    return selected_population;
}

// 交叉操作（单点交叉）
std::pair<std::vector<double>, std::vector<double>> crossover(const std::vector<double>& parent1, const std::vector<double>& parent2, double crossover_rate) {
    std::vector<double> child1 = parent1;
    std::vector<double> child2 = parent2;
    if (rand() / double(RAND_MAX) < crossover_rate) {
        int point = rand() % parent1.size();
        for (int i = point; i < parent1.size(); ++i) {
            std::swap(child1[i], child2[i]);
        }
    }
    return { child1, child2 };
}

// 变异操作
void mutate(std::vector<double>& individual, double mutation_rate, double lower_bound, double upper_bound) {
    for (size_t i = 0; i < individual.size(); ++i) {
        if (rand() / double(RAND_MAX) < mutation_rate) {
            individual[i] += (rand() / double(RAND_MAX) * 2 - 1); // 在 [-1, 1] 范围内随机变异
            individual[i] = std::max(lower_bound, std::min(upper_bound, individual[i])); // 限制在范围内
        }
    }
}

// 遗传改进算法
std::pair<std::vector<double>, double> genetic_algorithm(int pop_size, int dim, double lower_bound, double upper_bound, int max_generations, double crossover_rate, double mutation_rate) {
    srand(time(0));
    auto population = initialize_population(pop_size, dim, lower_bound, upper_bound);
    std::vector<double> best_solution;
    double best_fitness = std::numeric_limits<double>::infinity();

    for (int generation = 0; generation < max_generations; ++generation) {
        // 计算适应度
        auto fitness = calculate_fitness(population);

        // 更新最优解
        auto min_it = std::min_element(fitness.begin(), fitness.end());
        double current_best_fitness = *min_it;
        int min_idx = std::distance(fitness.begin(), min_it);
        if (current_best_fitness < best_fitness) {
            best_fitness = current_best_fitness;
            best_solution = population[min_idx];
        }

        // 选择下一代种群
        auto selected_population = selection(population, fitness);

        // 生成新种群
        std::vector<std::vector<double>> new_population;
        for (size_t i = 0; i < selected_population.size(); i += 2) {
            auto parent1 = selected_population[i];
            auto parent2 = selected_population[i + 1 < selected_population.size() ? i + 1 : 0];
            auto [child1, child2] = crossover(parent1, parent2, crossover_rate);
            mutate(child1, mutation_rate, lower_bound, upper_bound);
            mutate(child2, mutation_rate, lower_bound, upper_bound);
            new_population.push_back(child1);
            new_population.push_back(child2);
        }

        population = new_population;

        // 输出当前代信息
        std::cout << "Generation " << generation + 1 << ": Best Fitness = " << best_fitness << std::endl;
    }

    return { best_solution, best_fitness };
}

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

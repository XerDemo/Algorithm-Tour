//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 6;// 6边形（Hexagon）
//typedef int ElementType;// 权重数据类型
//
//vector<vector<ElementType>> weight = {// 给出权函数。
//        {0, 2, 3, 1, 5, 6},
//        {2, 0, 3, 4, 8, 6},
//        {3, 3, 0, 10, 13, 7},
//        {1, 4, 10, 0, 12, 5},
//        {5, 8, 13, 12, 0, 3},
//        {6, 6, 7, 5, 3, 0} };
//
//vector<ElementType> tempWeight(N, 0);// 临时vector，给下面提供。
//vector<int> tempPoint(N, -1);// 临时vector，给下面提供。
//vector<vector<ElementType>> bestWeight(N, tempWeight);// bestWeight[i][j] 记录凸子多边形 {Vi, ..., Vj} 三角剖分的最优权值。
//vector<vector<int>> bestPoint(N, tempPoint);// bestPoing[i][j] 记录与 Vi、Vj 构成三角形第三个顶点 Vk 。
//
//// 计算由 Vi、Vk、Vj 组成的三角形的权重之和。
//ElementType getWeight(int i, int k, int j);
//
//// 自顶向下的递归动态规划算法：自顶向下递归计算多边形 {Vi, ..., Vj} 最优三角剖分的权值之和。
//ElementType triangulationRec(const int & i, const int & j);
//
//// 自底向上的动态规划算法：自底向上计算 n 边形最优三角剖分的权值之和。
//ElementType triangulation(int n);
//
//// 打印凸子多边形 {Vi, ..., Vj} 的最优三角剖分结果。
//void printTriangulation(int i, int j);
//
//int main() {
//    // 以下两段注释选一段执行，观察一种算法的测试运行结果。
//
//    //cout << endl << "----------使用自顶向下的递归动态规划算法计算----------" << endl;
//    //cout << endl << "最优三角剖分的权值之和为：" << triangulationRec(0, N - 1) << endl << endl;
//
//    //cout << endl << "------------使用自底向上的动态规划算法计算------------" << endl;
//    //cout << endl << "最优三角剖分的权值之和为：" << triangulation(N) << endl << endl;
//
//    cout << "剖分结果为：" << endl;
//    printTriangulation(0, N - 1);
//
//    return 0;
//}
//
//// 计算由 Vi、Vk、Vj 组成的三角形的权重之和。
//ElementType getWeight(int i, int k, int j) {
//    return weight[i][k] + weight[i][j] + weight[k][j];
//}
//
//// 自顶向下的递归动态规划算法：自顶向下递归计算多边形 {Vi, ..., Vj} 最优三角剖分的权值之和。
//ElementType triangulationRec(const int & i, const int & j) {
//    if (bestWeight[i][j] != 0) {
//        // 此处运用了备忘录算法的思想，要点为：初始值为0，如果不为0，说明已经计算过了，直接拿来用。
//        return bestWeight[i][j];
//    }
//
//    if (i + 1 == j || i == j) {
//        // 多变形退化成一条边或一个点，权值返回0。
//        // 实际上，退化成一个点的情况不用考虑，因为后面的代码不会允许这种情况发生。
//        return 0;
//    }
//
//    // 先单独处理 k = i + 1 的情况，
//    // 这样 bestWeight[i][j]、bestPoint[i][j] 才能得到基准值。
//    int k = i + 1;
//    bestWeight[i][j] = triangulationRec(i, k) + triangulationRec(k, j) + getWeight(i, k, j);
//    bestPoint[i][j] = k;
//
//    // 然后从 k = i + 2 开始寻找最优权值。
//    for (k = i + 2; k < j; ++k) {
//        int temp = triangulationRec(i, k) + triangulationRec(k, j) + getWeight(i, k, j);
//        if (temp < bestWeight[i][j]) {
//            // 得到了更优的权值，更新 bestWeight[i][j]、bestPoint[i][j]。
//            bestWeight[i][j] = temp;
//            bestPoint[i][j] = k;
//        }
//    }
//
//    return bestWeight[i][j];
//}
//
//// 自底向上的动态规划算法：自底向上计算 n 边形最优三角剖分的权值之和。
//ElementType triangulation(int n) {
//    // 多变形退化成一条边或一个点，权值为0。
//    bestWeight[n - 1][n - 1] = 0;
//    for (int i = 0; i < n - 1; ++i) {
//        bestWeight[i][i] = bestWeight[i][i + 1] = 0;
//    }
//
//    for (int scale = 2; scale < n; ++scale) {
//        // scale 代表子问题规模，例如，子问题 {V0, V1, V2} 的规模为2，
//        // 问题 {V0, ..., V5} 的规模为5。
//        for (int i = 0; i < n - scale; ++i) {// n - scale - 1 代表规模为 scale 的最后一个子问题的前边界。
//            int j = i + scale;// j 代表当前以 Vi 为起点的子问题的后边界 Vj。
//
//            // 先单独处理 k = i + 1 的情况，
//            // 这样 bestWeight[i][j]、bestPoint[i][j] 才能得到基准值。
//            bestWeight[i][j] = bestWeight[i][i + 1] + bestWeight[i + 1][j] + getWeight(i, i + 1, j);
//            bestPoint[i][j] = i + 1;
//
//            // 然后从 k = i + 2 开始寻找最优权值。
//            for (int k = i + 2; k < j; ++k) {
//                int temp = bestWeight[i][k] + bestWeight[k][j] + getWeight(i, k, j);
//                if (temp < bestWeight[i][j]) {
//                    // 得到了更优的权值，更新 bestWeight[i][j]、bestPoint[i][j]。
//                    bestWeight[i][j] = temp;
//                    bestPoint[i][j] = k;
//                }
//            }
//        }
//    }
//
//    return bestWeight[0][n - 1];
//}
//
//// 打印凸子多边形 {Vi, ..., Vj} 的最优三角剖分结果。
//void printTriangulation(int i, int j) {
//    if (i + 1 == j || i == j) {
//        // 使用“短路”提高打印效率，因为 i + 1 == j 发生频率比 i == j 高。
//        return;
//    }
//
//    printTriangulation(i, bestPoint[i][j]);
//    cout << "V" << i << " -- V" << bestPoint[i][j] << " -- V" << j << " = " << getWeight(i, bestPoint[i][j], j) << endl;
//    printTriangulation(bestPoint[i][j], j);
//}
#include <iostream>
#include <vector>
#include "Net.h"

int main()
{
    Net* net = new Net();

    /*std::vector<Eigen::MatrixXf> weights;
    Eigen::MatrixXf weights12(2,3);
    weights12 << 0.25, 0.25, 0, 0.5, -0.4, 0.9;
    Eigen::MatrixXf weights23(1,2);
    weights23 << -1, 1;
    weights.push_back(weights12);
    weights.push_back(weights23);
    net->setWieghts(weights);
*/
    net->setWieghts("Test.txt");
    Eigen::MatrixXf input(3,1);
    input << 1, 1, 1;

    net->saveWeights("Test.txt");

    Eigen::MatrixXf result = net->predict(input);
    std::cout << result << std::endl;

    return 0;
}
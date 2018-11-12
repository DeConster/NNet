#pragma once
#include <vector>
#include <string>
#include "eigen/Eigen/Core"

class Net
{
    Eigen::MatrixXf mInput;
    std::vector<Eigen::MatrixXf> mWeights;
    Eigen::MatrixXf mOutput;

public:
    void setInput(Eigen::MatrixXf input);
    void setWieghts(std::vector<Eigen::MatrixXf> weights);
    void setWieghts(std::string filePath);
    void saveWeights(std::string filePath);
    Eigen::MatrixXf predict(Eigen::MatrixXf input);
    Eigen::MatrixXf training(Eigen::MatrixXf input, int result);
    void ActivationFunction(Eigen::MatrixXf& input);
    float sigmoid(float input);
};
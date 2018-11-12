#include "Net.h"
#include <iostream>
#include <fstream>
#include <math.h>

void Net::setInput(Eigen::MatrixXf input)
{
    mInput = input;
}

void Net::setWieghts(std::vector<Eigen::MatrixXf> weights)
{
    mWeights = weights;
}

void Net::setWieghts(std::string filePath)
{
    std::ifstream file(filePath.c_str());
    if (file.is_open())
    {
        float temp;
        while (file >> temp)
        {
            std::cout << temp << std::endl;
        }

        file.close();
    }
    // TODO: implement read from file
}

void Net::saveWeights(std::string filePath)
{
    std::ofstream file(filePath.c_str());
    if (file.is_open())
    {
        for (Eigen::MatrixXf m : mWeights)
        {
            file << m << std::endl;
        }

        file.close();
    }
}

Eigen::MatrixXf Net::predict(Eigen::MatrixXf input)
{
    mInput = input;

    for (int i = 0; i < mWeights.size(); i++)
    {
        mInput = mWeights[i] * mInput;
        ActivationFunction(mInput);
        mOutput = mInput;
    }

    return mOutput;
}

Eigen::MatrixXf training(Eigen::MatrixXf input, int result)
{
    Eigen::MatrixXf output = predict(input);
    float error = output(0,0) - result;
    float sigmoidDer = output(0,0) * (1 - output(0,0));
    float weightsDelta = error * sigmoidDer;

    // TODO: Finish
}

void Net::ActivationFunction(Eigen::MatrixXf& input)
{
    for (int i = 0; i < input.rows(); i++)
    {
        for (int j = 0; j < input.cols(); j++)
        {
            input(i,j) = sigmoid(input(i,j)); // TODO: need to use any function
        }
    }
}

float Net::sigmoid(float input)
{
    return 1 / (1 + exp(-input));
}
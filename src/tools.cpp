#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */

  VectorXd rmse(4);
	rmse << 0,0,0,0;

	if(estimations.size() == 0 || ground_truth.size() == 0){
		cout << "ERROR - CalculateRMSE ()" << endl;
		return rmse;
	}

	unsigned int n = estimations.size();
	if(n != ground_truth.size()){
		cout << "ERROR - CalculateRMSE () - The ground-truth and estimations vectors must have the same size." << endl;
		return rmse;
	}

	for(unsigned int i=0; i < estimations.size(); ++i){

		VectorXd residual = estimations[i] - ground_truth[i];

		//coefficient-wise multiplication
		residual = residual.array()*residual.array();
		rmse += residual;
	}

	//calculate the mean
	rmse = rmse/n;
	rmse = rmse.array().sqrt();

	cout << "rmse = " << rmse << endl;
	return rmse;
}
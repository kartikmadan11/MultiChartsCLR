#include "C:\Users\magic\source\repos\MultiCharts\MultiCharts\MultiCharts.cpp"

#pragma once

namespace MultiChartsCppWrapper {
	public ref class MultiChartsWrapper
	{
	public:
		MultiChartsWrapper();
		~MultiChartsWrapper();

		void SetTrainingData(array<System::Double> ^trainingData);
		void SetDateArray(array<System::String^> ^dateArray);
		void SetFileName(System::String fileName);
		void SetLearningRate(double learningRate);
		void SetEpochs(int epochs);
		void SetScale(int scale);
		void SetOptimizer(int optimizer);
		void SetMomentum(int momentum);
		void SetTestingPart(double testingPart);
		void SetTestingWeight(double testingWeight);
		double TrainModel();

	private:
		MultiCharts *multiCharts;
	};
}
#include "stdafx.h"
#include "MultiChartsCLR.h"

using System::Runtime::InteropServices::Marshal;
using MultiChartsCppWrapper::MultiChartsWrapper;

MultiChartsWrapper::MultiChartsWrapper()
{
	multiCharts = new MultiCharts();
}

MultiChartsWrapper::~MultiChartsWrapper()
{
	this->multiCharts->DisposeMultiCharts();
}

void MultiChartsWrapper::SetTrainingData(array<System::Double> ^trainingData)
{
	double* trainingDataUnmanaged = new double[trainingData->Length];
	Marshal::Copy(trainingData, 0, System::IntPtr(trainingDataUnmanaged), trainingData->Length);
	multiCharts->InitDateArray(trainingData->Length);
	multiCharts->SetTrainingData(trainingDataUnmanaged);
	delete trainingDataUnmanaged;
}

void MultiChartsWrapper::SetDateArray(array<System::String^> ^dateArray)
{
	int dateWidth = dateArray[0]->Length + 1;
	int totalCharLength = dateArray->Length * dateWidth;

	char* dateArrayUnmanaged = new char[totalCharLength];
	
	for (int i = 0; i < totalCharLength; i += dateArray[0]->Length)
	{
		char* date = new char[dateWidth];
		date = (char*)(void*)Marshal::StringToHGlobalAnsi(dateArray[i / dateWidth]);
		for (int j = 0; j < dateWidth; j++)
		{
			dateArrayUnmanaged[i + j] = date[j];
		}
	}

	multiCharts->InitDateArray(totalCharLength);
	multiCharts->SetDateArray(dateArrayUnmanaged);
}

void MultiChartsWrapper::SetDateArrayUNIX(array<long long> ^dateArray)
{
	long long* dateArrayUnmanaged = new long long[dateArray->Length];
	Marshal::Copy(dateArray, 0, System::IntPtr(dateArrayUnmanaged), dateArray->Length);
	multiCharts->InitDateArrayUNIX(dateArray->Length);
	multiCharts->SetDateArrayUNIX(dateArrayUnmanaged);
	delete dateArrayUnmanaged;
}

void MultiChartsWrapper::SetFileName(System::String^ fileName)
{
	char* fileNameUnmanaged = new char[fileName->Length];
	fileNameUnmanaged = (char*)(void*)Marshal::StringToHGlobalAnsi(fileName);
	
	multiCharts->InitFileName(fileName->Length);
	multiCharts->SetDateArray(fileNameUnmanaged);
	delete fileNameUnmanaged;
}

void MultiChartsWrapper::SetLearningRate(double learningRate)
{
	multiCharts->SetLearningRate(learningRate);
}

void MultiChartsWrapper::SetEpochs(int epochs)
{
	multiCharts->SetEpochs(epochs);
}

void MultiChartsWrapper::SetScale(int scale)
{
	multiCharts->SetScale(scale);
}

void MultiChartsWrapper::SetOptimizer(int optimizer)
{
	multiCharts->SetOptimizer(optimizer);
}

void MultiChartsWrapper::SetMomentum(int momentum)
{
	multiCharts->SetMomentum(momentum);
}

void MultiChartsWrapper::SetTestingPart(double testingPart)
{
	multiCharts->SetTestingPart(testingPart);
}

void MultiChartsWrapper::SetTestingWeight(double testingWeight)
{
	multiCharts->SetTestingWeight(testingWeight);
}

double MultiChartsWrapper::TrainModel()
{
	return multiCharts->TrainModel();
}
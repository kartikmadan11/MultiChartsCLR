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
	int totalCharLength = dateArray->Length * dateArray[0]->Length;
	char* dateArrayUnmanaged = new char[totalCharLength];
	for (int i = 0; i < dateArray->Length; i++)
	{
		dateArrayUnmanaged[i] = (char*)(void*)Marshal::StringToHGlobalAnsi(dateArray[i]);
	}
	Marshal::FreeHGlobal(dateArrayU);
/*
	char*  = new char[dateArray->Length];
	Marshal::Copy(dateArray, 0, System::IntPtr(dateArrayUnmanaged), dateArray->Length);
	multiCharts->InitDateArray(dateArray->Length);
	multiCharts->SetDateArray(dateArrayUnmanaged);
	delete dateArrayUnmanaged;*/
}

void MultiChartsWrapper::SetFileName(System::String fileName)
{
	char* fileNameUnmanaged = new char[fileName->Length];
	Marshal::Copy(fileName, 0, System::IntPtr(fileNameUnmanaged), fileName->Length);
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
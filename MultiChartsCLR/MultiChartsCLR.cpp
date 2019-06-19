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

void MultiChartsWrapper::DisposeMultiCharts()
{
	multiCharts->DisposeMultiCharts();
}

void MultiChartsWrapper::SetTrainingData(array<double> ^trainingData)
{
	double* trainingDataUnmanaged = new double[trainingData->Length];
	Marshal::Copy(trainingData, 0, System::IntPtr(trainingDataUnmanaged), trainingData->Length);
	multiCharts->InitTrainingData(trainingData->Length);
	multiCharts->SetTrainingData(trainingDataUnmanaged);
	delete[] trainingDataUnmanaged;
}

void MultiChartsWrapper::SetTestingData(array<double> ^testingData)
{
	double* testingDataUnmanaged = new double[testingData->Length];
	Marshal::Copy(testingData, 0, System::IntPtr(testingDataUnmanaged), testingData->Length);
	multiCharts->InitTestingData(testingData->Length);
	multiCharts->SetTestingData(testingDataUnmanaged);
	delete[] testingDataUnmanaged;
}

void MultiChartsWrapper::SetDateArrayUNIX(array<long long> ^dateArray)
{
	long long* dateArrayUnmanaged = new long long[dateArray->Length];
	Marshal::Copy(dateArray, 0, System::IntPtr(dateArrayUnmanaged), dateArray->Length);
	multiCharts->InitDateArrayUNIX(dateArray->Length);
	multiCharts->SetDateArrayUNIX(dateArrayUnmanaged);
	delete[] dateArrayUnmanaged;
}
	
void MultiChartsWrapper::SetTestDateArrayUNIX(array<long long> ^dateArray)
{
	long long* testDateArrayUnmanaged = new long long[dateArray->Length];
	Marshal::Copy(dateArray, 0, System::IntPtr(testDateArrayUnmanaged), dateArray->Length);
	multiCharts->InitTestDateArrayUNIX(dateArray->Length);
	multiCharts->SetTestDateArrayUNIX(testDateArrayUnmanaged);
	delete[] testDateArrayUnmanaged;
}

void MultiChartsWrapper::SetFileName(System::String^ fileName)
{
	char* fileNameUnmanaged = new char[fileName->Length];
	fileNameUnmanaged = (char*)(void*)Marshal::StringToHGlobalAnsi(fileName);
	
	multiCharts->InitFileName(fileName->Length);
	multiCharts->SetFileName(fileNameUnmanaged);
	delete[] fileNameUnmanaged;
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

void MultiChartsWrapper::SetMomentum(double momentum)
{
	multiCharts->SetMomentum(momentum);
}

double MultiChartsWrapper::TrainModel()
{
	return multiCharts->TrainModel();
}

double MultiChartsWrapper::TestModel()
{
	return multiCharts->TestModel();
}

array<double>^ MultiChartsWrapper::Predict(int ticks)
{
	double* unmanagedArr = multiCharts->Predict(ticks);
	array<System::Double> ^managedArr = gcnew array<System::Double>(ticks);
	for (int i = 0; i < ticks; i++)
	{
		managedArr[i] = unmanagedArr[i];
	}
	return managedArr;
}
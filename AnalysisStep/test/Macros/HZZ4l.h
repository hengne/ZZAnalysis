#ifndef HZZ4l_h
#define HZZ4l_h

#include "HZZ4lBase.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TMath.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include <ZZMatrixElement/MELA/interface/Mela.h>
#include <ZZMatrixElement/MELA/src/computeAngles.h>

#include <TString.h>
#include <string>
#include <vector>

const double PI_VAL = TMath::Pi();
const int kNumFiles=35;
const int nFinalStates=5;

enum sample {
	kfg2_0_fg4_0,
	kfg2_1_fg4_0,
	kfg2_0_fg4_1,
	kfLambda1_1,

	kfg2_05_fg4_0,
	kfg2_0_fg4_05,
	kfg2_05_fg4_05,
	kfLambda1_m05,

	kfg2_33_fg4_33,
	kfg2_01_fg4_0,
	kfg2_0_fg4_01,
	kfg2_01_fg4_01,

	kfLambda1_05,
	kfLambda1_03, // No sample here
	kfLambda1_01,

	kfg2_05_fg4_0_p290,
	kfg2_0_fg4_05_p390,
	kfg2_05_fg4_05_p390,

	kfg2_33_fg4_33_p390,
	kfg2_01_fg4_0_p290,
	kfg2_0_fg4_01_p390,
	kfg2_01_fg4_01_p390,

	kfg2_05_fg4_0_p2Pi,
	kfg2_0_fg4_05_p3Pi,
	kfg2_05_fg4_05_p2Pi,

	kfg2_05_fLambda1_m05,
	kfg2_05_fLambda1_m05_p2270,
	kfg2_05_fLambda1_05,
	kfg2_33_fLambda1_33_p2Pi,

	kfg4_05_fLambda1_m05,
	kfg4_05_fLambda1_m05_p3270,
	kfg4_05_fLambda1_05,
	kfg4_33_fLambda1_33_p3Pi,

	kfZG_1_fGG_0,
	kfZG_0_fGG_1,
	kfZG_05_fGG_0,
	kfZG_0_fGG_05,

	kfMZG_1_fMGG_0,
	kfMZG_0_fMGG_1,
	kfMZG_05_fMGG_0,
	kfMZG_0_fMGG_05,

	kfZG_05_fMZG_05,
	kfGG_05_fMGG_05,

	kfZG_SM_fGG_SM,

	kNumSamples
};
const double gi_phi2_phi4[2][kNumSamples][13]={ // g1-4; phia2,3; MASS, WIDTH; g1pp; gZG, gGG; gZG-PS, gGG-PS
	{
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // Pure SM
		{	0,	1.0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=1
		{	0,	0,	0,	1.0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa3=1
		{	0,	0,	0,	0,		0,	0,	126.0,	0.1,	1.0, 0, 0, 0, 0}, // fL1=1
												
		{	1.0,	1.624,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=0.5
		{	1.0,	0,	0,	2.484,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa3=0.5
		{	0,	0.654,	0,	1.0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=fa3=0.5
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	12003.14, 0, 0, 0, 0}, // fLambda1=-0.5, for T3 templates
												
		{	1.0,	1.624,	0,	2.484,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=fa3=1/3
		{	1.0,	0.541,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=0.1
		{	1.0,	0,	0,	0.828,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa3=0.1
		{	1.0,	0.574,	0,	0.878,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=fa3=0.1
												
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	-12003.14, 0, 0, 0, 0}, // fLambda1=0.5
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	-7857.90, 0, 0, 0, 0}, // g1pp=-7857.90, g1=1: flambda1=0.3
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	-4001.05, 0, 0, 0, 0}, // g1pp=-4001.05, g1=1: flambda1=0.1 
												
		{	1.0,	1.624,	0,	0,		PI_VAL/2.0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=0.5, phia2=90
		{	1.0,	0,	0,	2.484,		0,	PI_VAL/2.0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa3=0.5, phia3=90
		{	0,	0.654,	0,	1.0,		0,	PI_VAL/2.0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=fa3=0.5, phia3=90
												
		{	1.0,	1.624,	0,	2.484,		0,	PI_VAL/2.0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=fa3=1/3, phia3=90
		{	1.0,	0.541,	0,	0,		PI_VAL/2.0,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=0.1, phia2=90
		{	1.0,	0,	0,	0.828,		0,	PI_VAL/2.0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa3=0.1, phia3=90
		{	1.0,	0.574,	0,	0.878,		0,	PI_VAL/2.0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=0.1, fa3=0.1, phia3=90
												
		{	1.0,	1.624,	0,	0,		PI_VAL,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=-0.5
		{	1.0,	0,	0,	2.484,		0,	PI_VAL,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa3=-0.5
		{	0,	0.654,	0,	1.0,		PI_VAL,	0,	126.0,	0.1,	0, 0, 0, 0, 0}, // fa2=-0.5, fa3=0.5
												
		{	0,	1.624,	0,	0,		0,	0,	126.0,	0.1,	12003.14, 0, 0, 0, 0}, // fa2=0.5, fLambda1=-0.5, for templates 25
		{	0,	1.624,	0,	0,		PI_VAL*3.0/2.0,	0,	126.0,	0.1,	12003.14, 0, 0, 0, 0}, // fa2=-0.5i, fLambda1=-0.5, for templates 26
		{	0,	1.624,	0,	0,		0,	0,	126.0,	0.1,	-12003.14, 0, 0, 0, 0}, // fa2=0.5, fLambda1=0.5 27
		{	1.0,	1.624,	0,	0,		PI_VAL,	0,	126.0,	0.1,	-12003.14, 0, 0, 0, 0}, // fa2=-0.33, fLambda1=0.33 28
												
		{	0,	0,	0,	2.484,		0,	0,	126.0,	0.1,	12003.14, 0, 0, 0, 0}, // fa3=0.5, fLambda1=-0.5, for templates 29
		{	0,	0,	0,	2.484,		PI_VAL*3.0/2.0,	0,	126.0,	0.1,	12003.14, 0, 0, 0, 0}, // fa3=-0.5i, fLambda1=-0.5, for templates 30
		{	0,	0,	0,	2.484,		0,	0,	126.0,	0.1,	-12003.14, 0, 0, 0, 0}, // fa3=0.5, fLambda1=0.5 31
		{	1.0,	0,	0,	2.484,		PI_VAL,	0,	126.0,	0.1,	-12003.14, 0, 0, 0, 0}, // fa3=-0.33, fLambda1=0.33 32
												
		{	0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 1, 0, 0, 0}, // Pure PM-ZG 33
		{	0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 1, 0, 0}, // Pure PM-GG 34
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0.0476, 0, 0, 0}, // fPM-ZG=0.5 35
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, -0.0541, 0, 0}, // fPM-GG=0.5 36
												
		{	0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 1, 0}, // Pure M-ZG 37
		{	0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 1}, // Pure M-GG 38
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 0.050895, 0}, // fM-ZG=0.5 39
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, -0.052872}, // fM-GG=0.5 40
												
		{	0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0.0476, 0, 0.050895, 0}, // fZG=fM-ZG=0.5 41
		{	0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, -0.0541, 0, -0.052872}, // fGG=fM-GG=0.5 42
												
		{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0.00175, -0.002, 0, 0} // SM ZZ, ZG. GG 43
	},
	{
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // Pure SM 0
		{	0,	1.0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=1 1
		{	0,	0,	0,	1.0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=1 2
		{	0,	0,	0,	0,		0,	0,	125.6,	0.00415,	1.0, 0, 0, 0, 0}, // fL1=1 3
												
		{	1.0,	1.638,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.5 4
		{	1.0,	0,	0,	2.521,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=0.5 5
		{	0,	0.650,	0,	1.0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=0.5 6
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	12046.01, 0, 0, 0, 0}, // fLambda1=-0.5, for T3 templates 7
												
		{	1.0,	1.638,	0,	2.521,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=1/3 8
		{	1.0,	0.546,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.1 9
		{	1.0,	0,	0,	0.840,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=0.1 10
		{	1.0,	0.579,	0,	0.891,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=0.1 11
												
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	-12046.01, 0, 0, 0, 0}, // fLambda1=0.5 12
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	-7885.965, 0, 0, 0, 0}, // flambda1=0.3 13
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	-4015.337, 0, 0, 0, 0}, // flambda1=0.1 14
												
		{	1.0,	1.638,	0,	0,		PI_VAL/2.0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.5, phia2=90 15
		{	1.0,	0,	0,	2.521,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=0.5, phia3=90 16
		{	0,	0.650,	0,	1.0,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=0.5, phia3=90 17
												
		{	1.0,	1.638,	0,	2.521,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=1/3, phia3=90 18
		{	1.0,	0.546,	0,	0,		PI_VAL/2.0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.1, phia2=90 19
		{	1.0,	0,	0,	0.840,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=0.1, phia3=90 20
		{	1.0,	0.579,	0,	0.891,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.1, fa3=0.1, phia3=90 21
												
		{	1.0,	1.638,	0,	0,		PI_VAL,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=-0.5 22
		{	1.0,	0,	0,	2.521,		0,	PI_VAL,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=-0.5 23
		{	0,	0.650,	0,	1.0,		PI_VAL,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=-0.5, fa3=0.5 24
												
		{	0,	1.638,	0,	0,		0,	0,	125.6,	0.00415,	12046.01, 0, 0, 0, 0}, // fa2=0.5, fLambda1=-0.5, for templates 25
		{	0,	1.638,	0,	0,		PI_VAL*3.0/2.0,	0,	125.6,	0.00415,	12046.01, 0, 0, 0, 0}, // fa2=-0.5i, fLambda1=-0.5, for templates 26
		{	0,	1.638,	0,	0,		0,	0,	125.6,	0.00415,	-12046.01, 0, 0, 0, 0}, // fa2=0.5, fLambda1=0.5 27
		{	1.0,	1.638,	0,	0,		PI_VAL,	0,	125.6,	0.00415,	-12046.01, 0, 0, 0, 0}, // fa2=-0.33, fLambda1=0.33 28
												
		{	0,	0,	0,	2.521,		0,	0,	125.6,	0.00415,	12046.01, 0, 0, 0, 0}, // fa3=0.5, fLambda1=-0.5, for templates 29
		{	0,	0,	0,	2.521,		PI_VAL*3.0/2.0,	0,	125.6,	0.00415,	12046.01, 0, 0, 0, 0}, // fa3=-0.5i, fLambda1=-0.5, for templates 30
		{	0,	0,	0,	2.521,		0,	0,	125.6,	0.00415,	-12046.01, 0, 0, 0, 0}, // fa3=0.5, fLambda1=0.5 31
		{	1.0,	0,	0,	2.521,		PI_VAL,	0,	125.6,	0.00415,	-12046.01, 0, 0, 0, 0}, // fa3=-0.33, fLambda1=0.33 32
												
		{	0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 1, 0, 0, 0}, // Pure PM-ZG 33
		{	0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 1, 0, 0}, // Pure PM-GG 34
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0.0473, 0, 0, 0}, // fPM-ZG=0.5 35
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, -0.0531, 0, 0}, // fPM-GG=0.5 36
												
		{	0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 1, 0}, // Pure M-ZG 37
		{	0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 1}, // Pure M-GG 38
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0.052161, 0}, // fM-ZG=0.5 39
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, -0.053666}, // fM-GG=0.5 40
												
		{	0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0.0473, 0, 0.052161, 0}, // fZG=fM-ZG=0.5 41
		{	0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, -0.0531, 0, -0.053666}, // fGG=fM-GG=0.5 42
												
		{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0.00175, -0.002, 0, 0} // SM ZZ, ZG. GG 43
	}
};
const double gi_phi2_phi4_files[kNumFiles][13]={ // g1-4; phia2,3; MASS, WIDTH; g1pp; gZG, gGG; gZG-PS, gGG-PS
// 126 GeV Spin 0											
	{	1.0,	0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0},
	{	0,	1.0,	0,	0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0},
	{	0,	0,	0,	1.0,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0},
											
	{	1.0,	0,	0,	2.498,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0},
	{	1.0,	0,	0,	2.498,		0,	PI_VAL/2.0,	126.0,	0.1,	0, 0, 0, 0, 0},
	{	1.0,	0,	0,	2.498,		0,	PI_VAL,	126.0,	0.1,	0, 0, 0, 0, 0},
	{	1.0,	0,	0,	2.498,		0,	PI_VAL*1.5,	126.0,	0.1,	0, 0, 0, 0, 0},
											
	{	1.0,	0,	0,	0.8327,		0,	0,	126.0,	0.1,	0, 0, 0, 0, 0},
	{	1.0,	0,	0,	0.8327,		0,	PI_VAL/2.0,	126.0,	0.1,	0, 0, 0, 0, 0},
	{	1.0,	0,	0,	0.8327,		0,	PI_VAL,	126.0,	0.1,	0, 0, 0, 0, 0},
	{	1.0,	0,	0,	0.8327,		0,	PI_VAL*1.5,	126.0,	0.1,	0, 0, 0, 0, 0},
// 125.6 GeV Spin 0											
	{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // Pure SM
	{	0,	1.0,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=1
	{	0,	0,	0,	1.0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=1
	{	0,	0,	0,	0,		0,	0,	125.6,	0.00415,	1.0, 0, 0, 0, 0}, // fL1=1
											
	{	1.0,	1.638,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.5
	{	1.0,	0,	0,	2.521,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=0.5
	{	0,	0.650,	0,	1.0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=0.5
	{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	12046.01, 0, 0, 0, 0}, // fLambda1=-0.5, for T3 templates
											
	{	1.0,	1.638,	0,	2.521,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=1/3
	{	1.0,	0.546,	0,	0,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.1
	{	1.0,	0,	0,	0.840,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=0.1
	{	1.0,	0.579,	0,	0.891,		0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=0.1
											
	{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	-12046.01, 0, 0, 0, 0}, // fLambda1=0.5
	// NOTE: No FLambda1=0.3 sample at 125.6 GeV is available										
	{	1.0,	0,	0,	0,		0,	0,	125.6,	0.00415,	-4015.337, 0, 0, 0, 0}, // flambda1=0.1 
											
	{	1.0,	1.638,	0,	0,		PI_VAL/2.0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.5, phia2=90
	{	1.0,	0,	0,	2.521,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=0.5, phia3=90
	{	0,	0.650,	0,	1.0,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=0.5, phia3=90
											
	{	1.0,	1.638,	0,	2.521,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=fa3=1/3, phia3=90
	{	1.0,	0.546,	0,	0,		PI_VAL/2.0,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.1, phia2=90
	{	1.0,	0,	0,	0.840,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=0.1, phia3=90
	{	1.0,	0.579,	0,	0.891,		0,	PI_VAL/2.0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=0.1, fa3=0.1, phia3=90
											
	{	1.0,	1.638,	0,	0,		PI_VAL,	0,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa2=-0.5
	{	1.0,	0,	0,	2.521,		0,	PI_VAL,	125.6,	0.00415,	0, 0, 0, 0, 0}, // fa3=-0.5
	{	0,	0.650,	0,	1.0,		PI_VAL,	0,	125.6,	0.00415,	0, 0, 0, 0, 0} // fa2=-0.5, fa3=0.5
};


//class TH1F;

class HZZ4l : public HZZ4lBase{
public:
  
  HZZ4l(TChain *tree, TString sampleName);
  virtual ~HZZ4l() {};
  void Loop(const Int_t channelType, const TString outputName);
  void identifySample(std::string outputfilename);

  //Methods to set the analyzer
  void set8TeV(bool myis8TeV){is8TeV = myis8TeV;}
  void setBSM(int myBSM_flag){BSM_flag = myBSM_flag;}
  void setKappa(float mykappa){kappa = mykappa;}
  void setCR(bool myisCR){isCR = myisCR;}
  void setHZZ4l(bool myHZZ4l,int myHZZ4lSample,float myHZZ4L_HMassPole){isHZZ4l = myHZZ4l; HZZ4lSample=myHZZ4lSample; HZZ4L_HMassPole=myHZZ4L_HMassPole;}
  void setHZZ4l_NoLepInt(bool myHZZ4l_NoLepInt){isHZZ4l_NoLepInt = myHZZ4l_NoLepInt;}
  void setGGQQB(bool myZZQQB,bool myZZGG){isZZQQB = myZZQQB; isZZGG = myZZGG;}

  // Some bookkeeping
	double N_generated[nFinalStates][kNumSamples+1];
	double N_generated_4GeVcut[nFinalStates][kNumSamples+1];

private:

  Float_t getMCWeight(const int year, const Int_t CandIndex) const;
  Float_t getAllWeight(const Float_t LepPt, const Float_t LepEta, const Int_t year, Int_t LepID) const;

  Float_t getNormalizedWeight(const Int_t channelType) const;

  std::string getSampleName(const std::string filestring) const;
  Int_t findBestCRCand(int) const;

  void getWeightFromFile(const TString& mPOLE, const Bool_t isVBF, const Bool_t isNewHighmass);
  Float_t getPwhgWeight(double mH, const Int_t WhichSide = 0) const;
  Float_t getHqTWeight(double mH, double genPt, TFile* f) const;

  Float_t getFakeWeight(const Float_t LepPt, const Float_t LepEta, const Int_t year, Int_t LepID, Int_t LepZ1ID);
  Float_t getZXfake_weight(const int year, const Int_t CandIndex);
  float getJHUGenMELAWeight(Mela& myMela, int lepId[4], float angularOrdered[8], double selfDHvvcoupl[30][2]);
  float getMCFMMELAWeight(Mela& myMela, int lepId[4], float angularOrdered[8]);
  void protection_nullPt(TVector3& myV);
  void protection_nullPt(TLorentzVector& myV);
  void calculateAngles(TLorentzVector thep4H, TLorentzVector thep4Z1, TLorentzVector thep4M11, TLorentzVector thep4M12, TLorentzVector thep4Z2, TLorentzVector thep4M21, TLorentzVector thep4M22, float& costheta1, float& costheta2, float& phi, float& costhetastar, float& phistar1, float& phistar2, float& phistar12, float& phi1, float& phi2);
//  void testSpin0MEDivergence(int iSample, int iHypo, float& MEVal);

  TString theSample;

  bool is8TeV;
  bool isCR;
  int BSM_flag;
  float kappa;

  bool isHZZ4l;
  bool isHZZ4l_NoLepInt;
  bool isZZQQB;
  bool isZZGG;
  int HZZ4lSample;
  float HZZ4L_HMassPole;

  TH1F* nEventComplete;

  std::vector<double> pwhg_bincenters;
  std::vector<double> pwhg_weight;
  std::vector<double> pwhg_weightCPSP;
  std::vector<double> pwhg_weightCPSM;
  std::vector<double> pwhg_weightIntP;
  std::vector<double> pwhg_weightIntM;

  TFile* ZXWeightTables[4];

};
#endif

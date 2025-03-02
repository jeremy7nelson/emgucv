//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2025 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#pragma once
#ifndef EMGU_MCC_C_H
#define EMGU_MCC_C_H

#include "opencv2/core/core_c.h"

#ifdef HAVE_OPENCV_MCC
#include "opencv2/mcc.hpp"
#else
static inline CV_NORETURN void throw_no_mcc() { CV_Error(cv::Error::StsBadFunc, "The library is compiled without mcc support. To use this module, please switch to the full Emgu CV runtime."); }

namespace cv {
	namespace mcc {
		class CChecker {};
		class CCheckerDraw {};
		class CCheckerDetector {};
		class DetectorParameters {};
		enum TYPECHART {};
	}
	namespace ccm {
		class ColorCorrectionModel {};
		enum CCM_TYPE {};
		enum DISTANCE_TYPE {};
		enum LINEAR_TYPE {};
		enum COLOR_SPACE {};
	}
}
#endif

CVAPI(cv::mcc::CChecker*) cveCCheckerCreate(cv::Ptr<cv::mcc::CChecker>** sharedPtr);
CVAPI(void) cveCCheckerGetBox(cv::mcc::CChecker* checker, std::vector< cv::Point2f >* box);
CVAPI(void) cveCCheckerSetBox(cv::mcc::CChecker* checker, std::vector< cv::Point2f >* box);
CVAPI(void) cveCCheckerGetCenter(cv::mcc::CChecker* checker, CvPoint2D32f* center);
CVAPI(void) cveCCheckerSetCenter(cv::mcc::CChecker* checker, CvPoint2D32f* center);
CVAPI(void) cveCCheckerRelease(cv::Ptr<cv::mcc::CChecker>** sharedPtr);
CVAPI(void) cveCCheckerGetChartsRGB(cv::mcc::CChecker* checker, cv::_OutputArray* chartsRgb);
CVAPI(void) cveCCheckerSetChartsRGB(cv::mcc::CChecker* checker, cv::Mat* chartsRgb);


CVAPI(cv::mcc::CCheckerDraw*) cveCCheckerDrawCreate(
	cv::mcc::CChecker* pChecker,
	CvScalar* color,
	int thickness,
	cv::Ptr<cv::mcc::CCheckerDraw>** sharedPtr);
CVAPI(void) cveCCheckerDrawDraw(cv::mcc::CCheckerDraw* ccheckerDraw, cv::_InputOutputArray* img);
CVAPI(void) cveCCheckerDrawRelease(cv::Ptr<cv::mcc::CCheckerDraw>** sharedPtr);

CVAPI(cv::mcc::CCheckerDetector*) cveCCheckerDetectorCreate(cv::Algorithm** algorithm, cv::Ptr<cv::mcc::CCheckerDetector>** sharedPtr);
CVAPI(bool) cveCCheckerDetectorProcess(
	cv::mcc::CCheckerDetector* detector,
	cv::_InputArray* image,
	const cv::mcc::TYPECHART chartType,
	const int nc,
	bool useNet,
	cv::mcc::DetectorParameters* param);
CVAPI(cv::mcc::CChecker*) cveCCheckerDetectorGetBestColorChecker(cv::mcc::CCheckerDetector* detector);
CVAPI(void) cveCCheckerDetectorRelease(cv::Ptr<cv::mcc::CCheckerDetector>** sharedPtr);

CVAPI(cv::mcc::DetectorParameters*) cveCCheckerDetectorParametersCreate();
CVAPI(void) cveCCheckerDetectorParametersRelease(cv::mcc::DetectorParameters** parameters);



CVAPI(cv::ccm::ColorCorrectionModel*) cveColorCorrectionModelCreate1(cv::Mat* src, int constColor);
CVAPI(cv::ccm::ColorCorrectionModel*) cveColorCorrectionModelCreate2(cv::Mat* src, cv::Mat* colors, int refCs);
CVAPI(cv::ccm::ColorCorrectionModel*) cveColorCorrectionModelCreate3(cv::Mat* src, cv::Mat* colors, int refCs, cv::Mat* colored);
CVAPI(void) cveColorCorrectionModelRelease(cv::ccm::ColorCorrectionModel** ccm);
CVAPI(void) cveColorCorrectionModelRun(cv::ccm::ColorCorrectionModel* ccm);
CVAPI(void) cveColorCorrectionModelGetCCM(cv::ccm::ColorCorrectionModel* ccm, cv::_OutputArray* result);
CVAPI(void) cveColorCorrectionModelInfer(cv::ccm::ColorCorrectionModel* ccm, cv::Mat* img, cv::_OutputArray* result, bool islinear);
#endif
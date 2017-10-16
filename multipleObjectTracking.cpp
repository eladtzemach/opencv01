#include "opencv2/highgui/highgui.hpp"

#include <iostream>

#include <stdio.h>

#include <opencv2/core/core.hpp>

#include "opencv2/imgcodecs/imgcodecs.hpp"

#include "opencv2/features2d.hpp"

#include "opencv2/opencv.hpp"



using namespace cv;

using namespace std;



int main(int argc, const char** argv)

{

	Mat img1 = imread("C:/Users/elad2_000/Desktop/12970888_1211797328838130_3381966939070486152_o.jpg", CV_LOAD_IMAGE_UNCHANGED);

	Mat img2 = imread("C:/Users/elad2_000/Desktop/12970888_1211797328838130_3381966939070486152_o.jpg", CV_LOAD_IMAGE_UNCHANGED);



	vector<KeyPoint> keypoints1;

	vector<KeyPoint> keypoints2;

	Mat descriptors1, descriptors2;

	Scalar color = Scalar::all(-1);

	int flags = DrawMatchesFlags::DEFAULT;





	// Initiate ORB detector

	Ptr<FeatureDetector> detector = ORB::create();



	// find the keypoints and descriptors with ORB

	detector->detect(img1, keypoints1);

	detector->detect(img2, keypoints2);



	detector->compute(img1, keypoints1, descriptors1);

	detector->compute(img2, keypoints2, descriptors2);



	//-- Draw keypoints

	Mat img_keypoints_1;

	Mat img_keypoints_2;



	drawKeypoints(img1, keypoints1, img_keypoints_1, color, flags);

	drawKeypoints(img2, keypoints2, img_keypoints_2, color, flags);



	//-- Show detected (drawn) keypoints

	imshow("Keypoints 1", img_keypoints_1);

	imshow("Keypoints 2", img_keypoints_2);



	waitKey(0);



	return 0;

}
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include<opencv2/nonfree/nonfree.hpp>
#include<opencv2/legacy/legacy.hpp>
#include<vector>
#include <fstream>
#include <tchar.h>
#include "siftDetec.h"
#include"io.h"
#include"direct.h"
using namespace std;
using namespace cv;
string numToString(int x)
{
	char tmp[100];
	_itoa_s(x,tmp,10);
	string s(tmp);
	return s;
}

void siftDetec(string listPath)
{
	ifstream fin(listPath);
	string featurePath="..\\FeatureFile\\";
	string cmd="mkdir " + featurePath;
	system(cmd.data());
	//string featurePath=mkdir("..\\FeatureFile\\");
	Mat img;
	string ImgPath;
	int i=0;
	while(getline(fin,ImgPath)){
		i++;
		img=imread(ImgPath);
		//如果读入图像失败
		if (img.empty()){
			fprintf(stderr, "Can not load image \n");
		}	

		Mat test_preProcess;//将测试图像根据先验知识进行剪裁处理
	    int temp=min(img.cols,img.rows);//获取图像的最小的（长度或者宽度）
	    test_preProcess=img(Range(0,(int)temp/3),Range(0,(int)temp/1.2));//以最小的长度作为参数对原图进行剪裁
	    Mat GuiYi;
	    resize(test_preProcess,GuiYi,Size(256,256));
		//cv::imwrite((featurePath + numToString(i)+ ".jpg"),GuiYi);
		//imshow("image",GuiYi);
		//sift特征检测
		SiftFeatureDetector siftdtc;
		vector<KeyPoint>kp;
		siftdtc.detect(GuiYi, kp);//到这里其实只是提取到了特征点的具体位置和角度，其保存在kp中
		//Mat outimg;
		//drawKeypoints(img, kp, outimg);
		//imshow("image keypoints", outimg);//之前看别的人博客，到这就可以看到特征点画在图上了，一直以为那些点就是自己要用的那个，其实真正要用的在下边

		SiftDescriptorExtractor extractor;//特征提取器
		Mat descriptor;	//这个描述符才是做实验要用的特征
		extractor.compute(GuiYi, kp, descriptor);
		ofstream file(featurePath+ numToString(i) +".feature");//提取到的特征保存在这个文件中，128维，整数做实验以后再归一化一下
		file << endl << descriptor << endl;
		printf("***************** 处理完第 %d 个测试图像 *****************\n",i);
	}
}

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
		//�������ͼ��ʧ��
		if (img.empty()){
			fprintf(stderr, "Can not load image \n");
		}	

		Mat test_preProcess;//������ͼ���������֪ʶ���м��ô���
	    int temp=min(img.cols,img.rows);//��ȡͼ�����С�ģ����Ȼ��߿�ȣ�
	    test_preProcess=img(Range(0,(int)temp/3),Range(0,(int)temp/1.2));//����С�ĳ�����Ϊ������ԭͼ���м���
	    Mat GuiYi;
	    resize(test_preProcess,GuiYi,Size(256,256));
		//cv::imwrite((featurePath + numToString(i)+ ".jpg"),GuiYi);
		//imshow("image",GuiYi);
		//sift�������
		SiftFeatureDetector siftdtc;
		vector<KeyPoint>kp;
		siftdtc.detect(GuiYi, kp);//��������ʵֻ����ȡ����������ľ���λ�úͽǶȣ��䱣����kp��
		//Mat outimg;
		//drawKeypoints(img, kp, outimg);
		//imshow("image keypoints", outimg);//֮ǰ������˲��ͣ�����Ϳ��Կ��������㻭��ͼ���ˣ�һֱ��Ϊ��Щ������Լ�Ҫ�õ��Ǹ�����ʵ����Ҫ�õ����±�

		SiftDescriptorExtractor extractor;//������ȡ��
		Mat descriptor;	//���������������ʵ��Ҫ�õ�����
		extractor.compute(GuiYi, kp, descriptor);
		ofstream file(featurePath+ numToString(i) +".feature");//��ȡ������������������ļ��У�128ά��������ʵ���Ժ��ٹ�һ��һ��
		file << endl << descriptor << endl;
		printf("***************** ������� %d ������ͼ�� *****************\n",i);
	}
}

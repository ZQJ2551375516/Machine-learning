// opencv_empty_proj.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include<opencv2/nonfree/nonfree.hpp>
#include<opencv2/legacy/legacy.hpp>
#include<vector>
#include <fstream>
#include <tchar.h>
#include "siftDetec.h"
using namespace std;
using namespace cv;
void siftDetec(string listPath);
int main(int argc, char* argv[])
{
	string cmd;
	if((cmd = argv[1]).size()==0)
		return -1;
	siftDetec(cmd);
	//�˺����ȴ�������������������ͷ���="C:\\Users\\qinjie\\Desktop\\database_feature\\list.txt"
	//waitKey();
	return 0;
}
// opencv_empty_proj.cpp : 定义控制台应用程序的入口点。
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
	//此函数等待按键，按键盘任意键就返回="C:\\Users\\qinjie\\Desktop\\database_feature\\list.txt"
	//waitKey();
	return 0;
}
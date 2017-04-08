// 基本工资.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <iomanip>						//本程序的setw在此头文件中定义
#include<fstream>						//本程序的ofstream和ifstream在此头文件中定义
using namespace std;
#define WorkerNum 3							//WorkerNum代表职工人数
//定义了职工的工资数据对应的结构体
struct worker {
	char name[8];        		//职工姓名
	char Id[4];            		//职工编号
	int bs;               		//基本工资
	int os;						//加班工资
	int bonus;      		    //奖金
	int lose;					//扣除
	int sum;					//实发工资
};
void WriteData();			//这3行是函数声明
void Sum(worker w[]);
void OutData(worker  w[]);
void main() {
	worker w[WorkerNum];					//定义保存职工的工资数据的数组
	WriteData();							//读入学生成绩
	OutData(w);							   //输出学生成绩表
}
void WriteData() {//从键盘读入各职工的工资数据，写入磁盘文件中Salary.dat
	ofstream outData("d:\\student.dat");
	char name[8];        		//职工姓名
	char Id[4];            		//职工编号
	int bs;               		//基本工资
	int os;						//加班工资
	int bonus;      		    //奖金
	int lose;					//扣除
	for (int i = 0; i<WorkerNum; i++) {
		cout << "输入单位职工" << i + 1 << "的职工编号，姓名，基本工资，加班工资，奖金，扣除"<<endl;
		cin >> Id >>name >> bs >> os >> bonus >> lose;
		outData << Id << " " << name << " " << bs << " " << os << " " << bonus << " " << lose << endl;
	}
	outData.close();
}
void Sum(worker w[]) {//计算实发工资
	for (int i = 0; i<WorkerNum; i++) {
		w[i].sum=w[i].bs + w[i].os + w[i].bonus - w[i].lose;
	}
}

void OutData(worker w[]) {//从文件中读出每位职工的工资数据并记录在worker数组w
	ifstream infile("d:\\student.dat");
	int i = 0;
	while (!infile.eof()&& i<WorkerNum)		//这里要多读一个空行才会结束，所以要加上&& i<WorkerNum以免数组越界
	{
		infile >> w[i].Id>> w[i].name >> w[i].bs >> w[i].os >> w[i].bonus >> w[i].lose;
		i++;
	}
	Sum(w);//计算实发工资
	cout <<"职工编号" << setw(18) << "姓名" << setw(18) << "基本工资"
		<< setw(18) << "加班工资" << setw(18) << "奖金" << setw(18) << "扣除" << setw(18) << "实发工资" <<endl;

	for (i = 0; i<WorkerNum; i++) {
		//设置左对齐格式化输出数据
		cout <<setiosflags(ios::left) << setw(22) <<w[i].Id << setw(14) << w[i].name << setw(18) << w[i].bs << setw(22) << w[i].os << setw(18) << w[i].bonus << setw(14) << w[i].lose<< w[i].sum;
		cout << endl;
	}
	infile.close();
}

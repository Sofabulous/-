// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <iomanip>						//�������setw�ڴ�ͷ�ļ��ж���
#include<fstream>						//�������ofstream��ifstream�ڴ�ͷ�ļ��ж���
using namespace std;
#define WorkerNum 3							//WorkerNum����ְ������
//������ְ���Ĺ������ݶ�Ӧ�Ľṹ��
struct worker {
	char name[8];        		//ְ������
	char Id[4];            		//ְ�����
	int bs;               		//��������
	int os;						//�Ӱ๤��
	int bonus;      		    //����
	int lose;					//�۳�
	int sum;					//ʵ������
};
void WriteData();			//��3���Ǻ�������
void Sum(worker w[]);
void OutData(worker  w[]);
void main() {
	worker w[WorkerNum];					//���屣��ְ���Ĺ������ݵ�����
	WriteData();							//����ѧ���ɼ�
	OutData(w);							   //���ѧ���ɼ���
}
void WriteData() {//�Ӽ��̶����ְ���Ĺ������ݣ�д������ļ���Salary.dat
	ofstream outData("d:\\student.dat");
	char name[8];        		//ְ������
	char Id[4];            		//ְ�����
	int bs;               		//��������
	int os;						//�Ӱ๤��
	int bonus;      		    //����
	int lose;					//�۳�
	for (int i = 0; i<WorkerNum; i++) {
		cout << "���뵥λְ��" << i + 1 << "��ְ����ţ��������������ʣ��Ӱ๤�ʣ����𣬿۳�"<<endl;
		cin >> Id >>name >> bs >> os >> bonus >> lose;
		outData << Id << " " << name << " " << bs << " " << os << " " << bonus << " " << lose << endl;
	}
	outData.close();
}
void Sum(worker w[]) {//����ʵ������
	for (int i = 0; i<WorkerNum; i++) {
		w[i].sum=w[i].bs + w[i].os + w[i].bonus - w[i].lose;
	}
}

void OutData(worker w[]) {//���ļ��ж���ÿλְ���Ĺ������ݲ���¼��worker����w
	ifstream infile("d:\\student.dat");
	int i = 0;
	while (!infile.eof()&& i<WorkerNum)		//����Ҫ���һ�����вŻ����������Ҫ����&& i<WorkerNum��������Խ��
	{
		infile >> w[i].Id>> w[i].name >> w[i].bs >> w[i].os >> w[i].bonus >> w[i].lose;
		i++;
	}
	Sum(w);//����ʵ������
	cout <<"ְ�����" << setw(18) << "����" << setw(18) << "��������"
		<< setw(18) << "�Ӱ๤��" << setw(18) << "����" << setw(18) << "�۳�" << setw(18) << "ʵ������" <<endl;

	for (i = 0; i<WorkerNum; i++) {
		//����������ʽ���������
		cout <<setiosflags(ios::left) << setw(22) <<w[i].Id << setw(14) << w[i].name << setw(18) << w[i].bs << setw(22) << w[i].os << setw(18) << w[i].bonus << setw(14) << w[i].lose<< w[i].sum;
		cout << endl;
	}
	infile.close();
}

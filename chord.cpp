// i am SB.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
  
#include "pch.h"
#include <iostream>
#include"define.h"
#include<regex>
using namespace std;
int main()
{
	//定时器
	time_t start, stop;
	start = time(NULL);
	int n;
	ChordRing * a = NULL;
	bool flag1 = false; //确认已创建公共结点，防异常
	bool flag2 = true;  //循环条件，用来调出循环
	cout << "1、创建公共结点（环）\n2、创建节点\n3、添加子节点\n4、更新子节点信息\n5、查找关键字\n6、结点离开\n7、验证look的时间复杂度为O（logn）\n8、注销环\n9、退出\n";

	{
		while (flag2)
		{
			string q;
			cin >> q;
			regex reg("^[0-9]*$");
			bool bValid = regex_match(q, reg);
			while (!bValid)
			{
				cout << "输入错误，请重新输入" << endl;
				cin >> q;
				regex reg("^[0-9]*$");
				bValid = regex_match(q, reg);
			}
			n = stoi(q, 0, 10);
			/*while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "请输入有效数字"<<endl;
				cin >> n;
			}
			*/
			if (n == 1)
			{
				if (a == NULL)
				{
					a = new ChordRing;
					cout << "创建成功,";
					flag1 = true;
					cout << "请进行下一操作" << endl;
				}
				else
				{
					cout << "环已建立，请勿重复建立" << endl;
				}
			}
			switch (n)
			{
			case(1):
			{
				break;
			}
			case(2):
				if (flag1)
				{
					cout << "请输入您想添加的结点名称（ip）" <<"    ";
					string ip;
					cin >> ip;
					a->Join(ip);
					cout << "添加成功，请进行下一操作" << endl;
					break;
				}
				else
				{
					cout << "请先创建公共结点(环)" << endl;
					break;
				}

			case(3):
				if (flag1)
				{
					cout << "请输入您想插入的关键字以及其值（key和value）" << "  ";
					string key, value;
					cin >> key >> value;
					a->Insert(key, value);
					cout << "添加成功，请进行下一操作" << endl;
					break;
				}
				else
				{
					cout << "请先创建公共结点(环)" << endl;
					break;
				}

			case(4):
				if (flag1)
				{
					cout << "请输入您想更新的结点的关键字以及其值（key和NEW_value）" << "     ";
					string key, value;
					cin >> key >> value;
					a->Update(key, value);
					cout << "请进行下一操作" << endl;
					break;
				}
				else
				{
					cout << "请先创建公共结点(环)" << endl;
					break;
				}
			case(5):
				if (flag1)
				{
					cout << "请输入您想查找的子节点关键字（key）" << "        ";
					string key;
					cin >> key;
					a->lookup(key);
					cout << "请进行下一操作" << endl;
					break;
				}
				else
				{
					cout << "请先创建公共结点(环)" << endl;
					break;
				}
			case(6):
				if (flag1)
				{
					cout << "请输入离开子节点的ip" << "       ";
					string ip;
					cin >> ip;
					a->leave(ip);
					cout << "请进行下一操作" << endl;
					break;
				}
				else
				{
					cout << "请先创建公共结点(环)" << endl;
					break;
				}

			case(7):
				if (flag1)
				{
					cout << "请输查找的节点的ip" << "     ";
					string ip;
					cin >> ip;
					a->debuglook(ip);
					cout << "请进行下一操作" << endl;
					break;
				}
				else
				{
					cout << "请先创建公共结点(环)" << endl;
					break;
				}
			case(8):
				if (flag1 == true)
				{
					a->deleteRing();
					delete a;
					a = NULL;
					flag1 = false;
					cout << "该环已注销," ;
					cout << "请进行下一操作" << endl;
					break;
				}
				else
				{
					cout << "未生成环，请先生成环后再注销" << endl;
					break;
				}
			case(9):
				flag2 = false;
				cout << "正在退出" << endl;
				break;
			case(1024):
			{
				if (flag1 == true)
				{
					char**c, **d;
					c = new char *[13374];
					d = new char *[13374];
					int n = 0;
					while (n < 13374)
					{
						c[n] = new char[90];
						d[n] = new char[90];
						n++;
					}
					getArray(c, d);
					a->Join("192.1.1.1");
					a->Join("192.1.2.1");
					a->Join("192.1.3.1");
					a->Join("192.1.4.1");
					a->Join("192.1.5.1");
					a->Join("192.1.6.1");
					a->Join("192.1.7.1");
					a->Join("192.1.8.1");
					a->Join("192.2.1.1");
					a->Join("192.2.2.1");
					a->Join("192.2.3.1");
					a->Join("192.2.4.1");
					a->CoutAllNode();
					for (int i = 0; i < 300; i++)
					{
						a->Insert(c[i],d[i]);
					}
					a->displayAllketNode();
					a->Insert("2017218081", "yanglin");
					a->Insert("2017218070", "wangrui");
					a->Insert("2017218094", "lisongjian");
					a->Insert("2017218060", "houtianrui");
					//a->debuglook("2017218081");
					//a->debuglook("2017218070");
					//a->debuglook("2017218094");
					//a->debuglook("2017218060");
					cout << "所有操作已完成" << endl;
					break;
				}
				else
				{
					cout << "请先创建公共结点(环)" << endl;
					break;
				}
			}
			default:
				cout << "请输入正确的数字" << endl;
				break;
			}
		}
	}


	/*
	string result
int get_cid(result)//将输入命令的第一个命令分别转化成int型以便在开关语句中使用
{
if(result=="create ring")
return 1;
else if(result=="addnode")
return 2;
else if(result=="addkey")
return 3;
else if(result=="updatekey")
return 4;
else if(result=="findkey")
return 5;
else if(result=="removenode")
return 6;
else if(result=="debuglook")
return 7;
else if(result=="delete")
return 8;
else if(result=="change")
return 8;
else if(result=="exit")
return 9;
else if(result=="auto")
return 1024;
return -1;
}
	
	a->Update("a", "b");
	//a->leave("192.1.1.1");
	//a->leave("192.1.4.1");
	//a->leave("192.1.5.1");
	//a->displayAllketNode();
	//a->displayAllTable("192.1.1.1");
	//a->CoutAllNode();
	//a->displayAllList("192.1.3.1");
	//a->leave("192.1.1.1");
	//a->CoutAllNode();
	//a.join(string ip);
	//  b.join();
	//  a.leave(string);a往b强制T出
	//  b.leave();b向a发出请求
	//  a.insert();
	//  a.updata();
	//  c
	*/
	stop = time(NULL);
	cout << stop - start;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

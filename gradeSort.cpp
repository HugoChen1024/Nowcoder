//用一维数组存储学号和成绩，然后，按成绩排序输出。
//输入描述 :
//
//输入第一行包括一个整数N(1 <= N <= 100)，代表学生的个数。
//接下来的N行每行包括两个整数p和q，分别代表每个学生的学号和成绩。
//
//
//输出描述 :
//
//按照学生的成绩从小到大进行排序，并将排序后的学生信息打印出来。
//如果学生的成绩相同，则按照学号的大小进行从小到大排序。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
	int id;
	int grade;
}student;

bool cmp(student &a,student &b)
{
	if (a.grade<b.grade)  //按成绩升序
	{
		return true;
	}
	else if (a.grade == b.grade)  
	{
		if (a.id < b.id)   //当成绩相等时，按照学号升序
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
int main(){
	int N;
	while (cin >> N)  //这样可以多次输入测试
	{
		student stu;
		vector<student> stuList;
		for (int i = 0; i < N; i++)
		{
			cin >> stu.id;
			cin >> stu.grade;
			stuList.push_back(stu);
		}
		sort(stuList.begin(),stuList.end(),cmp);  //默认按照升序排列，重写cmp函数
		for (int i = 0; i < N; i++){
			cout << stuList[i].id << " " << stuList[i].grade << endl;
		}		
	}
	return 0;
}
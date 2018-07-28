
```C++
/*!
 * \file main.cpp
 * \date 2018/07/28 15:52
 *
 * \author ranjiewen
 * Contact: ranjiewen@foxmail.com
 *
 * \brief
 *
 * TODO: long description
 *
 * \note
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

#define ERROR_INPUT                -10
#define ERROR_INVALID_NUM_FORMAT   ERROR_INPUT-1   //含有不合法的字母，无法转为数字
#define ERROR_OUT_RANGE            ERROR_INPUT-2   //转换数字超出方位，如:负数等
#define ERROR_INCORRENT_COMMAND    ERROR_INPUT-3   //输入命令格式错误，如:多余空格等
#define ERROR_MAZE_UNCONNECTED     ERROR_INPUT-4   //不符合网络联通定义
#define ERROR_OTHER                ERROR_INPUT-5

//C++文件输入,方便输入调试;不用文件输入，控制台手动输入也可
#define cin infile 
ifstream infile("ini.txt", ifstream::in);

typedef struct Pair_
{
	int x1, y1;
	int x2, y2;

}Connected_Cell;

const string W = "[W]";
const string R = "[R]";

//函数功能：在渲染网格中，添加道路网格
//函数参数说明：render_gird为渲染网络矩阵;row,col分别为道路网格的行和列
//函数返回值：正常返回0
int init_render_gird(vector<vector<string>>& render_gird, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			render_gird[(i + 1) * 2 - 1][(j + 1) * 2 - 1] = R;
		}
	}
	return 0;
}

//函数功能：在渲染网格中，将定义好的连通位置，渲染为字符串
//函数参数说明：render_gird为渲染网络矩阵;con_pairs一系列合法的连通cell坐标
//函数返回值：正常返回0
int modify_render_grid(vector<vector<string>> &render_grid, vector<Connected_Cell> con_pairs)
{
	for (int i = 0; i < con_pairs.size(); i++)
	{
		int x1 = con_pairs[i].x1;
		int y1 = con_pairs[i].y1;
		int x2 = con_pairs[i].x2;
		int y2 = con_pairs[i].y2;
		if (x1 == x2)
		{
			render_grid[(x1 + 1) * 2 - 1][(y1 + 1) * 2] = R;
		}
		if (y1 == y2)
		{
			render_grid[(x1 + 1) * 2][(y1 + 1) * 2 - 1] = R;
		}
	}
	return 0;
}

//函数功能：打印渲染网格中的字符串
//函数参数说明：render_gird为渲染网络矩阵
//函数返回值：正常返回0
int output_render_grid(vector<vector<string>> render_grid)
{
	for (int i = 0; i < render_grid.size(); i++)
	{
		for (int j = 0; j < render_grid[0].size(); j++)
		{
			cout << render_grid[i][j];
			if (j != render_grid.size() - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

//函数功能：解析命令行第一行的字符串
//函数参数说明：grid_size_str输入字符串；row,col解析输出的道路网格的行和列
//函数返回值：正常返回0；异常返回对应的异常负值
int parse_command_one(string grid_size_str, int &row, int &col)
{
	string str_row, str_col;

	int pos = 0;
	bool flag = true;
	for (int i = 0; i < grid_size_str.size(); i++)
	{
		if ((grid_size_str[i] <= '9'&&grid_size_str[i] >= '0') || grid_size_str[i] == '-' || grid_size_str[i] == '+' || grid_size_str[i] == ' '&&flag)
		{
			if (grid_size_str[i] == ' ') //多个空格
			{
				pos = i;
				flag = false;
			}
			continue;
		}
		else if (!flag)
		{
			cout << "Incorrent command format." << endl;
			return ERROR_INCORRENT_COMMAND;
		}
		else //包含其他无效字符，无法进行数字转换
		{
			cout << "Invalid number format." << endl;
			return ERROR_INVALID_NUM_FORMAT;
		}
	}
	if (pos != 0 || pos != grid_size_str.size())
	{
		str_row = grid_size_str.substr(0, pos);
		str_col = grid_size_str.substr(pos);
	}

	row = atoi(str_row.c_str());
	col = atoi(str_col.c_str());

	if (row<=0||col<=0)
	{
		cout << "Number out of range." << endl;
		return ERROR_OUT_RANGE;
	}
	return 0;
}

//函数功能：将输入字符串s,以字符串c(;)进行拆分,拆分结果放在v中
//函数参数说明：s为输入字符串；c为拆分的字符串；v为拆分结果
//函数返回值：正常返回0
int split_string(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
	return 0;
}

//函数功能：判断定义的一组连通坐标是否合法
//函数参数说明：输入cells为两个连通点；row，col分别为道路网格的行列
//函数返回值：正常返回0；异常返回对应的负值
int isValid(Connected_Cell cells,int row,int col)
{
	if (cells.x1<0||cells.x1>=row||cells.y1<0||cells.y1>=col||cells.x2<0||cells.x2>=row||cells.y2<0||cells.y2>=col) //超出边界
	{
		cout << "Number out of range." << endl;
		return ERROR_OUT_RANGE;
	}
	if ((cells.x1==cells.x2&&abs(cells.y1-cells.y2)==1)||(cells.y1==cells.y2&&abs(cells.x1-cells.x2)==1)) //相邻点，符合连通定义
	{
		return 0;
	}
	else
	{
		cout << "Maze format error." << endl;
		return ERROR_MAZE_UNCONNECTED;
	}
	return 0;
}

//函数功能：解析命令行第二行的字符串
//函数参数说明：src输入字符串；con_pairs为从输入字符串中解析出的一系列连通坐标;row,col解析输出的道路网格的行和列
//函数返回值：正常返回0；异常返回对应的异常负值
int parse_command_two(string src, vector<Connected_Cell>& con_pairs,int row,int col)
{
	vector<string> pair_connect;
	split_string(src, pair_connect, ";");

	for (int i = 0; i < pair_connect.size(); i++)
	{
		Connected_Cell con_cell;
		vector<string> cells;
		split_string(pair_connect[i], cells, " ");
		if (cells.size() != 2)
		{
			cout << "Incorrent command format." << endl;
			return ERROR_INCORRENT_COMMAND;
		}
		else
		{
			vector<string> cell;
			split_string(cells[0], cell, ",");
			con_cell.x1 = atoi(cell[0].c_str());
			con_cell.y1 = atoi(cell[1].c_str());

			vector<string> cell_;
			split_string(cells[1], cell_, ",");
			con_cell.x2 = atoi(cell_[0].c_str());
			con_cell.y2 = atoi(cell_[1].c_str());
		}
		int ret_valid = isValid(con_cell,row,col);
		if (ret_valid<0)
		{
			return ret_valid;
		}
		con_pairs.push_back(con_cell);
	}
	return 0;
}

// 解题思路：
// 1.首先从字符串中解析出有效的道路网格行和列；以及有效道路网格连通性定义的坐标
// 2.然后进行将迷宫渲染为字符串

// 优化方向：
// 1.本题完成使用C,然后使用了一些C++的库函数
int main()
{
	//解析输入第一行字符串
	string grid_size_str;
	getline(cin, grid_size_str);
	int row, col;
	int ret_one = parse_command_one(grid_size_str, row, col);
	if (ret_one<0)
	{
		return ret_one;
	}

	//解析输入第二行字符串
	string conneted_define;
	getline(cin, conneted_define);
	vector<Connected_Cell> con_pairs;
	int ret_two = parse_command_two(conneted_define, con_pairs,row,col);
	if (ret_two<0)
	{
		return ret_two;
	}

	//渲染字符串
	vector<vector<string>> render_grid(row * 2 + 1, vector<string>(col * 2 + 1, W));
	init_render_gird(render_grid, row, col);
	//output_render_grid(render_grid);
	//cout << "--------------------------------" << endl;
	modify_render_grid(render_grid, con_pairs);
	output_render_grid(render_grid);

	system("pause");
	return 0;
}
```

#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>

//			遍历容器
/*
for_each
transform
*/
// 1、for_each(iterator begin,iterator end,func)	遍历容器
// 
// ①.使用普通函数
void print1(int val)
{
	cout << val << " ";
}

// ②.使用仿函数
class print2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), print1);  // 传入普通函数
	cout << endl;
	for_each(v1.begin(), v1.end(), print2());// 传入匿名的函数对象
}

// 2、transform(iterator begin1,iterator end1,iterator begin2,func)	搬运容器到另一个容器中

// ①.使用普通函数
int trans(int val)
{
	return val;
}
// ②.使用仿函数
class trans2
{
public:
	int operator()(int val)
	{
		return val;
	}
};
void test02()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int >v2;	// 目标容器
	v2.resize(v1.size()); // 提前开辟空间
	transform(v1.begin(), v1.end(), v2.begin(), trans);  // 1
	transform(v1.begin(), v1.end(), v2.begin(), trans2()); // 2
	for_each(v2.begin(), v2.end(), print1);  // 传入普通函数
}

/* 查找算法
find			查找目标元素
find_if			按条件查找目标元素
adjacent_find	查找相邻重复元素
binary_search	二分查找法
count			统计元素个数
count_if		按条件统计元素个数
*/

// 1、find(iterator begin.iterator end,val)	查找val元素
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	// 重载== 使find底层知道如何对比自定义数据类型
	bool operator == (const person &p)
	{
		if (p.m_name == this->m_name && p.m_age == this->m_age)
			return true;
		else
			return false;
	}
	string m_name;
	int m_age;
};
void test03()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// ①查找内置数据类型
	vector<int>::iterator it = find(v1.begin(), v1.end(), 1);
	if (it == v1.end())
		cout << "没有" << endl;
	else
		cout << "有了：" << *it << endl;
}
//  ②自定义数据类型
void test04()
{
	vector<person> v;
	person p1("Joyce", 21);	person p2("Tatina", 20);
	person p3("Nna", 3);	person p4("knnz", 40);

	v.push_back(p1); v.push_back(p2);
	v.push_back(p3); v.push_back(p4);

	person p5("Nna", 3);
	vector<person>::iterator it = find(v.begin(), v.end(), p5);
	if (it == v.end())
		cout << "没有" << endl;
	else
		cout << "有了：" << it->m_name << it->m_age << endl;
}

// 2、find_if(iterator begin,iterator end,_Pred);
// 内置数据类型
class GreaterSix // 内置数据类型 val大于6即可
{
public:
	bool operator()(int val)
	{
		return val > 6;
	}
};
void test05()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterSix());
	cout << *it << endl;
}

// 自定义数据类型
class person1
{
public:
	person1(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
class AgeGreateTwenty // 年龄大于33即可
{
public:
	bool operator()(person1& p)
	{
		return p.m_age > 33;
	}
};
void test05_2()
{
	vector<person1>v;
	person1 p1("Joyce", 21);person1 p2("Tatina", 20);
	person1 p3("Nna", 3);	person1 p4("knnz", 40);

	v.push_back(p1); v.push_back(p2);
	v.push_back(p3); v.push_back(p4);
	vector<person1>::iterator it = find_if(v.begin(), v.end(), AgeGreateTwenty());
	if (it == v.end())
		cout << "没有" << endl;
	else
		cout << it->m_name <<it->m_age<< endl;
}

//	3、adjacent_find(iterator begin,iterator end);
void test06()
{
	vector<int> v;
	v.push_back(1);	v.push_back(3);	v.push_back(1);
	v.push_back(33);	v.push_back(53);	v.push_back(23);
	v.push_back(3);	v.push_back(3);	v.push_back(8);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
		cout << "没有" << endl;
	else
		cout << *it;
}

// 4、binary_search(iterator begin,iterator end,val);
void test07()
{
	vector<int> v;
	int i = 0;
	while (i++ < 10)
	{
		v.push_back(i);
	}

	bool it = binary_search(v.begin(), v.end(), 5);
	if (it)
		cout << "有了" << endl;
	else
		cout << "没有" << endl;
}

// 5、count(iterator begin,iterator end,val);

// 5.1、统计内置数据类型
void test08()
{
	vector<int> v;
	v.push_back(1);	v.push_back(3);	v.push_back(1);
	v.push_back(33);	v.push_back(53);	v.push_back(23);
	v.push_back(3);	v.push_back(3);	v.push_back(8);

	int ret = count(v.begin(), v.end(), 3);
	cout << ret << endl;
}
// 5.2、统计自定义数据类型
void test08_2()
{
	vector<person> v;
	person p1("Joyce", 21); person p2("Tatina", 20);
	person p3("Nna", 3);	person p4("knnz", 40);
	person p6("Nna", 3);
	v.push_back(p1); v.push_back(p2);
	v.push_back(p3); v.push_back(p4); v.push_back(p6);
	person p5("Nna", 3);
	int ret = count(v.begin(), v.end(), p5);
	cout <<"与p5同名同姓的人员个数为："<< ret << endl;
}

// 6、count_if(iterator begin,iterator end,_Pred);
// 6.1、内置数据类型
class GreaterFive // 大于5的谓词
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test09_1()
{
	vector<int> v;
	v.push_back(1);	v.push_back(3);	v.push_back(1);
	v.push_back(33);v.push_back(53);	v.push_back(23);
	v.push_back(3);	v.push_back(3);	v.push_back(8);

	int ret = count_if(v.begin(), v.end(), GreaterFive());
	cout << "大于5的数字有 " << ret << " 个" << endl;
}

// 6.2、自定义数据类型
class Greater20 // 年龄大于20
{
public:
	bool operator()(const person& p)
	{
		if (p.m_age > 20)
			return true;
		else
			return false;
	}
};
void test09_2()
{
	vector<person> v;
	person p1("Joyce", 21); person p2("Tatina", 20);
	person p3("Nna", 3);	person p4("knnz", 40);
	person p5("Bbyeaz", 33);
	v.push_back(p1); v.push_back(p2);
	v.push_back(p3); v.push_back(p4); v.push_back(p5);

	int ret = count_if(v.begin(), v.end(),Greater20());
	cout << "大于20岁的人员个数为：" << ret << endl;
}

/*	常用排序算法
sort			对容器内元素进行排序
random_shuffle	洗牌，对指定范围内元素随即调整次序
merge			容器元素合并，并存储至另一容器中
reverse			反转指定范围内元素
*/

// 1、sort(iterator begin,iterator end,_Pred);

void test10()
{
	vector<int> v;
	v.push_back(1);	v.push_back(3);	v.push_back(2);
	v.push_back(33); v.push_back(53);	v.push_back(23);
	v.push_back(5);	v.push_back(4);	v.push_back(8);
	
	// 升序-默认
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print2());
	cout << endl;
	// 降序-重载
	sort(v.begin(), v.end(), greater<int>()); // greater 内建函数对象
	for_each(v.begin(), v.end(), print2());
}
#include<ctime>
// 2、random_shuffle(iterator begin,iterator end);
void test11()
{
	srand((unsigned)time(NULL)); // 随机数种子
	vector<int> v;
	int i = 0;
	while (i++ < 10)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print2());
	cout << endl;
	random_shuffle(v.begin(), v.end()); // 洗牌
	for_each(v.begin(), v.end(), print2());
}

//	3、merge(iterator begin1,iterator end1,iterator begin2,iterator end2,iterator dest);
void test12()
{
	vector<int> v;
	vector<int> v2;
	int i = 0;
	while (i++ < 5)
	{
		v.push_back(i);
		v2.push_back(i+6);
	}

	vector<int>v3;
	v3.resize(v.size() + v2.size()); // 给目标容器开辟空间
	merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), print2());
}

// 4、reverse(iterator begin,iterator end);
void test13()
{
	vector<int> v;
	int i = 0;
	while (i++ < 10)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print2());
	cout << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), print2());
}

/*常用拷贝和替换算法
copy        容器内指定范围内的元素拷贝到另一容器中
replace     将容器中指定范围内的元素替换为新的元素
replace_if  容器内指定范围内满足条件的元素替换为新的元素
swap        交换2个相同类型容器的元素
*/

// 1、copy(iterator begin1,iterator end1,iterator dest);
void test14()
{
	vector<int> v;
	int i = 0;
	while (i++ < 10)
	{
		v.push_back(i);
	}
	vector<int> v2;
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());
	for_each(v2.begin(), v2.end(), print2());
}

// 2、replace(iterator begin1,iterator end1,oldval,newval);
void test15()
{
	vector<int> v;
	v.push_back(1);	v.push_back(3);	v.push_back(2);
	v.push_back(3); v.push_back(53);	v.push_back(23);
	v.push_back(3);	v.push_back(4);	v.push_back(8);
	for_each(v.begin(), v.end(), print2());
	cout << endl;
	replace(v.begin(), v.end(), 3, 888);
	for_each(v.begin(), v.end(), print2());
}

// 3、replace_if(iterator begin,iterator end,_Pred,newval);
void test16()
{
	vector<int> v;
	v.push_back(1);	v.push_back(3);	v.push_back(2);
	v.push_back(3); v.push_back(53);	v.push_back(23);
	v.push_back(3);	v.push_back(4);	v.push_back(8);
	for_each(v.begin(), v.end(), print2());
	cout << endl;
	replace_if(v.begin(), v.end(), GreaterSix(), 888);
	for_each(v.begin(), v.end(), print2());
}

// swap(container c1,container c2);
void test17()
{
	vector<int> v;
	vector<int> v2;		int i = 0;
	while (i++ < 10)
	{
		v.push_back(i);
		v2.push_back(i+16);
	}
	cout << "交换前：" << endl;
	for_each(v.begin(), v.end(), print2()); cout << endl;
	for_each(v2.begin(), v2.end(), print2());
	cout << endl;	 cout << "交换后：" << endl;
	swap(v, v2);
	for_each(v.begin(), v.end(), print2()); cout << endl;
	for_each(v2.begin(), v2.end(), print2());
}

/*常用算术生成算法
accumulate    计算容器元素累计总和
fill          向容器中添加元素
*/
#include<numeric>

// 1、accumulate(iterator begin,iterator end,val);
void test18()
{
	vector<int> v;
	int i = 0;
	while (i++ < 100)
	{
		v.push_back(i);
	}
	int num = accumulate(v.begin(), v.end(),0);
	//	0是起始值，即num=总和+0；如果是1000，即num=总和+1000
	cout << num;
}

// 2、fill(iterator begin,iterator end,val);
void test19()
{
	vector<int> v;
	int i = 0;
	while (i++ < 10)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print1);	cout << endl;
	fill(v.begin() + 1, v.end() - 1, 888);
	for_each(v.begin(), v.end(), print1);
}

/*常用集合算法
set_intersection  求两个容器的交集
set_union         求两个容器的并集
set_difference    求两个容器的差集
*/
//	1、set_intersection(iterator begin1,iterator end1,iterator begin2,iterator end2,iterator dest);
void test20()
{
	vector<int> v;
	vector<int> v2;
	int i = 0;
	while (i++ < 8)
	{
		v.push_back(i);		// 1-8
		v2.push_back(i + 3);// 4-11
	}
	for_each(v.begin(), v.end(), print2()); cout << endl; for_each(v2.begin(), v2.end(), print2());
	vector<int>v3;
	v3.resize(min(v.size(), v2.size())); // 给目标容器开辟空间
	vector<int>::iterator itEnd = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	// 返回容器里最后一个数据的迭代器
	cout << endl;
	for_each(v3.begin(), itEnd, print2());
}

// 2、set_union(iterator begin1,iterator end1,iterator begin2,iterator end2,iterator dest);
void test21()
{
	vector<int> v;
	vector<int> v2;
	int i = 0;
	while (i++ < 8)
	{
		v.push_back(i);		// 1-8
		v2.push_back(i + 3);// 4-11
	}
	for_each(v.begin(), v.end(), print2()); cout << endl; for_each(v2.begin(), v2.end(), print2());
	vector<int>v3;
	v3.resize(v.size() + v2.size()); // 给目标容器开辟空间
	vector<int>::iterator itEnd = set_union(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	// 返回容器里最后一个数据的迭代器
	cout << endl;
	for_each(v3.begin(), itEnd, print2());
}

// 3、set_difference(iterator begin1,iterator end1,iterator begin2,iterator end2,iterator dest);
void test22()
{
	vector<int> v;
	vector<int> v2;
	int i = 0;
	while (i++ < 8)
	{
		v.push_back(i);		// 1-8
		v2.push_back(i + 3);// 4-11
	}
	for_each(v.begin(), v.end(), print2()); cout << endl; for_each(v2.begin(), v2.end(), print2());
	vector<int>v3;
	v3.resize(max(v.size(), v2.size())); // 给目标容器开辟空间
	cout << endl;
	vector<int>::iterator itEnd = set_difference(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	// 返回容器里最后一个数据的迭代器
	cout << "v1和v2的差集："<<endl;
	for_each(v3.begin(), itEnd, print2());	cout << endl;
	cout << "v2和v1的差集：" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v.begin(), v.end(), v3.begin());
	for_each(v3.begin(), itEnd, print2());	cout << endl;
}
int main()
{
	test22();
	return 0;
}

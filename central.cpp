#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>

//			��������
/*
for_each
transform
*/
// 1��for_each(iterator begin,iterator end,func)	��������
// 
// ��.ʹ����ͨ����
void print1(int val)
{
	cout << val << " ";
}

// ��.ʹ�÷º���
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
	for_each(v1.begin(), v1.end(), print1);  // ������ͨ����
	cout << endl;
	for_each(v1.begin(), v1.end(), print2());// ���������ĺ�������
}

// 2��transform(iterator begin1,iterator end1,iterator begin2,func)	������������һ��������

// ��.ʹ����ͨ����
int trans(int val)
{
	return val;
}
// ��.ʹ�÷º���
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
	vector<int >v2;	// Ŀ������
	v2.resize(v1.size()); // ��ǰ���ٿռ�
	transform(v1.begin(), v1.end(), v2.begin(), trans);  // 1
	transform(v1.begin(), v1.end(), v2.begin(), trans2()); // 2
	for_each(v2.begin(), v2.end(), print1);  // ������ͨ����
}

/* �����㷨
find			����Ŀ��Ԫ��
find_if			����������Ŀ��Ԫ��
adjacent_find	���������ظ�Ԫ��
binary_search	���ֲ��ҷ�
count			ͳ��Ԫ�ظ���
count_if		������ͳ��Ԫ�ظ���
*/

// 1��find(iterator begin.iterator end,val)	����valԪ��
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	// ����== ʹfind�ײ�֪����ζԱ��Զ�����������
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
	// �ٲ���������������
	vector<int>::iterator it = find(v1.begin(), v1.end(), 1);
	if (it == v1.end())
		cout << "û��" << endl;
	else
		cout << "���ˣ�" << *it << endl;
}
//  ���Զ�����������
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
		cout << "û��" << endl;
	else
		cout << "���ˣ�" << it->m_name << it->m_age << endl;
}

// 2��find_if(iterator begin,iterator end,_Pred);
// ������������
class GreaterSix // ������������ val����6����
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

// �Զ�����������
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
class AgeGreateTwenty // �������33����
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
		cout << "û��" << endl;
	else
		cout << it->m_name <<it->m_age<< endl;
}

//	3��adjacent_find(iterator begin,iterator end);
void test06()
{
	vector<int> v;
	v.push_back(1);	v.push_back(3);	v.push_back(1);
	v.push_back(33);	v.push_back(53);	v.push_back(23);
	v.push_back(3);	v.push_back(3);	v.push_back(8);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
		cout << "û��" << endl;
	else
		cout << *it;
}

// 4��binary_search(iterator begin,iterator end,val);
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
		cout << "����" << endl;
	else
		cout << "û��" << endl;
}

// 5��count(iterator begin,iterator end,val);

// 5.1��ͳ��������������
void test08()
{
	vector<int> v;
	v.push_back(1);	v.push_back(3);	v.push_back(1);
	v.push_back(33);	v.push_back(53);	v.push_back(23);
	v.push_back(3);	v.push_back(3);	v.push_back(8);

	int ret = count(v.begin(), v.end(), 3);
	cout << ret << endl;
}
// 5.2��ͳ���Զ�����������
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
	cout <<"��p5ͬ��ͬ�յ���Ա����Ϊ��"<< ret << endl;
}

// 6��count_if(iterator begin,iterator end,_Pred);
// 6.1��������������
class GreaterFive // ����5��ν��
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
	cout << "����5�������� " << ret << " ��" << endl;
}

// 6.2���Զ�����������
class Greater20 // �������20
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
	cout << "����20�����Ա����Ϊ��" << ret << endl;
}

/*	���������㷨
sort			��������Ԫ�ؽ�������
random_shuffle	ϴ�ƣ���ָ����Χ��Ԫ���漴��������
merge			����Ԫ�غϲ������洢����һ������
reverse			��תָ����Χ��Ԫ��
*/

// 1��sort(iterator begin,iterator end,_Pred);

void test10()
{
	vector<int> v;
	v.push_back(1);	v.push_back(3);	v.push_back(2);
	v.push_back(33); v.push_back(53);	v.push_back(23);
	v.push_back(5);	v.push_back(4);	v.push_back(8);
	
	// ����-Ĭ��
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print2());
	cout << endl;
	// ����-����
	sort(v.begin(), v.end(), greater<int>()); // greater �ڽ���������
	for_each(v.begin(), v.end(), print2());
}
#include<ctime>
// 2��random_shuffle(iterator begin,iterator end);
void test11()
{
	srand((unsigned)time(NULL)); // ���������
	vector<int> v;
	int i = 0;
	while (i++ < 10)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print2());
	cout << endl;
	random_shuffle(v.begin(), v.end()); // ϴ��
	for_each(v.begin(), v.end(), print2());
}

//	3��merge(iterator begin1,iterator end1,iterator begin2,iterator end2,iterator dest);
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
	v3.resize(v.size() + v2.size()); // ��Ŀ���������ٿռ�
	merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), print2());
}

// 4��reverse(iterator begin,iterator end);
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

/*���ÿ������滻�㷨
copy        ������ָ����Χ�ڵ�Ԫ�ؿ�������һ������
replace     ��������ָ����Χ�ڵ�Ԫ���滻Ϊ�µ�Ԫ��
replace_if  ������ָ����Χ������������Ԫ���滻Ϊ�µ�Ԫ��
swap        ����2����ͬ����������Ԫ��
*/

// 1��copy(iterator begin1,iterator end1,iterator dest);
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

// 2��replace(iterator begin1,iterator end1,oldval,newval);
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

// 3��replace_if(iterator begin,iterator end,_Pred,newval);
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
	cout << "����ǰ��" << endl;
	for_each(v.begin(), v.end(), print2()); cout << endl;
	for_each(v2.begin(), v2.end(), print2());
	cout << endl;	 cout << "������" << endl;
	swap(v, v2);
	for_each(v.begin(), v.end(), print2()); cout << endl;
	for_each(v2.begin(), v2.end(), print2());
}

/*�������������㷨
accumulate    ��������Ԫ���ۼ��ܺ�
fill          �����������Ԫ��
*/
#include<numeric>

// 1��accumulate(iterator begin,iterator end,val);
void test18()
{
	vector<int> v;
	int i = 0;
	while (i++ < 100)
	{
		v.push_back(i);
	}
	int num = accumulate(v.begin(), v.end(),0);
	//	0����ʼֵ����num=�ܺ�+0�������1000����num=�ܺ�+1000
	cout << num;
}

// 2��fill(iterator begin,iterator end,val);
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

/*���ü����㷨
set_intersection  �����������Ľ���
set_union         �����������Ĳ���
set_difference    �����������Ĳ
*/
//	1��set_intersection(iterator begin1,iterator end1,iterator begin2,iterator end2,iterator dest);
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
	v3.resize(min(v.size(), v2.size())); // ��Ŀ���������ٿռ�
	vector<int>::iterator itEnd = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	// �������������һ�����ݵĵ�����
	cout << endl;
	for_each(v3.begin(), itEnd, print2());
}

// 2��set_union(iterator begin1,iterator end1,iterator begin2,iterator end2,iterator dest);
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
	v3.resize(v.size() + v2.size()); // ��Ŀ���������ٿռ�
	vector<int>::iterator itEnd = set_union(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	// �������������һ�����ݵĵ�����
	cout << endl;
	for_each(v3.begin(), itEnd, print2());
}

// 3��set_difference(iterator begin1,iterator end1,iterator begin2,iterator end2,iterator dest);
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
	v3.resize(max(v.size(), v2.size())); // ��Ŀ���������ٿռ�
	cout << endl;
	vector<int>::iterator itEnd = set_difference(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	// �������������һ�����ݵĵ�����
	cout << "v1��v2�Ĳ��"<<endl;
	for_each(v3.begin(), itEnd, print2());	cout << endl;
	cout << "v2��v1�Ĳ��" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v.begin(), v.end(), v3.begin());
	for_each(v3.begin(), itEnd, print2());	cout << endl;
}
int main()
{
	test22();
	return 0;
}

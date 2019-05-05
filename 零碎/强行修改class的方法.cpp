//无聊时间的思考
//经过对于汇编的学习对于内存有了些新的理解 
//尽管private限制了我们对于class数据的修改,但是如果我们绕过访问操作符,而是直接通过地址,便可以修改class中的数据
//当然,class中的数据也不是像我们简单看到的这样的分布,这里涉及编译器对于数据分布的字节对齐,也就是编译器,会填充一些,无用的,内存
//使得所有类型的数据所占据的大小一致,方便cpu的读取,详情见字节对齐.cpp
//所有只有我么对class数据中的类型和顺寻清楚,便可以修改
//下面是一些简单的例子
#include<iostream>
using std::cout;
using std::endl;
class fff 
{
	public:
		fff(int _i=0,double _j=0,int _e=0):i(_i),j(_j),e(_e){}
		void print ()
		{
			cout<<"i="<<i<<"j="<<j<<"e="<<e<<endl;	
		} 
	private:
		int i;
		double j;
		int e;
}; 
class fff1
{
	public:
		fff1 (char _j='a',int _i=0,double _e=0.0):j(_j),i(_i),e(_e){}
		void print ()
		{
			cout<<"j="<<j<<"i="<<i<<"e="<<e<<endl;	
		} 
	private:
		char j;
		int i;		
		double e;
};
class fff2
{
	public:
	fff2 (const char *_s="sd",int _i=0,double _j=10.0):i(_i),j(_j){s[0]=_s[0],s[1]=_s[1],s[2]='\0';}
	void print()
	{
		cout<<"s="<<s<<' '<<"i="<<i<<' '<<"j="<<j<<endl;	
	}
	private:
	char s[3];
	int i;
	double j;	
};
class fff3
{
	public:
	fff3 (char a='a',int _i=0,double _j=0):f1(a,_i,_j),e(a),i(_i),j(_j){}
	void print()
	{
		cout<<"e="<<' '<<e<<endl;
		f1.print();
		cout<<"i="<<' '<<i<<"j="<<j<<endl;	
	} 
	private:
	char e;
	fff1 f1;
	int i;
	double j;	
};
int main ()
{
	cout<<"sizeof(fff)="<<sizeof(fff)<<endl; 
	fff t(10,2,4);
	t.print();
	void* tt=&t;
	*static_cast<int*>(tt)=666;
	tt=static_cast<char*>(tt)+8;
	*static_cast<double*>(tt)=666;
	tt=static_cast<char*>(tt)+8;
	*static_cast<int*>(tt)=666;
	t.print();
	cout<<"sizeof(fff1)="<<sizeof(fff1)<<endl;
	fff1 t1('a',10,888.0);
	t1.print();
	void *tt1=&t1;
	*static_cast<char*>(tt1)='b';
	tt1=static_cast<char*>(tt1)+4;
	*static_cast<int*>(tt1)=777;
	tt1=static_cast<char*>(tt1)+4;
	*static_cast<double*>(tt1)=678.89;
	t1.print();
	cout<<"sizeof(fff2)="<<sizeof(fff2)<<endl;//3+1+4+8=16
	fff2 t2("ds",10,888.0);
	t2.print();
	void *tt2=&t2;
	*static_cast<char*>(tt2)='b';
	tt2=static_cast<char*>(tt2)+1;
	*static_cast<char*>(tt2)='a';
	tt2=static_cast<char*>(tt2)+3;
	*static_cast<int*>(tt2)=678;
	tt2=static_cast<char*>(tt2)+4;
	*static_cast<double*>(tt2)=678.344; 
	t2.print();
	cout<<"sizeof(fff3)="<<sizeof(fff3)<<endl;//1+7+16+4+4+8=40
	fff3 t3('a',100,99.9);
	t3.print();
	void *tt3=&t3;
	*static_cast<char*>(tt3)='n';
	tt3=static_cast<char*>(tt3)+8;
	*static_cast<char*>(tt3)='b';
	tt3=static_cast<char*>(tt3)+4;
	*static_cast<int*>(tt3)=776;
	tt3=static_cast<char*>(tt3)+4;
	*static_cast<double*>(tt3)=776.777;	
	tt3=static_cast<char*>(tt3)+8;
	*static_cast<int*>(tt3)=777;	
	tt3=static_cast<char*>(tt3)+8;
	*static_cast<double*>(tt3)=777.777;	
	t3.print();
	return 0;
} 

#include<bits/stdc++.h>
namespace ql211
{
	
	void print ()//��ֹ���� 
	{
		
	}
	template<typename T,typename... Ts>
	void print(const T& first,const Ts&... args)//�ػ� ,һ����һ�� 
	{
		std::cout<<first<<std::endl;
		print(args...); //ʣ�µ�һ���������ֽ�λ,һ����һ���ݹ���ȥ; 
	}
	template<typename... Ts>
	void print(const Ts&... args)//���� 
	{
		/*...*/
	} 
} 

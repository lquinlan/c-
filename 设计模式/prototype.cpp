/*
    当我们设计一个框架,我们不知道未来,会派生出什么类型的时候,可以采用这个设计模式
    子类传一份自己的原型回去,让后按照原型,构造
*/
#include<iostream>
using namespace std;
enum imagetype
{
    Last,Post
};
class image{
    public :
    virtual void draw ()=0;
    static image* findandclone (imagetype cp)
    {
        for(int i=0;i<_next;i++)
        {
            if(_prototype[i]->return_type()==cp)
            {
                return _prototype[i]->clone();
            }
        }
    }
    virtual ~image()
    {
    
    }
    protected:
    virtual imagetype return_type ()=0;
    virtual image* clone()=0;
    static void addprototype (image* p)//在派生类中返回静态原型 
    {
        _prototype[_next++]=p;

    }
    private:
    static image* _prototype[10];//保存静态原型 
    static int _next;
};
//定义 
image* image::_prototype[];
int image::_next=0;
class image1:public image{
    public :
    virtual imagetype return_type ()
    {
        return Last;
    }
    ~image1 ()
    {
    	//cout<<"1"<<endl;
    }
    virtual void draw ()
    {
        cout<<"this is image1 draw"<<endl;
    }
    image* clone ()
    {
        return new image1(1);
    }
    protected:
    	//只是为了与另一个构造函数进行区分,私有,保护都可以,同样,这里的参数并没有什么意义; 
    image1 (int num)
    {
        id=count++;
    }
    private:
    	//因为只允许基类通过原型进行构造,所有,设计成私有静态的,同样构造函数设置为私有,内部可以调用,保证一定有一个可以传回去 
    static image1 Image1;
    image1 ()
    {
        addprototype(this);//上传原型.且只有这一份原型 
    }
    int id;
    static int count;
};
image1 image1::Image1;
int image1::count=1;
class image2:public image{
    public :
    virtual imagetype return_type ()
    {
        return Post;
    }
    ~image2()
    {
    	//cout<<"2"<<endl;
    }
    virtual void draw ()
    {
        cout<<"this is image2 draw"<<endl;
    }
    image* clone ()
    {
        return new image2(1);
    }
    protected:
    image2 (int num)
    {
        id=count++;
    }
    private:
    static image2 Image2;
    image2 ()
    {
        addprototype(this);
    }
    int id;
    static int count;
};
image2 image2::Image2;
int image2::count=1;
const int maxn=8;
imagetype input[maxn]={Last,Last,Last,Post,Post,Post,Last,Post};
int main ()
{
	image *images[maxn];
	for(int i=0;i<maxn;i++)
	{
		images[i]=image::findandclone(input[i]);
	}
	for(int i=0;i<maxn;i++)
	{
		images[i]->draw();
	}
	for(int i=0;i<maxn;i++)
	{
		delete images[i];
	}
	return 0; 
}

/*
    ���������һ�����,���ǲ�֪��δ��,��������ʲô���͵�ʱ��,���Բ���������ģʽ
    ���ഫһ���Լ���ԭ�ͻ�ȥ,�ú���ԭ��,����
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
    static void addprototype (image* p)//���������з��ؾ�̬ԭ�� 
    {
        _prototype[_next++]=p;

    }
    private:
    static image* _prototype[10];//���澲̬ԭ�� 
    static int _next;
};
//���� 
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
    	//ֻ��Ϊ������һ�����캯����������,˽��,����������,ͬ��,����Ĳ�����û��ʲô����; 
    image1 (int num)
    {
        id=count++;
    }
    private:
    	//��Ϊֻ�������ͨ��ԭ�ͽ��й���,����,��Ƴ�˽�о�̬��,ͬ�����캯������Ϊ˽��,�ڲ����Ե���,��֤һ����һ�����Դ���ȥ 
    static image1 Image1;
    image1 ()
    {
        addprototype(this);//�ϴ�ԭ��.��ֻ����һ��ԭ�� 
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

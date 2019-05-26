//如果自己写一个allocator所需接口
/*
    一组typedef
    allocator::value_type
    allocator::pointer
    allocator::const_pointer
    allocator::reference
    allocator::const_reference
    allocator::size_type
    allocator::difference_type

    allcoator::rebind allocator的内嵌模板,需要定义,other成员
    allocator::allocator()构造函数
    allocator::allocator(const allocator&)拷贝构造
    template<class T>
    allocator::allocator(const allocator<T>&)泛化的拷贝构造函数
    allocator::~allocator()析构函数
    pointer allocator ::affress (reference x)返回对象地址
    pointer allocator::allocate(size_type n,const void*=0)
    分配n个对象,对象的类型为T
    void allocator::deallocator(pointer p,size_type n)
    释放空间
    size_type allocator::max_szie()const 可以分配的最大空间
    void allocator::construct(pointer p,const T& x);
    new(p) T(x),placement new;
    void allocator::destroy(pointer p):相当于p->~T();

*/
#ifndef _allocator_test_

#define _allocator_test_
#endif // !_allocator_test_
#include<cstddef>
#include<cstdlib>
namespace qlstl
{
    template<class T>
    struct alloc{
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        template<class U> struct rebind
        {
            /* data */
            typedef alloc<U> other;
        };
         allco(){};
         alloc(const alloc<T>& ){}
         
         template<class U>
         alloc (alloc<u> const&){}

         pointer allocate (size_type n,cosnt void* p=0)
         {
             T*buffer=(T*)malloc((size_t)(n*sizeof(T)));
             if(buffer==nullptr)
             {
                 std::cerr<<"malloc fail"<<endl;
             }
             return buffer;
         }
         void deallocate(pointer p,size_type n)
         {
             if(p!=nullptr)
             {
                 free(p);
             }
         }
         void construct (pointer p,const T& value)
         {
             new(p) T(value);
         }
         void destroy(pointer p,size_type n)
         {
             p->~T();
         }
         size_type max_size ()const 
         {
             return static_cast<size_type>(-1/sizeof(T));
         }
         pointer address (reference x)
         {
             return static_cast<pointer>(&x);
         }
         const_pointer const_address (const_reference x)
         {
             return static_cast<const_pointer>(&x);
         }
    };
    template<class u,class t>
	bool operator == (const alloc<u>&,const alloc<t>&)
	{
		return (true);
	}
	template<class u,class t>
	bool operator != (const alloc<u>&,const alloc<t>&)
	{
		return (false);
	}
} // namespace ql


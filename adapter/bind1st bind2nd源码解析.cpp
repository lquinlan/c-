//一个仿函数的基类,定义了,一些通用的typedef来适配整个stl的使用 
template <class _Arg, class _Result>
struct unary_function {
  typedef _Arg argument_type;
  typedef _Result result_type;
};
//binder1st继承自 unary_function 
template <class _Operation> 
class binder1st
  : public unary_function<typename _Operation::second_argument_type,
                          typename _Operation::result_type> {
protected:
  _Operation op;//要绑定的函数操作 
  typename _Operation::first_argument_type value;//绑定的该函数的第一参数 
public:
  binder1st(const _Operation& __x,
            const typename _Operation::first_argument_type& __y)
      : op(__x), value(__y) {}//构造函数 
  typename _Operation::result_type
  operator()(const typename _Operation::second_argument_type& __x) const {
    return op(value, __x); //bind1st的operator()调用的就是要绑定的函数操作 
  }
};
//同样你要绑定的反函数要继承自这个类,才可以与整个stl想适配
/*
template <class _Arg1, class _Arg2, class _Result>
struct binary_function {
  typedef _Arg1 first_argument_type;
  typedef _Arg2 second_argument_type;
  typedef _Result result_type;
}; 
*/ 
//提供的对外接口 
template <class _Operation, class _Tp>
inline binder1st<_Operation> 
bind1st(const _Operation& __oper, const _Tp& __x) 
{
  typedef typename _Operation::first_argument_type _Arg1_type;
  return binder1st<_Operation>(__oper, _Arg1_type(__x));
}
//道理同上,不在复述 
template <class _Operation> 
class binder2nd
  : public unary_function<typename _Operation::first_argument_type,
                          typename _Operation::result_type> {
protected:
  _Operation op;
  typename _Operation::second_argument_type value;
public:
  binder2nd(const _Operation& __x,
            const typename _Operation::second_argument_type& __y) 
      : op(__x), value(__y) {}
  typename _Operation::result_type
  operator()(const typename _Operation::first_argument_type& __x) const {
    return op(__x, value); 
  }
};

template <class _Operation, class _Tp>
inline binder2nd<_Operation> 
bind2nd(const _Operation& __oper, const _Tp& __x) 
{
  typedef typename _Operation::second_argument_type _Arg2_type;
  return binder2nd<_Operation>(__oper, _Arg2_type(__x));
}

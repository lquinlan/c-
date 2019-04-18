//һ���º����Ļ���,������,һЩͨ�õ�typedef����������stl��ʹ�� 
template <class _Arg, class _Result>
struct unary_function {
  typedef _Arg argument_type;
  typedef _Result result_type;
};
//binder1st�̳��� unary_function 
template <class _Operation> 
class binder1st
  : public unary_function<typename _Operation::second_argument_type,
                          typename _Operation::result_type> {
protected:
  _Operation op;//Ҫ�󶨵ĺ������� 
  typename _Operation::first_argument_type value;//�󶨵ĸú����ĵ�һ���� 
public:
  binder1st(const _Operation& __x,
            const typename _Operation::first_argument_type& __y)
      : op(__x), value(__y) {}//���캯�� 
  typename _Operation::result_type
  operator()(const typename _Operation::second_argument_type& __x) const {
    return op(value, __x); //bind1st��operator()���õľ���Ҫ�󶨵ĺ������� 
  }
};
//ͬ����Ҫ�󶨵ķ�����Ҫ�̳��������,�ſ���������stl������
/*
template <class _Arg1, class _Arg2, class _Result>
struct binary_function {
  typedef _Arg1 first_argument_type;
  typedef _Arg2 second_argument_type;
  typedef _Result result_type;
}; 
*/ 
//�ṩ�Ķ���ӿ� 
template <class _Operation, class _Tp>
inline binder1st<_Operation> 
bind1st(const _Operation& __oper, const _Tp& __x) 
{
  typedef typename _Operation::first_argument_type _Arg1_type;
  return binder1st<_Operation>(__oper, _Arg1_type(__x));
}
//����ͬ��,���ڸ��� 
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

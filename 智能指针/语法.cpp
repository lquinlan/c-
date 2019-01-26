template <typename T>

class sh_prt
{
	public :
		sh_prt (T* tt): t(tt){}
		T& operator *() const
		{
			return *t;
		}
		T* operator-> () const //对于->操作符,作用完成后不会失效,还会继续作用下去,c++语法规定 
		{
			return t;
		} 
		//...
	private:
		T* t;
		//...
};

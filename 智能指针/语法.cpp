template <typename T>

class sh_prt
{
	public :
		sh_prt (T* tt): t(tt){}
		T& operator *() const
		{
			return *t;
		}
		T* operator-> () const //����->������,������ɺ󲻻�ʧЧ,�������������ȥ,c++�﷨�涨 
		{
			return t;
		} 
		//...
	private:
		T* t;
		//...
};

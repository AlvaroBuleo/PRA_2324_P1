#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {
	private:
    		T* arr;
	      	int max;
		int n;
		static const int MINSIZE;
	public:
		ListArray();
		~ListArray();
		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
		void resize(int new_size);
		virtual void insert(int pos,T e) override;
		virtual void append(T e) override;
		virtual void prepend(T e) override;
		virtual T remove(int pos) override;
		virtual T get(int pos) override;
		virtual int search(T e) override;
		virtual bool empty() override;
		int size();
};

#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {
	private:
    		T* arr;
	      	int max;
		int n;
		static const int MINSIZE = 2;
	public:
		ListArray(){
			arr = new T[MINSIZE];
			n = MINSIZE;
			max = 10;
		}
		~ListArray();
		T operator[](int pos){
			if(pos < 0 || pos >= size()){
                                throw std::out_of_range("La posicion que intentas insertar no es valida");
                        }
                        else{
                        	return arr[pos];
                        }
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
		void resize(int new_size);
		virtual void insert(int pos,T e) override{
			if(pos < 0 || pos >= size()){
				throw std::out_of_range("La posicion que intentas insertar no es valida");
			}
			else{
				n++;
				for(int i = size()-1;i >= pos;i--){
					if(arr[i] != NULL){
						arr[i+1] = arr[i];
					}
				}
				arr[pos] = e;
			}
		}

		virtual void append(T e) override{
			n++;
			arr[size()-1] = e;
		}

		virtual void prepend(T e) override{
                	n++;
                        for(int i = size()-1;i >= 0;i--){
       				if(arr[i] != NULL){
				   	arr[i+1] = arr[i];
				}
			}      
		 	arr[0] = e;
		}

		virtual T remove(int pos) override{
			if(pos < 0 || pos >= size()){
                                throw std::out_of_range("La posicion que intentas insertar no es valida");
			}
                        else{
                                arr[pos] = NULL;
				int maxpos = size() - pos;
				for(int i = 1;i < maxpos;i++){
					if(arr[pos+i] != NULL){
						arr[pos+i-1] = arr[pos+i];
						arr[pos+i] = NULL;
					}
				}
				n--;
			}
		}

		virtual T get(int pos) override{
			if(pos < 0 || pos >= size()){
                                throw std::out_of_range("La posicion que intentas insertar no es valida");
			}
                        else{
                                return arr[pos];
                        }
		}

		virtual int search(T e) override{
			for(int i = 0;i < size();i++){
				if(arr[i] == e)
					return i;
			}
			return -1;
		}

		virtual bool empty() override{
			for(int i = 0;i < size();i++){
				if(arr[i] != NULL)
					return false;
			}
			return true;
		}

		int size(){
			return n;
		}	
};

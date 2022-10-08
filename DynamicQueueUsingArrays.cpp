//Dynamic Queue Implementation using arrays and templates

#include <iostream>
using namespace std;

template <typename T>
class queueUsingArray{
	private:
		T * data;
		int firstIndex;
		int nextIndex;
		int size;
		int capacity;
	
	public:
	    queueUsingArray(int s){
	    	data = new T[s];
	    	firstIndex = -1;
	    	nextIndex = 0;
	    	size = 0;
	    	capacity = s;
	    	
		}
		
		int getSize(){
			return size;
		}
		
		bool isEmpty(){
			return size == 0;
		}
		
		void enqueue(T element){
			if(size == capacity){
				T * newData = new T[2*capacity];
				int j = 0;
				for(int i = firstIndex ; i < capacity ; i++){
					newData[j] = data[i];
					j++;
				}
				
				for(int i = 0 ; i < firstIndex ; i++){
					newData[j] = data[i];
					j++;
				}
				delete [] data;
				data = newData;
				firstIndex = 0;
				nextIndex = capacity;
				capacity = capacity * 2;
			}
			
			data[nextIndex] = element;
			nextIndex = (nextIndex + 1) % capacity;
			if(firstIndex == -1){
				firstIndex = 0;
			}
			size++;
		}
		
		T front(){
			if(isEmpty()){
				cout << "Queue is Empty!" << endl;
				return 0;
			}
			return data[firstIndex];
		}
		
		T dequeue(){
			if(isEmpty()){
				cout << "Queue is Empty!" << endl;
				return 0;
			}
			T ans = data[firstIndex];
			firstIndex = (firstIndex + 1) % capacity;
			size --;
			
			if(size == 0){
				firstIndex = -1;
				nextIndex = 0;
			}
			
			return ans;
		}
		
};

int main(){
	
	queueUsingArray<int> s(5);
		
		s.enqueue(10);
		s.enqueue(20);
		s.enqueue(30);
		s.enqueue(40);
		s.enqueue(50);
		
		s.enqueue(60); 
		
		cout << s.front() << endl; //Prints 10
		 
		cout<< s.dequeue() << endl; // Deletes and prints 10
		cout<< s.dequeue() << endl; // Deletes and prints 20
		cout<< s.dequeue() << endl; // Deletes and prints 30
		
		cout << s.getSize() << endl; // Prints 3
		
		cout << s.isEmpty() << endl; // Prints 0(FALSE)
		
	return 0;
}

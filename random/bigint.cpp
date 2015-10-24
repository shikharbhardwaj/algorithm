#ifndef BIGINT_H
#define BIGINT_H
#include <vector>
#include <iostream>
//A big integer datatype implemetation with simple stuff
//like addition and multiplication
class BigInt{
friend std::ostream& operator<<(std::ostream&, const BigInt&);
private:
	std::vector<int> data;
public:
	BigInt(){
		data.push_back(0);
	}
	BigInt(const std::vector<int> &input){
		for(auto elem:input){
			data.push_back(elem);
		}
	}
	BigInt(const long long &in){
		int N = in;
		while(N > 0){
			data.push_back(N%10);
			N /= 10;
		}
	}
	BigInt& operator= (const BigInt &copy){
		data = copy.data;
	}
	BigInt operator+= (const BigInt &rhs){
		int pos = 0;
		int carry = 0;
		while(true){
			if(pos == this->data.size() && pos < rhs.data.size()){
				this->data.push_back(0);
			}
			if(pos == rhs.data.size()){
				this->data[pos] += carry;
				break;
			}
			this->data[pos] += rhs.data[pos] + carry;
			carry = this->data[pos]/10;
			this->data[pos] %= 10;
			pos++;
		}
		return *this;
	}
	
};
BigInt operator+ (const BigInt &lhs, const BigInt &rhs){
	BigInt ret(lhs);
	ret += rhs;
	return ret;
}
std::ostream& 
operator<<(std::ostream& out, const BigInt& s){
    for(int i = s.data.size()-1; i >= 0;i--){
    	out<<s.data[i];
    }
    return out;
}
int main(){
	int T,x,y;
	std::cin>>T;
	while(T--){
		std::cin>>x>>y;
		BigInt first(x);
		BigInt second(y);
		first += second;
		std::cout<<first;
		std::cout<<" "<<x+y;
		std::cout<<std::endl;
	}
}
#endif

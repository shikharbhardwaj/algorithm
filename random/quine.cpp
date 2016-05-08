#include <fstream>
#include <iostream>
using namespace std;
int main(){
	ifstream thisFile(__FILE__);  //The __FILE__ gives us the name of the current file compiled
        std::string line;
	while(!thisFile.eof()){
		getline(thisFile, line);
		cout<<endl<<line;
	}
	return 0;
}

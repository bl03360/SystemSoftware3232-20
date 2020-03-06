#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int i = 0;
	while(cin) {
		int x;
		cin>>x;
		int sqI = x * x;
		if(i != sqI){		
			cout<<sqI<<"\t";
			i = sqI;
		}
	};

cout<<"\n";

}
	

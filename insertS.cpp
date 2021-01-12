#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	vector<int> insert;
	ifstream file;
	int curr;
	int iter2;
	int iter1;
	int temp;
	file.open("data.txt");
	
	if(!file)
		return 1;
	
	while(!file.eof()){
		cout<<"Before"<<endl;
		while(file >> curr){
			cout<<curr<<endl;
			insert.push_back(curr);
			iter2=insert.size()-1;
			iter1=iter2-1;

			while(insert[iter2]<insert[iter1]&&iter1>=0){
				int temp=insert[iter1];
				insert[iter1]=insert[iter2];
				insert[iter2]=temp;
				iter2--;
				iter1--;
			}
		}
	}
	cout<<endl<<"After"<<endl;
	for(int i=0;i<insert.size();i++)
		cout << insert[i] << endl;

	file.close();
	return 0;
}

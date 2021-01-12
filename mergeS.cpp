#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2){
		vector<int> vec;
		int iter1=0;
		int iter2=0;

	
		while(iter1<v1.size()&&iter2<v2.size()){
			if(v1[iter1]>=v2[iter2]){
				vec.push_back(v2[iter2]);
				iter2++;
			}
			else{	
				vec.push_back(v1[iter1]);
				iter1++;	
			}
		}
		while(iter1<v1.size()){
				vec.push_back(v1[iter1]);
				iter1++;	
		}
		while(iter2<v2.size()){
				vec.push_back(v2[iter2]);
				iter2++;
		}
	
		return vec;
}

vector<int> mergeSort(vector<int> vec){
	if(vec.size()>1){	

		vector<int> v1;
		vector<int> v2;
		vector<int> r;
		
		for(int i=0;i<vec.size()/2;i++){
			v1.push_back(vec[i]);
		}
		for(int i=vec.size()/2;i<vec.size();i++){
			v2.push_back(vec[i]);
		}

		v1=mergeSort(v1);
		v2=mergeSort(v2);
		
		r=merge(v1,v2);
		return r;
					
	}
	else{
		return vec;
	}
}

int main(){
	vector<int> merge;
	ifstream file;
	int curr;
	int iter2;
	int iter1;
	int temp;
	file.open("data.txt");
	
	if(!file)
		return 1;
	
	while(!file.eof()){
		while(file >> curr){
			merge.push_back(curr);
		}
	}
	cout<<"Before"<<endl;
	for(int i=0;i<merge.size();i++)
		cout << merge[i] << endl;
	cout<<endl;


	merge=mergeSort(merge);
	cout<<endl;
	cout<<"After"<<endl;
	for(int i=0;i<merge.size();i++)
		cout << merge[i] << endl;



	file.close();
	return 0;
}

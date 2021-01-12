
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){
	srand(time(NULL));
	vector<int> insert;
	int n=0;
	int iter2;
	int iter1;
	int temp;
	clock_t t2,t1;
	

	
	for(int i=0;i<8;i++){
		n+=5000;
		t2=clock();

		for(int x=0;x<n;x++){
			insert.push_back(rand()%10000);
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
		t1=clock();
		insert.clear();
		float elapse=(float)t1 - (float)t2;
		cout<<"Size: "<<n<<" Time: "<<elapse<<" "<<elapse/CLOCKS_PER_SEC<<"s"<<endl;

			
	//	for(int i=0;i<insert.size();i++)
	//		cout << insert[i] << endl;
	}

	return 0;
}


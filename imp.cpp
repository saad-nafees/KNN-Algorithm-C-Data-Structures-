#include<iostream>
#include<math.h>
#include"KNN.h"
using namespace std;

int knn :: distancefuc(graph b,graph a){
    	int cc= (pow((a.x1-b.x1),2) + pow((a.x2-b.x2),2));
    	return cc;
}

void knn :: sort(int *temp){
	int k;
    for(int i=0 ; i<4 ; i++){
    	temp[i] = d[i];
	}
	for (int i=1 ; i < 4 ; i++)
	{
			k=temp[i];
		int j;
		for (j=i-1 ; j>=0 && k<temp[j] ; j--)
			temp[j+1] = temp[j];
	    temp[j+1]=k;
			
	
}

}

void knn :: formatcluster(graph *a1,graph a){
        cout  << "\nEnter the K = No. of nearest Neigbours: ";
		cin >> k;
		for(int i=0 ; i<4 ; i++){
			d[i] = distancefuc(a,a1[i]);
		}	
		
		cout << "\n\n\nX1\tX2\tDis\n";
	for(int i=0 ; i< 4 ; i++){
		cout << a1[i].x1 << "\t" << a1[i].x2 << "\t" << d[i] ;
		cout << endl;
	}
		int rr[4];
		sort(rr);
		
		for(int j=0 ; j<4 ; j++){
    	for(int i=0 ; i<4 ; i++){
		{
		if(rr[i] == d[j]){
    		r[i] = j+1;
		}
	}
}
}
	
	cout << "\n\n\nX1\tX2\tDis\tRank\tincluded in 3 NN\n";
	for(int i=0 ; i< 4 ; i++){
		cout << a1[i].x1 << "\t" << a1[i].x2 << "\t"<< d[i]  << "\t"<< r[i] << "\t" ;
		if(r[i] <= k){
			cout << "Yes";
		}
		else{
			cout << "NO";
		}
		cout << endl;
	}
	
	cout << "\n\n\nX1\tX2\tDis\tRank\tY\n";
	for(int i=0 ; i< 4 ; i++){
		cout << a1[i].x1 << "\t" << a1[i].x2 << "\t"<< d[i]  << "\t"<< r[i] << "\t" ;
			if(a1[i].c==Bad && r[i] <= k){
		cout << "Bad";
	}
		else if(a1[i].c==Good && r[i] <= k){
		cout << "Good";
	}
	else{
		cout << "-";
	}
		cout << endl;
	}
	
	cout << "\n\nPrediction or Classification of the Paper Tissue is: ";
	int cn = 0,cn1 =0;
	for(int i=0 ; i<4 ; i++){
		if(a1[i].c==Good && r[i] <= k){
			cn++;
		}
		else if(a1[i].c==Bad && r[i] <= k){
			cn1++;
		}
	}
	if(cn > cn1){
		cout << "\n\nGood !!!!!!\n\n";
	}
	else{
       		cout << "\n\nBad !!!!!!\n\n";		
	}
}

void knn ::  testKNNfuc(graph *a,graph v){
	   formatcluster(a,v);
}



#include<iostream>
 
using namespace std;
 
int main() {
    int input[7],received[7],c,c1,c2,c3,i;
 
    cout<<"Enter 4 bits of input one by one\n";
    cin>>input[2];
    cin>>input[4];
    cin>>input[5];
    cin>>input[6];
 
    input[0]=input[2]^input[4]^input[6];
	input[1]=input[2]^input[5]^input[6];
	input[3]=input[4]^input[5]^input[6];
 
	cout<<"\nEncoded input is\n";
	for(i=0;i<7;i++)
        cout<<input[i];
    
	cout<<"\n\nEnter received input bits one by one\n";
    for(i=0;i<7;i++)
        cin>>received[i];
 
    c1=received[0]^received[2]^received[4]^received[6];
	c2=received[1]^received[2]^received[5]^received[6];
    c3=received[3]^received[4]^received[5]^received[6];
	c=c3*4+c2*2+c1 ;
 
    if(c==0) {
		cout<<"\nNo error while transmission of input\n";
    }
	else {
		cout<<"\nError on position "<<c;
		
		cout<<"\nData sent : ";
		for(i=0;i<7;i++)
        	cout<<input[i];
        
		cout<<"\nData received : ";
        for(i=0;i<7;i++)
        	cout<<received[i];
        
		cout<<"\nCorrect message is\n";

		if(received[c-1]==0)
			received[c-1]=1;
        else
		 	received[c-1]=0;
		for (i=0;i<7;i++) {
			cout<<received[i];
		}
	}
	
	return 0;
}
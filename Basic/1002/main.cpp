
#include<iostream>
#include<string>

using namespace std;

class sovle{
	public:
    string num;
    int result;
    void innum(){
       cin >> num; 
    }
    void calculate(){
        result = 0;
        for( int i = 0 ; i < num.length() ; i ++ ){
            result += num[i]-'0';
        }
    }
    void print(){
    	int resultn = result;
    	int shu[8] = {0};
    	int i = 0;
        while( resultn != 0 ){
        	shu[i] = resultn%10;
        	i++;
        	resultn = resultn/10;
        	//cout << i << endl; 
        }
        	i--;
        for( ; i >= 0 ; i -- ){
        	switch( shu[i] ){
        		case 0:  cout << "ling";
        				break;
        		case 1:  cout << "yi";
        		        break;
        		case 2:  cout << "er";
        				break;
        		case 3:  cout << "san";
        				break;
        		case 4:  cout << "si";
        				break;
        		case 5:  cout << "wu";
        				break;
        		case 6:  cout << "liu";
        				break;
        		case 7:  cout << "qi";
        				break;
        		case 8:  cout << "ba";
        				break;
        		case 9:  cout << "jiu";
        				break;
			}
			if( i > 0 ){
				cout << " ";
			}
	}
    };
};

int main (int argc, char** argv){
    sovle *re = new sovle();
    re->innum();
    re->calculate();
    re->print();
    return 0;
}

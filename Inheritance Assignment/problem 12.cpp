#include<iostream>
#include <string.h> 
using namespace std;
class String{
	protected:
		static const int limit = 80;
		char str[limit];
	public:
		String():str(){}
		explicit String(const char s[]):str(s){	
		   strcpy(str,s);
		}
	    string operator+=(string s){
	    	if(strlen(str)+strlen(s.str)>=limit){
	    		cout<<endl<<" Buffer Overflow "<<endl;
	    		return String("");
	    		
			}
			strcat(str,str.s);
			return String(str);
		}
		operator char*(){return str};
		
		void show()const{
			cout<<str<<endl;
		}		
};

class PString : public String{
	public:
		PString:String(){	}
        explicit PString(char s[]){
        	if(strlen(s)>=limit){
        		strncpy(str,s,limit-1);
			}
			else{
				strcpy(str,s);
			}
		}				
};

class PString2 : public PString{
	PString2():PString(){}
	explicit PString2(char s[]):PString(){}
	
	PString2 &left(char s[], int n) {
        int i;
        for (i = 0; i < n; ++i) {
            str[i] = s[i];
        }
        str[i] = '\0';

        return *this;
    }
};

int main(){
	
	

}
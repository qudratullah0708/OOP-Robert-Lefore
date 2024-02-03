#include<iostream>
using namespace std;

class shamiBurger{
	private:
   	 int shami,bun;
   	public:
   	  void initilizeStock();
   	  void SellStock();
   	  void ViewStock();
};

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Intilize Stock" << endl;
    cout << "2. Sell Stock" << endl;
    cout << "3.  View Stock" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
}

void SellingMenu(){
	cout << "Menu:" << endl;
    cout << "1. Sell from stall 1" << endl;
    cout << "2. Sell from stall 2" << endl;
    cout << "3.  Sell from stall 3" << endl;
    cout << "4.  Sell from stall 4" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";
}

void LeftStockMenu(){
	cout << "Menu:" << endl;
    cout << "1. Remaining Stock in stall 1" << endl;
    cout << "2. Remaining Stock in stall 2" << endl;
    cout << "3. Remaining Stock in stall 3" << endl;
    cout << "4. Remaining Stock in stall 4" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";
}


void shamiBurger :: initilizeStock(){
	cin>>shami;
	cin>>bun;	
}
// Sell Stock
void shamiBurger :: SellStock(){
	 shami--;
	 bun--;
}
// View Stock

void shamiBurger :: ViewStock(){
      cout << "View Stock" << endl;
    cout<<" View stock for the following stalls"<<endl;
	cout<<"No. of Shami Burgers"<<shami<<" "<<bun<<"Left";
}
int main(){
	shamiBurger s1,s2,s3,s4;
	
	
		int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
	cout<<"Intilize Stock for s1 "<<endl;
	s1.initilizeStock();
	cout<<"Intilize Stock for s2 "<<endl;
	s2.initilizeStock();
	cout<<"Intilize Stock for s3 "<<endl;
	s3.initilizeStock();
	cout<<"Intilize Stock for s4 "<<endl;
	s4.initilizeStock();
               break;
            case 2:  // Sell Stock
                cout << "Sell Stock" << endl;
                 int choice;
    do {
        SellingMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Sell Stock from stall 1 " << endl;
                     s1.SellStock();
                break;
            case 2:
                cout << "Sell Stock from stall 2" << endl;
                 s2.SellStock();
                break;
            
            case 3:
                cout << "Sell Stock from stall 3" << endl;
                s3.SellStock();
                break;
			case 4:
                cout << "Sell Stock from stall 4" << endl;
                s4.SellStock();
                break;
            
            case 5:                                   
                cout << "Exiting Program" << endl;        
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
                break;
            case 3:  // View Stock
                cout << "View Stock" << endl;
    do {
        LeftStockMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "View Stock from stall 1 " << endl;
                     s1.ViewStock();   
                break;
            case 2:
                cout << "View Stock from stall 2" << endl;
                 s2.ViewStock(); 
                break;
            
            case 3:
                cout << "View Stock from stall 3" << endl;
                s3.ViewStock();     
                break;
			case 4:
                cout << "View Stock from stall 4" << endl;
                s4.ViewStock(); 
                break;
            
            case 5:                                   
                cout << "Exiting Program" << endl;        
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    
                break;
            
            case 4:                                   
                cout << "Exiting Program" << endl;        
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);   
}


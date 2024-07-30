#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;
class login{
	public:
		string lid,lpw;
	void setid(string id){
		lid=id;}
	void setpw(string pw){
		lpw=pw;}
	string getid(){
		return lid;}
	string getpw(){
		return lpw;}
			
};
registration(login log)
{
	system("cls");	
	string id,pw;
	cout<<"enter login id:";
	cin>>id;
	cout<<"enter login password:";
	cin>>pw;
	log.setid(id);
	log.setpw(pw);
	ofstream file("D:\debanjan pratice code\cpp project\login.txt",ios::app);
	if(!file)
	{
		cout<<"file can not open:"<<endl;
	}
	else
	{
		file<<"\t"<<log.getid()<<" : "<<log.getpw()<<endl;
		cout<<"user registration successfull."<<endl;	
	}
	//sleep(3000);
	file.close();	
}
loging()
{
	system("cls");
	string id,pw;
	cout<<"enter the login id:";
	cin>>id;
	cout<<"enter password:";
	cin>>pw;
	ifstream file("D:\debanjan pratice code\cpp project\login.txt");
	if(!file)
	{
		cout<<"can not open"<<endl;
	}
	else
	{
		string line;
		bool found=false;
		while (getline(file,line)){
			stringstream ss;
			ss<<line;
			string uid,upw;
			char delimiter;
			ss>>uid>>delimiter>>upw;
			if(uid==id && upw==pw)
			{
				found=true;
				cout<<"\t\t welcome to the main page!!!"<<endl<<endl<< endl;
			}
			
		}
		if(!found){
			cout<<"incorrect login and password!!"<<endl;
		}
		
	}
	file.close();
}

int main()
{
	start:
	login log;
	int ch;
	cout<<"\t\t welcome to registration and login page:"<<endl;
	cout<<"\t\t 1.registration \t\t 2. login \t\t 3. exit"<<endl;
	cout<<"enter your choice:";
	cin>>ch;
	system("cls");
	if(ch==1)
	{
		registration(log);
	}
	else if(ch==2)
	{
		loging();
	}
	else{
		goto start;
	}
	goto start;

}

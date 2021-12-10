#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>

using namespace std;

class PersonalInfo
{
	private:
		string name;
		string staffID;
		string gender;
	
	public:
		string getName()
		{
			return name;
		}
		string getStaffID()
		{
			return staffID;
		}
		string getGender()
		{
			return gender;
		}
		void setData(string , string  , string);
		PersonalInfo()
		{
			name="";
			staffID="";
			gender="";
		}
		
		~PersonalInfo()
		{
			name="";
			staffID="";
			gender="";
		}
		
};
void PersonalInfo::setData(string n, string id, string g) 
		{
			name=n;
			staffID=id;
			gender=g;
		}
class FitnessInfo
{
	private:
		string staffId;
		float weight;
		float height;
	
	public:
		string getStaffId()
		{
			return staffId;
		}
		float getWeight()
		{
			return weight;
		}
		float getHeight()
		{
			return height;
		}
		void setData2(string , float , float);
		FitnessInfo()
		{
			staffId="";
			weight=0.0;
			height=0.0;
		}
		~FitnessInfo(){};
};

void FitnessInfo::setData2(string id, float w, float h)
		{
			staffId=id;
			weight=w;
			height=h;
		}
	class userInfo:public PersonalInfo
	{
		private:
			FitnessInfo ob;
			int age;
			float bmi;
			float bmr;
			float rmr;
			string category;
			string birthDate;
		
		public:
			
			void displayData();
			int AGE(string);
			void BMI(float,float);
			void BMR(float,float,string,string);
			void RMR(float,float,string,string);
			void setData3( string ,string  ,float , float);
			void setdata(string,float,float);
			void Category(float);
			float getBMI(){return bmi;}
			float getBMR(){return bmr;}
			float getRMR(){return rmr;}
			string getCategory(){return category;}
			float getWeight(){return ob.getWeight();}
			float getHeight(){return ob.getHeight();}
			float getAge(){return age;}
			void birthday(string);
			void displayData2();
			friend void analysis(userInfo ob[],int a);
			
	};
			void userInfo::birthday(string id)
			{
				birthDate=id;
				birthDate.erase(6);
				if(birthDate.substr(0,2)>="20")
				{
					birthDate.insert(0,"19");
					birthDate.insert(4,"-");
					birthDate.insert(7,"-");
				}
				else
				{
					birthDate.insert(0,"20");
					birthDate.insert(4,"-");
					birthDate.insert(7,"-");
					
				}
			}
			void userInfo::Category(float b)
			{
				
				  if(b<20)
					{
					category ="underweight";
					}
					else if (b>=20&&b<25)
					{
					category="Normal Weight";
					}
					else if (b>=25&&b<30)
					{
					category="overweight";
					}
					else if (b>=30)
					{
					category="obese";
					}
				 	

			}
			void userInfo::setdata(string id, float w, float h)
			{
				ob.setData2(id,w,h);
			}
			void userInfo::setData3( string id,string g ,float w, float h)
			{
				ob.setData2(id,w,h);
				age=AGE(id);
				BMI(w,h);
				BMR(w,h,id,g);
				RMR(w,h,id,g);
				Category(bmi);
				birthday(id);
			}
			void userInfo::displayData()
			{
				cout<<fixed<<setprecision(0);
				cout<<left<<setfill(' ')<<setw(20)<<getName()<<"		";
				cout<<setfill('0')<<setw(12)<<getStaffID()<<"	";
				cout<<getGender()<<"	"<<getAge()<<"	"<<ob.getWeight()<<"		";
				cout<<ob.getHeight()<<"		"<<birthDate<<endl;
			}
			void userInfo::displayData2()
			{	
				cout<<fixed<<setprecision(0);
				cout<<left<<setfill(' ')<<setw(20)<<getName()<<"		";
				cout<<setfill('0')<<setw(12)<<getStaffID()<<"	";
				cout<<getGender()<<"	"<<bmi<<"	"<<bmr<<"	"<<rmr<<"	";
				cout<<category<<endl;
				
			}

			int userInfo::AGE(string id)
			{
				int bornYear=0,d,age=0;
				for(int i=0;i<2;i++)
				{
					if(id.at(i)=='0')
						d=0;
					if(id.at(i)=='1')
						d=1;
					if(id.at(i)=='2')
						d=2;
					if(id.at(i)=='3')
						d=3;
					if(id.at(i)=='4')
						d=4;
					if(id.at(i)=='5')
						d=5;
					if(id.at(i)=='6')
						d=6;
					if(id.at(i)=='7')
						d=7;
					if(id.at(i)=='8')
						d=8;
					if(id.at(i)=='9')
						d=9;
						
						if(id.at(0)=='0'&& i>0)
						{
							bornYear=2000+d;
						}
						if(id.at(0)=='1'&& i>0)
						{
							bornYear=2000+(bornYear*10)+d;
						}
						else
						{
							bornYear=(bornYear*10)+d;
							if(i>0)
							{
								bornYear=1900+bornYear;
							}
						}
			}
					age=2020-bornYear;
					return age;

				
			}
			void userInfo::BMI(float w,float h)
			{
				bmi= w/((h/100)*(h/100));
			}
			void userInfo::BMR(float w,float h,string id,string g) //function of calculationn of bmr
			{
			
				if(g=="Male"||g=="male")
				{
					bmr = 10 * w + 6.25 * (h/100)- 5 * age + 5;
				}
				else
				{
					bmr = 10 * w + 6.25 * (h/100) - 5 * age - 161;
				}
		
			}
			void userInfo::RMR(float W,float H,string id,string g) //function of calculation of rmr
			{
				if(g=="Male"||g=="male")	{
					rmr=88.362 + (13.397 * W) + (4.799 * (H/100)) - (5.677 * age);
				}
				else
				{
					rmr=447.593 + (9.247 * W) + (3.098 *(H/100)) - (4.330 * age);
				}
				
			}

string validateGender()
{
	string gender;
		cin>>gender;
		while(gender!="Male"&&gender!="Female")
		{
			cout<<"Invalid Input Data. Please input again"<<endl;
			cout<<"Female or Male Only"<<endl;
			cin>>gender;
		}
	return gender;
}

double validateWeight()
{
	double weight;
	do
	{
		cin>>weight;
		while(cin.fail())
		{
			cout<<"Invalid Input Data. Please input again"<<endl;
			cin>>weight;
		}
		if(weight<0)
		{
			cout<<"Weight cannot be negative value"<<endl;
		}
	}while(weight<0);
	return weight;
}

double validateHeight()
{
	double height;
	do
	{
		cin>>height;
		while(cin.fail())
		{
			cout<<"Invalid Input Data. Please input again"<<endl;
			cin>>height;
		}
		if(height<0)
		{
			cout<<"Height cannot be negative value"<<endl;
		}
	}while(height<0);
	return height;
}

double validateBMI()
{
	double BMI;
	do
	{
		cin>>BMI;
		while(cin.fail())
		{
			cout<<"Invalid Input Data. Please input again"<<endl;
			cin>>BMI;
		}
		if(BMI<0)
		{
			cout<<"BMI cannot be negative value"<<endl;
		}
	}while(BMI<0);
	return BMI;
}

double validateAge()
{
	double age;
	do
	{
		cin>>age;
		while(cin.fail())
		{
			cout<<"Invalid Input Data. Please input again"<<endl;
			cin>>age;
		}
		if(age<0)
		{
			cout<<"Age cannot be negative value"<<endl;
		}
	}while(age<0);
	return age;
}
			
			
			
void menu() //function of menu list.
{
	char ch;
	cout<<"Welcome to Let's Get Fit. Let's start now by pressing any key.";
	cin.get(ch);
	cout<<"Press select your choice."<<endl;
	cout<<"1:Reading Data From File"<<endl<<"2:Proccessed Data"<<endl;
	cout<<"3:Adding New Informations"<<endl<<"4:Searching Data"<<endl;
	cout<<"5:Modify Data"<<endl;
	cout<<"6:Amount of category"<<endl;
	cout<<"Plese enter the above choice only."<<endl;
}

void searching(userInfo user[],int a)
{
	string name,staffGender;
	string id;
	int choice,indc[9999]={0},check=1,condition,index,minAge,maxAge;
	int minWeight,maxWeight,minBMI,maxBMI,minHeight,maxHeight;
	char addCondition,B;
			cout<<"Enter 1 to search specific data"<<endl;
			cout<<"Enter 2 to search combinational data"<<endl;
			cin>>choice;
			while (cin.fail())
		    {
		        cin.clear();
		        cin.ignore();
		        cout<<"Invalid Choice. Please Re-Enter"<<endl;
		        cin >> choice;
		    }
		switch(choice)
		{
			case 1 : cout<<"Enter ID to search individual data"<<endl;
					 cin>>id;
					 for(int i=0;i<=a;i++)
					 {
					 	if(id == user[i].getStaffID())
					 	{
					 		index=i;
					 		break;
						}
						else
						index=-1;
					 }
					 if(index==-1)
					 {
					 	cout<<"Invalid Data"<<endl;
					 }
					 else
					 {
					 	cout<<"Name"<<"\t\t\t\t"<<"ID"<<"\t\t"<<"Gender"<<"\t"<<"Age"<<"\t";
					 	cout<<"Weight(KG)"<<"\t"<<"Height(CM)"<<"\t"<<"Birthday"<<endl; 
						user[index].displayData();
					 }
	
					 break;
			
			case 2 : cout<<"1:Gender"<<endl<<"2:Age"<<endl<<"3:BMI"<<endl<<"4:Weight"<<endl<<"5:Height"<<endl;
					 do{
						if(check==1)   //for first condition only.
						{
						cout<<"Enter a condition  to search:";
						cin>>condition;
						if(condition==1){
						cout<<"Male or Female"<<endl<<"Enter the required gender:";
						staffGender=validateGender();
						for(int j=0;j<a;j++)
						{
						if(user[j].getGender() ==staffGender)
						indc[j]=1; // to know which data fullfills the condition.
						else
						indc[j]=0; // to know which data does not fullfill the condition.
						}
				    	}
						if(condition==2){
						cout<<"Enter minimum age:";
						minAge=validateAge();
						cout<<"Enter maximum age:";
						maxAge=validateAge();
						for(int j=0;j<a;j++){
						if(user[j].getAge()>=minAge && user[j].getAge()<=maxAge)
						indc[j]=1;
						else
						indc[j]=0;	
						}
						}
						if(condition==3){
						cout<<"Enter the minimum BMI:";
						minBMI=validateBMI();
						cout<<"Enter the maximum BMI:";
						maxBMI=validateBMI();
						for(int j=0;j<a;j++){
						if(user[j].getBMI()>=minBMI && user[j].getBMI()<=maxBMI)
						indc[j]=1;
						else
						indc[j]=0;
							}
						}
						if(condition==4){
						cout<<"Enter the maximum weight:";
						maxWeight=validateWeight();
						cout<<"Enter the minimum weight:";
						minWeight=validateWeight();
						for(int j=0;j<a;j++){
						if(user[j].getWeight()>=minWeight && user[j].getWeight()<=maxWeight)
						indc[j]=1;
						else
						indc[j]=0; 
						}
						}
						if(condition==5){
						cout<<"Enter the maximum height:";
						maxHeight=validateHeight();
						cout<<"Enter the minimum height:";
						minWeight=validateHeight();
						for(int j=0;j<a;j++){
						if(user[j].getHeight()>=minHeight && user[j].getHeight()<=maxHeight)
						indc[j]=1;
						else
						indc[j]=0;
							}
						}
		
					}
					else // for second time and more.
					{
					cout<<"Enter a condition  to search:";
					cin>>condition;
					if(condition==1){
					cout<<"Male or Female"<<endl<<"Enter the required gender:";
					staffGender=validateGender();
					for(int j=0;j<a;j++){
					if(indc[j]==1){
					if(user[j].getGender()==staffGender)
						indc[j]=1;
					else
						indc[j]=0;
					}
					}
					}
					if(condition==2){
					cout<<"Enter minimum age:";
					minAge=validateAge();
					cout<<"Enter maximum age:";
					maxAge=validateAge();
					for(int j=0;j<a;j++){
					if(indc[j]==1){
					if(user[j].getAge()>=minAge && user[j].getAge()<=maxAge)
						indc[j]=1;
					else
						indc[j]=0;	
							}
						}
					}
					if(condition==3){
					cout<<"Enter the minimum BMI:";
					minBMI=validateBMI();
					cout<<"Enter the maximum BMI:";
					maxBMI=validateBMI();
					for(int j=0;j<a;j++){
					if(indc[j]==1){
					if(user[j].getBMI()>=minBMI && user[j].getBMI()<=maxBMI)
						indc[j]=1;
					else
						indc[j]=0;
							}
						}
					}
					if(condition==4){
					cout<<"Enter the maximum weight:";
					maxWeight=validateWeight();
					cout<<"Enter the minimum weight:";
					minWeight=validateWeight();
					for(int j=0;j<a;j++){
					if(indc[j==1]){
					if(user[j].getWeight()>=minWeight && user[j].getWeight()<=maxWeight)
						indc[j]=1;
					else
						indc[j]=0; 
						}
					}
					}
					if(condition==5){
					cout<<"Enter the maximum height:";
					maxHeight=validateHeight();
					cout<<"\Enter the minimum height:";
					minWeight=validateHeight();
					for(int j=0;j<a;j++){
					if(indc[j]==1){
				
					if(user[j].getHeight()>=minHeight && user[j].getHeight()<=maxHeight)
						indc[j]=1;
					else
					indc[j]=0;
						}
					}	
				}
				}
				check++;
				cout<<"Press Y to add more condition or Press N to search.";//add more condition.
				cin>>addCondition;
		
	
					}while(addCondition=='y'||addCondition=='Y');
					cout<<"\n";
					cout<<"Name"<<"\t\t\t\t"<<"ID"<<"\t\t"<<"Gender"<<"\t"<<"Age"<<"\t";
					cout<<"Weight(KG)"<<"\t"<<"Height(CM)"<<"\t"<<"Birthday"<<endl;
					for(int j=0;j<=a;j++)
					{
						if(indc[j]==1)
						{
							user[j].displayData();
							cout<<endl;
						}
					}
					break;		 
		}				

}

void modify(userInfo ob[], int size)
{
	string search;
	int index;
	float weight,height;


			cout<<"Enter Id to search "<<endl;
			cin>>search;
			for(int i=0;i<=size;i++)
			{
				if(ob[i].getStaffID() == search)
				{
					index=i;
					break;
				}
				index=-1;
			}
			if(index == -1)
			{
				cout<<"Invalid Data"<<endl;

			}
			else
			{
				cout<<"Enter new weight and height for "<<ob[index].getName()<<endl;
				cin>>weight>>height;
				ob[index].setData3(search,ob[index].getGender(),weight,height);
			}
}

void analysis(userInfo ob[],int a)
{
	int uw=0,nw=0,ow=0,obe=0;
	for(int i=0;i<=a;i++)
	  {

			if (ob[i].getBMI()<20)
				{
					uw++;
				}
			else if (ob[i].getBMI()>=20&&ob[i].getBMI()<25)
				{
					nw++;
				}
			else if (ob[i].getBMI()>=25&&ob[i].getBMI()<30)
				{
					ow++;
				}
			else if (ob[i].getBMI()>=30)
				{
					obe++;
				}
		}
			cout<<"Category"<<"\t"<<"Amount"<<endl;
			cout<<"Under Weight"<<"\t"<<uw<<endl;
			cout<<"Normal Weight"<<"\t"<<nw<<endl;
			cout<<"Overweight"<<"\t"<<ow<<endl;
			cout<<"Obese"<<"\t\t"<<obe<<endl;
			cout<<endl;
}

void addUser(userInfo ob[], int &a)
{
	a++;
	string name,gender,id;
	float weight,height;
	cin.ignore();
	cout<<"Enter your name: "; getline(cin,name);
	cout<<"Enter your gender: ";gender=validateGender();
	cout<<"Enter your staff id: ";cin>>id;
	cout<<"Enter your weight: ";weight=validateWeight();
	cout<<"Enter your height: ";height=validateHeight();
	ob[a].setData(name,id,gender);
	ob[a].setData3(id,gender,weight,height);
}

void readFile(userInfo ob[],int &i)
	{
		string name,gender;
		string id;
		int s,a=999;
		float weight,height;
		int temp,temp1,cal,cal2;
		fstream infile,infile2;
		string line;
		infile.open("PersonalInfo.txt");
		if(!infile)
		{
			cout<<"PeronalInfo File Error ";
		}
		while(getline(infile,line))
		{

			temp=line.find('\t');
			id=line.substr(0 ,temp);
			temp1=line.find('\t',temp+1);
			cal=temp1-temp;
			name=line.substr(temp+1,cal-1);
			cal2=line.length()-temp1;
			gender=line.substr(temp1+1,cal2);
			if(gender!="Male"&&gender!="Female")
			{
				continue;
			}
			ob[i].setData(name,id,gender);
			if(infile.eof())
			{
				break;
			}
			i++;
			
		}
		infile.close();
		infile2.open("FitnessInfo.txt");
		if(!infile2)
		{
			cout<<"FitnessInfo File Error";
		}
		while(!infile2.eof())
		{
			infile2>>id>>weight>>height;
			for(int j=0;j<=i;j++)
			{
				if(id==ob[j].getStaffID())
				{
					ob[j].setData3(id,ob[j].getGender(),weight,height);
					break;
				}
			}
			
		
		}
		infile2.close();
	
}
void output(userInfo ob[],int size)
{
	int num=1;
	fstream output;
	output.open("minimal statistical information.txt",ios::out);
	output<<"Num"<<"\t"<<"NAME"<<"\t\t\t"<<"ID"<<"\t\t"<<"GENDER"<<"\t"<<"Weight(KG)"<<"\t"<<"Height(CM)"<<"\t"<<"BMI"<<"\t\t"<<"BMR"<<"\t\t"<<"RMR"<<"\t\t"<<"Category"<<endl;
	for(int i=0;i<=size;i++)
	{
		output<<num++<<"\t"<<left<<setfill(' ')<<setw(20)<<ob[i].getName()<<"\t"<<ob[i].getStaffID()<<"\t";
		output<<ob[i].getGender()<<"\t"<<ob[i].getWeight()<<"\t\t"<<ob[i].getHeight()<<"\t\t";
		output<<ob[i].getBMI()<<"\t\t"<<ob[i].getBMR()<<"\t\t"<<ob[i].getRMR()<<"\t\t"<<ob[i].getCategory()<<endl;
	}
	output.close();
}

void Delete(userInfo ob[],int &i)
{
	int indc[999],y=0,x=0;
	
	for(int j=0;j<=i;j++)
	{
		if(ob[j].getWeight()!=0&&ob[j].getHeight()!=0)
		{
			indc[y]=-1;
		}
		y++;
	}
	for(int j=0;j<=i;j++)
	{
		if(indc[j]==-1)
		{
			ob[x].setData(ob[j].getName(),ob[j].getStaffID(),ob[j].getGender());
			ob[x].setData3(ob[j].getStaffID(),ob[j].getGender(),ob[j].getWeight(),ob[j].getHeight());
			x++;
		}
	}
}

	int main()
	{
		int choice;
		char B;
		int a=999,i=0;
		userInfo user[a];
		readFile(user,i);
		Delete(user,i);
		do
		{
			menu();
			cin>>choice;
			cout<<endl;
			while (cin.fail())
		    {
		        cin.clear();
		        cin.ignore();
		        cout<<"Invalid Choice. Please Re-Enter"<<endl;
		        cin >> choice;
		    }
			switch(choice)
			{
				case 1 :cout<<"Name"<<"\t\t\t\t"<<"ID"<<"\t\t"<<"Gender"<<"\t"<<"Age"<<"\t";
						cout<<"Weight(KG)"<<"\t"<<"Height(CM)"<<"\t"<<"Birthday"<<endl; 
						for(int j=0;j<=i;j++)
						{
							user[j].displayData();
						}
						break;
				
				case 2: cout<<"Name"<<"\t\t\t\t"<<"ID"<<"\t\t"<<"Gender"<<"\t"<<"BMI"<<"\t";
						cout<<"BMR"<<"\t"<<"RMR"<<"\t"<<"Category"<<endl; 
						for(int j=0;j<=i;j++)
						{
							user[j].displayData2();
						}
						break;
				
				case 3:addUser(user,i);
					   break;
				
				case 4 :searching(user,i);
						break;
				
				case 5 :modify(user,i);
						break;
				
				case 6 : analysis(user,i);
						break;
		
				default :cout<<"Invalid Choice. Please select the choice give only"<<endl;
						 	
			}
		cout<<endl;
		cout<<"Press'Y' to return menu or Press other key to exit"<<endl;
		cin>>B;
		}while(B=='Y'||B=='y');
		output(user,i);
		return 0;
	
	}

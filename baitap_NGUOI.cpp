#include<iostream>
#include<iomanip>
#include<string.h>
#include<conio.h>
using namespace std;
class Nguoi{
    private:
    string ht;
    int tuoi;
    string nghe;
    string quoctich;
    public:
    Nguoi(){
        ht="Pham Dinh Hoang";
        this->tuoi=19;
        nghe="CNTT";
        quoctich="Viet Nam";
    }
    Nguoi(string ht, int tuoi, string nghe, string quoctich){
        ht,ht;
        nghe,nghe;
        quoctich,quoctich;
        this->tuoi=tuoi;
    }
    ~Nguoi(){}
    void input()
    {
        fflush(stdin);
        cout<<"\n Nhap ho ten cho nguoi ";
        getline(cin,ht);
        cout<<"\n Nhap nghe nghiep cua nguoi ";
        getline(cin,nghe);
        cout<<"\n Nhap quoc tich cua nguoi ";
        getline(cin,quoctich);
        cout<<"\n Nhap tuoi cua nguoi ";
        cin>>tuoi;
    }
    void output()
    {
        cout<<setw(30)<<ht<<setw(3)<<"|"
        <<setw(10)<<tuoi<<setw(3)<<"|"
        <<setw(20)<<nghe<<setw(3)<<"|"
        <<setw(20)<<quoctich<<setw(3)<<"|"<<endl;

    }
    string quoctichv()
    {return quoctich;}
    int &sotuoi()
    {
    	return tuoi;
    }
    string gethoten()
    {
        return ht;   
    }
    string tachten(string hoten)
    {
        int vt,i,j;
        string a;
        for(int i=hoten.length()-1;i>=0;i--)
        {
            if(hoten[i]==' ')
            {
                vt = i;
                break;
            }
        }
        for (int j=vt+1;j<hoten.length();j++)
        {
            a=a+hoten[j];
        }
        return a;
    }
};
void title()
    {
        cout<<setw(30)<<"Ho va ten"<<setw(3)<<"|"
        <<setw(10)<<"Tuoi"<<setw(3)<<"|"
        <<setw(20)<<"Nghe nghiep"<<setw(3)<<"|"
        <<setw(20)<<"Quoc tich"<<setw(3)<<"|"<<endl;

    }

main()
{
    Nguoi *ng;
    int n;
    cout<<"\n Nhap so nguoi can kiem tra la : ";
    do{
        cin>>n;
        if(n<=0)
        cout<<"\n Nhap lai so nguoi can kiem tra : ";
    }while(n<=0);
    ng= new Nguoi[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n Nhap thong tin cho nguoi thu "<<i+1<<" : "<<endl;
        ng[i].input();
    
    }
    cout<<"\n\t\t\t\t--------- Thong tin cua nguoi vua nhap la --------- "<<endl;
	title();
    
    for(int i=0;i<n;i++)
    {
        ng[i].output();
    }
	cout<<endl;
    cout<<"\n\t\t\t\t--------- Thong tin cua nguoi vua nhap theo ten la --------- "<<endl;
    title();
    for(int i=0;i<n;i++)
    {for(int j=i+1;j<n;j++)
    {
        if(ng[i].tachten(ng[i].gethoten())>ng[j].tachten(ng[j].gethoten()))
        {
            Nguoi temp=ng[i];
            ng[i]=ng[j];
            ng[j]=temp;
        }
        

    }ng[i].output();
    }
    cout<<endl;
	cout<<"\n\t\t\t\t--------- Thong tin cua nguoi vua nhap 0 co vn la --------- "<<endl;
	title();
    
    for(int i=0;i<n;i++)
    {
    	if(ng[i].quoctichv()!="Viet Nam")
    	
        ng[i].output();
    }
	cout<<endl;
		cout<<"\n\t\t\t\t--------- Sap xep giam dan theo tuoi ---------  "<<endl;
	title();
	
	for(int i=1;i<n;i++)
	{
    Nguoi x=ng[i];
		
		int pos = i-1;
		while((pos>=0)&&(ng[pos].sotuoi()<x.sotuoi()))
		{
			ng[pos + 1]=ng[pos];
			 pos=pos-1;
		}		
	    ng[pos + 1]=x;
        
	
	}
	for(int i=0;i<n;i++)
	{
			ng[i].output();
	}

}

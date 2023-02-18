#include <bits/stdc++.h>
using namespace std;

struct Column_c
{   
public:
	string NO; // Given
	int A; 
	int B; 
	int C; 
	
};

bool compareTwoColumnBCA(Column_c a, Column_c b)
{
	//compare
	if (a.B != b.B)
		return a.B < b.B;

	if (a.C != b.C)
        return a.C < b.C;
 
    return (a.A < b.A);
}

bool compareTwoColumnABC(Column_c a, Column_c b)
{
	//compare
	if (a.A != b.A)
		return a.A < b.A;

	if (a.B != b.B)
        return a.B < b.B;
 
    return (a.C < b.C);

};
//displayfunc
void display(Column_c a[]){
	int n =14;
    cout << "NO."
		<< "    ";
	cout << "A" << "\t"<< "B" << "\t" << "C" << "\n";
		
		



	for (int i = 0; i < n; i++) {
		cout << a[i].NO << "    " ;
		cout << a[i].A << "\t" << a[i].B << "\t"
			<< a[i].C << "\t";
		
		cout << "\n";
	}
}
// compute and display
void computeanddisplay(Column_c a[], int n)
{

	sort(a, a + 14, compareTwoColumnABC);
	cout << "Sort by ABC" << endl;
	display(a);
    sort(a, a + 14, compareTwoColumnBCA);
	cout << "Sort by BCA" << endl;
	display(a);
	

}

// Driver code
int main()
{
	int n = 14;

	// array of structure objects
	Column_c a[n];

	a[0].NO = "One";
	a[0].A = 1;
	a[0].B = 1;
	a[0].C = 4;

	a[1].NO = "Two";
	a[1].A = 3;
	a[1].B = 1;
	a[1].C = 1;

	a[2].NO = "Thr";
	a[2].A = 4;
	a[2].B = 4;
	a[2].C = 4;

	a[3].NO = "Fou";
	a[3].A = 2;
	a[3].B = 4;
	a[3].C = 4;

	a[4].NO = "Fiv";
	a[4].A = 3;
	a[4].B = 5;
	a[4].C = 3;

    a[5].NO = "Six";
	a[5].A = 4;
	a[5].B = 3;
	a[5].C = 3;

    a[6].NO = "Sev";
	a[6].A = 1;
	a[6].B = 3;
	a[6].C = 3;

    a[7].NO = "Eig";
	a[7].A = 2;
	a[7].B = 4;
	a[7].C = 3;

    a[8].NO = "Nin";
	a[8].A = 3;
	a[8].B = 3;
	a[8].C = 5;

    a[9].NO = "Ten";
	a[9].A = 1;
	a[9].B = 5;
	a[9].C = 3;

    a[10].NO = "Ele";
	a[10].A = 1;
	a[10].B = 1;
	a[10].C = 4;

    a[11].NO = "Twe";
	a[11].A = 4;
	a[11].B = 1;
	a[11].C = 1;

    a[12].NO = "Tht";
	a[12].A = 5;
	a[12].B = 2;
	a[12].C = 3;

    a[13].NO = "Fot";
	a[13].A = 3;
	a[13].B = 5;
	a[13].C = 2;

	computeanddisplay(a, n);
	
	
    
	


	return 0;
}

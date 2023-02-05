#include <bits/stdc++.h>
using namespace std;

struct Student{
    char name[50];
    int score;
    
};
struct Student student[10];

void MaxStudent(){
    int max_score = 0;
    int max_student = 0;
    for(int i=0;i<10;i++){
        if (student[i].score >= max_score){
            max_score = student[i].score;
            max_student = i;
        }
    }
    cout<<" Max score student is "<<student[max_student].name<<endl;
    cout<<"score = "<<student[max_student].score<<endl;
}
void MinStudent(){
    int min_score = 100;
    int min_student = 100;
    for(int i=0;i<10;i++){
        if (student[i].score <= min_score){
            min_score = student[i].score;
            min_student = i;
        }
    }
    cout<<" Min score student is "<<student[min_student].name<< endl;
    cout<<"score = "<<student[min_student].score<<endl;
}
void AvrScore(){
    float score = 0;
    for(int i=0; i<10;i++){
        score += student[i].score;
        
    score = score/10;
    cout<<"Average score :"<<score<<endl;
    }
}
void ModeScore(){
       char namee[30];
    int point;
    for(int i=0;i<10;i++){
        int min = 100;
        int minn = 0;
        for(int j=i;j<10;j++){
            if (student[j].score <= min){
                min = student[j].score;
                minn = j;
            }
        }
        strcpy(namee,student[i].name);
        point = student[i].score;
        strcpy(student[i].name,student[minn].name);
        student[i].score = student[minn].score;
        strcpy(student[minn].name,namee);
        student[minn].score = point;
    }
    int counter = 0;
    int count_max = 0;
    int mode = 0;
    for(int l=1;l<10;l++){
        if(student[l].score == student[l-1].score){
            counter++;
            if(counter > count_max){
                count_max = counter;
                mode = student[l].score;
            }
        }
        else{
            counter = 0;
        }
    }
    cout<<"Mode score : "<<mode << endl;
};
void MedianScore(){
        char namee[30];
    int point;
    float med;
    for(int i=0;i<10;i++){
        int min = 100;
        int minn = 0;
        for(int j=i;j<10;j++){
            if (student[j].score <= min){
                min = student[j].score;
                minn = j;
            }
        }
        strcpy(namee,student[i].name);
        point = student[i].score;
        strcpy(student[i].name,student[minn].name);
        student[i].score = student[minn].score;
        strcpy(student[minn].name,namee);
        student[minn].score = point;
    }
    cout<<"MedianScore : "<< (student[4].score+student[5].score)/2 << endl;
}
void SDScore(){
    float sum = 0;
    float mean,standardDeviation,sd;
    for(int i=0;i<10;i++){
        sum += student[i].score;
    }
    mean = sum/10;
    for(int j=0;j<10;j++) {
        standardDeviation += pow(student[j].score - mean, 2);
  }
   cout<<"SD score : "<< sqrt(standardDeviation / 10) << endl;
}
void show_grade(){
    float summ = 0;
    float mean,standardDeviation,SD;
    for(int i=0;i<10;i++){
        summ += student[i].score;
    }
    mean = summ/10;
    for(int j=0;j<10;j++) {
    standardDeviation += pow(student[j].score - mean, 2);
     }
    SD = sqrt(standardDeviation / 10);
    for(int l=1;l<10;l++){
        if(student[l].score >= mean + (2 * SD)){
            cout << "Name : " << student[l].name << endl;
            cout << "Grade A" << endl;
        }
        else if(student[l].score >= mean + SD){
            cout << "Name : " << student[l].name << endl;
            cout << "Grade B" << endl;
        }
        else if(student[l].score >= mean){
            cout << "Name : " << student[l].name << endl;
            cout << "Grade C" << endl;
        }
        else if(student[l].score >= mean - SD){
            cout << "Name : " << student[l].name << endl;
            cout << "Grade D" << endl;
        }
        else{
            cout<<"Name : "<<student[l].name<<endl;
            cout<<"Grade F"<<endl;
        }
    }
}



int main() {
 
        strcpy(student[0].name, "John");
        student[0].score = 95;
        strcpy(student[1].name, "Two");
        student[1].score = 81;
        strcpy(student[2].name, "King");
        student[2].score = 86;
        strcpy(student[3].name, "Jame");
        student[3].score = 75;
        strcpy(student[4].name, "Jordan");
        student[4].score = 60;
        strcpy(student[5].name, "Curry");
        student[5].score = 54;
        strcpy(student[6].name, "Mark");
        student[6].score = 41;
        strcpy(student[7].name, "Kelly");
        student[7].score = 66;
        strcpy(student[8].name, "George");
        student[8].score = 30;
        strcpy(student[9].name, "Adam");
        student[9].score = 71;
        MaxStudent();
        MinStudent();
        AvrScore();
        ModeScore();
        MedianScore();
        SDScore();
        show_grade();
        return 0;
        
    }
      
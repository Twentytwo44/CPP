#include <bits/stdc++.h>

using namespace std;

class Scoreboard{
    public:
        int point;
        string name;
        Scoreboard *prev;
        Scoreboard *next;
};

class Linkedlist{
    private:
        Scoreboard *head;
        Scoreboard *tail;
        int score_size = 0;
    public:
        Linkedlist(){
            this->head = NULL;
            void insert(string name,int point);
        };
void insert(string name,int point){
    Scoreboard *s = new Scoreboard;
    s->name = name;
    s->point = point;
    s->prev = NULL;
    s->next = NULL;

    
        if (head == NULL) {
            head = s;
            tail = s;
            score_size++;
        }
        else {
            Scoreboard *pt = head;
            while ((pt != NULL) && (pt->point > point)) {
                pt = pt->next;
            }
            if (pt == NULL) {
                tail->next = s;
                s->prev = tail;
                tail = s;
                score_size++;
            }
            else {
                s->next = pt;
                s->prev = pt->prev;
                pt->prev = s;
                if (pt == head) {
                    head = s;
                }
                else {
                    s->prev->next = s;
                }
                score_size++;
            }
            if (score_size > 10) {
                Scoreboard* pt = tail;
                tail = pt->prev;
                tail->next = NULL;
                delete pt;
                score_size--;
            }
        }

}
void display(){
    Scoreboard *p = this->head;
        int number = 1;
        cout<< "NO." << "\t" << "Name" << "\t" << "Score" << endl;
    while(p){
        cout<< number<< "\t" << p->name << "\t" << p->point << endl;
        p = p->next;
        number++;

    }
 
}
};
int main() {
    int new_score;
    string new_name;
    Linkedlist l;
    l.insert("Palm", 100);
    l.insert("Pin", 80);
    l.insert("Prim", 90);
    l.insert("David", 10);
    l.insert("Two", 70);
    l.insert("Jerry", 55);
    l.insert("Folk", 75);
    l.insert("Deaw", 67);
    l.insert("Pluem", 98);
    l.insert("Poom", 100);
    l.display();
    cout <<"Enter new name and score \n";
    cin >> new_name;
    cin >> new_score;
    l.insert(new_name, new_score);
    l.display();
    return 0;
}
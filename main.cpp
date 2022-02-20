#include <iostream>
using namespace std;

FILE* pollinom;
FILE* new_pollinom;

static void fill_poll(char* poll1, char *poll2);
void file_read(){
    char poll1[50];
    char poll2[50];
    pollinom = fopen("pollinom.txt", "rt");
    fgets(poll1, 50, pollinom);
    fgets(poll2, 50, pollinom);
    fclose(pollinom);
    cout << poll1<<endl;
    cout << poll2<<endl;
    fill_poll(poll1, poll2);
}

struct pollinom1{
    int degree;
    int coefficient;
    pollinom1(int degree, int coefficient) {
        this->degree = degree;
        this->coefficient = coefficient;
    }
};
struct Nodelist1{
    struct Node1{
        pollinom1* data;
        Node1* next;
        Node1(pollinom1& st) {
            data = &st;
        }
    };
    Node1* head = nullptr;
    Node1* tail = nullptr;
    void fill(pollinom1* data);
    void print(){
        Node1* iter = head;
        while(iter != nullptr){
            cout << iter->data->coefficient<<"-"<<iter->data->degree<<endl;
            iter = iter->next;
        }
    }
};
void Nodelist1::fill(pollinom1* data){
    Node1* node = new Node1(*data);
    if (head == nullptr) {
        head = node;
        tail = node;

    }
    else{
        tail->next = node;
        tail = node;
    }
}

struct pollinom2{
    int degree;
    int coefficient;
    pollinom2(int degree, int coefficient) {
        this->degree = degree;
        this->coefficient = coefficient;
    }
};
struct Nodelist2{
    struct Node2{
        pollinom2* data;
        Node2* next;
        Node2(pollinom2& st) {
            data = &st;
        }
    };
    Node2* head = nullptr;
    Node2* tail = nullptr;
    void fill(pollinom2* data);
    void print(){
        Node2* iter = head;
        while(iter != nullptr){
            cout << iter->data->coefficient<<"-"<<iter->data->degree<<endl;
            iter = iter->next;
        }
    }
};
void Nodelist2::fill(pollinom2* data){
    Node2* node = new Node2(*data);
    if (head == nullptr) {
        head = node;
        tail = node;

    }
    else{
        tail->next = node;
        tail = node;
    }
}

struct pollinom3{
    int degree;
    int coefficient;
    pollinom3(int degree, int coefficient) {
        this->degree = degree;
        this->coefficient = coefficient;
    }
};
struct Nodelist3{
    struct Node3{
        pollinom3* data;
        Node3* next;
        Node3(pollinom3& st) {
            data = &st;
        }
    };
    Node3* head = nullptr;
    Node3* tail = nullptr;
    void fill(pollinom3* data);
    void print(){
        Node3* iter = head;
        while(iter != nullptr){
            cout << iter->data->coefficient<<"-"<<iter->data->degree<<endl;
            iter = iter->next;
        }
    }
};
void Nodelist3::fill(pollinom3* data){
    Node3* node = new Node3(*data);
    if (head == nullptr) {
        head = node;
        tail = node;

    }
    else{
        tail->next = node;
        tail = node;
    }
}


void multiplication(const Nodelist1 &list1, const Nodelist2 &list2, Nodelist3 &list3) {
    Nodelist1::Node1* iter1 = list1.head;
    while(iter1!=nullptr){
        int coef;
        int deg;
        Nodelist2::Node2* iter2 = list2.head;
        while(iter2 != nullptr){
            coef = (iter1->data->coefficient)*(iter2->data->coefficient);
            deg = (iter1->data->degree)+(iter2->data->degree);
            list3.fill(new pollinom3(deg, coef));
            iter2 = iter2->next;
        }
        iter1 = iter1->next;
    }
    list3.print();
}

void print_new_pollinom(const Nodelist3 &list3) {
    Nodelist3::Node3* iter3 = list3.head;
    cout << "---------------------\n\tNew Pollinom\n---------------------\n";
    while(iter3 != nullptr){
        if(iter3->next != nullptr){
            cout<<iter3->data->coefficient<<"x^"<<iter3->data->degree<<"+";
            iter3 = iter3->next;
        }else{
            cout<<iter3->data->coefficient<<"x^"<<iter3->data->degree;
            iter3 = iter3->next;
        }
    }
}

static void fill_poll(char *poll1, char *poll2){

    Nodelist2 list2;
    Nodelist3 list3;
    Nodelist1 list1;
    int coefficient = 0;
    int degree = 0;
    int iterator = 1;
    for(int i = 0; i < 50; i++){
        if(poll1[i] == 'x'){
            if(i == 0 || isdigit(poll1[i-1]) == 0){
                coefficient = 1;
            }else{
                for(int j = i; isdigit(poll1[j-1]); j--){
                    coefficient += (int(poll1[j-1])-48)*iterator;
                    iterator *= 10;
                }
                iterator = 1;
            }

            if( i == sizeof(poll1) - 1 || isdigit(poll1[i+2]) == 0){
                degree = 1;
            }else if(poll1[i+1] == '^'){
                int j = i+2;
                for(j; isdigit(poll1[j]); j++){
                    degree += (int(poll1[j]-48)*iterator);
                    iterator *= 10;
                }
                i = j-1;
            }
            // write into the list
            list1.fill(new pollinom1(degree, coefficient));
            iterator = 1;
            coefficient = 0;
            degree = 0;
        }
    }

    for(int i = 0; i < 50; i++){
        if(poll2[i] == 'x'){
            if(i == 0 || isdigit(poll2[i-1]) == 0){
                coefficient = 1;
            }else{
                for(int j = i; isdigit(poll2[j-1]); j--){
                    coefficient += (int(poll2[j-1])-48)*iterator;
                    iterator *= 10;
                }
                iterator = 1;
            }

            if( i == sizeof(poll2) - 1 || isdigit(poll2[i+2]) == 0){
                degree = 1;
            }else if(poll2[i+1] == '^'){
                int j = i+2;
                for(j; isdigit(poll2[j]); j++){
                    degree += (int(poll2[j]-48)*iterator);
                    iterator *= 10;
                }
                i = j-1;
            }
            // write into the list
            list2.fill(new pollinom2(degree, coefficient));
            iterator = 1;
            coefficient = 0;
            degree = 0;
        }
    }

    multiplication(list1, list2, list3);
    print_new_pollinom(list3);
}


int main(){
    file_read();

}



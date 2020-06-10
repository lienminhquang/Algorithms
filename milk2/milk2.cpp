/*
ID: minhqua3
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Node{
    int start, end;
    Node* next;
    bool deleted;

    Node(int s, int e):
        start(s),
        end(e),
        next(nullptr),
        deleted(false){}
};



int cmp(const void* a,const void* b)
{
    if(((int*)a)[0] == ((int*)b)[0]) return 0;
    if(((int*)a)[0] > ((int*)b)[0]) return 1;
    return -1;
}



void _qsort(int arr[][2], int l, int h)
{
    if(l >= h) return;
    int pivot = arr[l + (h - l) / 2][0];
    int i = l, j = h;
    while(i <= j){
        while(arr[i][0] < pivot) i++;
        while(arr[j][0] > pivot) j--;

        if(i <= j)
        {
            swap(arr[i][0], arr[j][0]);
            swap(arr[i][1], arr[j][1]);
            i++;
            j--;
        }
    }
    _qsort(arr, l, j);
    _qsort(arr, i, h);
}

struct List {
    Node* head;
    Node* tail;

    List():
        head(nullptr),
        tail(nullptr){}




    void insert_order(int s, int e)
    {
        Node* node = new Node(s, e);
        if(head == nullptr)
        {
            head = tail = node;
            return;
        }

        //neu nhu 2 khoang thoi gian giao nhau thi hop chung lai
        if(tail->end >= node->start)
        {
            tail->end = max(node->end, tail->end);
        }
        else//neu khong thi them vao cuoi list
        {
            tail->next = node;
            tail = node;
        }

    }
};


int min(int x, int y){return x<y?x:y;}
int max(int x, int y){return x>y?x:y;}




int arr[5000][2];

int main()
{

    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int N = 0;

    int start = 0, end = 0;
    List schedule;

    fin >> N;

    for(int i = 0; i < N; ++i)
    {
        fin >> start >> end;
        //schedule.add(start, end);
        arr[i][0] = start;
        arr[i][1] = end;
        //cout << start << " ";
    }

    _qsort(arr, 0, N - 1);
    //qsort(arr, N, sizeof(arr[0]), cmp);

    for(int i = 0; i < N; ++i)
    {
        schedule.insert_order(arr[i][0], arr[i][1]);
    }
    int max_milking = 0, max_idle = 0;
    Node* n = schedule.head;
    int pre_end = n->start;

    while(n != nullptr){
        max_milking = max(max_milking, n->end - n->start);
        max_idle = max(max_idle, n->start - pre_end);
        pre_end = n->end;
        n = n->next;
    }

    fout << max_milking << " " << max_idle << endl;

    return 0;
}

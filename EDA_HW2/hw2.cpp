#include<iostream>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct pattern_node{
    string out;
    pattern_node in;
};

struct nand_node{
    char out;
    char in1;
    char in2;
};
struct not_node{
    char out;
    char in;
};

void readPattern(void){
    string data
}


int main(int argc, char* argv[]){
	ifstream in(argv[1]);
	string str = argv[1];
	for(int i = str.size()-1; i >= 0; i--){
		if(str[i] == '.'){
			str.erase(i+1, str.size());
		}
		
	}
	int cnt = 0;
	for(int i = str.size()-1; i >= 0; i --){
		if(str[i] == '/'){
			cnt = i;
			break;
		}
	}
	str.erase(0, cnt+1);
	str+= "txt";
	ofstream fout(str);

	string **patterns;
	do{
		string module_save;
	}while(getline( in, patterns));
	int resource, type, size, num, s, e;
	in >> size >> resource;
	int arr[size][size];
	for(int x = 0; x < size; x++){
		for(int y = 0; y < size; y ++){
			in >> arr[x][y]; 
		}
	}
} 














int compare(const void *a, const void *b){
    struct node *c=(struct node*)a;
    struct node *d=(struct node*)b;
	if(c->s == d->s){
		return (int)(c->num - d->num);
	}
	return (int)(c->s - d->s);
}
int main(int argc, char* argv[]){
	ifstream in(argv[1]);
	string str = argv[1];
	for(int i = str.size()-1; i >= 0; i--){
		if(str[i] == '.'){
			str.erase(i+1, str.size());
		}
		
	}
	int cnt = 0;
	for(int i = str.size()-1; i >= 0; i --){
		if(str[i] == '/'){
			cnt = i;
			break;
		}
	}
	str.erase(0, cnt+1);
	str+= "txt";
	ofstream fout(str);
	
	
	int resource, type, size, num, s, e;
	in >> size >> resource;
	int arr[size][size];
	for(int x = 0; x < size; x++){
		for(int y = 0; y < size; y ++){
			in >> arr[x][y]; 
		}
	}
    node mem[size];
    vector< vector<node> > input(resource + 1);
    
	for(int i = 0; i < size; i++){
        in >> type >> s >> e;
        mem[i].type = type;
        mem[i].num = i;
        mem[i].s = s;
        mem[i].e = e;
		mem[i].del = 0;
    }

	qsort(mem, size, sizeof(node), compare);
	
	for(int i = 0; i < size; i++){
		int t = mem[i].type;
		input[t].push_back(mem[i]);
    }
	
	for(int i = 1; i <= resource; i ++){
		vector<int> reg[input[i].size()];
		int index = 0;
		int f = 1;
		while(f){
			int last = 0;
			for(int j = 0; j < input[i].size(); j ++){
				if(input[i][j].s >= last && input[i][j].del == 0){
					reg[index].push_back(input[i][j].num);
					input[i][j].del = 1;
					last = input[i][j].e;
				}
			}
			int t = 0;
			for(int k = 0; k < input[i].size(); k++){
				t += input[i][k].del;
			}
			if(t == input[i].size())
				f=0;
			index++;

		}
		fout << "Demand of resource" << i << ": "<<index << endl;
		for(int j = 0;j < index; j++){
			for(int k = 0; k < reg[j].size() ; k ++){
				fout << reg[j][k]<<" ";
			}
			fout <<endl;
		}
	}
} 
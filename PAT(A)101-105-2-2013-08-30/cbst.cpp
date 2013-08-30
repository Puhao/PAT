#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int val;
	Node *left;
	Node *right;
	Node(int v):val(v){}
	/* data */
};

Node *CreatTree(int index,int &pos,vector<int> &v,int m)
{
	if (index >= m)
		return NULL;
	Node *t = new Node(1);
	t->left = CreatTree(index*2 + 1,pos,v,m);
	t->val = v[pos++];
	t->right = CreatTree(index*2 + 2,pos,v,m);
	return t; 
}

void BuildArray(int index,int &pos,vector<int> &v,vector<int> &cbst,int m)
{
	if (index >=m)
		return;
	//先填左子树，然后填自己，最后填右子树
	BuildArray(index*2 + 1,pos,v,cbst,m);
	cbst[index] = v[pos++];
	BuildArray(index*2 + 2,pos,v,cbst,m);
	return;
}


void PrintTree(Node *t)
{
	if (t == NULL)
		return;
	cout << t->val << " ";
	PrintTree(t->left);
	PrintTree(t->right);
	return;
}

int main()
{
	int num;
	cin >> num;
	int count = num;
	std::vector<int> v;
	vector<int> cbst(num,0);
	int tmp;
	while(count--)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int pos = 0;
	//Node *tree = CreatTree(0,pos,v,num);
	//PrintTree(tree);
	BuildArray(0,pos,v,cbst,num);
	for(int i=0;i<num;i++)
	{
		cout << cbst[i] << " ";
	}
	cout << endl;
	return 0;
}
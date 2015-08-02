// Returns first common ansestor of two persons in a family tree

#include <iostream>

using namespace std;

struct Person
{
	int id;
	Person* mother;
	Person* father;
};

struct ret
{
	ret(int i, int l)
	{
		id = i;
		level = l;
	}

	int id;
	int level;
};

bool Find(Person* p, int pid)
{
	if (p->id == pid) return true;
	bool m = false;
	bool f = false;
	if(p->mother != 0) m = Find(p->mother, pid);
	if (p->father != 0) f = Find(p->father, pid);
	if (m || f) return true;
	return false;
}

ret CommonAncestor(Person* p1, Person* p2, int level)
{
	if(Find(p2, p1->id)) return ret(p1->id, level);
	ret mancestor(-1, 100000), fancenstor(-1, 100000);
	if(p1->mother != 0) mancestor = CommonAncestor(p1->mother, p2, level + 1);
	if(p1->father != 0) fancenstor = CommonAncestor(p1->father, p2, level + 1);
	if (mancestor.level < fancenstor.level) return mancestor;
	return fancenstor;
}

int main()
{
    /*
    p14  p15 p16 p17 p13 p11 p12
      \  /    \  /    \  /\ /
       p4      p5      p6 p10 p9
         \    /  \    /    \  /
           p2      p3       p8
            \    /    \    /
              p1        p7
     
    */
    
	Person* p1 = new Person();
	Person* p2 = new Person();
	Person* p3 = new Person();
	Person* p4 = new Person();
	Person* p5 = new Person();
	Person* p6 = new Person();
	Person* p7 = new Person();
	Person* p8 = new Person();
	Person* p9 = new Person();
	Person* p10 = new Person();
	Person* p11 = new Person();
	Person* p12 = new Person();
	Person* p13 = new Person();
	Person* p14 = new Person();
	Person* p15 = new Person();
	Person* p16 = new Person();
	Person* p17 = new Person();

	p1->id = 1;
	p2->id = 2;
	p3->id = 3;
	p4->id = 4;
	p5->id = 5;
	p6->id = 6;
	p7->id = 7;
	p8->id = 8;
	p9->id = 9;
	p10->id = 10;
	p11->id = 11;
	p12->id = 12;
	p13->id = 13;
	p14->id = 14;
	p15->id = 15;
	p16->id = 16;
	p17->id = 17;

	p1->mother = p2;
	p1->father = p3;
	p7->mother = p3;
	p7->father = p8;
	p2->mother = p4;
	p2->father = p5;
	p3->mother = p5;
	p3->father = p6;
	p8->mother = p10;
	p8->father = p9;
	p4->mother = p14;
	p4->father = p15;
	p5->mother = p16;
	p5->father = p17;
	p6->mother = p13;
	p6->father = p11;
	p10->mother = p11;
	p10->father = p12;
	p9->mother = 0;
	p9->father = 0;
	p11->mother = 0;
	p11->father = 0;
	p12->mother = 0;
	p12->father = 0;
	p13->mother = 0;
	p13->father = 0;
	p14->mother = 0;
	p14->father = 0;
	p15->mother = 0;
	p15->father = 0;
	p16->mother = 0;
	p16->father = 0;
	p17->mother = 0;
	p17->father = 0;

	ret ca = CommonAncestor(p1, p8, 0);
	cout << ca.id << endl;
}

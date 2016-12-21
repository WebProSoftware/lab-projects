#pragma once
class node_coord
{
	double *pcoord;  // pcoord[0] -x pcoord[1] -y
public:
	node_coord() { pcoord = NULL; }
	node_coord(double x, double y);
	node_coord(const node_coord &nc);
	~node_coord();
	void disp();
	friend double distance(node_coord &a, node_coord &b);
private:
	void crash();
};


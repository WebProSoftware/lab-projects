#pragma once
class triangle
{
	node_coord vert_a;
	node_coord vert_b;
	node_coord vert_c;
	char *str;

public:
	triangle(node_coord AA, node_coord BB, node_coord CC, char *strr) : vert_a(AA), vert_b(BB), vert_c(CC) { str = strr; };
	~triangle();
	void disp();
	double distance(int First, int Second);
};

